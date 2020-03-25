#pragma once

#include "Array.h"
#include "DisjointSet.h"
#include "Edge.h"
#include "Matrix.h"
#include "Vertex.h"

namespace LCU
{
	inline namespace DataStructures
	{
		/**
		 * Graph Class
		 *
		 * @project DataStructures
		 * @author Amine MAYOUF
		 */
		template <typename Type>
		class UndirectedGraph : public AContainer<Vertex<Type>>
		{
		protected:
			using AContainer<Vertex<Type>>::m_size; // The number of vertices
			Array<Edge<Type>> m_edges;

		public:
			UndirectedGraph();
			explicit UndirectedGraph(size_t p_vertices, size_t p_edges);
			explicit UndirectedGraph(const Matrix<bool>& p_adjacencyMatrix);
			virtual ~UndirectedGraph();

			using AContainer<Vertex<Type>>::Size;

			//Array<Vertex<Type>> Vertices() const;
			Array<Edge<Type>> Edges() const;

			// A
			bool AreAdjacents(size_t p_firstVertexId, size_t p_secondVertexId) const;
			bool AreIncidents(size_t p_firstVertexId, size_t p_secondVertexId) const;
			// C
			virtual void Connect(size_t p_firstVertexId, size_t p_secondVertexId, int p_weight);
			virtual void Connect(Vertex<Type>* p_pFirstVertex, Vertex<Type>* p_pSecondVertex, int p_weight);
			bool Contains(const Vertex<Type>& p_vertex) const override;
			virtual bool Contains(const Edge<Type>* p_pEdge) const;
			// D
			size_t Degree() const;
			// I
			bool IsAcyclic() const;
			bool IsBipartite(const Array<bool>& setOfVertices) const;
			bool IsComplete() const;
			bool IsEmpty() const override;
			bool IsMultigraph() const;
			size_t IndexOf(const Edge<Type>& p_edge) const;
			bool IsRegular() const;
			bool IsSimple() const;
			// K
			UndirectedGraph* kruskalMST() const;
			static UndirectedGraph* kruskalMST(const UndirectedGraph& p_graph);
			// O
			//size_t Order() const;
			// P
			void Purge() override;
			// S
			void SortEdges();
			// T
			//Matrix<size_t> ToAdjacencyMatrix() const;
			String ToString() const override;
			// V
			//Iterator VertexAt(size_t p_vertexIndex) const;
		};

		template <typename Type>
		UndirectedGraph<Type>::UndirectedGraph()
			: AContainer(), m_edges()
		{
		}

		template <typename Type>
		UndirectedGraph<Type>::UndirectedGraph(size_t p_vertices, size_t p_edges)
			: m_edges(p_edges)
		{
			m_size = p_vertices;
		}

		template <typename Type>
		UndirectedGraph<Type>::UndirectedGraph(const Matrix<bool>& p_adjacencyMatrix) : AContainer()
		{
			if (!p_adjacencyMatrix.IsSquare())
			{
				return;
			}

			m_size = p_adjacencyMatrix.Rows();
			m_edges.Resize(p_adjacencyMatrix.Rows() * p_adjacencyMatrix.Cols());
			for (size_t i = 0; i < p_adjacencyMatrix.Rows(); ++i)
			{
				for (size_t j = 0; j < p_adjacencyMatrix.Cols(); ++j)
				{
					if (p_adjacencyMatrix.ValueAt(i, j) != false)
					{
						Connect(i, j, 0);
					}
				}
			}
		}

		template <typename Type>
		UndirectedGraph<Type>::~UndirectedGraph()
		{
		}

		//template <typename Type>
		//Array<Vertex<Type>> Graph<Type>::Vertices() const
		//{
		//	return m_vertices;
		//}

		template <typename Type>
		Array<Edge<Type>> UndirectedGraph<Type>::Edges() const
		{
			return m_edges;
		}

		template <typename Type>
		bool UndirectedGraph<Type>::AreAdjacents(size_t p_firstVertexId, size_t p_secondVertexId) const
		{
			if (p_firstVertexId > m_size || p_secondVertexId > m_size)
			{
				return false;
			}
			return false;
		}

		template <typename Type>
		bool UndirectedGraph<Type>::AreIncidents(size_t p_firstVertexId, size_t p_secondVertexId) const
		{
			return AreAdjacents(p_firstVertexId, p_secondVertexId);
		}

		template <typename Type>
		void UndirectedGraph<Type>::Connect(size_t p_firstVertexId, size_t p_secondVertexId, int p_weight)
		{
			if (p_firstVertexId > m_size || p_secondVertexId > m_size)
			{
				return;
			}
			m_edges.PushBack(Edge<Type>(p_firstVertexId, p_secondVertexId, p_weight));
		}

		template <typename Type>
		void UndirectedGraph<Type>::Connect(Vertex<Type>* p_pFirstVertex, Vertex<Type>* p_pSecondVertex, int p_weight)
		{
			if (p_pFirstVertex->Id() > m_size || p_pSecondVertex->Id() > m_size)
			{
				return;
			}
			m_edges.PushBack(Edge<Type>(p_pFirstVertex, p_pFirstVertex, p_weight));
		}

		template <typename Type>
		bool UndirectedGraph<Type>::Contains(const Vertex<Type>& p_vertex) const
		{
			return false;
		}

		template <typename Type>
		bool UndirectedGraph<Type>::Contains(const Edge<Type>* const p_pEdge) const
		{
			return false;
		}

		template <typename Type>
		size_t UndirectedGraph<Type>::Degree() const
		{
			size_t maxDegree = 0;
			return maxDegree;
		}

		template <typename Type>
		bool UndirectedGraph<Type>::IsAcyclic() const
		{
			return false;
		}

		template <typename Type>
		bool UndirectedGraph<Type>::IsBipartite(const Array<bool>& setOfVertices) const
		{
			return true;
		}

		template <typename Type>
		bool UndirectedGraph<Type>::IsComplete() const
		{
			return true;
		}

		template <typename Type>
		bool UndirectedGraph<Type>::IsEmpty() const
		{
			return m_edges.IsEmpty();
		}

		template <typename Type>
		bool UndirectedGraph<Type>::IsMultigraph() const
		{
			return !IsSimple();
		}

		template <typename Type>
		size_t UndirectedGraph<Type>::IndexOf(const Edge<Type>& p_edge) const
		{
			return 0;
		}

		template <typename Type>
		bool UndirectedGraph<Type>::IsRegular() const
		{
			return true;
		}

		template <typename Type>
		bool UndirectedGraph<Type>::IsSimple() const
		{
			return true;
		}

		template <typename Type>
		UndirectedGraph<Type>* UndirectedGraph<Type>::kruskalMST() const
		{
			return kruskalMST(*this);
		}

		template <typename Type>
		UndirectedGraph<Type>* UndirectedGraph<Type>::kruskalMST(const UndirectedGraph<Type>& p_graph)
		{
			int V = p_graph.Size();
			int E = p_graph.Size() - 1;
			UndirectedGraph* pResult = new UndirectedGraph(V, E);
			// Step 1: Sort all the edges in non-decreasing 
			// order of their weight. If we are not allowed to 
			// change the given graph, we can create a copy of 
			// array of edges 
			p_graph.Edges().Sort();
			// Allocate memory for creating V subsets
			DisjointSet<int> set(V);
			// Create V subsets with single elements 
			for (int v = 0; v < V; ++v)
			{
				set.subsets[v].parent = v;
				set.subsets[v].rank = 0;
			}

			int e = 0; // An index variable, used for edges[]
			int i = 0; // An index variable, used for sorted edges 
			// Number of edges to be taken is equal to V-1 
			while (e < E && i < p_graph.Edges().Size())
			{
				// Step 2: Pick the smallest edge. And increment 
				// the index for next iteration 
				Edge<int> nextEdge = p_graph.Edges()[i];
				++i;

				int x = set.find(nextEdge.src);
				int y = set.find(nextEdge.dest);

				// If including this edge does't cause cycle, 
				// include it in 'edges' and increment the index 
				// of 'edges' for next edge 
				if (x != y)
				{
					pResult->Edges()[e] = nextEdge;
					++e;
					set.unionOf(x, y);
				}
				// Else discard the next_edge 
			}

			return pResult;
		}

		//template <typename Type>
		//size_t Graph<Type>::Order() const
		//{
		//	return m_size;
		//}

		template <typename Type>
		void UndirectedGraph<Type>::Purge()
		{
			m_edges.Purge();
		}

		template <typename Type>
		void UndirectedGraph<Type>::SortEdges()
		{
			m_edges.Sort();
		}

		//template <typename Type>
		//Matrix<size_t> Graph<Type>::ToAdjacencyMatrix() const
		//{
		//	Matrix<size_t> p_adjacencyMatrix(m_size, m_size);

		//	Vertex<Type>* pCurrentVertex = m_pInitial;
		//	Successor* pCurrentSuccessor;

		//	while (pCurrentVertex)
		//	{
		//		pCurrentSuccessor = pCurrentVertex->Successors();

		//		while (pCurrentSuccessor)
		//		{
		//			p_adjacencyMatrix.Assign(pCurrentSuccessor->Edge()->weight, pCurrentVertex->key, pCurrentSuccessor->key);

		//			pCurrentSuccessor = pCurrentSuccessor->Next();
		//		}

		//		pCurrentVertex = pCurrentVertex->Next();
		//	}

		//	return p_adjacencyMatrix;
		//}

		template <typename Type>
		String UndirectedGraph<Type>::ToString() const
		{
			return m_edges.ToString();
		}

		//template <typename Type>
		//typename Graph<Type>::Iterator Graph<Type>::VertexAt(size_t p_vertexIndex) const
		//{
		//	if (p_vertexIndex > m_size)
		//	{
		//		//throw ArgumentOutOfRangeException();
		//		return Iterator(nullptr);
		//	}

		//	Vertex<Type>* pCurrentVertex = m_pInitial;

		//	if (pCurrentVertex)
		//	{
		//		while (pCurrentVertex && pCurrentVertex->key != p_vertexIndex)
		//		{
		//			pCurrentVertex = pCurrentVertex->Next();
		//		}
		//	}

		//	return Iterator(pCurrentVertex);
		//}
	}
}
