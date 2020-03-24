#pragma once


#include "AEventHandler.h"

#include <typeinfo>

namespace LCU
{
	inline namespace Events
	{
		/**
		 * Event Handler For Non Member Functions Class
		 *
		 * @project Events
		 * @author Amine MAYOUF
		 *
		 * A helper class that handles non member function calls.
		 */
		template <typename... Types>
		class EventHandlerForNonMemberFunctions : public AEventHandler<Types...>
		{
			void (*m_pCallback)(Types ...);

		public:
			explicit EventHandlerForNonMemberFunctions(void (*p_pCallback)(Types ...));

			bool IsBindedToSameFunctionAs(AEventHandler<Types...>* p_pOther) override;
			void OnEventTriggered(Types ... p_values) override;
		};

		template <typename ...Types>
		EventHandlerForNonMemberFunctions<Types...>::EventHandlerForNonMemberFunctions(void (*p_pCallback)(Types ...))
			: m_pCallback(p_pCallback)
		{
		}

		template <typename ... Types>
		bool EventHandlerForNonMemberFunctions<Types...>::IsBindedToSameFunctionAs(AEventHandler<Types...>* p_pOther)
		{
			if (!p_pOther || typeid(*this) != typeid(*p_pOther))
			{
				return false;
			}
			return m_pCallback == dynamic_cast<EventHandlerForNonMemberFunctions*>(p_pOther)->m_pCallback;
		}

		template <typename ...Types>
		void EventHandlerForNonMemberFunctions<Types...>::OnEventTriggered(Types ...p_values)
		{
			m_pCallback(p_values...);
		}

		/**
		 * A specialization of the Event Handler For Non Member Functions Class for when void is passed.
		 */
		template <>
		class EventHandlerForNonMemberFunctions<void> : public AEventHandler<void>
		{
			void (*m_pCallback)();

		public:
			explicit EventHandlerForNonMemberFunctions(void (*p_pCallback)());

			bool IsBindedToSameFunctionAs(AEventHandler<void>* p_pOther) override;
			void OnEventTriggered() override;
		};

		inline EventHandlerForNonMemberFunctions<void>::EventHandlerForNonMemberFunctions(void (*p_pCallback)())
			: m_pCallback(p_pCallback)
		{
		}

		inline bool EventHandlerForNonMemberFunctions<void>::IsBindedToSameFunctionAs(AEventHandler<void>* p_pOther)
		{
			if (!p_pOther || typeid(*this) != typeid(*p_pOther))
			{
				return false;
			}
			return m_pCallback == dynamic_cast<EventHandlerForNonMemberFunctions*>(p_pOther)->m_pCallback;
		}

		inline void EventHandlerForNonMemberFunctions<void>::OnEventTriggered()
		{
			m_pCallback();
		}
	}
}
