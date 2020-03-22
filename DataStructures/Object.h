#pragma once

#include "PrimitiveObject.h"
#include "Str.h"

namespace LCU
{
	inline namespace DataStructures
	{
		/**
		 * Object Class
		 *
		 * @project DataStructures
		 * @author Amine MAYOUF
		 */
		class Object : public PrimitiveObject
		{
			// T
			const char* ToPrimitiveString() const override;
		public:
			virtual String ToString() const;
		};
	}
}
