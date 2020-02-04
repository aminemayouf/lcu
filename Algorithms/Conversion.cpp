#include "Conversion.h"
#include "Validation.h"

namespace LCU {
	inline namespace Algorithms {

		int Conversion::ToASCII(char p_primitiveChar) {
			return p_primitiveChar;
		}

		char Conversion::ToLowerCase(char p_primitiveChar) {
			if (Validation::IsUpperCase(p_primitiveChar)) {
				return p_primitiveChar + 32;
			}
			return p_primitiveChar;
		}

		char Conversion::ToUpperCase(char p_primitiveChar) {
			if (Validation::IsLowerCase(p_primitiveChar)) {
				return p_primitiveChar - 32;
			}
			return p_primitiveChar;
		}
	}
}
