#pragma once

namespace LCU
{
	inline namespace Interfaces
	{
		/**
		 * IObserver Interface
		 *
		 * @project Interfaces
		 * @author Amine MAYOUF
		 */
		class IObserver
		{
		public:
			IObserver() = default;
			virtual ~IObserver() = default;

			virtual void Update() = 0;
		};
	}
}
