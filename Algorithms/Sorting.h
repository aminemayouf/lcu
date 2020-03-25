#pragma once


#include "Utility.h"

#include <ctime>

namespace lcu
{
	inline namespace algorithms
	{
		/**
		 * Sorting Class
		 *
		 * @project Algorithms
		 * @author Amine MAYOUF
		 */
		template <typename Type>
		class Sorting
		{
		public:
			Sorting() = delete;
			~Sorting() = delete;

			// COMPARISON SORTS
			// Basic Sorts
			/**
			 * @complexity
			 *	Best case: O(p_size) The array is already sorted.
			 *	Worst and average case: O(p_size) The array is sorted in the opposite order.
			 */
			static void BubbleSort(Type* p_pArray, size_t p_size);
			static void BubbleSort(Type* p_pArray, size_t p_startIndex, size_t p_endIndex);
			/**
			 * This algorithm is interesting because it can be used to classify values in real time,
			 * as they arrive... Very useful if the list Contains less than 15 items.
			 *
			 * @complexity
			 *	Best case: O(p_size) The array is already sorted.
			 *	Worst and average case: O(p_size) The array is sorted in the opposite order.
			 */
			static void InsertionSort(Type* p_pArray, size_t p_size);
			static void InsertionSort(Type* p_pArray, size_t p_startIndex, size_t p_endIndex);
			/**
			 * This algorithm can be useful if the list contains less than 7 items.
			 *
			 * @complexity
			 *	Best case: O(p_size) The array is already sorted.
			 *	Worst and average case: O(p_size) The array is sorted in the opposite order.
			 */
			static void SelectionSort(Type* p_pArray, size_t p_size);
			static void SelectionSort(Type* p_pArray, size_t p_startIndex, size_t p_endIndex);
			/**
			 * Shell sort is an excellent optimization of insertion sort.
			 * Regarding memory, very little is needed.
			 *
			 * @complexity O(p_size).
			 */
			static void ShellSort(Type* p_pArray, size_t p_size);
			static void ShellSort(Type* p_pArray, size_t p_startIndex, size_t p_endIndex);

			// Advanced Sorts
		public:
			/**
			 * @complexity
			 *	Best case: O(p_size*ln(p_size)).
			 *	Worst case: O(p_size) -> The array is sorted in reverse.
			 */
			static void QuickSort(Type* p_pArray, size_t p_size);
			static void QuickSort(Type* p_pArray, long long p_startIndex, long long p_endIndex);
			// NON-COMPARISON SORTS
			static void CountingSort(int* p_pArray, int* p_pArray_out, int p_size, int p_maxValue);
		};

		template <typename Type>
		void Sorting<Type>::BubbleSort(Type* p_pArray, size_t p_size)
		{
			bool ordered = false;
			while (!ordered)
			{
				ordered = true;
				for (size_t i = 0; i < p_size - 1; ++i)
				{
					if (p_pArray[i] > p_pArray[i + 1])
					{
						Utility::Swap(p_pArray[i], p_pArray[i + 1]);
						ordered = false;
					}
				}
				--p_size;
			}
		}

		template <typename Type>
		void Sorting<Type>::BubbleSort(Type* p_pArray, size_t p_startIndex, size_t p_endIndex)
		{
			bool ordered = false;
			while (!ordered)
			{
				ordered = true;
				for (size_t i = p_startIndex; i < p_endIndex; ++i)
				{
					if (p_pArray[i] > p_pArray[i + 1])
					{
						Utility::Swap(p_pArray[i], p_pArray[i + 1]);
						ordered = false;
					}
				}
				--p_endIndex;
			}
		}

		template <typename Type>
		void Sorting<Type>::InsertionSort(Type* p_pArray, size_t p_size)
		{
			size_t j;
			Type current;
			for (size_t i = 1; i < p_size; ++i)
			{
				current = p_pArray[i]; // storing current element whose left side is checked for its correct position.
				// check whether the adjacent element in left side is greater or less than the current element.
				for (j = i; j > 0 && p_pArray[j - 1] > current; j--)
				{
					p_pArray[j] = p_pArray[j - 1]; // moving the left side element to one position forward .
				}
				p_pArray[j] = current; // moving current element to its  correct position.
			}
		}

		template <typename Type>
		void Sorting<Type>::InsertionSort(Type* p_pArray, size_t p_startIndex, size_t p_endIndex)
		{
			size_t j;
			Type current;
			for (size_t i = p_startIndex + 1; i < p_endIndex + 1; ++i)
			{
				current = p_pArray[i]; // storing current element whose left side is checked for its correct position.
				// check whether the adjacent element in left side is greater or less than the current element.
				for (j = i; j > p_startIndex && p_pArray[j - 1] > current; j--)
				{
					p_pArray[j] = p_pArray[j - 1]; // moving the left side element to one position forward .
				}
				p_pArray[j] = current; // moving current element to its  correct position.
			}
		}

		template <typename Type>
		void Sorting<Type>::SelectionSort(Type* p_pArray, size_t p_size)
		{
			size_t max;
			while (p_size > 0)
			{
				// temporary variable to store the position of maximum element
				max = 0; // assuming first element to be maximum of the unsorted array .
				for (size_t i = 1; i < p_size; ++i)
				{
					if (p_pArray[i] > p_pArray[max])
					{
						// finds the maximum element
						max = i;
					}
					Utility::Swap(p_pArray[max], p_pArray[p_size - 1]);
				}
				--p_size;
			}
		}

		template <typename Type>
		void Sorting<Type>::SelectionSort(Type* p_pArray, size_t p_startIndex, size_t p_endIndex)
		{
			size_t max;
			while (p_endIndex + 1 > 0)
			{
				// temporary variable to store the position of maximum element
				max = p_startIndex; // assuming first element to be maximum of the unsorted array .
				for (size_t i = p_startIndex + 1; i < p_endIndex + 1; ++i)
				{
					if (p_pArray[i] > p_pArray[max])
					{
						// finds the maximum element
						max = i;
					}
					Utility::Swap(p_pArray[max], p_pArray[p_endIndex]);
					// putting maximum element on its proper position.
				}
				--p_endIndex;
			}
		}

		template <typename Type>
		void Sorting<Type>::ShellSort(Type* p_pArray, size_t p_size)
		{
			size_t step = 0;
			while (step < p_size)
			{
				step = 3 * step + 1;
			}
			Type memory;
			size_t j;
			while (step != 0)
			{
				step /= 3;
				for (size_t i = step; i < p_size; ++i)
				{
					memory = p_pArray[i];
					j = i;
					while ((j > (step - 1)) && (p_pArray[j - step] > memory))
					{
						p_pArray[j] = p_pArray[j - step];
						j = j - step;
					}
					p_pArray[j] = memory;
				}
			}
		}

		template <typename Type>
		void Sorting<Type>::ShellSort(Type* p_pArray, size_t p_startIndex, size_t p_endIndex)
		{
			size_t step = p_startIndex;
			while (step < p_endIndex + 1)
			{
				step = 3 * step + 1;
			}
			size_t j;
			Type memory;
			while (step != 0)
			{
				step /= 3;
				for (size_t i = step; i < p_endIndex + 1; ++i)
				{
					memory = p_pArray[i];
					j = i;
					while ((j > (step - 1)) && (p_pArray[j - step] > memory))
					{
						p_pArray[j] = p_pArray[j - step];
						j = j - step;
					}
					p_pArray[j] = memory;
				}
			}
		}

		template <typename Type>
		void Sorting<Type>::QuickSort(Type* p_pArray, size_t p_size)
		{
			QuickSort(p_pArray, 0, p_size - 1);
		}

		template <typename Type>
		void Sorting<Type>::QuickSort(Type* p_pArray, long long p_startIndex, long long p_endIndex)
		{
			long long i = p_startIndex;
			long long j = p_endIndex;
			Type pivot = p_pArray[(p_startIndex + p_endIndex) / 2];

			/* partition */
			while (i <= j)
			{
				while (p_pArray[i] < pivot)
					++i;
				while (p_pArray[j] > pivot)
					--j;
				if (i <= j)
				{
					Utility::Swap(p_pArray[i], p_pArray[j]);
					++i;
					--j;
				}
			}

			if (p_startIndex < j)
				QuickSort(p_pArray, p_startIndex, j);
			if (i < p_endIndex)
				QuickSort(p_pArray, i, p_endIndex);
		}

		template <typename Type>
		void Sorting<Type>::CountingSort(int* const p_pArray, int* array_t_out, int p_size, int p_maxValue)
		{
			int* pArrayTAux = new int[p_maxValue + 1];
			// initialize the elements of array with 0 .
			for (int i = 0; i <= p_maxValue; ++i)
			{
				pArrayTAux[i] = 0;
			}
			/*stores the frequencies of each distinct element of p_pArray[ ],by
			mapping its value as the index of pArrayTAux[ ] array.*/
			for (int j = 0; j < p_size; ++j)
			{
				pArrayTAux[p_pArray[j]] ++;
			}
			/*calculates how many elements are less than or equal to i by
			running sum of  pArrayTAux array. */
			for (int i = 1; i <= p_maxValue; ++i)
			{
				pArrayTAux[i] = pArrayTAux[i] + pArrayTAux[i - 1];
			}
			// places each element of p_pArray[ ] at its correct position int Out [ ] array.
			for (int j = p_size - 1; j >= 0; j--)
			{
				array_t_out[pArrayTAux[p_pArray[j]] - 1] = p_pArray[j];
				pArrayTAux[p_pArray[j]] = pArrayTAux[p_pArray[j]] - 1;
			}
			delete[] pArrayTAux;
		}
	}
}
