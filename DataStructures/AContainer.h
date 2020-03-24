#pragma once

#include "Object.h"

#include "../Interfaces/IContainer.h"

namespace LCU
{
	inline namespace DataStructures
	{
		/**
		 * AContainer Class
		 *
		 * @project DataStructures
		 * @author Amine MAYOUF
		 */
		template <typename Type>
		class AContainer : public Object, public IContainer<Type>
		{
		protected:
			size_t m_size;

		public:
			AContainer();
			AContainer(size_t p_size);

			size_t Size() const;
			using Object::ToString;
		};

		template <typename Type>
		AContainer<Type>::AContainer() : m_size(0)
		{
		}

		template <typename Type>
		AContainer<Type>::AContainer(size_t p_size) : m_size(p_size)
		{
		}

		template <typename Type>
		size_t AContainer<Type>::Size() const
		{
			return m_size;
		}
	}
}
