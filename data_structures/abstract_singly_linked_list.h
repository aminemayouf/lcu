#pragma once

#include "abstract_container.h"
#include "singly_linked_list_node.h"

#include "../interfaces/comparable.h"
#include "../interfaces/forward_iterator.h"

namespace lcu
{
	inline namespace data_structures
	{
		/**
		 * ASinglyLinkedList Class
		 *
		 * @project data_structures
		 * @author Amine MAYOUF
		 */
		template <typename Type>
		class ASinglyLinkedList : public AContainer<Type>, public IComparable<ASinglyLinkedList<Type>>
		{
		public:
			class Iterator : public IForwardIterator<Type>
			{
				SinglyLinkedListNode<Type>* m_pCurrent;

			public:

				explicit Iterator(SinglyLinkedListNode<Type>* const p_pElement)
				{
					m_pCurrent = p_pElement;
				}

				Iterator& operator++() override
				{
					m_pCurrent = m_pCurrent->Previous();
					return *this;
				}

				Type& operator*() const override
				{
					return m_pCurrent->key;
				}

				Type* operator->() const override
				{
					return &m_pCurrent->key;
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
			SinglyLinkedListNode<Type>* m_pFront;
			SinglyLinkedListNode<Type>* m_pBack;
			using AContainer<Type>::m_size;

		public:
			ASinglyLinkedList();
			ASinglyLinkedList(const ASinglyLinkedList& p_list);
			virtual ~ASinglyLinkedList();

			Iterator Begin() const;
			Iterator End() const;

			// C
			void Concat(const ASinglyLinkedList& p_list);
			bool Contains(const Type& p_key) const override;
			// F
			Type FirstKey() const;
			// I
			bool IsEmpty() const override;
			// L
		protected:
			Type LastKey() const;
		public:
			// M
			Type Max() const;
			Type Min() const;
			// P
		protected:
			virtual Type PopBack();
			virtual Type PopFront();
			virtual void PushBack(const Type& p_key);
			virtual void PushFront(const Type& p_key);
		public:
			void Purge() override;
			// R
			void ReplaceAll(const Type& p_keyToReplace, const Type& p_replacementKey);
			void ReplaceFirst(const Type& p_keyToReplace, const Type& p_replacementKey);
			void Reverse();
			// #
			ASinglyLinkedList& operator =(const ASinglyLinkedList& p_list);
			bool operator <(const ASinglyLinkedList& p_list) const override;
			bool operator >(const ASinglyLinkedList& p_list) const override;
			bool operator ==(const ASinglyLinkedList& p_list) const override;
		};

		template <typename Type>
		ASinglyLinkedList<Type>::ASinglyLinkedList() : AContainer(), m_pFront(nullptr), m_pBack(nullptr)
		{
		}

		template <typename Type>
		ASinglyLinkedList<Type>::ASinglyLinkedList(const ASinglyLinkedList& p_list) : AContainer(), m_pFront(nullptr),
		                                                                              m_pBack(nullptr)
		{
			SinglyLinkedListNode<Type>* pOther = p_list.m_pFront;
			while (pOther)
			{
				PushBack(pOther->key);
				pOther = pOther->Previous();
			}
		}

		template <typename Type>
		ASinglyLinkedList<Type>::~ASinglyLinkedList()
		{
			while (!ASinglyLinkedList<Type>::IsEmpty())
			{
				m_pBack = m_pFront->Previous();
				delete m_pFront;
				m_pFront = m_pBack;
			}
		}

		template <typename Type>
		typename ASinglyLinkedList<Type>::Iterator ASinglyLinkedList<Type>::Begin() const
		{
			return Iterator(m_pFront);
		}

		template <typename Type>
		typename ASinglyLinkedList<Type>::Iterator ASinglyLinkedList<Type>::End() const
		{
			return Iterator(m_pBack->Previous());
		}

		template <typename Type>
		void ASinglyLinkedList<Type>::Concat(const ASinglyLinkedList& p_list)
		{
			SinglyLinkedListNode<Type>* pCurrent = p_list.m_pFront;
			while (pCurrent)
			{
				PushBack(pCurrent->key);
				pCurrent = pCurrent->Previous();
			}
		}

		template <typename Type>
		bool ASinglyLinkedList<Type>::Contains(const Type& p_key) const
		{
			if (!IsEmpty())
			{
				SinglyLinkedListNode<Type>* pCurrent = m_pFront;
				while (pCurrent)
				{
					if (pCurrent->key == p_key)
					{
						return true;
					}
					pCurrent = pCurrent->Previous();
				}
			}
			return false;
		}

		template <typename Type>
		Type ASinglyLinkedList<Type>::FirstKey() const
		{
			if (IsEmpty())
			{
				// throw NullPointerException();
			}
			return m_pFront->key;
		}

		template <typename Type>
		bool ASinglyLinkedList<Type>::IsEmpty() const
		{
			return !m_pFront ? true : false;
		}

		template <typename Type>
		Type ASinglyLinkedList<Type>::LastKey() const
		{
			if (IsEmpty())
			{
				// throw NullPointerException();
			}
			return m_pBack->key;
		}

		template <typename Type>
		Type ASinglyLinkedList<Type>::Max() const
		{
			/*if (IsEmpty())
			{
				throw NullPointerException();
			}*/

			Type max = m_pFront->key;
			SinglyLinkedListNode<Type>* pCurrent = m_pFront->Previous();
			while (pCurrent)
			{
				if (pCurrent->key > max)
				{
					max = pCurrent->key;
				}
				pCurrent = pCurrent->Previous();
			}
			return max;
		}

		template <typename Type>
		Type ASinglyLinkedList<Type>::Min() const
		{
			/*if (IsEmpty())
			{
				throw NullPointerException();
			}*/

			Type min = m_pFront->key;
			SinglyLinkedListNode<Type>* pCurrent = m_pFront->Previous();
			while (pCurrent)
			{
				if (pCurrent->key < min)
				{
					min = pCurrent->key;
				}
				pCurrent = pCurrent->Previous();
			}
			return min;
		}

		template <typename Type>
		Type ASinglyLinkedList<Type>::PopBack()
		{
			if (IsEmpty())
			{
				// throw NullPointerException();
			}

			SinglyLinkedListNode<Type>* pTemp = m_pFront;
			// If there is only one node left in the list
			if (m_pFront == m_pBack)
			{
				m_pFront = nullptr;
				pTemp = nullptr;
			}
			else
			{
				while (pTemp->Previous() != m_pBack)
				{
					pTemp = pTemp->Previous();
				}
				pTemp->SetPrevious(nullptr);
			}

			Type backKey = m_pBack->key;
			delete m_pBack;
			m_pBack = pTemp;
			--m_size;

			return backKey;
		}

		template <typename Type>
		Type ASinglyLinkedList<Type>::PopFront()
		{
			if (IsEmpty())
			{
				// throw NullPointerException();
			}

			SinglyLinkedListNode<Type>* pCurrent = m_pFront->Previous();
			// If there is only one node left in the list
			if (m_pFront == m_pBack)
			{
				m_pBack = nullptr;
			}

			Type frontKey = m_pFront->key;
			delete m_pFront;
			m_pFront = pCurrent;
			--m_size;

			return frontKey;
		}

		template <typename Type>
		void ASinglyLinkedList<Type>::PushBack(const Type& p_key)
		{
			SinglyLinkedListNode<Type>* pNode = new SinglyLinkedListNode<Type>(p_key);

			if (IsEmpty())
			{
				m_pFront = pNode;
			}
			else
			{
				m_pBack->SetPrevious(pNode);
			}

			m_pBack = pNode;
			++m_size;
		}

		template <typename Type>
		void ASinglyLinkedList<Type>::PushFront(const Type& p_key)
		{
			SinglyLinkedListNode<Type>* pNode = new SinglyLinkedListNode<Type>(p_key, m_pFront);

			if (IsEmpty())
			{
				m_pBack = pNode;
			}

			m_pFront = pNode;
			++m_size;
		}

		template <typename Type>
		void ASinglyLinkedList<Type>::Purge()
		{
			while (!IsEmpty())
			{
				m_pBack = m_pFront->Previous();
				delete m_pFront;
				m_pFront = m_pBack;
			}
			m_pFront = nullptr;
			m_pBack = nullptr;
			m_size = 0;
		}

		template <typename Type>
		void ASinglyLinkedList<Type>::ReplaceAll(const Type& p_keyToReplace, const Type& p_replacementKey)
		{
			SinglyLinkedListNode<Type>* pCurrent = m_pFront;
			while (pCurrent)
			{
				if (pCurrent->key == p_keyToReplace)
				{
					pCurrent->setKey(p_replacementKey);
				}
				pCurrent = pCurrent->Previous();
			}
		}

		template <typename Type>
		void ASinglyLinkedList<Type>::ReplaceFirst(const Type& p_keyToReplace, const Type& p_replacementKey)
		{
			SinglyLinkedListNode<Type>* pCurrent = m_pFront;
			while (pCurrent && pCurrent->key != p_keyToReplace)
			{
				pCurrent = pCurrent->Previous();
			}
			if (pCurrent)
			{
				pCurrent->setKey(p_replacementKey);
			}
		}

		template <typename Type>
		void ASinglyLinkedList<Type>::Reverse()
		{
			SinglyLinkedListNode<Type>* pCurrent = m_pFront;
			SinglyLinkedListNode<Type>* pNext = nullptr;
			SinglyLinkedListNode<Type>* Previous;
			while (pCurrent)
			{
				Previous = pCurrent->Previous();
				pCurrent->SetPrevious(pNext);
				pNext = pCurrent;
				pCurrent = Previous;
			}
			Utility::Swap(m_pFront, m_pBack);
		}

		template <typename Type>
		ASinglyLinkedList<Type>& ASinglyLinkedList<Type>::operator =(const ASinglyLinkedList<Type>& p_list)
		{
			if (&p_list != this)
			{
				if (p_list.IsEmpty())
				{
					Purge();
				}
				else
				{
					SinglyLinkedListNode<Type>* pCurrent = m_pFront;
					SinglyLinkedListNode<Type>* pOther = p_list.m_pFront;

					if (m_size == p_list.m_size)
					{
						while (pCurrent)
						{
							pCurrent->key = pOther->key;
							pCurrent = pCurrent->Previous();
							pOther = pOther->Previous();
						}
					}
					else if (m_size < p_list.m_size)
					{
						while (pCurrent)
						{
							pCurrent->key = pOther->key;
							pCurrent = pCurrent->Previous();
							pOther = pOther->Previous();
						}
						while (pOther)
						{
							PushBack(pOther->key);
							pOther = pOther->Previous();
						}
					}
					else
					{
						while (pOther)
						{
							pCurrent->key = pOther->key;
							m_pBack = pCurrent;
							pCurrent = pCurrent->Previous();
							pOther = pOther->Previous();
						}

						m_pBack->SetPrevious(nullptr);

						while (pCurrent)
						{
							pOther = pCurrent->Previous();
							delete pCurrent;
							pCurrent = pOther;
						}
						m_size = p_list.m_size;
					}
				}
			}
			return *this;
		}

		template <typename Type>
		bool ASinglyLinkedList<Type>::operator<(const ASinglyLinkedList& p_list) const
		{
			return m_size < p_list.m_size;
		}

		template <typename Type>
		bool ASinglyLinkedList<Type>::operator>(const ASinglyLinkedList& p_list) const
		{
			return m_size > p_list.m_size;
		}

		template <typename Type>
		bool ASinglyLinkedList<Type>::operator ==(const ASinglyLinkedList& p_list) const
		{
			if (m_size != p_list.m_size)
			{
				return false;
			}
			SinglyLinkedListNode<Type>* pCurrent = m_pFront;
			SinglyLinkedListNode<Type>* pOther = p_list.m_pFront;
			while (pCurrent && pOther)
			{
				if (pCurrent->key != pOther->key)
				{
					return false;
				}
				pCurrent = pCurrent->Previous();
				pOther = pOther->Previous();
			}
			return true;
		}
	}
}
