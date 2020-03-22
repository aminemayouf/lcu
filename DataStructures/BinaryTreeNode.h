#pragma once

#include "Node.h"

namespace LCU
{
	inline namespace DataStructures
	{
		/**
		 * BinaryTreeNode Class
		 *
		 * @project DataStructures
		 * @author Amine MAYOUF
		 */
		template <typename Type>
		class BinaryTreeNode : public Node<Type>
		{
		protected:
			BinaryTreeNode* m_pParent;
			BinaryTreeNode* m_pLeftChild;
			BinaryTreeNode* m_pRightChild;

		public:
			explicit BinaryTreeNode(const Type& p_key,
			                        BinaryTreeNode* p_pParent = nullptr,
			                        BinaryTreeNode* p_pLeftChild = nullptr,
			                        BinaryTreeNode* p_pRightChild = nullptr);

			BinaryTreeNode* Parent() const;
			void SetParent(BinaryTreeNode* p_pParent);
			BinaryTreeNode* LeftChild() const;
			void SetLeftChild(BinaryTreeNode* p_pLeftChild);
			BinaryTreeNode* RightChild() const;
			void SetRightChild(BinaryTreeNode* p_pRightChild);
			// D
			size_t Depth() const;
			// H
			bool HasChildren() const;
			bool HasOneChild() const;
			bool HasSiblings() const;
			bool HasTwoChildren() const;
			// I
			bool IsAncestor(const BinaryTreeNode* p_pNode) const;
			bool IsChild(const BinaryTreeNode* p_pNode) const;
			bool IsDescendantRecursive(const BinaryTreeNode* p_pNode) const;
			bool IsGrandParent(const BinaryTreeNode* p_pNode) const;
			bool IsLeaf() const;
			bool IsRoot() const;
			bool IsSibling(const BinaryTreeNode* p_pNode) const;
			bool IsUncle(const BinaryTreeNode* p_pNode) const;
		};

		template <typename Type>
		BinaryTreeNode<Type>::BinaryTreeNode(const Type& p_key,
		                                     BinaryTreeNode* const p_pParent,
		                                     BinaryTreeNode* const p_pLeftChild,
		                                     BinaryTreeNode* const p_pRightChild)
			: Node<Type>(p_key),
			  m_pParent(p_pParent),
			  m_pLeftChild(p_pLeftChild),
			  m_pRightChild(p_pRightChild)
		{
		}

		template <typename Type>
		BinaryTreeNode<Type>* BinaryTreeNode<Type>::Parent() const
		{
			return m_pParent;
		}

		template <typename Type>
		void BinaryTreeNode<Type>::SetParent(BinaryTreeNode* const p_pParent)
		{
			m_pParent = p_pParent;
		}

		template <typename Type>
		BinaryTreeNode<Type>* BinaryTreeNode<Type>::LeftChild() const
		{
			return m_pLeftChild;
		}

		template <typename Type>
		void BinaryTreeNode<Type>::SetLeftChild(BinaryTreeNode* const p_pLeftChild)
		{
			m_pLeftChild = p_pLeftChild;
		}

		template <typename Type>
		BinaryTreeNode<Type>* BinaryTreeNode<Type>::RightChild() const
		{
			return m_pRightChild;
		}

		template <typename Type>
		void BinaryTreeNode<Type>::SetRightChild(BinaryTreeNode* const p_pRightChild)
		{
			m_pRightChild = p_pRightChild;
		}

		template <typename Type>
		size_t BinaryTreeNode<Type>::Depth() const
		{
			size_t n = 0;
			BinaryTreeNode<Type>* pCurrent = m_pParent;
			while (pCurrent)
			{
				++n;
				pCurrent = pCurrent->Parent();
			}
			return n;
		}

		template <typename Type>
		bool BinaryTreeNode<Type>::HasChildren() const
		{
			// If it doesn't, then it's a leaf...
			return m_pLeftChild || m_pRightChild ? true : false;
		}

		template <typename Type>
		bool BinaryTreeNode<Type>::HasOneChild() const
		{
			return HasChildren() && !HasTwoChildren();
		}

		template <typename Type>
		bool BinaryTreeNode<Type>::HasSiblings() const
		{
			if (!m_pParent)
			{
				return false;
			}
			return ((m_pParent->m_pLeftChild && m_pParent->m_pLeftChild != this)
				       || m_pParent->m_pRightChild && m_pParent->m_pRightChild != this)
				       ? true
				       : false;
		}

		template <typename Type>
		bool BinaryTreeNode<Type>::HasTwoChildren() const
		{
			return m_pLeftChild && m_pRightChild;
		}

		template <typename Type>
		bool BinaryTreeNode<Type>::IsAncestor(const BinaryTreeNode* const p_pNode) const
		{
			BinaryTreeNode* pCurrent = m_pParent;
			while (pCurrent)
			{
				if (pCurrent == p_pNode)
				{
					return true;
				}
				pCurrent = pCurrent->m_pParent;
			}
			return false;
		}

		template <typename Type>
		bool BinaryTreeNode<Type>::IsChild(const BinaryTreeNode* const p_pNode) const
		{
			if (!p_pNode)
			{
				return false;
			}
			return p_pNode == m_pLeftChild || p_pNode == m_pRightChild;
		}

		template <typename Type>
		bool BinaryTreeNode<Type>::IsDescendantRecursive(const BinaryTreeNode* const p_pNode) const
		{
			if (IsChild(p_pNode))
			{
				return true;
			}
			if (m_pLeftChild)
			{
				return m_pLeftChild->IsDescendantRecursive(p_pNode);
			}
			if (m_pRightChild)
			{
				return m_pRightChild->IsDescendantRecursive(p_pNode);
			}
			return false;
		}

		template <typename Type>
		bool BinaryTreeNode<Type>::IsGrandParent(const BinaryTreeNode* const p_pNode) const
		{
			if (m_pParent)
			{
				if (p_pNode == m_pParent->m_pParent)
				{
					return true;
				}
			}
			return false;
		}

		template <typename Type>
		bool BinaryTreeNode<Type>::IsLeaf() const
		{
			return !HasChildren();
		}

		template <typename Type>
		bool BinaryTreeNode<Type>::IsRoot() const
		{
			return !m_pParent;
		}

		template <typename Type>
		bool BinaryTreeNode<Type>::IsSibling(const BinaryTreeNode* const p_pNode) const
		{
			if (!p_pNode)
			{
				return false;
			}
			return p_pNode->m_pParent == m_pParent && p_pNode != this;
		}

		template <typename Type>
		bool BinaryTreeNode<Type>::IsUncle(const BinaryTreeNode* const p_pNode) const
		{
			if (m_pParent)
			{
				BinaryTreeNode* pGrandParent = m_pParent->m_pParent;
				if (pGrandParent)
				{
					if ((m_pParent == pGrandParent->m_pLeftChild && p_pNode == pGrandParent->m_pRightChild)
						|| (m_pParent == pGrandParent->m_pRightChild && p_pNode == pGrandParent->m_pLeftChild))
					{
						return true;
					}
				}
			}
			return false;
		}
	}
}
