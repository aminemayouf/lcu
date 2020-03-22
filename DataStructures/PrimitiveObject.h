#pragma once

#include "../Interfaces/IPrintable.h"

namespace LCU
{
	inline namespace DataStructures
	{
		/**
		 * PrimitiveObject Class
		 *
		 * @project DataStructures
		 * @author Amine MAYOUF
		 */
		class PrimitiveObject : public IPrintable
		{
		public:
			virtual ~PrimitiveObject() = default;

			// H
			size_t HashCode() const;
			// N
			const char* Name() const;
			//T
			const char* ToPrimitiveString() const override;
		};
	}
}
