#pragma once

#include "abstract_singly_linked_list.h"

namespace lcu
{
	inline namespace data_structures
	{
		/**
		 * Singly-Linked List Class
		 *
		 * @project data_structures
		 * @author Amine MAYOUF
		 */
		template <typename Type>
		class ForwardList : public ASinglyLinkedList<Type>
		{
			using ASinglyLinkedList<Type>::m_pFront;
			using ASinglyLinkedList<Type>::m_pBack;
			using ASinglyLinkedList<Type>::m_size;

		public:
			// B
			Type Back() const;
			// F
		private:
			using ASinglyLinkedList<Type>::FirstKey;
		public:
			Type Front() const;
			// I
			size_t IndexOf(const Type& p_key) const;
			void InsertAt(const Type& p_key, size_t p_index);
			using ASinglyLinkedList<Type>::IsEmpty;
			// L
		private:
			using ASinglyLinkedList<Type>::LastKey;
		public:
			// P
			using ASinglyLinkedList<Type>::PopBack;
			using ASinglyLinkedList<Type>::PopFront;
			using ASinglyLinkedList<Type>::PushBack;
			using ASinglyLinkedList<Type>::PushFront;
			// R
			void RemoveAll(const Type& p_key);
			void RemoveFirst(const Type& p_key);
			void RemoveAt(size_t p_index);
			// S
			ForwardList& SubList(size_t p_startIndex, size_t p_endIndex) const;
			// T
			String ToString() const override;
			// V
			Type KeyAt(size_t p_index) const;
		};

		template <typename Type>
		Type ForwardList<Type>::Back() const
		{
			return LastKey();
		}

		template <typename Type>
		Type ForwardList<Type>::Front() const
		{
			return FirstKey();
		}

		template <typename Type>
		size_t ForwardList<Type>::IndexOf(const Type& p_key) const
		{
			size_t i = 1;
			SinglyLinkedListNode<Type>* pCurrent = m_pFront;
			while (pCurrent)
			{
				if (pCurrent->key == p_key)
				{
					return i;
				}
				++i;
				pCurrent = pCurrent->Previous();
			}
			return 0;
		}

		template <typename Type>
		void ForwardList<Type>::InsertAt(const Type& p_key, size_t p_index)
		{
			if (p_index < 1 || p_index > (m_size + 1))
			{
				// throw argumentoutofrangeexception();
			}
			if (p_index == 1)
			{
				PushFront(p_key);
			}
			else if (p_index == (m_size + 1))
			{
				PushBack(p_key);
			}
			else
			{
				size_t i = 2;
				SinglyLinkedListNode<Type>* pCurrent = m_pFront->Previous();
				SinglyLinkedListNode<Type>* pNext = m_pFront;
				while (pCurrent)
				{
					if (i == p_index)
					{
						SinglyLinkedListNode<Type>* pNode = new SinglyLinkedListNode<Type>(p_key, pCurrent);
						pNext->SetNext(pNode);
						break;
					}
					++i;
					pNext = pCurrent;
					pCurrent = pCurrent->Previous();
				}
				++m_size;
			}
		}

		template <typename Type>
		void ForwardList<Type>::RemoveAll(const Type& p_key)
		{
			if (IsEmpty())
			{
				return;
			}

			SinglyLinkedListNode<Type>* pCurrent = m_pFront->Previous();
			if (m_pFront->key == p_key)
			{
				delete m_pFront;
				m_pFront = pCurrent;
				--m_size;
			}
			else
			{
				SinglyLinkedListNode<Type>* pNext = m_pFront;
				while (pCurrent)
				{
					if (pCurrent->key == p_key)
					{
						pNext->SetNext(pCurrent->Previous());
						delete pCurrent;
						--m_size;
					}
					pNext = pCurrent;
					pCurrent = pCurrent->Previous();
				}
			}
		}

		template <typename Type>
		void ForwardList<Type>::RemoveFirst(const Type& p_key)
		{
			if (IsEmpty())
			{
				return;
			}

			SinglyLinkedListNode<Type>* pCurrent = m_pFront->Previous();
			if (m_pFront->key == p_key)
			{
				delete m_pFront;
				m_pFront = pCurrent;
				--m_size;
			}
			else
			{
				SinglyLinkedListNode<Type>* pNext = m_pFront;
				while (pCurrent)
				{
					if (pCurrent->key == p_key)
					{
						pNext->SetNext(pCurrent->Previous());
						delete pCurrent;
						--m_size;
						return;
					}
					pNext = pCurrent;
					pCurrent = pCurrent->Previous();
				}
			}
		}

		template <typename Type>
		void ForwardList<Type>::RemoveAt(size_t p_index)
		{
			if (p_index < 1 || p_index > m_size)
			{
				// throw ArgumentOutOfRangeException();
			}
			if (p_index == 1)
			{
				PopFront();
			}
			else if (p_index == m_size)
			{
				PopBack();
			}
			else
			{
				size_t i = 2;
				SinglyLinkedListNode<Type>* pCurrent = m_pFront->Previous();
				SinglyLinkedListNode<Type>* pNext = m_pFront;
				while (pCurrent)
				{
					if (i == p_index)
					{
						pNext->SetNext(pCurrent->Previous());
						delete pCurrent;
						--m_size;
						return;
					}
					++i;
					pNext = pCurrent;
					pCurrent = pCurrent->Previous();
				}
			}
		}

		template <typename Type>
		ForwardList<Type>& ForwardList<Type>::SubList(size_t p_startIndex, size_t p_endIndex) const
		{
			if (p_startIndex > p_endIndex)
			{
				return *new ForwardList<Type>();
			}

			size_t i = 1;
			SinglyLinkedListNode<Type>* pCurrent = m_pFront;
			ForwardList<Type>* pResult = new ForwardList<Type>();
			while (pCurrent)
			{
				if (i == p_startIndex)
				{
					while (i <= p_endIndex)
					{
						pResult->PushBack(pCurrent->key);
						++i;
						pCurrent = pCurrent->Previous();
					}
					break;
				}
				++i;
				pCurrent = pCurrent->Previous();
			}

			return *pResult;
		}

		template <typename Type>
		String ForwardList<Type>::ToString() const
		{
			String result;
			SinglyLinkedListNode<Type>* pCurrent = m_pFront;
			while (pCurrent)
			{
				result += String::ValueOf(*pCurrent);
				result += "->";
				pCurrent = pCurrent->Previous();
			}
			result += "|nullptr|";
			return result;
		}

		template <typename Type>
		Type ForwardList<Type>::KeyAt(size_t p_index) const
		{
			if (p_index < 1 || p_index > m_size)
			{
				// throw ArgumentOutOfRangeException();
			}
			if (p_index == m_size)
			{
				return m_pBack->key;
			}

			size_t i = 1;
			SinglyLinkedListNode<Type>* pCurrent = m_pFront;
			while (pCurrent)
			{
				if (i == p_index)
				{
					return pCurrent->key;
				}
				++i;
				pCurrent = pCurrent->Previous();
			}

			return 0;
		}
	}
}
