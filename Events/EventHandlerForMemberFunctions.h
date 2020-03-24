#pragma once


#include "AEventHandler.h"

namespace LCU
{
	inline namespace Events
	{
		/**
		 * Event Handler For Member Functions Class
		 *
		 * @project Events
		 * @author Amine MAYOUF
		 * 
		 * A helper class that handles member function calls.
		 */
		template <class Class, typename... Types>
		class EventHandlerForMemberFunctions : public AEventHandler<Types...>
		{
			Class* m_pCaller;
			void (Class::*m_pCallback)(Types ...);

		public:
			EventHandlerForMemberFunctions(Class* p_pCaller, void (Class::*p_pCallback)(Types ...));

			bool IsBindedToSameFunctionAs(AEventHandler<Types ...>* p_pOther) override;
			void OnEventTriggered(Types ... p_values) override;
		};

		template <class Class, typename ...Types>
		EventHandlerForMemberFunctions<Class, Types...>::EventHandlerForMemberFunctions(
			Class* p_pCaller, void (Class::* p_pCallback)(Types ...))
			: m_pCaller(p_pCaller),
			  m_pCallback(p_pCallback)
		{
		}

		template <class Class, typename ... Types>
		bool EventHandlerForMemberFunctions<Class, Types...>::IsBindedToSameFunctionAs(
			AEventHandler<Types...>* p_pOther)
		{
			if (!p_pOther || typeid(*this) != typeid(*p_pOther))
			{
				return false;
			}
			return m_pCallback == dynamic_cast<EventHandlerForMemberFunctions*>(p_pOther)->m_pCallback;
		}

		template <class Class, typename ... Types>
		void EventHandlerForMemberFunctions<Class, Types...>::OnEventTriggered(Types ... p_values)
		{
			if (m_pCaller)
			{
				(m_pCaller->*m_pCallback)(p_values...);
			}
		}

		/**
		 * A specialization of the Event Handler For Non Member Functions Class for when void is passed.
		 */
		template <class Class>
		class EventHandlerForMemberFunctions<Class, void> : public AEventHandler<void>
		{
			Class* m_pCaller;
			void (Class::*m_pCallback)();

		public:
			EventHandlerForMemberFunctions(Class* p_pCaller, void (Class::*p_pCallback)());

			bool IsBindedToSameFunctionAs(AEventHandler<void>* pOther) override;
			void OnEventTriggered() override;
		};

		template <class Class>
		EventHandlerForMemberFunctions<Class, void>::EventHandlerForMemberFunctions(
			Class* p_pCaller, void ( Class::* p_pCallback)())
			: m_pCaller(p_pCaller),
			  m_pCallback(p_pCallback)
		{
		}

		template <class Class>
		bool EventHandlerForMemberFunctions<Class, void>::IsBindedToSameFunctionAs(AEventHandler<void>* p_pOther)
		{
			if (!p_pOther || typeid(*this) != typeid(*p_pOther))
			{
				return false;
			}
			return m_pCallback == dynamic_cast<EventHandlerForMemberFunctions*>(p_pOther)->m_pCallback;
		}

		template <class Class>
		void EventHandlerForMemberFunctions<Class, void>::OnEventTriggered()
		{
			if (m_pCaller)
			{
				(m_pCaller->*m_pCallback)();
			}
		}
	}
}
