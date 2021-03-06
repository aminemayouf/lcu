#pragma once

#include "forward_iterator.h"

namespace lcu
{
	inline namespace interfaces
	{
		/**
		 * IIterator Interface
		 *
		 * @project Interfaces
		 * @author Amine MAYOUF
		 */
		template <typename Type>
		class IIterator : public IForwardIterator<Type>
		{
		public:
			virtual IIterator& operator--() = 0; // Prefix decrement
			//virtual IIterator& operator--(size_t p_i) = 0; // Postfix decrement
		};
	}
}
