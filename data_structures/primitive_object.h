#pragma once

#include "../algorithms/utility.h"
#include "../interfaces/printable.h"

namespace lcu
{
	inline namespace data_structures
	{
		/**
		 * PrimitiveObject Class
		 *
		 * @project data_structures
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
