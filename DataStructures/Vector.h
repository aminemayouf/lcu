#pragma once

#include "Array.h"

namespace LCU
{
	inline namespace DataStructures
	{
		/**
		 * Vector Class
		 *
		 * @project DataStructures
		 * @author Amine MAYOUF
		 */
		template <typename Type>
		class Vector : public Array<Type>
		{
			using Array<Type>::m_capacity;
			using Array<Type>::m_size;
			using Array<Type>::m_pDataT;

		public:
			Vector();
			explicit Vector(size_t p_capacity);
			Vector(size_t p_size, const Type& p_defaultValue);
			Vector(const Array<Type>& p_array);
			Vector(std::initializer_list<Type> p_parameters);
			// A
			using Array<Type>::AllocateMemory;
			// C
			using Array<Type>::CopyValue;
			using Array<Type>::CopyValues;
			// F
			using Array<Type>::FillWith;
			// P
			/**
			 * Adds a p_value to the back of the array.
			 *
			 * Complexity: O(1) if the capacity is greater than the actual length.
			 *	     else: O(n) or more precisely O(3n+log(n)).
			 */
			void PushBack(const Type& p_value) override;
		};
	}

	template <typename Type>
	Vector<Type>::Vector() : Array()
	{
	}

	template <typename Type>
	Vector<Type>::Vector(size_t p_capacity)
	{
		m_capacity = Utility::AdaptedCapacity(p_capacity);
		m_size = 0;
		m_pDataT = AllocateMemory(m_capacity);
	}

	template <typename Type>
	Vector<Type>::Vector(size_t p_size, const Type& p_defaultValue)
	{
		m_capacity = Utility::AdaptedCapacity(p_size);
		m_size = p_size;
		m_pDataT = AllocateMemory(m_capacity);
		CopyValue(p_defaultValue, m_pDataT, p_size);
	}

	template <typename Type>
	Vector<Type>::Vector(const Array<Type>& p_array)
	{
		m_capacity = Utility::AdaptedCapacity(p_array.Capacity());
		m_size = p_array.Size();
		m_pDataT = AllocateMemory(m_capacity);
		FillWith(p_array);
	}

	template <typename Type>
	Vector<Type>::Vector(std::initializer_list<Type> p_parameters)
	{
		m_size = p_parameters.size();
		m_capacity = Utility::AdaptedCapacity(m_size);
		m_pDataT = AllocateMemory(m_capacity);
		size_t i = 0;
		for (auto it = p_parameters.begin(); it != p_parameters.end(); ++i, ++it)
		{
			m_pDataT[i] = *it;
		}
	}

	template <typename Type>
	void Vector<Type>::PushBack(const Type& p_value)
	{
		if (m_size < m_capacity)
		{
			m_pDataT[m_size] = p_value;
		}
		else
		{
			m_capacity = Utility::AdaptedCapacity(m_size + 1);
			Type* pDataT = AllocateMemory(m_capacity);
			CopyValues(m_pDataT, pDataT, m_size);
			pDataT[m_size] = p_value;
			FreeMemory(m_pDataT);
			m_pDataT = pDataT;
		}
		++m_size;
	}
}
