#pragma once

#include "array.h"
#include "subset.h"

namespace lcu
{
	inline namespace data_structures
	{
		/**
		 * DisjointSet Class
		 *
		 * @project data_structures
		 * @author Amine MAYOUF
		 */
		template <typename Type>
		class DisjointSet : public AContainer<Subset<Type>>
		{
		protected:
			using AContainer<Subset<Type>>::m_size; // The number of vertices

		public:
			Subset<Type>* subsets;

			DisjointSet(int p_subsets);
			~DisjointSet();

			// C
			bool Contains(const Subset<Type>& p_value) const override { return false; }
			// I
			bool IsEmpty() const override { return subsets == nullptr; }

			// P
			void Purge() override
			{
				delete[] subsets;
				m_size = 0;
			};

			/**
			 * A utility function to find a set of an element using path compression technique
			 *
			 * @param p_i The element to find the subset of.
			 */
			int find(int p_i);

			// A function that does union of two sets of x and y 
			// (uses union by rank) 
			/**
			* A function that does the union of two sets
			*
			* @param p_x The first set.
			* @param p_y The second set.
			*/
			void unionOf(int p_x, int p_y);
		};

		template <typename Type>
		DisjointSet<Type>::DisjointSet(int p_subsets) : AContainer(p_subsets)
		{
			subsets = new Subset<int>[p_subsets];
		}

		template <typename Type>
		DisjointSet<Type>::~DisjointSet()
		{
			delete[] subsets;
		}

		template <typename Type>
		int DisjointSet<Type>::find(int p_i)
		{
			if (p_i >= m_size)
			{
				// Index out of range
			}
			// Find the root and make as as parent of i (path compression) 
			if (subsets[p_i].parent != p_i)
			{
				subsets[p_i].parent = find(subsets[p_i].parent);
			}
			return subsets[p_i].parent;
		}

		template <typename Type>
		void DisjointSet<Type>::unionOf(int p_x, int p_y)
		{
			int xroot = find(p_x);
			int yroot = find(p_y);
			// Attach the tree with the smaller rank under the root of a high rank tree (Union by Rank) 
			if (subsets[xroot].rank < subsets[yroot].rank)
			{
				subsets[xroot].parent = yroot;
			}
			else if (subsets[xroot].rank > subsets[yroot].rank)
			{
				subsets[yroot].parent = xroot;
			}
				// If ranks are the same, make one as root and increment its rank by one 
			else
			{
				subsets[yroot].parent = xroot;
				++subsets[xroot].rank;
			}
		}
	}
}
