#include "Validation.h"

namespace LCU
{
	inline namespace Algorithms
	{
		bool Validation::IsAlpha(char p_primitiveChar)
		{
			return ((p_primitiveChar >= 65 && p_primitiveChar <= 90)
				       || (p_primitiveChar >= 97 && p_primitiveChar <= 122))
				       ? true
				       : false;
		}

		bool Validation::IsNumeric(char p_primitiveChar)
		{
			return (p_primitiveChar >= 48 && p_primitiveChar <= 57) ? true : false;
		}

		bool Validation::IsAlphaNumeric(char p_primitiveChar)
		{
			return IsAlpha(p_primitiveChar) || IsNumeric(p_primitiveChar);
		}

		bool Validation::IsPunctuation(char p_primitiveChar)
		{
			switch (p_primitiveChar)
			{
			case 33: // !
			case 34: // "
			case 39: // '
			case 40: // (
			case 41: // )
			case 45: // -
			case 46: // .
			case 58: // :
			case 59: // ;
			case 63: // ?
			case 91: // [
			case 93: // ]
				return true;

			default:
				break;
			}
			return false;
		}

		bool Validation::IsLowerCase(char p_primitiveChar)
		{
			return (p_primitiveChar >= 97 && p_primitiveChar <= 122) ? true : false;
		}

		bool Validation::IsUpperCase(char p_primitiveChar)
		{
			return (p_primitiveChar >= 65 && p_primitiveChar <= 90) ? true : false;
		}
	}
}
