#pragma once

#include "Vertex.h"

namespace lcu
{
	inline namespace data_structures
	{
		/**
		 * Edge Class
		 *
		 * @project DataStructures
		 * @author Amine MAYOUF
		 */
		template <typename Type>
		class Edge : public Object, public IComparable<Edge<Type>>
		{
		public:
			int src;
			Vertex<Type>* source;
			int dest;
			Vertex<Type>* destination;
			int weight;

			Edge();
			Edge(const Edge& p_edge);
			explicit Edge(const size_t& p_firstVertexId, const size_t& p_secondVertexId, int p_weight = 0);
			explicit Edge(Vertex<Type>* p_pFirstVertex, Vertex<Type>* p_pSecondVertex, int p_weight = 0);
			virtual ~Edge();

			String ToString() const override;

			Edge& operator =(const Edge& p_edge);
			bool operator <(const Edge& p_edge) const override;
			bool operator >(const Edge& p_edge) const override;
			bool operator ==(const Edge& p_edge) const override;
		};

		template <typename Type>
		Edge<Type>::Edge() : src(0), source(nullptr), dest(0), destination(nullptr), weight(0)
		{
		}

		template <typename Type>
		Edge<Type>::Edge(const Edge& p_edge)
		{
			source = p_edge.source;
			destination = p_edge.destination;
			weight = p_edge.weight;
		}

		template <typename Type>
		Edge<Type>::Edge(const size_t& p_firstVertexId, const size_t& p_secondVertexId, int p_weight)
			: src(p_firstVertexId), source(new Vertex<Type>(p_firstVertexId)), dest(p_secondVertexId),
			  destination(new Vertex<Type>(p_secondVertexId)), weight(p_weight)
		{
		}

		template <typename Type>
		Edge<Type>::Edge(Vertex<Type>* p_pFirstVertex, Vertex<Type>* p_pSecondVertex, int p_weight)
			: weight(p_weight)
		{
			source = p_pFirstVertex;
			destination = p_pSecondVertex;
		}

		template <typename Type>
		Edge<Type>::~Edge()
		{
		}

		template <typename Type>
		String Edge<Type>::ToString() const
		{
			String result = "[s(";
			result += source ? String::ValueOf(source->Id()) : "-1";
			result += "),d(";
			result += destination ? String::ValueOf(destination->Id()) : "-1";
			result += "),w(";
			result += String::ValueOf(weight);
			result += ")]";
			return result;
		}

		template <typename Type>
		Edge<Type>& Edge<Type>::operator =(const Edge<Type>& p_edge)
		{
			if (&p_edge != this)
			{
				source = p_edge.source;
				destination = p_edge.destination;
				weight = p_edge.weight;
			}
			return *this;
		}

		template <typename Type>
		bool Edge<Type>::operator ==(const Edge<Type>& p_edge) const
		{
			return weight == p_edge.weight;
		}

		template <typename Type>
		bool Edge<Type>::operator <(const Edge<Type>& p_edge) const
		{
			return weight < p_edge.weight;
		}

		template <typename Type>
		bool Edge<Type>::operator >(const Edge<Type>& p_edge) const
		{
			return weight > p_edge.weight;
		}
	}
}
