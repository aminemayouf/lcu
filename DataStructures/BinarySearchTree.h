#pragma once

#include "BinaryTree.h"

namespace LCU
{
	inline namespace DataStructures
	{
		/**
		 * BinarySearchTree Class
		 *
		 * @project DataStructures
		 * @author Amine MAYOUF
		 */
		template <typename Type>
		class BinarySearchTree : public BinaryTree<Type>
		{
		protected:
			using BinaryTree<Type>::Iterator;
			using BinaryTree<Type>::m_pRoot;
			using BinaryTree<Type>::m_size;

		public:
			using BinaryTree<Type>::BinaryTree;

			bool Contains(const Type& p_key) const override;
			bool Contains(const BinaryTreeNode<Type>* p_pNode) const override;
			bool ContainsRecursive(const Type& p_key) const override;
			bool ContainsRecursive(const BinaryTreeNode<Type>* p_pNode) const override;
			static bool ContainsRecursive(const BinaryTreeNode<Type>* p_pRoot, const Type& p_key);
			static bool ContainsRecursive(const BinaryTreeNode<Type>* p_pRoot, const BinaryTreeNode<Type>* p_pNode);
			// F
			Iterator FindFirst(const Type& p_key) const;
			Iterator FindLast(const Type& p_key) const;
			// I
			void Insert(const Type& p_key) override;
			using BinaryTree<Type>::InsertRecursive;
		protected:
			void InsertRecursive(BinaryTreeNode<Type>* p_pRoot, const Type& p_key) override;
		public:
			using BinaryTree<Type>::IsEmpty;
			// M
			Type Max() const;
			Iterator MaxNode() const;
			Iterator MaxNodeRecursive() const;
		private:
			static const BinaryTreeNode<Type>* MaxNode(const BinaryTreeNode<Type>* p_pRoot);
			static const BinaryTreeNode<Type>* MaxNodeRecursive(const BinaryTreeNode<Type>* p_pRoot);
		public:
			Type Min() const;
			Iterator MinNode() const;
			Iterator MinNodeRecursive() const;
		private:
			static const BinaryTreeNode<Type>* MinNode(const BinaryTreeNode<Type>* p_pRoot);
			static const BinaryTreeNode<Type>* MinNodeRecursive(const BinaryTreeNode<Type>* p_pRoot);
		public:
			// R
			void RemoveFirst(const Type& p_key);
			void RemoveFirstRecursive(const Type& p_key);
		private:
			static BinaryTreeNode<Type>* RemoveFirstRecursive(BinaryTreeNode<Type>* p_pRoot, const Type& p_key,
			                                                  size_t& p_size);
		};

		template <typename Type>
		bool BinarySearchTree<Type>::Contains(const Type& p_key) const
		{
			BinaryTreeNode<Type>* pCurrent = m_pRoot;
			while (pCurrent)
			{
				if (p_key == pCurrent->key)
				{
					return true;
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
			return false;
		}

		template <typename Type>
		bool BinarySearchTree<Type>::Contains(const BinaryTreeNode<Type>* const p_pNode) const
		{
			if (!p_pNode)
			{
				//throw ArgumentNullException();
				return false;
			}

			BinaryTreeNode<Type>* pCurrent = m_pRoot;
			while (pCurrent)
			{
				if (p_pNode->key == pCurrent->key)
				{
					if (p_pNode == pCurrent)
					{
						return true;
					}
					pCurrent = pCurrent->RightChild();
				}
				else if (p_pNode->key < pCurrent->key)
				{
					pCurrent = pCurrent->LeftChild();
				}
				else if (p_pNode->key > pCurrent->key)
				{
					pCurrent = pCurrent->RightChild();
				}
			}
			return false;
		}

		template <typename Type>
		bool BinarySearchTree<Type>::ContainsRecursive(const Type& p_key) const
		{
			return ContainsRecursive(m_pRoot, p_key);
		}

		template <typename Type>
		bool BinarySearchTree<Type>::ContainsRecursive(const BinaryTreeNode<Type>* const p_pNode) const
		{
			if (!p_pNode)
			{
				//throw ArgumentNullException();
				return false;
			}
			return ContainsRecursive(m_pRoot, p_pNode);
		}

		template <typename Type>
		bool BinarySearchTree<Type>::ContainsRecursive(const BinaryTreeNode<Type>* const p_pRoot, const Type& p_key)
		{
			if (p_pRoot)
			{
				if (p_key == p_pRoot->key)
				{
					return true;
				}
				if (p_key < p_pRoot->key)
				{
					return ContainsRecursive(p_pRoot->LeftChild(), p_key);
				}
				if (p_key > p_pRoot->key)
				{
					return ContainsRecursive(p_pRoot->RightChild(), p_key);
				}
			}
			return false;
		}

		template <typename Type>
		bool BinarySearchTree<Type>::ContainsRecursive(const BinaryTreeNode<Type>* const p_pRoot,
		                                               const BinaryTreeNode<Type>* const p_pNode)
		{
			if (p_pRoot)
			{
				if (p_pNode->key == p_pRoot->key)
				{
					if (p_pRoot == p_pNode)
					{
						return true;
					}
				}

				if (p_pNode->key < p_pRoot->key)
				{
					return ContainsRecursive(p_pRoot->LeftChild(), p_pNode);
				}

				if (p_pNode->key > p_pRoot->key)
				{
					return ContainsRecursive(p_pRoot->RightChild(), p_pNode);
				}
			}
			return false;
		}

		template <typename Type>
		typename BinaryTree<Type>::Iterator BinarySearchTree<Type>::FindFirst(const Type& p_key) const
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
			return nullptr;
		}

		template <typename Type>
		typename BinaryTree<Type>::Iterator BinarySearchTree<Type>::FindLast(const Type& p_key) const
		{
			BinaryTreeNode<Type>* pLast = nullptr;

			if (!IsEmpty())
			{
				BinaryTreeNode<Type>* pCurrent = m_pRoot;
				while (pCurrent)
				{
					if (p_key == pCurrent->key)
					{
						pLast = pCurrent;
						pCurrent = pCurrent->RightChild();
					}
					else if (p_key < pCurrent->key)
					{
						pCurrent = pCurrent->LeftChild();
					}
					else if (p_key > pCurrent->key)
					{
						pCurrent = pCurrent->RightChild();
					}
				}
			}
			return Iterator(pLast);
		}

		template <typename Type>
		void BinarySearchTree<Type>::Insert(const Type& p_key)
		{
			if (IsEmpty())
			{
				m_pRoot = new BinaryTreeNode<Type>(p_key);
			}
			else
			{
				BinaryTreeNode<Type>* pCurrent = m_pRoot;
				while (pCurrent)
				{
					if (p_key < pCurrent->key)
					{
						if (!pCurrent->LeftChild())
						{
							pCurrent->SetLeftChild(new BinaryTreeNode<Type>(p_key, pCurrent));
							break;
						}
						pCurrent = pCurrent->LeftChild();
					}
					else
					{
						if (!pCurrent->RightChild())
						{
							pCurrent->SetRightChild(new BinaryTreeNode<Type>(p_key, pCurrent));
							break;
						}
						pCurrent = pCurrent->RightChild();
					}
				}
			}
			++m_size;
		}

		template <typename Type>
		void BinarySearchTree<Type>::InsertRecursive(BinaryTreeNode<Type>* const p_pRoot, const Type& p_key)
		{
			if (p_key < p_pRoot->key)
			{
				if (!p_pRoot->LeftChild())
				{
					p_pRoot->SetLeftChild(new BinaryTreeNode<Type>(p_key, p_pRoot));
					++m_size;
				}
				else
				{
					this->InsertRecursive(p_pRoot->LeftChild(), p_key);
				}
			}
			else
			{
				if (!p_pRoot->RightChild())
				{
					p_pRoot->SetRightChild(new BinaryTreeNode<Type>(p_key, p_pRoot));
					++m_size;
				}
				else
				{
					this->InsertRecursive(p_pRoot->RightChild(), p_key);
				}
			}
		}

		template <typename Type>
		Type BinarySearchTree<Type>::Max() const
		{
			if (IsEmpty)
			{
				throw /*NullPointerException()*/;
			}

			BinaryTreeNode<Type>* pCurrent = m_pRoot;
			while (pCurrent->RightChild())
			{
				pCurrent = pCurrent->RightChild();
			}
			return pCurrent->key;
		}

		template <typename Type>
		typename BinaryTree<Type>::Iterator BinarySearchTree<Type>::MaxNode() const
		{
			return Iterator(MaxNode(m_pRoot));
		}

		template <typename Type>
		typename BinaryTree<Type>::Iterator BinarySearchTree<Type>::MaxNodeRecursive() const
		{
			return Iterator(MaxNodeRecursive(m_pRoot));
		}

		template <typename Type>
		const BinaryTreeNode<Type>* BinarySearchTree<Type>::MaxNode(const BinaryTreeNode<Type>* const p_pRoot)
		{
			if (!p_pRoot)
			{
				return nullptr;
			}

			const BinaryTreeNode<Type>* pCurrent = p_pRoot;
			while (pCurrent->RightChild())
			{
				pCurrent = pCurrent->RightChild();
			}
			return pCurrent;
		}

		template <typename Type>
		const BinaryTreeNode<Type>* BinarySearchTree<Type>::MaxNodeRecursive(const BinaryTreeNode<Type>* const p_pRoot)
		{
			if (!p_pRoot)
			{
				return nullptr;
			}
			if (!p_pRoot->RightChild())
			{
				return p_pRoot;
			}
			return MaxNodeRecursive(p_pRoot->RightChild());
		}

		template <typename Type>
		Type BinarySearchTree<Type>::Min() const
		{
			if (IsEmpty)
			{
				throw /*NullPointerException()*/;
			}

			BinaryTreeNode<Type>* pCurrent = m_pRoot;
			while (pCurrent->LeftChild())
			{
				pCurrent = pCurrent->LeftChild();
			}
			return pCurrent->key;
		}

		template <typename Type>
		typename BinaryTree<Type>::Iterator BinarySearchTree<Type>::MinNode() const
		{
			return Iterator(MinNode(m_pRoot));
		}

		template <typename Type>
		typename BinaryTree<Type>::Iterator BinarySearchTree<Type>::MinNodeRecursive() const
		{
			return Iterator(MinNodeRecursive(m_pRoot));
		}

		template <typename Type>
		const BinaryTreeNode<Type>* BinarySearchTree<Type>::MinNode(const BinaryTreeNode<Type>* const p_pRoot)
		{
			if (!p_pRoot)
			{
				return nullptr;
			}

			const BinaryTreeNode<Type>* pCurrent = p_pRoot;
			while (pCurrent->LeftChild())
			{
				pCurrent = pCurrent->LeftChild();
			}
			return pCurrent;
		}

		template <typename Type>
		const BinaryTreeNode<Type>* BinarySearchTree<Type>::MinNodeRecursive(const BinaryTreeNode<Type>* const p_pRoot)
		{
			if (!p_pRoot)
			{
				return nullptr;
			}
			if (!p_pRoot->LeftChild())
			{
				return p_pRoot;
			}
			return MinNodeRecursive(p_pRoot->LeftChild());
		}

		template <typename Type>
		void BinarySearchTree<Type>::RemoveFirst(const Type& p_key) // TODO: Implement
		{
			if (IsEmpty())
			{
				//throw NullPointerException();
				return;
			}

			BinaryTreeNode<Type>* pCurrent = m_pRoot;
			while (pCurrent)
			{
				if (p_key < pCurrent->key)
				{
					pCurrent = pCurrent->LeftChild();
				}
				else if (p_key > pCurrent->key)
				{
					pCurrent = pCurrent->RightChild();
				}
				else
				{
					const BinaryTreeNode<Type>* pTemp;
					// Case 1: ! child
					if (!pCurrent->HasChildren())
					{
						pTemp = pCurrent;
					}
						// Case 2: one child
					else if (pCurrent->HasOneChild())
					{
						pTemp = pCurrent;
						if (!pCurrent->LeftChild())
						{
							pCurrent = pCurrent->RightChild();
						}
						else if (!pCurrent->RightChild())
						{
							pCurrent = pCurrent->LeftChild();
						}
						pCurrent->SetParent(pTemp->Parent());
					}
					else
					{
						pTemp = MinNode(pCurrent->RightChild());
						pCurrent->key = pTemp->key;
					}

					if (!pTemp->Parent())
					{
						m_pRoot = pCurrent;
					}
					else
					{
						if (pTemp == pTemp->Parent()->LeftChild())
						{
							pTemp->Parent()->SetLeftChild(nullptr);
						}
						else
						{
							pTemp->Parent()->SetRightChild(nullptr);
						}
					}

					delete pTemp;
					--m_size;

					return;
				}
			}
		}

		template <typename Type>
		void BinarySearchTree<Type>::RemoveFirstRecursive(const Type& p_key)
		{
			m_pRoot = RemoveFirstRecursive(m_pRoot, p_key, m_size);
		}

		template <typename Type>
		BinaryTreeNode<Type>* BinarySearchTree<Type>::RemoveFirstRecursive(
			BinaryTreeNode<Type>* p_pRoot, const Type& p_key, size_t& p_size)
		{
			if (!p_pRoot)
			{
				return p_pRoot;
			}

			if (p_key < p_pRoot->key)
			{
				p_pRoot->SetLeftChild(RemoveFirstRecursive(p_pRoot->LeftChild(), p_key, p_size));
			}
			else if (p_key > p_pRoot->key)
			{
				p_pRoot->SetRightChild(RemoveFirstRecursive(p_pRoot->RightChild(), p_key, p_size));
			}
			else
			{
				// Case 1: ! Child
				if (!p_pRoot->HasChildren())
				{
					delete p_pRoot;
					p_pRoot = nullptr;
					--p_size;
				}
					// Case 2: one child
				else if (p_pRoot->HasOneChild())
				{
					BinaryTreeNode<Type>* pTemp = p_pRoot;
					if (!p_pRoot->LeftChild())
					{
						p_pRoot = p_pRoot->RightChild();
					}
					else if (!p_pRoot->RightChild())
					{
						p_pRoot = p_pRoot->LeftChild();
					}

					delete pTemp;
					p_pRoot->SetParent(nullptr);
					--p_size;
				}
				else
				{
					const BinaryTreeNode<Type>* pTemp = MinNodeRecursive(p_pRoot->RightChild());
					p_pRoot->key = pTemp->key;
					p_pRoot->SetRightChild(RemoveFirstRecursive(p_pRoot->RightChild(), pTemp->key, p_size));
				}
			}

			return p_pRoot;
		}
	}
}
