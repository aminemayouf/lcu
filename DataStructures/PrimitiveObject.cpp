#include "PrimitiveObject.h"

#include "../Algorithms/Utility.h"

namespace LCU
{
	inline namespace DataStructures
	{
		size_t PrimitiveObject::HashCode() const
		{
			return Utility::HashCodeOf(*this);
		}

		const char* PrimitiveObject::Name() const
		{
			return Utility::NameOf(*this);
		}

		const char* PrimitiveObject::ToPrimitiveString() const
		{
			return Utility::NameOf(*this);
		}
	}
}
