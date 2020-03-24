#pragma once

#include "RedBlackTree.h"
#include "Pair.h"

namespace LCU
{
	inline namespace DataStructures
	{
		/**
		 * Map Class
		 *
		 * @project DataStructures
		 * @author Amine MAYOUF
		 */
		template <typename KeyType, typename ValueType>
		class Map : public RedBlackTree<Pair<KeyType, ValueType>> // TODO: Inherit from a balancing tree instead
		{
			using BinarySearchTree<Pair<KeyType, ValueType>>::Iterator;
			using BinarySearchTree<Pair<KeyType, ValueType>>::m_pRoot;
			using BinarySearchTree<Pair<KeyType, ValueType>>::m_size;

		public:
			using RedBlackTree<Pair<KeyType, ValueType>>::RedBlackTree;
			// F
			typename BinaryTree<Pair<KeyType, ValueType>>::Iterator FindByKey(const KeyType& p_key) const;
			// I
		private:
			void Insert(const Pair<KeyType, ValueType>& p_node) override;
		public:
			void Insert(const KeyType& p_key, const ValueType& p_value);
		private:
			using BinarySearchTree<Pair<KeyType, ValueType>>::InsertRecursive;
			void InsertRecursive(BinaryTreeNode<Pair<KeyType, ValueType>>* p_pRoot,
			                     const Pair<KeyType, ValueType>& p_node) override;
		public:
			void InsertRecursive(const KeyType& p_key, const ValueType& p_value);
			using BinarySearchTree<Pair<KeyType, ValueType>>::IsEmpty;
			// R
			void Remove(const KeyType& p_key);
			// #
			ValueType& operator[](const KeyType& p_key);
		};

		template <typename KeyType, typename ValueType>
		typename BinaryTree<Pair<KeyType, ValueType>>::Iterator Map<KeyType, ValueType>::FindByKey(
			const KeyType& p_key) const
		{
			if (!IsEmpty())
			{
				BinaryTreeNode<Pair<KeyType, ValueType>>* pCurrent = m_pRoot;
				while (pCurrent)
				{
					if (p_key == pCurrent->key.first)
					{
						return Iterator(pCurrent);
					}
					if (p_key < pCurrent->key.first)
					{
						pCurrent = pCurrent->LeftChild();
					}
					else if (p_key > pCurrent->key.first)
					{
						pCurrent = pCurrent->RightChild();
					}
				}
			}
			return Iterator(nullptr);
		}

		template <typename KeyType, typename Type>
		void Map<KeyType, Type>::Insert(const Pair<KeyType, Type>& p_node)
		{
			if (IsEmpty())
			{
				m_pRoot = new BinaryTreeNode<Pair<KeyType, Type>>(p_node);
			}
			else
			{
				BinaryTreeNode<Pair<KeyType, Type>>* pCurrent = m_pRoot;
				while (pCurrent)
				{
					if (p_node < pCurrent->key)
					{
						if (!pCurrent->LeftChild())
						{
							pCurrent->SetLeftChild(new BinaryTreeNode<Pair<KeyType, Type>>(p_node, pCurrent));
							break;
						}
						pCurrent = pCurrent->LeftChild();
					}
					else if (p_node > pCurrent->key)
					{
						if (!pCurrent->RightChild())
						{
							pCurrent->SetRightChild(new BinaryTreeNode<Pair<KeyType, Type>>(p_node, pCurrent));
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

		template <typename KeyType, typename ValueType>
		void Map<KeyType, ValueType>::Insert(const KeyType& p_key, const ValueType& p_value)
		{
			Insert(Pair<KeyType, ValueType>(p_key, p_value));
		}

		template <typename KeyType, typename Type>
		void Map<KeyType, Type>::InsertRecursive(BinaryTreeNode<Pair<KeyType, Type>>* const p_pRoot,
		                                         const Pair<KeyType, Type>& p_node)
		{
			if (p_node < p_pRoot->key)
			{
				if (!p_pRoot->LeftChild())
				{
					p_pRoot->SetLeftChild(new BinaryTreeNode<Pair<KeyType, Type>>(p_node, p_pRoot));
					++m_size;
				}
				else
				{
					this->InsertRecursive(p_pRoot->LeftChild(), p_node);
				}
			}
			else if (p_node > p_pRoot->key)
			{
				if (!p_pRoot->RightChild())
				{
					p_pRoot->SetRightChild(new BinaryTreeNode<Pair<KeyType, Type>>(p_node, p_pRoot));
					++m_size;
				}
				else
				{
					this->InsertRecursive(p_pRoot->RightChild(), p_node);
				}
			}
		}

		template <typename KeyType, typename ValueType>
		void Map<KeyType, ValueType>::InsertRecursive(const KeyType& p_key, const ValueType& p_value)
		{
			BinarySearchTree<Pair<KeyType, ValueType>>::InsertRecursive(Pair<KeyType, ValueType>(p_key, p_value));
		}

		template <typename KeyType, typename ValueType>
		void Map<KeyType, ValueType>::Remove(const KeyType& p_key)
		{
			// TODO: Implement
		}

		template <typename KeyType, typename ValueType>
		ValueType& Map<KeyType, ValueType>::operator[](const KeyType& p_key)
		{
			BinaryTreeNode<Pair<KeyType, ValueType>>* pCurrent = m_pRoot;
			while (pCurrent)
			{
				if (p_key == pCurrent->key.first)
				{
					return pCurrent->key.second;
				}

				if (p_key < pCurrent->key.first)
				{
					pCurrent = pCurrent->LeftChild();
				}
				else
				{
					pCurrent = pCurrent->RightChild();
				}
			}
			throw;
		}
	}
}
