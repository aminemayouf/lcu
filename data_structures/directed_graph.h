#pragma once


#include "forward_list.h"
#include "undirected_graph.h"

namespace lcu
{
	inline namespace data_structures
	{
		/**
		 * Directed Graph Class
		 *
		 * @project data_structures
		 * @author Amine MAYOUF
		 */
		template <typename Type>
		class DirectedGraph : public UndirectedGraph<Type>
		{
		public:
			explicit DirectedGraph(const Matrix<size_t>& p_adjacencyMatrix);
			// B
			ForwardList<size_t> BreadthFirstTraversal(size_t p_startVertex = 0) const;
			// C
			void Connect(size_t p_startVertex, size_t p_arrivalVertex, size_t p_arcWeight = 1) const;
			// D
			ForwardList<size_t> DepthFirstTraversal(size_t p_startVertex = 0) const;
			// S
			Array<size_t> ShortestPaths(size_t p_startVertex) const;
		};

		template <typename Type>
		DirectedGraph<Type>::DirectedGraph(const Matrix<size_t>& p_adjacencyMatrix) : UndirectedGraph()
		{
			if (!p_adjacencyMatrix.IsSquare())
			{
				//throw UnsupportedOperationException();
				return;
			}

			AddVertices(p_adjacencyMatrix.Rows());

			for (size_t i = 0; i < p_adjacencyMatrix.Rows(); ++i)
			{
				for (size_t j = 0; j < p_adjacencyMatrix.Cols(); ++j)
				{
					if (p_adjacencyMatrix.ValueAt(i, j) != 0)
					{
						Connect(i, j, p_adjacencyMatrix.ValueAt(i, j));
					}
				}
			}
		}

		template <typename Type>
		ForwardList<size_t> DirectedGraph<Type>::BreadthFirstTraversal(size_t p_startVertex) const
		{
			ForwardList<size_t> result;

			if (IsEmpty())
			{
				return result;
			}

			Array<bool> array(m_size);
			array[p_startVertex] = true;

			Queue<size_t> queue;
			queue.Push(p_startVertex);

			size_t currentId;
			Vertex<Type>* pCurrentVertex;
			Successor<Type>* pCurrentSuccessor;

			while (!queue.IsEmpty())
			{
				currentId = queue.Pop();
				result.PushBack(currentId);
				pCurrentVertex = m_pInitial;

				while (pCurrentVertex)
				{
					if (pCurrentVertex->key == currentId)
					{
						pCurrentSuccessor = pCurrentVertex->Successors();
						while (pCurrentSuccessor)
						{
							if (!array[pCurrentSuccessor->key])
							{
								array[pCurrentSuccessor->key] = true;
								queue.Push(pCurrentSuccessor->key);
							}
							pCurrentSuccessor = pCurrentSuccessor->Next();
						}
						break;
					}
					pCurrentVertex = pCurrentVertex->Next();
				}
			}

			return result;
		}

		template <typename Type>
		void DirectedGraph<Type>::Connect(size_t p_startVertex, size_t p_arrivalVertex, size_t p_arcWeight) const
		{
			if (p_startVertex > m_size || p_arrivalVertex > m_size)
			{
				//throw ArgumentOutOfRangeException();
				return;
			}
			Vertex<Type>* pCurrentVertex = &*VertexAt(p_startVertex);
			pCurrentVertex->SetSuccessors(
				new Successor<Type>(p_arrivalVertex, p_arcWeight, pCurrentVertex->Successors()));

			//++m_edges;
		}

		template <typename Type>
		ForwardList<size_t> DirectedGraph<Type>::DepthFirstTraversal(size_t p_startVertex) const
		{
			ForwardList<size_t> result;

			if (IsEmpty())
			{
				return result;
			}

			Array<bool> array(m_size);
			array[p_startVertex] = true;

			Stack<size_t> stack;
			stack.Push(p_startVertex);

			size_t currentId = stack.Top();

			result.PushBack(currentId);

			Vertex<Type>* pCurrentVertex;
			Successor<Type>* pCurrentSuccessor;

			while (!stack.IsEmpty())
			{
				pCurrentVertex = m_pInitial;
				while (pCurrentVertex)
				{
					if (pCurrentVertex->key == currentId)
					{
						pCurrentSuccessor = pCurrentVertex->Successors();
						while (pCurrentSuccessor && array[pCurrentSuccessor->key])
						{
							pCurrentSuccessor = pCurrentSuccessor->Next();
						}
						if (!pCurrentSuccessor)
						{
							stack.Pop();
							if (!stack.IsEmpty())
							{
								currentId = stack.Top();
							}
						}
						else
						{
							array[pCurrentSuccessor->key] = true;
							stack.Push(pCurrentSuccessor->key);
							currentId = pCurrentSuccessor->key;
							result.PushBack(currentId);
						}
					}
					pCurrentVertex = pCurrentVertex->Next();
				}
			}

			return result;
		}

		template <typename Type>
		Array<size_t> DirectedGraph<Type>::ShortestPaths(size_t p_startVertex) const
		{
			if (IsEmpty())
			{
				return Array<size_t>();
			}

			const Array<bool> visited(m_size, false);
			Array<int> paths(m_size, -1);
			Array<size_t> distances(m_size, static_cast<size_t>(INFINITY));

			distances[p_startVertex] = 0;

			size_t currentKey;
			Vertex<Type>* pCurrentVertex;
			Successor<Type>* pCurrentSuccessor;

			while (true)
			{
				currentKey = -1;
				for (size_t i(0); i < m_size; ++i)
				{
					if (!visited[i] && distances[i] < distances[currentKey])
					{
						currentKey = i;
					}
				}
				if (currentKey == -1)
				{
					break;
				}

				pCurrentVertex = &*VertexAt(currentKey);
				pCurrentSuccessor = pCurrentVertex->Successors();
				while (pCurrentSuccessor)
				{
					distances[pCurrentSuccessor->key] = static_cast<size_t>(Utility::Min(
						distances[pCurrentSuccessor->key],
						distances[currentKey] + pCurrentSuccessor->Edge()->weight));

					pCurrentSuccessor = pCurrentSuccessor->Next();
				}

				visited[currentKey] = true;
			}

			return distances;
		}
	}
}
