#pragma once

#include "AContainer.h"

#include "../Interfaces/IIterator.h"

namespace lcu
{
	inline namespace data_structures
	{
		/**
		  * Array Class
		  *
		  * @project DataStructures
		  * @author Amine MAYOUF
		  */
		template <typename Type>
		class Array : public AContainer<Type>, public IComparable<Array<Type>>
		{
		public:
			class Iterator : public IIterator<Type>
			{
				Type* m_pCurrent;

			public:
				explicit Iterator(Type* const p_pElement)
				{
					m_pCurrent = p_pElement;
				}

				Iterator& operator++() override
				{
					++m_pCurrent;
					return *this;
				}

				Iterator& operator--() override
				{
					--m_pCurrent;
					return *this;
				}

				Type& operator*() const override
				{
					return *m_pCurrent;
				}

				Type* operator->() const override
				{
					return m_pCurrent;
				}

				bool operator==(const Iterator& p_iterator) const
				{
					return m_pCurrent == p_iterator.m_pCurrent;
				}

				bool operator!=(const Iterator& p_iterator) const
				{
					return m_pCurrent != p_iterator.m_pCurrent;
				}
			};

		protected:
			Type* m_pDataT;

			size_t m_capacity;
			using AContainer<Type>::m_size;

		public:
			Array();
			explicit Array(size_t p_capacity, size_t p_size = 0);
			Array(size_t p_size, const Type& p_defaultValue);
			Array(const Array& p_array);
			Array(std::initializer_list<Type> p_parameters);
			virtual ~Array();

			size_t Capacity() const;

			// Type* DataT() const;

			Iterator Begin() const;
			Iterator BeginReverse() const;

			Iterator End() const;
			Iterator EndReverse() const;

			// A
			static Type* AllocateMemory(size_t p_cells);
			void Assign(const Type& p_value, size_t p_index);
			// C
			void Concat(const Array& p_array);
			bool Contains(const Type& p_value) const override;
			static Type* CopyOf(const Type* p_pDataT, size_t p_size);
			static void CopyValue(const Type& p_value, Type* p_pTo, size_t p_size);
			static void CopyValues(const Type* p_pFrom, Type* p_pTo, size_t p_size);
			// F
			/**
			 * Fills the array with the given p_value.
			 * @param p_value The value to fill the array with.
			 *
			 * Complexity: O(n).
			 */
			void FillWith(const Type& p_value);
			void FillWith(const Array<Type>& p_arrayValues);
			static void FreeMemory(Type* p_pDataT);
			static void FreeMemorySafe(Type* p_pDataT);
			// I
			/**
			 * @return the p_index of the first p_value that equals the given one. -1 if the p_value doesn't exist.
			 *
			 * Complexity: O(n).
			 */
			size_t IndexOf(const Type& p_value) const;
			bool IsEmpty() const override;
			/**
			 * Checks if the array is sorted.
			 *
			 * Complexity: O(n).
			 */
			bool IsSorted() const;
			// M
			Type Max() const;
			Type Min() const;
			// P
			void PopBack();
			void Purge() override;
			/**
			 * Adds a value to the back of the array.
			 *
			 * Complexity: O(n) or more precisely O(3n+log(n)).
			 */
			virtual void PushBack(const Type& p_value);
			// R
			void ReplaceAll(const Type& p_valueToReplace, const Type& p_replacementValue);
			void ReplaceFirst(const Type& p_valueToReplace, const Type& p_replacementValue);
			/**
			 * Reverses order of the p_value in the array.
			 *
			 * Complexity: O(n/2).
			 */
			void Reverse();
			virtual void Resize(size_t p_newLength, bool p_keepData = true);
			// 
			/**
			 * Sorts the values using the Quick Sort.
			 *
			 * Complexity: O(nlog(n)).
			 */
			void Sort();
			Array SubArray(size_t p_startIndex, size_t p_endIndex) const;
			// T
			String ToString() const override;
			// V
			Type ValueAt(size_t p_index) const;
			// #
			Type& operator [](size_t p_index) const;
			Array& operator =(const Type& p_value);
			Array& operator =(const Array& p_array);
			bool operator <(const Array& p_array) const override;
			bool operator >(const Array& p_array) const override;
			/**
			 * Compares two arrays based on their lengths and then by their values.
			 * @param p_array The array to compare with.
			 * @return False if their lengths doesn't match and/or their values are different. True if their lengths and values match.
			 *
			 * Complexity: O(1) if their "Length" differs.
			 * else : O(n).
			 */
			bool operator ==(const Array& p_array) const override;
			Array operator +(const Type& p_value) const;
			Array operator +(const Array& p_array) const;
			Array operator -(const Type& p_value) const;
			Array operator -(const Array& p_array) const;
			Array operator *(const Type& p_value) const;
			Array operator *(const Array& p_array) const;
			Array operator /(const Type& p_value) const;
			Array operator /(const Array& p_array) const;
			Array& operator +=(const Type& p_value);
			Array& operator +=(const Array& p_array);
			Array& operator -=(const Type& p_value);
			Array& operator -=(const Array& p_array);
			Array& operator *=(const Type& p_value);
			Array& operator *=(const Array& p_array);
			Array& operator /=(const Type& p_value);
			Array& operator /=(const Array& p_array);
		};

		template <typename Type>
		Array<Type>::Array() : AContainer(), m_pDataT(nullptr), m_capacity(0)
		{
		}

		template <typename Type>
		Array<Type>::Array(size_t p_capacity, size_t p_size) : AContainer()
		{
			m_capacity = p_capacity;
			m_size = p_size;
			m_pDataT = AllocateMemory(m_capacity);
		}

		template <typename Type>
		Array<Type>::Array(size_t p_size, const Type& p_defaultValue) : m_capacity(p_size)
		{
			m_pDataT = AllocateMemory(p_size);
			m_size = p_size;
			CopyValue(p_defaultValue, m_pDataT, p_size);
		}

		template <typename Type>
		Array<Type>::Array(const Array<Type>& p_array)
		{
			m_pDataT = AllocateMemory(p_array.m_capacity);
			m_capacity = p_array.m_capacity;
			CopyValues(p_array.m_pDataT, m_pDataT, p_array.m_size);
			m_size = p_array.m_size;
		}

		template <typename Type>
		Array<Type>::Array(std::initializer_list<Type> parameters)
		{
			m_capacity = parameters.size();
			m_size = parameters.size();
			m_pDataT = AllocateMemory(m_capacity);
			size_t i = 0;
			for (auto it = parameters.begin(); it != parameters.end(); ++i, ++it)
			{
				m_pDataT[i] = *it;
			}
		}

		// The default destructor.
		template <typename Type>
		Array<Type>::~Array()
		{
			FreeMemory(m_pDataT);
		}

		template <typename Type>
		size_t Array<Type>::Capacity() const
		{
			return m_capacity;
		}

		template <typename Type>
		typename Array<Type>::Iterator Array<Type>::Begin() const
		{
			return Iterator(m_pDataT);
		}

		template <typename Type>
		typename Array<Type>::Iterator Array<Type>::BeginReverse() const
		{
			return Iterator(m_pDataT + m_size - 1);
		}

		template <typename Type>
		typename Array<Type>::Iterator Array<Type>::End() const
		{
			return Iterator(m_pDataT + m_size);
		}

		template <typename Type>
		typename Array<Type>::Iterator Array<Type>::EndReverse() const
		{
			return Iterator(m_pDataT - 1);
		}

		/*template <typename Type>
		Type* Array<Type>::DataT() const
		{
			return m_pDataT;
		}*/

		template <typename Type>
		Type* Array<Type>::AllocateMemory(size_t p_cells)
		{
			return new Type[p_cells];
		}

		template <typename Type>
		void Array<Type>::Assign(const Type& p_value, size_t p_index)
		{
			/*if (p_index < 0 || p_index > m_size) 
			{
				throw ArgumentOutOfRangeException();
			}*/

			m_pDataT[p_index] = p_value;
		}

		template <typename Type>
		void Array<Type>::Concat(const Array<Type>& p_array)
		{
			if (m_size + p_array.m_size <= m_capacity)
			{
				for (size_t i = 0; i < p_array.m_size; ++i)
				{
					PushBack(p_array.m_pDataT[i]);
				}
			}
			else
			{
				m_capacity = m_size + p_array.m_size;
				Type* pDataT;
				AllocateMemory(pDataT, m_capacity);
				CopyValues(m_pDataT, pDataT, m_size);
				for (size_t i = m_size; i < m_capacity; ++i)
				{
					pDataT[i] = p_array.m_pDataT[i - m_size];
				}
				FreeMemory(m_pDataT);
				m_pDataT = pDataT;
				m_size = m_capacity;
			}
		}

		template <typename Type>
		bool Array<Type>::Contains(const Type& p_value) const
		{
			for (size_t i = 0; i < m_size; ++i)
			{
				if (m_pDataT[i] == p_value)
				{
					return true;
				}
			}
			return false;
		}

		template <typename Type>
		void Array<Type>::CopyValue(const Type& p_value, Type* const p_pTo, size_t p_size)
		{
			for (size_t i = 0; i < p_size; ++i)
			{
				p_pTo[i] = p_value;
			}
		}

		template <typename Type>
		Type* Array<Type>::CopyOf(const Type* const p_pDataT, size_t p_size)
		{
			if (!p_pDataT)
			{
				// throw ArgumentNullException();
				return nullptr;
			}

			Type* pResult = AllocateMemory(p_size);
			CopyValues(p_pDataT, pResult, p_size);
			return pResult;
		}

		template <typename Type>
		void Array<Type>::CopyValues(const Type* const p_pFrom, Type* const p_pTo, size_t p_size)
		{
			for (size_t i = 0; i < p_size; ++i)
			{
				p_pTo[i] = p_pFrom[i];
			}
		}

		template <typename Type>
		void Array<Type>::FillWith(const Type& p_value)
		{
			CopyValue(p_value, m_pDataT, m_size);
		}

		template <typename Type>
		void Array<Type>::FillWith(const Array<Type>& p_arrayValues)
		{
			const size_t n = m_size < p_arrayValues.m_size ? m_size : p_arrayValues.m_size;
			CopyValues(p_arrayValues.m_pDataT, m_pDataT, n);
		}

		template <typename Type>
		void Array<Type>::FreeMemory(Type* p_pDataT)
		{
			delete[] p_pDataT;
		}

		template <typename Type>
		void Array<Type>::FreeMemorySafe(Type* p_pDataT)
		{
			FreeMemory(p_pDataT);
			p_pDataT = nullptr;
		}

		// Returns the p_index of the first p_value that equals the given one. -1 if the p_value doesn't exist.
		template <typename Type>
		size_t Array<Type>::IndexOf(const Type& p_value) const
		{
			for (size_t i = 0; i < m_size; ++i)
			{
				if (m_pDataT[i] == p_value)
				{
					return i;
				}
			}
			return std::numeric_limits<size_t>::infinity();
		}

		template <typename Type>
		bool Array<Type>::IsEmpty() const
		{
			return m_size == 0;
		}

		// Checks if the array is sorted.
		template <typename Type>
		bool Array<Type>::IsSorted() const
		{
			for (size_t i = 0; i < m_size - 1; ++i)
			{
				if (m_pDataT[i] > m_pDataT[i + 1])
				{
					return false;
				}
			}
			return true;
		}

		template <typename Type>
		Type Array<Type>::Max() const
		{
			/*if (IsEmpty()) 
			{
				throw NullPointerException();
			}*/

			Type max = m_pDataT[0];
			for (size_t i = 1; i < m_size; ++i)
			{
				if (m_pDataT[i] > max)
				{
					max = m_pDataT[i];
				}
			}
			return max;
		}

		template <typename Type>
		Type Array<Type>::Min() const
		{
			/*if (IsEmpty()) 
			{
				throw NullPointerException();
			}*/

			Type min = m_pDataT[0];
			for (size_t i = 1; i < m_size; ++i)
			{
				if (m_pDataT[i] < min)
				{
					min = m_pDataT[i];
				}
			}
			return min;
		}

		template <typename Type>
		void Array<Type>::PopBack()
		{
			if (m_size > 0)
			{
				--m_size;
			}
		}

		template <typename Type>
		void Array<Type>::Purge()
		{
			FreeMemorySafe(m_pDataT);
			m_capacity = 0;
			m_size = 0;
		}

		// Adds a p_value in the back of the array.
		template <typename Type>
		void Array<Type>::PushBack(const Type& p_value)
		{
			if (m_size < m_capacity)
			{
				m_pDataT[m_size] = p_value;
			}
			else
			{
				++m_capacity;
				Type* pDataT = AllocateMemory(m_capacity);
				CopyValues(m_pDataT, pDataT, m_size);
				pDataT[m_size] = p_value;
				FreeMemory(m_pDataT);
				m_pDataT = pDataT;
			}
			++m_size;
		}

		template <typename Type>
		void Array<Type>::ReplaceAll(const Type& p_valueToReplace, const Type& p_replacementValue)
		{
			for (size_t i = 0; i < m_size; ++i)
			{
				if (m_pDataT[i] == p_valueToReplace)
				{
					m_pDataT[i] = p_replacementValue;
				}
			}
		}

		template <typename Type>
		void Array<Type>::ReplaceFirst(const Type& p_valueToReplace, const Type& p_replacementValue)
		{
			for (size_t i = 0; i < m_size; ++i)
			{
				if (m_pDataT[i] == p_valueToReplace)
				{
					m_pDataT[i] = p_replacementValue;
					break;
				}
			}
		}

		template <typename Type>
		void Array<Type>::Reverse()
		{
			for (size_t i = 0; i < m_size / 2; ++i)
			{
				Utility::Swap(m_pDataT[i], m_pDataT[m_size - 1 - i]);
			}
		}

		template <typename Type>
		void Array<Type>::Resize(size_t p_newLength, bool p_keepData)
		{
			if (p_newLength == m_size)
			{
				return;
			}

			if (p_newLength < m_size || (p_newLength > m_size && p_newLength <= m_capacity))
			{
				m_size = p_newLength;

				/*if (!p_keepData)
				{
					CopyValue(0, m_pDataT, m_size);
				}*/
			}
			else
			{
				if (p_keepData)
				{
					Type* pDataT = AllocateMemory(p_newLength);
					CopyValues(m_pDataT, pDataT, m_size);
					m_capacity = p_newLength;
				}
				else
				{
					FreeMemory(m_pDataT);
					m_pDataT = AllocateMemory(p_newLength);
					m_capacity = p_newLength;
					m_size = 0;
				}
			}
		}

		template <typename Type>
		int SortFunction(const void* p_first, const void* p_second)
		{
			Type firstValue = *static_cast<Type*>(p_first);
			Type secondValue = *static_cast<Type*>(p_second);
			if (firstValue > secondValue) return 1;
			if (firstValue < secondValue) return -1;
			return 0;
		}

		// Sorts the values using the Quick Sort.
		template <typename Type>
		void Array<Type>::Sort()
		{
			std::qsort(m_pDataT, m_size, sizeof(Type), SortFunction<Type>);
			//Sorting<Type>::QuickSort(m_pDataT, 0, m_size - 1);
		}

		template <typename Type>
		Array<Type> Array<Type>::SubArray(size_t p_startIndex, size_t p_endIndex) const
		{
			if (p_startIndex > p_endIndex)
			{
				// throw ;
				return nullptr;
			}

			Array<Type> result(p_endIndex - p_startIndex + 1);
			for (size_t i = p_startIndex; i < p_endIndex + 1; ++i)
			{
				result.m_pDataT[i - p_startIndex] = m_pDataT[i];
			}
			return result;
		}

		template <typename Type>
		String Array<Type>::ToString() const
		{
			String result;
			if (!IsEmpty())
			{
				result += "|";
			}
			for (size_t i = 0; i < m_size; ++i)
			{
				result += String::ValueOf(m_pDataT[i]);
				result += "|";
			}
			return result;
		}

		template <typename Type>
		Type Array<Type>::ValueAt(size_t p_index) const
		{
			/*if (IsEmpty()) 
			{
				throw NullPointerException();
			}*/

			/*if (p_index >= m_size) 
			{
				throw ArgumentOutOfRangeException();
			}*/

			return m_pDataT[p_index];
		}

		template <typename Type>
		Type& Array<Type>::operator [](size_t p_index) const
		{
			/*if (IsEmpty())
			{
				throw NullPointerException();
			}*/

			/*if (p_index >= m_size) 
			{
				throw ArgumentOutOfRangeException();
			}*/

			return m_pDataT[p_index];
		}

		template <typename Type>
		Array<Type>& Array<Type>::operator =(const Type& p_value)
		{
			CopyValue(p_value, m_pDataT, m_size);
			return *this;
		}

		template <typename Type>
		Array<Type>& Array<Type>::operator =(const Array<Type>& p_array)
		{
			if (&p_array != this)
			{
				if (m_capacity != p_array.m_capacity)
				{
					FreeMemory(m_pDataT);
					m_pDataT = AllocateMemory(p_array.m_capacity);
					m_capacity = p_array.m_capacity;
				}
				CopyValues(p_array.m_pDataT, m_pDataT, p_array.m_size);
				m_size = p_array.m_size;
			}
			return *this;
		}

		template <typename Type>
		bool Array<Type>::operator<(const Array& p_array) const
		{
			if (m_capacity < p_array.m_capacity)
			{
				return true;
			}
			if (m_capacity == p_array.m_capacity)
			{
				return m_size < p_array.m_size;
			}
			return false;
		}

		template <typename Type>
		bool Array<Type>::operator>(const Array& p_array) const
		{
			if (m_capacity > p_array.m_capacity)
			{
				return true;
			}
			if (m_capacity == p_array.m_capacity)
			{
				return m_size > p_array.m_size;
			}
			return false;
		}

		template <typename Type>
		bool Array<Type>::operator ==(const Array<Type>& p_array) const
		{
			if (m_size != p_array.m_size/* && m_capacity != p_array.m_capacity*/)
			{
				return false;
			}
			for (size_t i = 0; i < m_size; ++i)
			{
				if (m_pDataT[i] != p_array.m_pDataT[i])
				{
					return false;
				}
			}
			return true;
		}

		template <typename Type>
		Array<Type> Array<Type>::operator +(const Type& p_value) const
		{
			Array result(*this);
			for (size_t i = 0; i < m_size; ++i)
			{
				result.m_pDataT[i] += p_value;
			}
			return result;
		}

		template <typename Type>
		Array<Type> Array<Type>::operator +(const Array& p_array) const
		{
			Array result(*this);
			for (size_t i = 0; i < m_size; ++i)
			{
				result.m_pDataT[i] += p_array.m_pDataT[i];
			}
			return result;
		}

		template <typename Type>
		Array<Type> Array<Type>::operator -(const Type& p_value) const
		{
			Array result(m_size);
			for (size_t i = 0; i < m_size; ++i)
			{
				result.m_pDataT[i] = m_pDataT[i] - p_value;
			}
			return result;
		}

		template <typename Type>
		Array<Type> Array<Type>::operator -(const Array& p_array) const
		{
			Array result(m_size);
			for (size_t i = 0; i < m_size; ++i)
			{
				result.m_pDataT[i] = m_pDataT[i] - p_array.m_pDataT[i];
			}
			return result;
		}

		template <typename Type>
		Array<Type> Array<Type>::operator *(const Type& p_value) const
		{
			Array result(m_size);
			for (size_t i = 0; i < m_size; ++i)
			{
				result.m_pDataT[i] = m_pDataT[i] * p_value;
			}
			return result;
		}

		template <typename Type>
		Array<Type> Array<Type>::operator *(const Array& p_array) const
		{
			Array result(m_size);
			for (size_t i = 0; i < m_size; ++i)
			{
				result.m_pDataT[i] = m_pDataT[i] * p_array.m_pDataT[i];
			}
			return result;
		}

		template <typename Type>
		Array<Type> Array<Type>::operator /(const Type& p_value) const
		{
			Array result(m_size);
			for (size_t i = 0; i < m_size; ++i)
			{
				result.m_pDataT[i] = m_pDataT[i] / p_value;
			}
			return result;
		}

		template <typename Type>
		Array<Type> Array<Type>::operator /(const Array& p_array) const
		{
			Array result(m_size);
			for (size_t i = 0; i < m_size; ++i)
			{
				result.m_pDataT[i] = m_pDataT[i] / p_array.m_pDataT[i];
			}
			return result;
		}

		template <typename Type>
		Array<Type>& Array<Type>::operator +=(const Type& p_value)
		{
			for (size_t i = 0; i < m_size; ++i)
			{
				m_pDataT[i] += p_value;
			}
			return *this;
		}

		template <typename Type>
		Array<Type>& Array<Type>::operator +=(const Array& p_array)
		{
			if (m_size == p_array.m_size)
			{
				for (size_t i = 0; i < m_size; ++i)
				{
					m_pDataT[i] += p_array.m_pDataT[i];
				}
			}
			return *this;
		}

		template <typename Type>
		Array<Type>& Array<Type>::operator -=(const Type& p_value)
		{
			for (size_t i = 0; i < m_size; ++i)
			{
				m_pDataT[i] -= p_value;
			}
			return *this;
		}

		template <typename Type>
		Array<Type>& Array<Type>::operator -=(const Array& p_array)
		{
			if (m_size == p_array.m_size)
			{
				for (size_t i = 0; i < m_size; ++i)
				{
					m_pDataT[i] -= p_array.m_pDataT[i];
				}
			}
			return *this;
		}

		template <typename Type>
		Array<Type>& Array<Type>::operator *=(const Type& p_value)
		{
			for (size_t i = 0; i < m_size; ++i)
			{
				m_pDataT[i] *= p_value;
			}
			return *this;
		}

		template <typename Type>
		Array<Type>& Array<Type>::operator *=(const Array& p_array)
		{
			if (m_size == p_array.m_size)
			{
				for (size_t i = 0; i < m_size; ++i)
				{
					m_pDataT[i] *= p_array.m_pDataT[i];
				}
			}
			return *this;
		}

		template <typename Type>
		Array<Type>& Array<Type>::operator /=(const Type& p_value)
		{
			for (size_t i = 0; i < m_size; ++i)
			{
				m_pDataT[i] /= p_value;
			}
			return *this;
		}

		template <typename Type>
		Array<Type>& Array<Type>::operator /=(const Array& p_array)
		{
			if (m_size == p_array.m_size)
			{
				for (size_t i = 0; i < m_size; ++i)
				{
					m_pDataT[i] /= p_array.m_pDataT[i];
				}
			}
			return *this;
		}
	}
}
