#pragma once

#include "IObserver.h"

namespace lcu
{
	inline namespace interfaces
	{
		/**
		 * IObservable Interface
		 *
		 * @project Interfaces
		 * @author Amine MAYOUF
		 */
		class IObservable
		{
		public:
			IObservable() = default;
			virtual ~IObservable() = default;

			virtual void AddObserver(const IObserver& p_observer) = 0;
			virtual void NotifyObservers() = 0;
			virtual void RemoveObserver(const IObserver& p_observer) = 0;
		};
	}
}
