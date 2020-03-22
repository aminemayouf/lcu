#pragma once

#include "ASinglyLinkedList.h"

namespace LCU
{
	inline namespace DataStructures
	{
		/**
		 * Stack Class
		 *
		 * @project DataStructures
		 * @author Amine MAYOUF
		 */
		template <typename Type>
		class Stack : public ASinglyLinkedList<Type>
		{
			using ASinglyLinkedList<Type>::m_pFront;

			// F
			using ASinglyLinkedList<Type>::FirstKey;
			// P
			using ASinglyLinkedList<Type>::PopFront;
		public:
			Type Pop();
		private:
			using ASinglyLinkedList<Type>::PushFront;
		public:
			void Push(const Type& p_key);
			// T
			Type Top() const;
			String ToString() const override;
		};

		template <typename Type>
		Type Stack<Type>::Pop()
		{
			return PopFront();
		}

		template <typename Type>
		void Stack<Type>::Push(const Type& p_key)
		{
			PushFront(p_key);
		}

		template <typename Type>
		Type Stack<Type>::Top() const
		{
			return FirstKey();
		}

		template <typename Type>
		String Stack<Type>::ToString() const
		{
			String result;
			SinglyLinkedListNode<Type>* pCurrent = m_pFront;
			while (pCurrent)
			{
				result += "---------\n";
				result += String::ValueOf(*pCurrent);
				result += "\n";
				pCurrent = pCurrent->Previous();
			}
			result += "---------\n";
			result += "|nullptr|\n";
			result += "---------";
			return result;
		}
	}
}
