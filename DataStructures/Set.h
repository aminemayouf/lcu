#pragma once

#include "RedBlackTree.h"

namespace LCU
{
	inline namespace DataStructures
	{
		/**
		 * Set Class
		 *
		 * @project DataStructures
		 * @author Amine MAYOUF
		 */
		template <typename Type>
		class Set : public RedBlackTree<Type>
		{
			using BinarySearchTree<Type>::m_pRoot;
			using BinarySearchTree<Type>::m_size;

		public:
			using RedBlackTree<Type>::RedBlackTree;
			// I
			void Insert(const Type& p_nodeKey) override;
			using BinarySearchTree<Type>::InsertRecursive;
		private:
			void InsertRecursive(BinaryTreeNode<Type>* p_pRoot, const Type& p_nodeKey) override;
			using BinarySearchTree<Type>::IsEmpty;
		};

		template <typename Type>
		void Set<Type>::Insert(const Type& p_nodeKey)
		{
			if (IsEmpty())
			{
				m_pRoot = new BinaryTreeNode<Type>(p_nodeKey);
			}
			else
			{
				BinaryTreeNode<Type>* pCurrent = m_pRoot;
				while (pCurrent)
				{
					if (p_nodeKey < pCurrent->key)
					{
						if (!pCurrent->LeftChild())
						{
							pCurrent->SetLeftChild(new BinaryTreeNode<Type>(p_nodeKey, pCurrent));
							break;
						}
						pCurrent = pCurrent->LeftChild();
					}
					else if (p_nodeKey > pCurrent->key)
					{
						if (!pCurrent->RightChild())
						{
							pCurrent->SetRightChild(new BinaryTreeNode<Type>(p_nodeKey, pCurrent));
							break;
						}
						pCurrent = pCurrent->RightChild();
					}
					else
					{
						break;
					}
				}
			}
			++m_size;
		}

		template <typename Type>
		void Set<Type>::InsertRecursive(BinaryTreeNode<Type>* const p_pRoot, const Type& p_nodeKey)
		{
			if (p_nodeKey < p_pRoot->key)
			{
				if (!p_pRoot->LeftChild())
				{
					p_pRoot->SetLeftChild(new BinaryTreeNode<Type>(p_nodeKey, p_pRoot));
					++m_size;
				}
				else
				{
					this->InsertRecursive(p_pRoot->LeftChild(), p_nodeKey);
				}
			}
			else if (p_nodeKey > p_pRoot->key)
			{
				if (!p_pRoot->RightChild())
				{
					p_pRoot->SetRightChild(new BinaryTreeNode<Type>(p_nodeKey, p_pRoot));
					++m_size;
				}
				else
				{
					this->InsertRecursive(p_pRoot->RightChild(), p_nodeKey);
				}
			}
		}
	}
}
