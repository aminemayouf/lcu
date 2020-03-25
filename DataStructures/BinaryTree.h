#pragma once

#include "Array.h"
#include "BinaryTreeNode.h"
#include "ForwardList.h"
#include "Stack.h"
#include "Queue.h"

namespace lcu
{
	inline namespace data_structures
	{
		/**
		 * BinaryTree Class
		 *
		 * @project DataStructures
		 * @author Amine MAYOUF
		 */
		template <typename Type>
		class BinaryTree : public AContainer<Type>, public IComparable<BinaryTree<Type>>
		{
		public:
			class Iterator : public IIterator<Type>
			{
				BinaryTreeNode<Type>* m_pCurrent;

			public:
				explicit Iterator(BinaryTreeNode<Type>* const p_pElement)
				{
					m_pCurrent = p_pElement;
				}

				Iterator& operator++() override
				{
					if (m_pCurrent->RightChild())
					{
						m_pCurrent = m_pCurrent->RightChild();
						while (m_pCurrent->LeftChild())
						{
							m_pCurrent = m_pCurrent->LeftChild();
						}
					}
					else
					{
						while (true)
						{
							if (m_pCurrent->IsRoot())
							{
								m_pCurrent = nullptr;
								break;
							}
							if (m_pCurrent == m_pCurrent->Parent()->LeftChild())
							{
								m_pCurrent = m_pCurrent->Parent();
								break;
							}
							m_pCurrent = m_pCurrent->Parent();
						}
					}
					return *this;
				}

				Iterator& operator--() override
				{
					if (m_pCurrent->LeftChild())
					{
						m_pCurrent = m_pCurrent->LeftChild();
						while (m_pCurrent->RightChild())
						{
							m_pCurrent = m_pCurrent->RightChild();
						}
					}
					else
					{
						while (true)
						{
							if (m_pCurrent->IsRoot())
							{
								m_pCurrent = nullptr;
								break;
							}
							if (m_pCurrent == m_pCurrent->Parent()->RightChild())
							{
								m_pCurrent = m_pCurrent->Parent();
								break;
							}
							m_pCurrent = m_pCurrent->Parent();
						}
					}
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
			BinaryTreeNode<Type>* m_pRoot;
			using AContainer<Type>::m_size;

		public:
			BinaryTree();
			BinaryTree(const BinaryTree<Type>& p_tree);
			virtual ~BinaryTree();

			Iterator Root() const;
			Iterator Begin() const;
			Iterator BeginReverse() const;
			Iterator End() const;
			Iterator EndReverse() const;
			// A
			/**
			 * The Arity of a node is the number of its children.
			 * @return The Arity of a node from its key.
			 */
			size_t Arity(const Type& p_key) const;
			size_t Arity(const BinaryTreeNode<Type>* p_pNode) const;
			// B
			Array<Type> BreadthFirstTraversal() const;
			// C
			BinaryTree CloneRecursive() const;
		private:
			static BinaryTreeNode<Type>* CloneRecursive(const BinaryTreeNode<Type>* p_pSubTreeRoot,
			                                            BinaryTreeNode<Type>* p_pParent);
		public:
			bool Contains(const Type& p_key) const override;
			virtual bool Contains(const BinaryTreeNode<Type>* p_pNode) const;
			virtual bool ContainsRecursive(const Type& p_key) const;
			virtual bool ContainsRecursive(const BinaryTreeNode<Type>* p_pNode) const;
			static bool ContainsRecursive(const BinaryTreeNode<Type>* p_pRoot, const Type& p_key);
			static bool ContainsRecursive(const BinaryTreeNode<Type>* p_pRoot, const BinaryTreeNode<Type>* p_pNode);
			// D
			void DestroyRecursive();
			static void DestroyRecursive(BinaryTreeNode<Type>* p_pRoot);
			static void DestroyRecursive(BinaryTreeNode<Type>* p_pRoot, size_t& p_treeSize);
			Array<Type> DepthFirstTraversal() const;
			/**
			 * The depth of a Node is the number of branches from the Root to the Node.
			 */
			size_t DepthOf(const Type& p_key) const;
			size_t DepthOf(const BinaryTreeNode<Type>* p_pNode) const;
			size_t DepthOfRecursive(const BinaryTreeNode<Type>* p_pNode) const;
			// E
			bool EqualsRecursive(const BinaryTree& p_tree) const;
			static bool EqualRecursive(const BinaryTreeNode<Type>* p_pRoot1, const BinaryTreeNode<Type>* p_pRoot2);
			// H
			/**
			 * The Height of a Tree is the Height of the uppermost leaf(i.e.the Root).
			 */
			size_t Height() const;
			size_t HeightRecursive() const;
			static size_t HeightOf(const BinaryTreeNode<Type>* p_pNode);
			static size_t HeightOfRecursive(const BinaryTreeNode<Type>* p_pNode);
			// I
			Array<Type> InorderTraversal() const;
			Array<Type> InorderTraversalRecursive() const;
		private:
			static void InorderTraversalRecursive(const BinaryTreeNode<Type>* p_pRoot, Array<Type>& p_result);
		public:
			virtual void Insert(const Type& p_key);
			void InsertRecursive(const Type& p_key);
		protected:
			virtual void InsertRecursive(BinaryTreeNode<Type>* p_pRoot, const Type& p_key);
		public:
			ForwardList<BinaryTreeNode<Type>> InternalNodesRecursive() const;
		private:
			static void InternalNodesRecursive(const BinaryTreeNode<Type>* p_pRoot,
			                                   ForwardList<BinaryTreeNode<Type>>& p_result);
		public:
			/**
			 * A degenerate (or pathological) tree is where each parent node has only one associated child node.
			 * This means that performance-wise, the tree will behave like a linked list data structure.
			 */
			bool IsDegenetate() const;
			static bool IsDegenerate(const BinaryTreeNode<Type>* p_pRoot);
			bool IsEmpty() const override;
			/**
			 * A full binary tree (sometimes referred to as a proper or plane binary tree)
			 * is a tree in which every node in the tree has either 0 or 2 children.
			 */
			bool IsFullRecursive() const;
			static bool IsFullRecursive(const BinaryTreeNode<Type>* p_pRoot);
			/**
			 * A perfect binary tree is a binary tree in which all interior nodes have two children and all leaves have the same depth or same level.
			 */
			bool IsPerfect() const;
			// L
			ForwardList<BinaryTreeNode<Type>> LeafNodesRecursive() const;
		private:
			static void LeafNodesRecursive(const BinaryTreeNode<Type>* p_pRoot,
			                               ForwardList<BinaryTreeNode<Type>>& p_result);
		public:
			// M
			void MirrorRecursive();
			static void MirrorRecursive(BinaryTreeNode<Type>* p_pRoot);
			// P
			Array<Type> PostorderTraversal() const;
			Array<Type> PostorderTraversalRecursive() const;
		private:
			static void PostorderTraversalRecursive(const BinaryTreeNode<Type>* p_pRoot, Array<Type>& p_result);
		public:
			Array<Type> PreorderTraversal() const;
			Array<Type> PreorderTraversalRecursive() const;
		private:
			static void PreorderTraversalRecursive(const BinaryTreeNode<Type>* p_pRoot, Array<Type>& p_result);
		public:
			void Purge() override;
			// S
			static size_t SizeOfRecursive(const BinaryTreeNode<Type>* p_pRoot);
			// T
			String ToString() const override;
			String ToStringRecursive() const;
		private:
			static void ToStringRecursive(const BinaryTreeNode<Type>* p_pRoot, String& p_result);
		public:
			// #
			BinaryTree& operator =(const BinaryTree& p_tree);
			bool operator <(const BinaryTree& p_tree) const override;
			bool operator >(const BinaryTree& p_tree) const override;
			bool operator ==(const BinaryTree& p_tree) const override;
		};

		template <typename Type>
		BinaryTree<Type>::BinaryTree() : AContainer(), m_pRoot(nullptr)
		{
		}

		template <typename Type>
		BinaryTree<Type>::BinaryTree(const BinaryTree<Type>& p_tree)
		{
			m_pRoot = CloneRecursive(p_tree.m_pRoot, nullptr);
			m_size = p_tree.m_size;
		}

		template <typename Type>
		BinaryTree<Type>::~BinaryTree()
		{
			DestroyRecursive(m_pRoot);
		}

		template <typename Type>
		typename BinaryTree<Type>::Iterator BinaryTree<Type>::Root() const
		{
			return Iterator(m_pRoot);
		}

		template <typename Type>
		typename BinaryTree<Type>::Iterator BinaryTree<Type>::Begin() const
		{
			BinaryTreeNode<Type>* pCurrent = m_pRoot;
			if (!IsEmpty())
			{
				while (pCurrent->LeftChild())
				{
					pCurrent = pCurrent->LeftChild();
				}
			}
			return Iterator(pCurrent);
		}

		template <typename Type>
		typename BinaryTree<Type>::Iterator BinaryTree<Type>::BeginReverse() const
		{
			BinaryTreeNode<Type>* pCurrent = m_pRoot;
			if (!IsEmpty())
			{
				while (pCurrent->RightChild())
				{
					pCurrent = pCurrent->RightChild();
				}
			}
			return Iterator(pCurrent);
		}

		template <typename Type>
		typename BinaryTree<Type>::Iterator BinaryTree<Type>::End() const
		{
			return Iterator(nullptr);
		}

		template <typename Type>
		typename BinaryTree<Type>::Iterator BinaryTree<Type>::EndReverse() const
		{
			return Iterator(nullptr);
		}

		template <typename Type>
		size_t BinaryTree<Type>::Arity(const Type& p_key) const
		{
			BinaryTreeNode<Type>* pCurrent = m_pRoot;
			while (pCurrent)
			{
				if (p_key == pCurrent->key)
				{
					if (!pCurrent->LeftChild() && !pCurrent->RightChild())
					{
						return 0;
					}
					if ((pCurrent->LeftChild() && !pCurrent->RightChild())
						|| (!pCurrent->LeftChild() && pCurrent->RightChild()))
					{
						return 1;
					}
					if (pCurrent->LeftChild() && pCurrent->RightChild())
					{
						return 2;
					}
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
			return 0;
		}

		template <typename Type>
		size_t BinaryTree<Type>::Arity(const BinaryTreeNode<Type>* const p_pNode) const
		{
			if (!p_pNode)
			{
				//throw ArgumentNullException();
				return -1;
			}

			BinaryTreeNode<Type>* pCurrent = m_pRoot;
			while (pCurrent)
			{
				if (p_pNode->key == pCurrent->key)
				{
					if (p_pNode == pCurrent)
					{
						if (!pCurrent->LeftChild() && !pCurrent->RightChild())
						{
							return 0;
						}
						if ((pCurrent->LeftChild() && !pCurrent->RightChild())
							|| (!pCurrent->LeftChild() && pCurrent->RightChild()))
						{
							return 1;
						}
						if (pCurrent->LeftChild() && pCurrent->RightChild())
						{
							return 2;
						}
					}
					else
					{
						pCurrent = pCurrent->RightChild();
					}
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

			return 0;
		}

		template <typename Type>
		Array<Type> BinaryTree<Type>::BreadthFirstTraversal() const
		{
			Array<Type> result(m_size);
			if (!IsEmpty())
			{
				BinaryTreeNode<Type>* pCurrent = m_pRoot;

				Queue<BinaryTreeNode<Type>*> queue;
				queue.Push(pCurrent);
				while (!queue.IsEmpty())
				{
					pCurrent = queue.Pop();
					result.PushBack(pCurrent->key);
					if (pCurrent->LeftChild())
					{
						queue.Push(pCurrent->LeftChild());
					}
					if (pCurrent->RightChild())
					{
						queue.Push(pCurrent->RightChild());
					}
				}
			}
			return result;
		}

		template <typename Type>
		BinaryTree<Type> BinaryTree<Type>::CloneRecursive() const
		{
			BinaryTree<Type> result;
			result.m_pRoot = CloneRecursive(m_pRoot, nullptr);
			result.m_size = m_size;
			return result;
		}

		template <typename Type>
		BinaryTreeNode<Type>* BinaryTree<Type>::CloneRecursive(const BinaryTreeNode<Type>* const p_pRoot,
		                                                       BinaryTreeNode<Type>* const p_pParent)
		{
			if (!p_pRoot)
			{
				return nullptr;
			}
			BinaryTreeNode<Type>* pNode = new BinaryTreeNode<Type>(p_pRoot->key, p_pParent);
			pNode->SetLeftChild(CloneRecursive(p_pRoot->LeftChild(), pNode));
			pNode->SetRightChild(CloneRecursive(p_pRoot->RightChild(), pNode));
			return pNode;
		}

		template <typename Type>
		bool BinaryTree<Type>::Contains(const Type& p_key) const // TODO: Implement
		{
			/*BinaryTreeNode<Type>* pCurrent = m_pRoot;
			while (pCurrent)
			{
				
			}*/

			return false;
		}

		template <typename Type>
		bool BinaryTree<Type>::Contains(const BinaryTreeNode<Type>* const p_pNode) const // TODO: Implement
		{
			if (!p_pNode)
			{
				//throw ArgumentNullException();
				return false;
			}

			/*BinaryTreeNode<Type>* pCurrent = m_pRoot;
			while (pCurrent)
			{
				
			}*/

			return false;
		}

		template <typename Type>
		bool BinaryTree<Type>::ContainsRecursive(const Type& p_key) const
		{
			return ContainsRecursive(m_pRoot, p_key);
		}

		template <typename Type>
		bool BinaryTree<Type>::ContainsRecursive(const BinaryTreeNode<Type>* const p_pNode) const
		{
			if (!p_pNode)
			{
				//throw ArgumentNullException();
				return false;
			}
			return ContainsRecursive(m_pRoot, p_pNode->key);
		}

		template <typename Type>
		bool BinaryTree<Type>::ContainsRecursive(const BinaryTreeNode<Type>* const p_pRoot, const Type& p_key)
		// TODO: Implement
		{
			if (!p_pRoot)
			{
				//throw ArgumentNullException();
				return false;
			}
			return false;
		}

		template <typename Type>
		bool BinaryTree<Type>::ContainsRecursive(const BinaryTreeNode<Type>* const p_pRoot,
		                                         const BinaryTreeNode<Type>* const p_pNode) // TODO: Implement
		{
			if (!p_pRoot)
			{
				//throw ArgumentNullException();
				return false;
			}
			return false;
		}

		template <typename Type>
		void BinaryTree<Type>::DestroyRecursive()
		{
			DestroyRecursive(m_pRoot);
			m_pRoot = nullptr;
			m_size = 0;
		}

		template <typename Type>
		void BinaryTree<Type>::DestroyRecursive(BinaryTreeNode<Type>* p_pRoot)
		{
			if (p_pRoot)
			{
				DestroyRecursive(p_pRoot->LeftChild());
				DestroyRecursive(p_pRoot->RightChild());
				delete p_pRoot;
			}
		}

		template <typename Type>
		void BinaryTree<Type>::DestroyRecursive(BinaryTreeNode<Type>* p_pRoot, size_t& p_branchSize)
		{
			if (p_pRoot)
			{
				DestroyRecursive(p_pRoot->LeftChild(), p_branchSize);
				DestroyRecursive(p_pRoot->RightChild(), p_branchSize);
				delete p_pRoot;
				--p_branchSize;
			}
		}

		template <typename Type>
		Array<Type> BinaryTree<Type>::DepthFirstTraversal() const
		{
			Array<Type> result(m_size);

			if (!IsEmpty())
			{
				BinaryTreeNode<Type>* pCurrent = m_pRoot;

				Stack<BinaryTreeNode<Type>*> visiting;
				visiting.Push(pCurrent);
				while (!visiting.IsEmpty())
				{
					pCurrent = visiting.Pop();
					result.PushBack(pCurrent->key);
					if (pCurrent->LeftChild())
					{
						visiting.Push(pCurrent->LeftChild());
					}
					if (pCurrent->RightChild())
					{
						visiting.Push(pCurrent->RightChild());
					}
				}
			}

			return result;
		}

		// The depth of a p_pRoot is the number of edges from the p_pRoot to the p_pRoot.
		template <typename Type>
		size_t BinaryTree<Type>::DepthOf(const Type& p_key) const
		{
			size_t i = 0;
			BinaryTreeNode<Type>* pCurrent = m_pRoot;
			while (pCurrent)
			{
				if (p_key == pCurrent->key)
				{
					break;
				}
				if (p_key < pCurrent->key)
				{
					++i;
					pCurrent = pCurrent->LeftChild();
				}
				else if (p_key > pCurrent->key)
				{
					++i;
					pCurrent = pCurrent->RightChild();
				}
			}
			return i;
		}

		template <typename Type>
		size_t BinaryTree<Type>::DepthOf(const BinaryTreeNode<Type>* const p_pNode) const
		{
			/*if (!p_pRoot)
			{
				throw ArgumentNullException();
			}*/

			size_t i = 0;
			BinaryTreeNode<Type>* pCurrent = m_pRoot;
			while (pCurrent)
			{
				if (p_pNode->key == pCurrent->key)
				{
					if (p_pNode == pCurrent)
					{
						break;
					}
					++i;
					pCurrent = pCurrent->RightChild();
				}
				else if (p_pNode->key < pCurrent->key)
				{
					++i;
					pCurrent = pCurrent->LeftChild();
				}
				else if (p_pNode->key > pCurrent->key)
				{
					++i;
					pCurrent = pCurrent->RightChild();
				}
			}
			return i;
		}

		template <typename Type>
		size_t BinaryTree<Type>::DepthOfRecursive(const BinaryTreeNode<Type>* const p_pNode) const
		{
			if (!p_pNode)
			{
				//throw ArgumentNullException();
				return 0;
			}
			if (!p_pNode->Parent())
			{
				return 0;
			}
			return 1 + DepthOfRecursive(p_pNode->Parent());
		}

		template <typename Type>
		bool BinaryTree<Type>::EqualsRecursive(const BinaryTree& p_tree) const
		{
			return EqualRecursive(m_pRoot, p_tree.m_pRoot);
		}

		template <typename Type>
		bool BinaryTree<Type>::EqualRecursive(const BinaryTreeNode<Type>* const p_pRoot1,
		                                      const BinaryTreeNode<Type>* const p_pRoot2)
		{
			if (!p_pRoot1 && !p_pRoot2)
			{
				return true;
			}
			if (p_pRoot1 && p_pRoot2)
			{
				return p_pRoot1->key == p_pRoot2->key
					&& EqualRecursive(p_pRoot1->LeftChild(), p_pRoot2->LeftChild())
					&& EqualRecursive(p_pRoot1->RightChild(), p_pRoot2->RightChild());
			}
			return false;
		}

		template <typename Type>
		size_t BinaryTree<Type>::Height() const
		{
			return HeightOf(m_pRoot);
		}

		template <typename Type>
		size_t BinaryTree<Type>::HeightRecursive() const
		{
			return HeightOfRecursive(m_pRoot);
		}

		template <typename Type>
		size_t BinaryTree<Type>::HeightOf(const BinaryTreeNode<Type>* const p_pNode)
		{
			if (!p_pNode)
			{
				//throw ArgumentNullException();
				return 0;
			}

			size_t height = 0;
			Queue<BinaryTreeNode<Type>*> queue;
			queue.Push(p_pNode);
			queue.Push(nullptr); // add null as marker
			while (!queue.IsEmpty())
			{
				BinaryTreeNode<Type>* pCurrent = queue.Pop();
				// check if pCurrent is null, if yes, we have reached to the end of the
				// pCurrent level, increment the height by 1, and add the another
				// null as marker for next level
				if (!pCurrent)
				{
					// before adding null, check if queue is empty, which means we
					// have traveled all the levels
					if (!queue.IsEmpty())
					{
						queue.Push(nullptr);
					}
					++height;
				}
				else
				{
					// else add the children of extracted p_pRoot.
					if (pCurrent->LeftChild())
					{
						queue.Push(pCurrent->LeftChild());
					}
					if (pCurrent->RightChild())
					{
						queue.Push(pCurrent->RightChild());
					}
				}
			}
			return height;
		}

		template <typename Type>
		size_t BinaryTree<Type>::HeightOfRecursive(const BinaryTreeNode<Type>* const p_pNode)
		{
			if (!p_pNode)
			{
				//throw NullArgumentException();
				return 0;
			}
			return 1 + Utility::Max(HeightOfRecursive(p_pNode->LeftChild()), HeightOfRecursive(p_pNode->RightChild()));
		}

		template <typename Type>
		Array<Type> BinaryTree<Type>::InorderTraversal() const
		{
			Array<Type> result(m_size);

			if (!IsEmpty())
			{
				BinaryTreeNode<Type>* pCurrent = m_pRoot;

				Stack<BinaryTreeNode<Type>*> visiting;
				visiting.Push(pCurrent);
				Stack<bool> visited;
				visited.Push(false);
				while (!visiting.IsEmpty())
				{
					pCurrent = visiting.Pop();
					if (visited.Pop())
					{
						result.PushBack(pCurrent->key);
					}
					else
					{
						if (pCurrent->RightChild())
						{
							visiting.Push(pCurrent->RightChild());
							visited.Push(false);
						}
						visiting.Push(pCurrent);
						visited.Push(true);
						if (pCurrent->LeftChild())
						{
							visiting.Push(pCurrent->LeftChild());
							visited.Push(false);
						}
					}
				}
			}
			return result;
		}

		template <typename Type>
		Array<Type> BinaryTree<Type>::InorderTraversalRecursive() const
		{
			Array<Type> result(m_size);
			InorderTraversalRecursive(m_pRoot, result);
			return result;
		}

		template <typename Type>
		void BinaryTree<Type>::InorderTraversalRecursive(const BinaryTreeNode<Type>* const p_pRoot,
		                                                 Array<Type>& p_result)
		{
			if (!p_pRoot)
			{
				//throw NullPointerException();
				return;
			}
			InorderTraversalRecursive(p_pRoot->LeftChild(), p_result);
			p_result.PushBack(p_pRoot->key);
			InorderTraversalRecursive(p_pRoot->RightChild(), p_result);
		}

		template <typename Type>
		void BinaryTree<Type>::Insert(const Type& p_key) // TODO: Implement
		{
			if (IsEmpty())
			{
				m_pRoot = new BinaryTreeNode<Type>(p_key);
			}
			else
			{
				/*BinaryTreeNode<Type>* pCurrent = m_pRoot;

				while (pCurrent)
				{
					
				}*/
			}
			++m_size;
		}

		template <typename Type>
		void BinaryTree<Type>::InsertRecursive(const Type& p_key)
		{
			if (IsEmpty())
			{
				m_pRoot = new BinaryTreeNode<Type>(p_key);
				++m_size;
			}
			else
			{
				InsertRecursive(m_pRoot, p_key);
			}
		}

		template <typename Type>
		void BinaryTree<Type>::InsertRecursive(BinaryTreeNode<Type>* const p_pRoot, const Type& p_key)
		{
			// TODO: Implement
		}

		template <typename Type>
		ForwardList<BinaryTreeNode<Type>> BinaryTree<Type>::InternalNodesRecursive() const
		{
			ForwardList<BinaryTreeNode<Type>> result;
			InternalNodesRecursive(m_pRoot, result);
			return result;
		}

		template <typename Type>
		void BinaryTree<Type>::InternalNodesRecursive(const BinaryTreeNode<Type>* const p_pRoot,
		                                              ForwardList<BinaryTreeNode<Type>>& p_result)
		{
			if (!p_pRoot)
			{
				//throw NullArgumentException();
				return;
			}
			if (p_pRoot->HasChildren())
			{
				p_result.PushBack(*p_pRoot);
			}
			else
			{
				InternalNodesRecursive(p_pRoot->LeftChild(), p_result);
				InternalNodesRecursive(p_pRoot->RightChild(), p_result);
			}
			return p_result;
		}

		template <typename Type>
		bool BinaryTree<Type>::IsDegenetate() const
		{
			return IsDegenerate(m_pRoot);
		}

		template <typename Type>
		bool BinaryTree<Type>::IsDegenerate(const BinaryTreeNode<Type>* const p_pRoot)
		{
			if (p_pRoot)
			{
				if (!p_pRoot->HasOneChild())
				{
					return false;
				}
				IsDegenerate(p_pRoot->LeftChild());
				IsDegenerate(p_pRoot->RightChild());
			}
			return true;
		}

		template <typename Type>
		bool BinaryTree<Type>::IsEmpty() const
		{
			return !m_pRoot ? true : false;
		}

		template <typename Type>
		bool BinaryTree<Type>::IsFullRecursive() const
		{
			return IsFullRecursive(m_pRoot);
		}

		template <typename Type>
		bool BinaryTree<Type>::IsFullRecursive(const BinaryTreeNode<Type>* const p_pRoot)
		{
			if (p_pRoot)
			{
				if (!p_pRoot->HasChildren() || p_pRoot->HasTwoChildren())
				{
					return IsFullRecursive(p_pRoot->LeftChild()) && IsFullRecursive(p_pRoot->RightChild());
				}
			}
			return false;
		}

		template <typename Type>
		bool BinaryTree<Type>::IsPerfect() const
		{
			ForwardList<BinaryTreeNode<Type>> internals = InternalNodesRecursive();
			for (auto it = internals.Begin(); it != internals.End(); ++it)
			{
				if (!(*it).key.HasTwoChildren())
				{
					return false;
				}
			}

			ForwardList<BinaryTreeNode<Type>> leaves = LeafNodesRecursive();
			int depth = leaves.Front().Depth();
			for (auto it = leaves.Begin(); it != leaves.End(); ++it)
			{
				if ((*it).key.Depth() != depth)
				{
					return false;
				}
			}

			return true;
		}

		template <typename Type>
		ForwardList<BinaryTreeNode<Type>> BinaryTree<Type>::LeafNodesRecursive() const
		{
			ForwardList<BinaryTreeNode<Type>> result;
			LeafNodesRecursive(m_pRoot, result);
			return result;
		}

		template <typename Type>
		void BinaryTree<Type>::LeafNodesRecursive(const BinaryTreeNode<Type>* const p_pRoot,
		                                          ForwardList<BinaryTreeNode<Type>>& p_result)
		{
			if (!p_pRoot)
			{
				//throw ArgumentNullException();
				return;
			}

			if (!p_pRoot->HasChildren())
			{
				p_result.PushBack(*p_pRoot);
			}
			else
			{
				LeafNodesRecursive(p_pRoot->LeftChild(), p_result);
				LeafNodesRecursive(p_pRoot->RightChild(), p_result);
			}

			return p_result;
		}

		template <typename Type>
		void BinaryTree<Type>::MirrorRecursive()
		{
			MirrorRecursive(m_pRoot);
		}

		template <typename Type>
		void BinaryTree<Type>::MirrorRecursive(BinaryTreeNode<Type>* const p_pRoot)
		{
			if (!p_pRoot)
			{
				return;
			}

			MirrorRecursive(p_pRoot->LeftChild());
			MirrorRecursive(p_pRoot->RightChild());

			BinaryTreeNode<Type>* pTemp = p_pRoot->LeftChild();
			p_pRoot->SetLeftChild(p_pRoot->RightChild());
			p_pRoot->SetRightChild(pTemp);
		}

		template <typename Type>
		Array<Type> BinaryTree<Type>::PostorderTraversal() const
		{
			Array<Type> result(m_size);

			if (!IsEmpty())
			{
				BinaryTreeNode<Type>* pCurrent = m_pRoot;

				Stack<BinaryTreeNode<Type>*> visiting;
				visiting.Push(pCurrent);
				Stack<bool> visited;
				visited.Push(false);
				while (!visiting.IsEmpty())
				{
					pCurrent = visiting.Pop();
					if (pCurrent)
					{
						if (visited.Pop())
						{
							result.PushBack(pCurrent->key);
						}
						else
						{
							visiting.Push(pCurrent);
							visited.Push(true);
							if (pCurrent->RightChild())
							{
								visiting.Push(pCurrent->RightChild());
								visited.Push(false);
							}
							if (pCurrent->LeftChild())
							{
								visiting.Push(pCurrent->LeftChild());
								visited.Push(false);
							}
						}
					}
				}
			}
			return result;
		}

		template <typename Type>
		Array<Type> BinaryTree<Type>::PostorderTraversalRecursive() const
		{
			Array<Type> result(m_size);
			PostorderTraversalRecursive(m_pRoot, result);
			return result;
		}

		template <typename Type>
		void BinaryTree<Type>::PostorderTraversalRecursive(const BinaryTreeNode<Type>* const p_pRoot,
		                                                   Array<Type>& p_result)
		{
			if (!p_pRoot)
			{
				//throw ArgumentNullException();
				return;
			}
			PostorderTraversalRecursive(p_pRoot->LeftChild(), p_result);
			PostorderTraversalRecursive(p_pRoot->RightChild(), p_result);
			p_result.PushBack(p_pRoot->key);
		}

		template <typename Type>
		Array<Type> BinaryTree<Type>::PreorderTraversal() const
		{
			Array<Type> result(m_size);

			if (!IsEmpty())
			{
				BinaryTreeNode<Type>* pCurrent = m_pRoot;

				Stack<BinaryTreeNode<Type>*> visiting;
				visiting.Push(pCurrent);
				while (!visiting.IsEmpty())
				{
					pCurrent = visiting.Pop();
					result.PushBack(pCurrent->key);
					if (pCurrent->RightChild())
					{
						visiting.Push(pCurrent->RightChild());
					}
					if (pCurrent->LeftChild())
					{
						visiting.Push(pCurrent->LeftChild());
					}
				}
			}
			return result;
		}

		template <typename Type>
		Array<Type> BinaryTree<Type>::PreorderTraversalRecursive() const
		{
			Array<Type> result(m_size);
			PreorderTraversalRecursive(m_pRoot, result);
			return result;
		}

		template <typename Type>
		void BinaryTree<Type>::PreorderTraversalRecursive(const BinaryTreeNode<Type>* const p_pRoot,
		                                                  Array<Type>& p_result)
		{
			if (!p_pRoot)
			{
				//throw ArgumentNullException();
				return;
			}
			p_result.PushBack(p_pRoot->key);
			PreorderTraversalRecursive(p_pRoot->LeftChild(), p_result);
			PreorderTraversalRecursive(p_pRoot->RightChild(), p_result);
		}

		template <typename Type>
		void BinaryTree<Type>::Purge()
		{
			DestroyRecursive();
		}

		template <typename Type>
		size_t BinaryTree<Type>::SizeOfRecursive(const BinaryTreeNode<Type>* const p_pRoot)
		{
			if (!p_pRoot)
			{
				return 0;
			}
			return 1 + SizeOfRecursive(p_pRoot->LeftChild()) + SizeOfRecursive(p_pRoot->RightChild());
		}

		template <typename Type>
		String BinaryTree<Type>::ToString() const
		{
			return ToStringRecursive();
		}

		template <typename Type>
		String BinaryTree<Type>::ToStringRecursive() const
		{
			String result;
			if (!IsEmpty())
			{
				result += "|__0__";
				ToStringRecursive(m_pRoot, result);
			}
			result.Backspace();
			return result;
		}

		template <typename Type>
		void BinaryTree<Type>::ToStringRecursive(const BinaryTreeNode<Type>* const p_pRoot, String& p_result)
		// TODO: Improve
		{
			p_result += String::ValueOf(*p_pRoot);
			p_result += "\n";

			if (p_pRoot->LeftChild())
			{
				for (size_t i = 0; i < p_pRoot->LeftChild()->Depth() /*-1*/; ++i)
				{
					p_result += "      ";
				}
				p_result += "|__L__";
				ToStringRecursive(p_pRoot->LeftChild(), p_result);
			}
			if (p_pRoot->RightChild())
			{
				for (size_t i = 0; i < p_pRoot->RightChild()->Depth() /*-1*/; ++i)
				{
					p_result += "      ";
				}
				p_result += "|__R__";
				ToStringRecursive(p_pRoot->RightChild(), p_result);
			}
		}

		template <typename Type>
		BinaryTree<Type>& BinaryTree<Type>::operator=(const BinaryTree& p_tree)
		{
			if (&p_tree != this)
			{
				DestroyRecursive();
				m_pRoot = CloneRecursive(p_tree.m_pRoot, nullptr);
				m_size = p_tree.m_size;
			}
			return *this;
		}

		template <typename Type>
		bool BinaryTree<Type>::operator<(const BinaryTree& p_tree) const
		{
			return m_size < p_tree.m_size;
		}

		template <typename Type>
		bool BinaryTree<Type>::operator>(const BinaryTree& p_tree) const
		{
			return m_size > p_tree.m_size;
		}

		template <typename Type>
		bool BinaryTree<Type>::operator==(const BinaryTree& p_tree) const
		{
			if (m_size != p_tree.m_size)
			{
				return false;
			}
			return InorderTraversal() != p_tree.InorderTraversal();
		}
	}
}
