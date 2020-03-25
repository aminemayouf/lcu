#pragma once

#include "Object.h"

namespace lcu
{
	inline namespace data_structures
	{
		/**
		 * Node Class
		 *
		 * @project DataStructures
		 * @author Amine MAYOUF
		 */
		template <typename Type>
		class Node : public Object, public IComparable<Node<Type>>
		{
		public:
			Type key;

			explicit Node(const Type& p_key);
			virtual ~Node() = default;

			String ToString() const override;
			// #
			bool operator <(const Node& p_node) const override;
			bool operator >(const Node& p_node) const override;
			bool operator ==(const Node& p_node) const override;
		};

		template <typename Type>
		Node<Type>::Node(const Type& p_key) : key(p_key)
		{
		}

		template <typename Type>
		String Node<Type>::ToString() const
		{
			String result("[");
			result += String::ValueOf(key);
			result += "]";
			return result;
		}

		template <typename Type>
		bool Node<Type>::operator<(const Node& p_node) const
		{
			return key < p_node.key;
		}

		template <typename Type>
		bool Node<Type>::operator>(const Node& p_node) const
		{
			return key > p_node.key;
		}

		template <typename Type>
		bool Node<Type>::operator==(const Node& p_node) const
		{
			return key == p_node.key;
		}
	}
}
