#pragma once

namespace LCU {
	inline namespace Interfaces {
		/**
		 * IForwardIterator Interface
		 *
		 * @project Interfaces
		 * @author Amine MAYOUF
		 */
		template <typename Type>
		class IForwardIterator {

		public:
			virtual ~IForwardIterator() = default;

			// #
			virtual IForwardIterator& operator++() = 0; // Prefix increment
			//virtual IForwardIterator& operator++(size_t p_i) = 0; // Postfix increment

			virtual Type& operator*() const = 0;

			virtual Type* operator->() const = 0;

			/*virtual bool operator==(const IForwardIterator<Type>& p_iterator) const = 0;
			virtual bool operator!=(const IForwardIterator<Type>& p_iterator) const = 0;*/
		};
	}
}
