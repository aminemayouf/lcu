#pragma once


#include "EventHandler.h"

#ifdef USE_DATASTRUSTURES
#include "DataStructures/Set.h"
#else
#include <set>
#endif

namespace LCU {
	inline namespace Events {
		/**
		 * Event Class
		 *
		 * @project Events
		 * @author Amine MAYOUF
		 *
		 * Event provides an event mechanism that is similar to the one found in C#.
		 *
		 * Here is an example on how we connect a handler to an event.
		 * @example myEvent += EventHandler::Bind(this, &Class::On...);
		 * @note Handlers will be notified when operator() is called.
		 */
		template <typename... Types> // Variadic template
		class Event {
			/*
			 *	Attributes
			 */
		protected:
#ifdef USE_DATASTRUSTURES
			Set<AEventHandler<Types...>*> m_handlers;
#else
			std::set<AEventHandler<Types...>*> m_handlers;
#endif
			/*
			 *	Methods
			 */
		public:
			Event() = default;
			Event(const Event&) = delete; // Disable copying.
			virtual ~Event();

			Event& operator +=(AEventHandler<Types...>* p_eventHandler);
			Event& operator -=(AEventHandler<Types...>* p_eventHandler);

			void operator ()(const Types&... p_values);

			Event& operator=(const Event&) = delete; // Same here.
		};

		template <typename ... Types>
		Event<Types...>::~Event() {
			// m_handlers.Purge();
		}

		template <typename ... Types>
		Event<Types...>& Event<Types...>::operator+=(AEventHandler<Types...>* p_eventHandler) {
			if (p_eventHandler) {
				m_handlers.Insert(p_eventHandler);
			}
			return *this;
		}

		template <typename ... Types>
		Event<Types...>& Event<Types...>::operator-=(AEventHandler<Types...>* p_eventHandler) {
			if (p_eventHandler) {
				for (auto it = m_handlers.Begin(); it != m_handlers.End(); ++it) {
					if ((*it)->IsBindedToSameFunctionAs(p_eventHandler)) {
						m_handlers.Remove(it);
						break;
					}
				}
			}
			return *this;
		}

		template <typename ... Types>
		void Event<Types...>::operator()(const Types&... p_values) {
			for (auto it = m_handlers.begin(); it != m_handlers.end(); ++it) {
				if (*it) {
					(*it)->OnEventTriggered(p_values...);
				}
			}
		}

		/**
		* A specialization of the Event Class for when void is passed.
		*/
		template <>
		class Event<void> {
			/*
			 *	Attributes
			 */
		protected:
#ifdef USE_DATASTRUSTURES
			Set<AEventHandler<void>*> m_handlers;
#else
			std::set<AEventHandler<void>*> m_handlers;
#endif
			/*
			 *	Methods
			 */
		public:
			Event() = default;
			Event(const Event&) = delete;
			virtual ~Event();

			Event& operator +=(AEventHandler<void>* p_eventHandler);
			Event& operator -=(AEventHandler<void>* p_eventHandler);

			void operator ()() const;

			Event& operator=(const Event&) = delete;
		};

		inline Event<void>::~Event() {
			// m_handlers.Purge();
		}

		inline Event<void>& Event<void>::operator+=(AEventHandler<void>* p_eventHandler) {
			if (p_eventHandler) {
#ifdef USE_DATASTRUSTURES
				m_handlers.Insert(p_eventHandler);
#else
				m_handlers.insert(p_eventHandler);
#endif // USE_DATASTRUSTURES
			}
			return *this;
		}

		inline Event<void>& Event<void>::operator-=(AEventHandler<void>* p_eventHandler) {
			if (p_eventHandler) {
#ifdef USE_DATASTRUSTURES
				for (auto it = m_handlers.Begin(); it != m_handlers.End(); ++it) {
#else
				for (auto it = m_handlers.begin(); it != m_handlers.end(); ++it) {
#endif // USE_DATASTRUSTURES
					if ((*it)->IsBindedToSameFunctionAs(p_eventHandler)) {
#ifdef USE_DATASTRUSTURES
						m_handlers.Remove(*it);
#else
						m_handlers.erase(*it);
#endif // USE_DATASTRUSTURES
						break;
					}
				}
			}
			return *this;
		}

		inline void Event<void>::operator()() const {
#ifdef USE_DATASTRUSTURES
			for (auto it = m_handlers.Begin(); it != m_handlers.End(); ++it) {
#else
			for (auto it = m_handlers.begin(); it != m_handlers.end(); ++it) {
#endif // USE_DATASTRUSTURES
				(*it)->OnEventTriggered();
			}
		}
	}
}
