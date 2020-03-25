#pragma once

#include "primitive_object.h"
#include "str.h"

namespace lcu
{
	inline namespace data_structures
	{
		/**
		 * Object Class
		 *
		 * @project data_structures
		 * @author Amine MAYOUF
		 */
		class Object : public PrimitiveObject
		{
			// T
			const char* ToPrimitiveString() const override;
		public:
			virtual String ToString() const;
		};

		const char* Object::ToPrimitiveString() const
		{
			return ToString().ToPrimitiveString();
		}

		String Object::ToString() const
		{
			return PrimitiveObject::ToPrimitiveString();
		}
	}
}
