#pragma once

#include <ostream>

namespace lcu
{
	inline namespace interfaces
	{
		/**
		 * IPrintable Interface
		 *
		 * @project Interfaces
		 * @author Amine MAYOUF
		 */
		class IPrintable
		{
		public:
			IPrintable() = default;
			virtual ~IPrintable() = default;

			virtual const char* ToPrimitiveString() const = 0;

			friend std::ostream& operator <<(std::ostream& p_out, const IPrintable& p_printableObject);
		};

		inline std::ostream& operator <<(std::ostream& p_out, const IPrintable& p_printableObject)
		{
			return p_out << p_printableObject.ToPrimitiveString();
		}
	}
}
