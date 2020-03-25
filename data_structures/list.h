#pragma once

#include "abstract_doubly_linked_list.h"

namespace lcu
{
	inline namespace data_structures
	{
		/**
		 * List Class
		 *
		 * @project data_structures
		 * @author Amine MAYOUF
		 */
		template <typename Type>
		class List : public ADoublyLinkedList<Type>
		{
			using ADoublyLinkedList<Type>::m_pFront;
			using ADoublyLinkedList<Type>::m_pBack;
			using ADoublyLinkedList<Type>::m_size;

		public:
			// C
			void Concat(const List& p_list);
			// I
			void InsertAt(const Type& p_key, size_t p_index);
			using ADoublyLinkedList<Type>::IsEmpty;
			// P
			void PushFront(const Type& p_key);
			// R
			void ReplaceAll(const Type& p_keyToReplace, const Type& p_replacementKey);
			void ReplaceFirst(const Type& p_keyToReplace, const Type& p_replacementKey);
		};

		template <typename Type>
		void List<Type>::Concat(const List& p_list)
		{
			DoublyLinkedListNode<Type>* pOther = p_list.m_pFront;
			while (pOther)
			{
				PushBack(pOther->key);
				pOther = pOther->Next();
			}
		}

		template <typename Type>
		void List<Type>::InsertAt(const Type& p_key, size_t p_index)
		{
			/*if (p_index < 1 || p_index > m_size + 1)
			{
				throw ArgumentOutOfRangeException();
			}*/

			if (p_index == 1)
			{
				PushFront(p_key);
			}
			else if (p_index == m_size + 1)
			{
				PushBack(p_key);
			}
			else
			{
				size_t i;
				DoublyLinkedListNode<Type>* pCurrent;
				DoublyLinkedListNode<Type>* pNode;
				if (p_index <= m_size / 2)
				{
					i = 2;
					pCurrent = m_pFront->Next();
					while (pCurrent)
					{
						if (i == p_index)
						{
							pNode = new DoublyLinkedListNode<Type>(p_key, pCurrent->Next(), pCurrent);
							pCurrent->Next()->SetNext(pNode);
							pCurrent->SetNext(pNode);
							break;
						}
						++i;
						pCurrent = pCurrent->Next();
					}
				}
				else
				{
					i = m_size;
					pCurrent = m_pBack;
					while (pCurrent)
					{
						if (i == p_index)
						{
							pNode = new DoublyLinkedListNode<Type>(p_key, pCurrent->Next(), pCurrent);
							pCurrent->Next()->SetNext(pNode);
							pCurrent->SetNext(pNode);
							break;
						}
						--i;
						pCurrent = pCurrent->Next();
					}
					++m_size;
				}
			}
		}

		template <typename Type>
		void List<Type>::PushFront(const Type& p_key)
		{
			DoublyLinkedListNode<Type>* pNode = new DoublyLinkedListNode<Type>(p_key, 0, m_pFront);
			if (IsEmpty())
			{
				m_pBack = pNode;
			}
			else
			{
				m_pFront->SetNext(pNode);
			}
			m_pFront = pNode;
			++m_size;
		}

		template <typename Type>
		void List<Type>::ReplaceAll(const Type& p_keyToReplace, const Type& p_replacementKey)
		{
			DoublyLinkedListNode<Type>* pCurrent = m_pFront;
			while (pCurrent)
			{
				if (pCurrent->key == p_keyToReplace)
				{
					pCurrent->setKey(p_replacementKey);
				}
				pCurrent = pCurrent->Next();
			}
		}

		template <typename Type>
		void List<Type>::ReplaceFirst(const Type& p_keyToReplace, const Type& p_replacementKey)
		{
			DoublyLinkedListNode<Type>* pCurrent = m_pFront;
			while (pCurrent && pCurrent->key != p_keyToReplace)
			{
				pCurrent = pCurrent->Next();
			}
			if (pCurrent)
			{
				pCurrent->setKey(p_replacementKey);
			}
		}
	}
}
