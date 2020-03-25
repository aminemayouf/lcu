#pragma once

#include "AContainer.h"
#include "DoublyLinkedListNode.h"

#include "../Interfaces/IIterator.h"

namespace lcu
{
	inline namespace data_structures
	{
		/**
		 * ADoublyLinkedList Class
		 *
		 * @project DataStructures
		 * @author Amine MAYOUF
		 */
		template <typename Type>
		class ADoublyLinkedList : public AContainer<Type>, public IComparable<ADoublyLinkedList<Type>>
		{
		public:
			class Iterator : public IIterator<Type>
			{
				DoublyLinkedListNode<Type>* m_pCurrent;

			public:
				explicit Iterator(DoublyLinkedListNode<Type>* const p_pElement)
				{
					m_pCurrent = p_pElement;
				}

				Iterator& operator++() override
				{
					m_pCurrent = m_pCurrent->Previous();

					return *this;
				}

				Iterator& operator--() override
				{
					m_pCurrent = m_pCurrent->Next();

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
			DoublyLinkedListNode<Type>* m_pFront;
			DoublyLinkedListNode<Type>* m_pBack;

			using AContainer<Type>::m_size;

		public:
			ADoublyLinkedList();
			ADoublyLinkedList(const ADoublyLinkedList& p_list);

			virtual ~ADoublyLinkedList();

			Iterator Begin() const;
			Iterator BeginReverse() const;

			Iterator End() const;
			Iterator EndReverse() const;

			// B
			Type Back() const;
			// C
			bool Contains(const Type& p_key) const override;
			// F
			Type Front() const;
			// I
			size_t IndexOf(const Type& p_key) const;
			bool IsEmpty() const override;
			// K
			Type KeyAt(size_t p_index) const;
			// M
			virtual Type Max() const;
			virtual Type Min() const;
			// P
			void PopBack();
			void PopFront();
			void Purge() override;
			void PushBack(const Type& p_key);
			// R
			void RemoveAt(size_t p_index);
			void Reverse();
			// T
			String ToString() const override;
			// #
			ADoublyLinkedList& operator =(const ADoublyLinkedList& p_list);
			bool operator <(const ADoublyLinkedList& p_list) const override;
			bool operator >(const ADoublyLinkedList& p_list) const override;
			bool operator ==(const ADoublyLinkedList& p_list) const override;
		};

		template <typename Type>
		ADoublyLinkedList<Type>::ADoublyLinkedList() : AContainer(), m_pFront(nullptr), m_pBack(nullptr)
		{
		}

		template <typename Type>
		ADoublyLinkedList<Type>::ADoublyLinkedList(const ADoublyLinkedList& p_list) : AContainer(), m_pFront(nullptr),
		                                                                              m_pBack(nullptr)
		{
			DoublyLinkedListNode<Type>* pOther = p_list.m_pFront;

			while (pOther)
			{
				PushBack(pOther->key);
				pOther = pOther->Previous();
			}
		}

		template <typename Type>
		ADoublyLinkedList<Type>::~ADoublyLinkedList()
		{
			while (!ADoublyLinkedList<Type>::IsEmpty())
			{
				m_pBack = m_pFront->Previous();
				delete m_pFront;
				m_pFront = m_pBack;
			}
		}

		template <typename Type>
		typename ADoublyLinkedList<Type>::Iterator ADoublyLinkedList<Type>::Begin() const
		{
			return Iterator(m_pFront);
		}

		template <typename Type>
		typename ADoublyLinkedList<Type>::Iterator ADoublyLinkedList<Type>::BeginReverse() const
		{
			return Iterator(m_pBack);
		}

		template <typename Type>
		typename ADoublyLinkedList<Type>::Iterator ADoublyLinkedList<Type>::End() const
		{
			return Iterator(m_pBack->Previous());
		}

		template <typename Type>
		typename ADoublyLinkedList<Type>::Iterator ADoublyLinkedList<Type>::EndReverse() const
		{
			return Iterator(m_pFront->Next());
		}

		/*template <typename Type>
		DoublyLinkedListNode<Type>* ADoublyLinkedList<Type>::Front() const
		{
			return m_pFront;
		}

		template <typename Type>
		DoublyLinkedListNode<Type>* ADoublyLinkedList<Type>::Back() const
		{
			return m_pBack;
		}*/

		template <typename Type>
		Type ADoublyLinkedList<Type>::Back() const
		{
			if (IsEmpty())
			{
				// throw NullPointerException();
			}
			return m_pBack->key;
		}

		template <typename Type>
		bool ADoublyLinkedList<Type>::Contains(const Type& p_key) const
		{
			if (!IsEmpty())
			{
				DoublyLinkedListNode<Type>* pCurrent = m_pFront;

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
		Type ADoublyLinkedList<Type>::Front() const
		{
			if (IsEmpty())
			{
				// throw NullPointerException();
			}
			return m_pFront->key;
		}

		template <typename Type>
		size_t ADoublyLinkedList<Type>::IndexOf(const Type& p_key) const
		{
			if (Back() == p_key)
			{
				return m_size;
			}

			size_t i = 1;
			DoublyLinkedListNode<Type>* pCurrent = m_pFront;

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
		bool ADoublyLinkedList<Type>::IsEmpty() const
		{
			return !m_pFront ? true : false;
		}

		template <typename Type>
		Type ADoublyLinkedList<Type>::KeyAt(size_t p_index) const
		{
			/*if (p_index < 1 || p_index > m_size)
			{
				throw ArgumentOutOfRangeException();
			}*/

			size_t i;
			DoublyLinkedListNode<Type>* pCurrent;

			if (p_index <= m_size / 2)
			{
				i = 1;
				pCurrent = m_pFront;
				while (pCurrent)
				{
					if (i == p_index)
					{
						return pCurrent->key;
					}
					++i;
					pCurrent = pCurrent->Previous();
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
						return pCurrent->key;
					}
					--i;
					pCurrent = pCurrent->Next();
				}
			}
			return 0;
		}

		template <typename Type>
		Type ADoublyLinkedList<Type>::Max() const
		{
			if (IsEmpty())
			{
				// throw NullPointerException();
			}

			Type max = m_pFront->key;
			DoublyLinkedListNode<Type>* pCurrent = m_pFront->Previous();

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
		Type ADoublyLinkedList<Type>::Min() const
		{
			if (IsEmpty())
			{
				// throw NullPointerException();
			}

			Type min = m_pFront->key;
			DoublyLinkedListNode<Type>* pCurrent = m_pFront->Previous();

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
		void ADoublyLinkedList<Type>::PopBack()
		{
			if (IsEmpty())
			{
				return;
			}

			DoublyLinkedListNode<Type>* pTemp = nullptr;

			if (m_pFront == m_pBack)
			{
				m_pFront = nullptr;
			}
			else
			{
				pTemp = m_pBack->Next();
				pTemp->SetNext(nullptr);
			}

			delete m_pBack;

			m_pBack = pTemp;
			--m_size;
		}

		template <typename Type>
		void ADoublyLinkedList<Type>::PopFront()
		{
			if (IsEmpty())
			{
				return;
			}

			DoublyLinkedListNode<Type>* pTemp = nullptr;

			if (m_pFront == m_pBack)
			{
				m_pBack = nullptr;
			}
			else
			{
				pTemp = m_pFront->Previous();
				pTemp->SetNext(nullptr);
			}

			delete m_pFront;
			m_pFront = pTemp;
			--m_size;
		}

		template <typename Type>
		void ADoublyLinkedList<Type>::Purge()
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
		void ADoublyLinkedList<Type>::PushBack(const Type& p_key)
		{
			DoublyLinkedListNode<Type>* pNode = new DoublyLinkedListNode<Type>(p_key, m_pBack);

			if (IsEmpty())
			{
				m_pFront = pNode;
			}
			else
			{
				m_pBack->SetNext(pNode);
			}
			m_pBack = pNode;
			++m_size;
		}

		// ____________________________________________________________________________________________________________________
		// ___________________________________________________[ R ]____________________________________________________________
		// ____________________________________________________________________________________________________________________

		template <typename Type>
		void ADoublyLinkedList<Type>::RemoveAt(size_t p_index)
		{
			/*if (p_index < 1 || p_index > m_size)
			{
				throw ArgumentOutOfRangeException();
			}*/

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
				size_t i;
				DoublyLinkedListNode<Type>* pCurrent;

				if (p_index <= m_size / 2)
				{
					i = 2;
					pCurrent = m_pFront->Previous();

					while (pCurrent)
					{
						if (i == p_index)
						{
							pCurrent->Next()->SetNext(pCurrent->Previous());
							pCurrent->Previous()->SetNext(pCurrent->Next());
							delete pCurrent;

							--m_size;
							break;
						}
						++i;
						pCurrent = pCurrent->Previous();
					}
				}
				else
				{
					i = m_size - 1;
					pCurrent = m_pBack->Next();

					while (pCurrent)
					{
						if (i == p_index)
						{
							pCurrent->Next()->SetNext(pCurrent->Previous());
							pCurrent->Previous()->SetNext(pCurrent->Next());
							delete pCurrent;

							--m_size;
							break;
						}
						--i;
						pCurrent = pCurrent->Next();
					}
				}
			}
		}

		template <typename Type>
		void ADoublyLinkedList<Type>::Reverse()
		{
			DoublyLinkedListNode<Type>* pCurrent = m_pFront;

			while (pCurrent)
			{
				DoublyLinkedListNode<Type>* temp = pCurrent->Next();
				pCurrent->SetNext(pCurrent->Previous());
				pCurrent->SetNext(temp);

				pCurrent = pCurrent->Next();
			}
			Utility::Swap(m_pFront, m_pBack);
		}

		template <typename Type>
		String ADoublyLinkedList<Type>::ToString() const
		{
			DoublyLinkedListNode<Type>* pCurrent = m_pFront;

			String result("|nullptr|<=");

			while (pCurrent)
			{
				result += String::ValueOf(*pCurrent);
				result += "<=>";

				pCurrent = pCurrent->Previous();
			}
			result += "|nullptr|";
			return result;
		}

		template <typename Type>
		ADoublyLinkedList<Type>& ADoublyLinkedList<Type>::operator =(const ADoublyLinkedList<Type>& p_list)
		{
			if (&p_list != this)
			{
				if (p_list.IsEmpty())
				{
					Purge();
				}
				else
				{
					DoublyLinkedListNode<Type>* pCurrent = m_pFront;
					DoublyLinkedListNode<Type>* pOther = p_list.m_pFront;

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
							pCurrent = pCurrent->Previous();
							pOther = pOther->Previous();
						}

						m_pBack = pCurrent->Next();
						m_pBack->SetNext(nullptr);

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
		bool ADoublyLinkedList<Type>::operator<(const ADoublyLinkedList& p_list) const
		{
			return m_size < p_list.m_size;
		}

		template <typename Type>
		bool ADoublyLinkedList<Type>::operator>(const ADoublyLinkedList& p_list) const
		{
			return m_size > p_list.m_size;
		}

		template <typename Type>
		bool ADoublyLinkedList<Type>::operator ==(const ADoublyLinkedList<Type>& p_list) const
		{
			if (m_size != p_list.m_size)
			{
				return false;
			}

			DoublyLinkedListNode<Type>* pCurrent = m_pFront;
			DoublyLinkedListNode<Type>* pOther = p_list.m_pFront;

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
