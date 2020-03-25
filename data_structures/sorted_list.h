#pragma once

#include "abstract_doubly_linked_list.h"

namespace lcu
{
	inline namespace data_structures
	{
		/**
		 * Sorted List Class
		 *
		 * @project data_structures
		 * @author Amine MAYOUF
		 */
		template <typename Type>
		class SortedList : public ADoublyLinkedList<Type>
		{
			using ADoublyLinkedList<Type>::m_pFront;
			using ADoublyLinkedList<Type>::m_pBack;
			using ADoublyLinkedList<Type>::m_size;

		public:
			// B
			using ADoublyLinkedList<Type>::Back;
			// F
			using ADoublyLinkedList<Type>::Front;
			// I
			void Insert(const Type& p_key);
			using ADoublyLinkedList<Type>::IsEmpty;
			// M
			Type Max() const override;
			Type Min() const override;
			// P
		private:
			using ADoublyLinkedList<Type>::PushBack;
		};

		template <typename Type>
		void SortedList<Type>::Insert(const Type& p_key)
		{
			DoublyLinkedListNode<Type>* pNode = new DoublyLinkedListNode<Type>(p_key);
			if (IsEmpty())
			{
				m_pFront = pNode;
				m_pBack = pNode;
			}
			else
			{
				if (p_key <= m_pFront->key)
				{
					pNode->SetNext(m_pFront);
					m_pFront->SetNext(pNode);
					m_pFront = pNode;
				}
				else if (p_key >= m_pBack->key)
				{
					pNode->SetNext(m_pBack);
					m_pBack->SetNext(pNode);
					m_pBack = pNode;
				}
				else
				{
					DoublyLinkedListNode<Type>* pCurrent = m_pFront->Previous();
					while (pCurrent)
					{
						if (p_key < pCurrent->key)
						{
							pNode->SetNext(pCurrent);
							pNode->SetNext(pCurrent->Next());

							pCurrent->Next()->SetNext(pNode);
							pCurrent->SetNext(pNode);
						}
						pCurrent = pCurrent->Previous();
					}
				}
			}
			++m_size;
		}

		template <typename Type>
		Type SortedList<Type>::Max() const
		{
			return Back() > Front() ? Back() : Front();
		}

		template <typename Type>
		Type SortedList<Type>::Min() const
		{
			return Front() > Back() ? Back() : Front();
		}
	}
}
