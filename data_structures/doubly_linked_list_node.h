#pragma once

#include "singly_linked_list_node.h"

namespace lcu
{
	inline namespace data_structures
	{
		/**
		 * Doubly-Linked List Node Class
		 *
		 * @project data_structures
		 * @author Amine MAYOUF
		 */
		template <typename Type>
		class DoublyLinkedListNode : public SinglyLinkedListNode<Type>
		{
			DoublyLinkedListNode* m_pNext;
			using SinglyLinkedListNode<Type>::m_pPrevious;

		public:
			explicit DoublyLinkedListNode(const Type& p_key,
			                              DoublyLinkedListNode* p_pNext = nullptr,
			                              DoublyLinkedListNode* p_pPrevious = nullptr);

			DoublyLinkedListNode* Next() const;
			void SetNext(DoublyLinkedListNode* p_pNext);

			DoublyLinkedListNode* Previous() const override;
		};

		template <typename Type>
		DoublyLinkedListNode<Type>::DoublyLinkedListNode(const Type& p_key,
		                                                 DoublyLinkedListNode* const p_pNext,
		                                                 DoublyLinkedListNode* const p_pPrevious)
			: SinglyLinkedListNode<Type>(p_key, p_pPrevious),
			  m_pPrevious(p_pNext)
		{
		}

		template <typename Type>
		DoublyLinkedListNode<Type>* DoublyLinkedListNode<Type>::Next() const
		{
			return m_pPrevious;
		}

		template <typename Type>
		void DoublyLinkedListNode<Type>::SetNext(DoublyLinkedListNode* const p_pNext)
		{
			m_pPrevious = p_pNext;
		}

		template <typename Type>
		DoublyLinkedListNode<Type>* DoublyLinkedListNode<Type>::Previous() const
		{
			return dynamic_cast<DoublyLinkedListNode<Type>*>(m_pPrevious);
		}
	}
}
