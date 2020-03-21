#pragma once


namespace LCU {
	inline namespace Algorithms {
		/**
		 * Searching Class
		 *
		 * @project Algorithms
		 * @author Amine MAYOUF
		*/
		template <typename Type>
		class Searching {
			/*
			 * Methods
			 */
		public:
			Searching() = delete;
			~Searching() = delete;

			// B
			static size_t BinarySearch(Type*const p_pArray, size_t p_size, const Type& p_value);

			// S
			static size_t SequentialSearch(Type*const p_pArray, size_t p_size, const Type& p_value);
		};

		template <typename Type>
		size_t Searching<Type>::BinarySearch(Type*const p_pArray, size_t p_size, const Type& p_value) {

			size_t startIndex = 0;
			size_t middleIndex;
			size_t endIndex = p_size;

			while ((endIndex - startIndex) > 1) {
				middleIndex = (startIndex + endIndex) / 2;

				if (p_pArray[middleIndex] == p_value) {
					return middleIndex;
				}

				if (p_pArray[middleIndex] > p_value) {
					endIndex = middleIndex;
				}
				else {
					startIndex = middleIndex;
				}
			}
			return p_pArray[startIndex] == p_value ? startIndex : std::numeric_limits<size_t>::infinity();
		}

		template <typename Type>
		size_t Searching<Type>::SequentialSearch(Type*const p_pArray, size_t p_size, const Type& p_value) {

			for (size_t i = 0; i < p_size; ++i) {
				if (p_pArray[i] == p_value) {
					return i;
				}
			}
			return std::numeric_limits<size_t>::infinity();
		}
	}
}
