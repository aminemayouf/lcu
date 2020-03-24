#pragma once

#include "IComparable.h"

namespace LCU
{
	inline namespace Interfaces
	{
		/**
		 * IComparer Interface
		 *
		 * @project Interfaces
		 * @author Amine MAYOUF
		*/
		template <class Class>
		class IComparer
		{
		public:
			IComparer() = default;
			virtual ~IComparer() = default;

			virtual int Compare(const Class& p_a, const Class& p_b) const = 0;
		};
	}
}
