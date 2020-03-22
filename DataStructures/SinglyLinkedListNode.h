#pragma once

#include "Node.h"

namespace LCU
{
	inline namespace DataStructures
	{
		/**
		 * SinglyLinkedListNode Class
		 *
		 * @project DataStructures
		 * @author Amine MAYOUF
		 */
		template <typename Type>
		class SinglyLinkedListNode : public Node<Type>
		{
		protected:
			SinglyLinkedListNode* m_pPrevious;

		public:
			explicit SinglyLinkedListNode(const Type& p_key, SinglyLinkedListNode* p_pPrevious = nullptr);
			virtual ~SinglyLinkedListNode() = default;

			virtual SinglyLinkedListNode* Previous() const;
			void SetPrevious(SinglyLinkedListNode* p_pPrevious);
		};

		template <typename Type>
		SinglyLinkedListNode<Type>::SinglyLinkedListNode(const Type& p_key, SinglyLinkedListNode* const p_pPrevious)
			: Node<Type>(p_key),
			  m_pPrevious(p_pPrevious)
		{
		}

		template <typename Type>
		SinglyLinkedListNode<Type>* SinglyLinkedListNode<Type>::Previous() const
		{
			return m_pPrevious;
		}

		template <typename Type>
		void SinglyLinkedListNode<Type>::SetPrevious(SinglyLinkedListNode* const p_pPrevious)
		{
			m_pPrevious = p_pPrevious;
		}
	}
}
