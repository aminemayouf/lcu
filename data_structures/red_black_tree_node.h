#pragma once

#include "binary_tree_node.h"

namespace lcu
{
	inline namespace data_structures
	{
		/**
		 * RedBlackTreeNode Class
		 *
		 * @project data_structures
		 * @author Amine MAYOUF
		 */
		template <typename Type>
		class RedBlackTreeNode : public BinaryTreeNode<Type>
		{
			enum Color
			{
				Red,
				Black
			};

		public:
			RedBlackTreeNode(const Type& p_key,
			                 Color p_color,
			                 RedBlackTreeNode* p_pParent = nullptr,
			                 RedBlackTreeNode* p_pLeftChild = nullptr,
			                 RedBlackTreeNode* p_pRightChild = nullptr);
		};

		template <typename Type>
		RedBlackTreeNode<Type>::RedBlackTreeNode(const Type& p_key,
		                                         Color p_color,
		                                         RedBlackTreeNode* p_pParent,
		                                         RedBlackTreeNode* p_pLeftChild,
		                                         RedBlackTreeNode* p_pRightChild) : BinaryTreeNode(
			p_key, p_pParent, p_pLeftChild, p_pRightChild)
		{
		}
	}
}
