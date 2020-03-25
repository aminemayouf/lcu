#pragma once


namespace lcu
{
	inline namespace events
	{
		/**
		 * Abstract Event Handler Class
		 *
		 * @project Events
		 * @author Amine MAYOUF
		 *
		 * A base class for all event handlers.
		 */
		template <typename... Types>
		class AEventHandler
		{
		public:
			AEventHandler() = default;
			virtual ~AEventHandler() = default;

			// This function verifies if both handlers are binded to the same function.
			virtual bool IsBindedToSameFunctionAs(AEventHandler<Types ...>*) = 0;
			// This function will be called eventually when a Event is raised.
			virtual void OnEventTriggered(Types ...) = 0;
		};

		/**
		 * A specialization of the Abstract Event Handler Class for when void is passed.
		 */
		template <>
		class AEventHandler<void>
		{
		public:
			AEventHandler() = default;

			virtual ~AEventHandler() = default;

			virtual bool IsBindedToSameFunctionAs(AEventHandler<void>*) = 0;

			virtual void OnEventTriggered() = 0;
		};
	}
}
