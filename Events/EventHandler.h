#pragma once

#include "EventHandlerForNonMemberFunctions.h"
#include "EventHandlerForMemberFunctions.h"

namespace lcu
{
	inline namespace events
	{
		/**
		 * Event Handler Class
		 *
		 * @project Events
		 * @author Amine MAYOUF
		 *
		 * Event handlers are used internally by Event.
		 */
		class EventHandler
		{
		public:
			EventHandler() = delete;
			~EventHandler() = delete;

			template <typename ...Types>
			static EventHandlerForNonMemberFunctions<Types...>* Bind(void (*p_callback)(Types ...));
			static EventHandlerForNonMemberFunctions<void>* Bind(void (*p_callback)());
			template <class Class, typename ...Types>
			static EventHandlerForMemberFunctions<Class, Types...>* Bind(
				Class* caller, void (Class::*p_callback)(Types ...));
			template <class Class>
			static EventHandlerForMemberFunctions<Class, void>* Bind(Class* caller, void (Class::*p_callback)());
		};

		template <typename ...Types>
		EventHandlerForNonMemberFunctions<Types...>* EventHandler::Bind(void (*p_callback)(Types ...))
		{
			return new EventHandlerForNonMemberFunctions<Types...>(p_callback);
		}

		inline EventHandlerForNonMemberFunctions<void>* EventHandler::Bind(void (*p_callback)())
		{
			return new EventHandlerForNonMemberFunctions<void>(p_callback);
		}

		template <class Class, typename ...Types>
		EventHandlerForMemberFunctions<Class, Types...>* EventHandler::Bind(
			Class* p_caller, void (Class::* p_callback)(Types ...))
		{
			return new EventHandlerForMemberFunctions<Class, Types...>(p_caller, p_callback);
		}

		template <class Class>
		EventHandlerForMemberFunctions<Class, void>* EventHandler::Bind(Class* p_caller, void (Class::* p_callback)())
		{
			return new EventHandlerForMemberFunctions<Class, void>(p_caller, p_callback);
		}
	}
}
