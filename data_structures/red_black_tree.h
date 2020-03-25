#pragma once

#include "binary_search_tree.h"
#include "red_black_tree_node.h"

namespace lcu
{
	inline namespace data_structures
	{
		/**
		 * RedBlackTree Class
		 *
		 * @project data_structures
		 * @author Amine MAYOUF
		 */
		template <typename Type>
		class RedBlackTree : public BinarySearchTree<Type> // TODO: Inherit from a balancing tree instead
		{
			using BinaryTree<Type>::m_pRoot;
			using BinaryTree<Type>::Iterator;

			// I
			using BinarySearchTree<Type>::IsEmpty;
			// F
		public:
			virtual Iterator FindByKey(const Type& p_key) const;
		private:
			using BinarySearchTree<Type>::FindFirst;
			using BinarySearchTree<Type>::FindLast;
			// R
			using BinarySearchTree<Type>::RemoveFirst;
		public:
			virtual void Remove(const Type& p_key);
		};

		template <typename Type>
		typename BinaryTree<Type>::Iterator RedBlackTree<Type>::FindByKey(const Type& p_key) const
		{
			if (!IsEmpty())
			{
				BinaryTreeNode<Type>* pCurrent = m_pRoot;
				while (pCurrent)
				{
					if (p_key == pCurrent->key)
					{
						return Iterator(pCurrent);
					}
					if (p_key < pCurrent->key)
					{
						pCurrent = pCurrent->LeftChild();
					}
					else if (p_key > pCurrent->key)
					{
						pCurrent = pCurrent->RightChild();
					}
				}
			}
			return Iterator(nullptr);
		}

		template <typename Type>
		void RedBlackTree<Type>::Remove(const Type& p_key)
		{
			RemoveFirst(p_key);
		}
	}
}
