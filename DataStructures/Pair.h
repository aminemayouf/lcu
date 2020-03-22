#pragma once


#include "Object.h"

namespace LCU
{
	inline namespace DataStructures
	{
		/**
		 * Pair Class
		 *
		 * @project DataStructures
		 * @author Amine MAYOUF
		 */
		template <typename FirstType, typename SecondType>
		class Pair : public Object, public IComparable<Pair<FirstType, SecondType>>
		{
		public:
			FirstType first;
			SecondType second;

			explicit Pair(const FirstType& p_firstValue = 0, const SecondType& p_secondValue = 0);

			// T
			String ToString() const override;
			// #
			Pair& operator =(const Pair& p_pair);
			bool operator <(const Pair& p_pair) const override;
			bool operator >(const Pair& p_pair) const override;
			bool operator ==(const Pair& p_pair) const override;
		};

		template <typename FirstType, typename SecondType>
		Pair<FirstType, SecondType>::Pair(const FirstType& p_firstValue,
		                                  const SecondType& p_secondValue)
			: first(p_firstValue),
			  second(p_secondValue)
		{
		}

		template <typename FirstType, typename SecondType>
		String Pair<FirstType, SecondType>::ToString() const
		{
			String result;
			result += "[";
			result += String::ValueOf(first);
			result += "|";
			result += String::ValueOf(second);
			result += "]";
			return result;
		}

		template <typename FirstType, typename SecondType>
		Pair<FirstType, SecondType>& Pair<FirstType, SecondType>::operator =(const Pair<FirstType, SecondType>& p_pair)
		{
			first = p_pair.first;
			second = p_pair.second;
			return *this;
		}

		template <typename FirstType, typename SecondType>
		bool Pair<FirstType, SecondType>::operator<(const Pair& p_pair) const
		{
			return first < p_pair.first/* && second < p_pair.second*/;
		}

		template <typename FirstType, typename SecondType>
		bool Pair<FirstType, SecondType>::operator>(const Pair& p_pair) const
		{
			return first > p_pair.first/* && second > p_pair.second*/;
		}

		template <typename FirstType, typename SecondType>
		bool Pair<FirstType, SecondType>::operator==(const Pair& p_pair) const
		{
			return first == p_pair.first/* && second == p_pair.second*/;
		}
	}
}
