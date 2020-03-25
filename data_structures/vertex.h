#pragma once

#include "array.h"
#include "node.h"

namespace lcu
{
	inline namespace data_structures
	{
		/**
		 * Vertex Class
		 *
		 * @project data_structures
		 * @author Amine MAYOUF
		 */
		template <typename Type>
		class Vertex : public Node<Type>, public IComparable<Vertex<Type>>
		{
			size_t m_id;

		public:
			explicit Vertex(const size_t& p_id, const Type& p_key = 0);
			~Vertex() = default;

			size_t Id() const;
			Array<Vertex>* Neighbors() const;

			// A
			void AddNeighbor(const Vertex& p_neighbor);
			// D
			/**
			 * Returns the degree (or valency) of the vertex:
			 * A vertex of degree zero (w/ no edge connected to it) is called "isolated".
			 * A vertex of degree one (connected to a single edge) is called "pendant".
			 * 
			 * @return The number of edges having one end in the top.
			 */
			size_t Degree() const;
			// I
			bool IsAdjacent(const Vertex& p_vertex) const;
			bool IsIncident(const Vertex& p_vertex) const;
			bool IsPendant() const;
			bool IsIsolated() const;

			Vertex& operator =(const Vertex& p_vertex);
			bool operator <(const Vertex& p_edge) const override;
			bool operator >(const Vertex& p_edge) const override;
			bool operator ==(const Vertex& p_edge) const override;
		};

		template <typename Type>
		Vertex<Type>::Vertex(const size_t& p_id, const Type& p_key)
			: Node<Type>(p_key), m_id(p_id)
		{
		}

		template <typename Type>
		size_t Vertex<Type>::Id() const
		{
			return m_id;
		}

		template <typename Type>
		Array<Vertex<Type>>* Vertex<Type>::Neighbors() const
		{
			return nullptr;
		}

		template <typename Type>
		void Vertex<Type>::AddNeighbor(const Vertex<Type>& p_neighbor)
		{
		}

		template <typename Type>
		size_t Vertex<Type>::Degree() const
		{
			size_t i = 0;
			/*Successor<Type>* pCurrent = m_pSuccessors;
			while (pCurrent)
			{
				if (pCurrent->key == key)
				{
					i += 2;
				}
				else
				{
					++i;
				}
				pCurrent = pCurrent->Next();
			}*/
			return i;
		}

		template <typename Type>
		bool Vertex<Type>::IsAdjacent(const Vertex<Type>& p_vertex) const
		{
			return false;
		}

		template <typename Type>
		bool Vertex<Type>::IsIncident(const Vertex<Type>& p_vertex) const
		{
			return IsAdjacent(p_vertex);
		}

		template <typename Type>
		bool Vertex<Type>::IsPendant() const
		{
			return Degree() == 1;
		}

		template <typename Type>
		bool Vertex<Type>::IsIsolated() const
		{
			return true;
		}

		template <typename Type>
		Vertex<Type>& Vertex<Type>::operator =(const Vertex<Type>& p_vertex)
		{
			if (&p_vertex != this)
			{
				source = p_vertex.source;
				destination = p_vertex.destination;
				weight = p_vertex.weight;
			}
			return *this;
		}

		template <typename Type>
		bool Vertex<Type>::operator ==(const Vertex<Type>& p_vertex) const
		{
			return m_id == p_vertex.m_id;
		}

		template <typename Type>
		bool Vertex<Type>::operator <(const Vertex<Type>& p_vertex) const
		{
			return m_id < p_vertex.m_id;
		}

		template <typename Type>
		bool Vertex<Type>::operator >(const Vertex<Type>& p_vertex) const
		{
			return m_id > p_vertex.m_id;
		}
	}
}
