#include "Object.h"

namespace LCU
{
	inline namespace DataStructures
	{
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
