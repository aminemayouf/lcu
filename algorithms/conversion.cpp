#include "conversion.h"
#include "validation.h"

namespace lcu
{
	inline namespace algorithms
	{
		int Conversion::ToASCII(char p_primitiveChar)
		{
			return p_primitiveChar;
		}

		char Conversion::ToLowerCase(char p_primitiveChar)
		{
			if (Validation::IsUpperCase(p_primitiveChar))
			{
				return p_primitiveChar + 32;
			}
			return p_primitiveChar;
		}

		char Conversion::ToUpperCase(char p_primitiveChar)
		{
			if (Validation::IsLowerCase(p_primitiveChar))
			{
				return p_primitiveChar - 32;
			}
			return p_primitiveChar;
		}
	}
}
