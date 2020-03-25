#pragma once

#include "ASinglyLinkedList.h"

namespace lcu
{
	inline namespace data_structures
	{
		/**
		 * Queue Class
		 *
		 * @project DataStructures
		 * @author Amine MAYOUF
		 */
		template <typename Type>
		class Queue : public ASinglyLinkedList<Type>
		{
			using ASinglyLinkedList<Type>::m_pFront;
			using ASinglyLinkedList<Type>::m_pBack;

			// F
			using ASinglyLinkedList<Type>::FirstKey;
		public:
			Type Front() const;
			// L
		private:
			using ASinglyLinkedList<Type>::LastKey;
			// P
			using ASinglyLinkedList<Type>::PopFront;
		public:
			Type Pop();
		private:
			using ASinglyLinkedList<Type>::PushBack;
		public:
			void Push(const Type& p_key);
			// T
			Type Tail() const;
			String ToString() const override;
		};

		template <typename Type>
		Type Queue<Type>::Front() const
		{
			return LastKey();
		}

		template <typename Type>
		Type Queue<Type>::Pop()
		{
			return PopFront();
		}

		template <typename Type>
		void Queue<Type>::Push(const Type& p_key)
		{
			PushBack(p_key);
		}

		template <typename Type>
		Type Queue<Type>::Tail() const
		{
			return FirstKey();
		}

		template <typename Type>
		String Queue<Type>::ToString() const
		{
			String result("[Exit]");
			SinglyLinkedListNode<Type>* pCurrent = m_pFront;
			while (pCurrent)
			{
				result += "<-";
				result += String::ValueOf(*pCurrent);
				pCurrent = pCurrent->Previous();
			}
			return result;
		}
	}
}
