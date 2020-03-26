#include "encryption.h"
#include "conversion.h"
#include "utility.h"
#include "validation.h"

namespace lcu
{
	inline namespace algorithms
	{
		char* Encryption::CaesarCipher(const char* const p_stringToCipher, int p_shift)
		{
			size_t stringToCipherLength = Utility::LengthOf(p_stringToCipher);
			char* result = Utility::CopyOf(p_stringToCipher, stringToCipherLength);
			p_shift %= 26;

			for (size_t i = 0; i < stringToCipherLength; ++i)
			{
				if (Validation::IsAlpha(result[i]))
				{
					if (Validation::IsLowerCase(result[i]) && Conversion::ToASCII(result[i]) + p_shift > 122
						|| Validation::IsUpperCase(result[i]) && Conversion::ToASCII(result[i]) + p_shift > 90)
					{
						result[i] -= 26;
					}
					result[i] += p_shift;
				}
			}
			return result;
		}

		char* Encryption::CaesarDecipher(const char* const p_stringToDecipher, int p_shift)
		{
			size_t stringToDecipherLength = Utility::LengthOf(p_stringToDecipher);
			char* result = Utility::CopyOf(p_stringToDecipher, stringToDecipherLength);
			p_shift %= 26;

			for (size_t i = 0; i < stringToDecipherLength; ++i)
			{
				if (Validation::IsAlpha(result[i]))
				{
					if (Validation::IsLowerCase(result[i]) && Conversion::ToASCII(result[i]) - p_shift < 97
						|| Validation::IsUpperCase(result[i]) && Conversion::ToASCII(result[i]) - p_shift < 65)
					{
						result[i] += 26;
					}
					result[i] -= p_shift;
				}
			}
			return result;
		}

		char* Encryption::VigenereCipher(const char* const p_stringToCipher, char* const p_key)
		{
			char** vigenereTable = VignereSquare();
			size_t stringToCipherLength = Utility::LengthOf(p_stringToCipher);
			char* result = Utility::CopyOf(p_stringToCipher, stringToCipherLength);
			size_t c = 0;

			for (size_t i = 0; i < stringToCipherLength; ++i)
			{
				if (c == Utility::LengthOf(p_key))
				{
					c = 0;
				}
				if (Validation::IsAlpha(result[i]))
				{
					result[i] = p_key[c];
					++c;
				}
			}

			for (c = 0; c < stringToCipherLength; ++c)
			{
				if (Validation::IsAlpha(result[c]))
				{
					result[c] = vigenereTable[Conversion::ToASCII(Conversion::ToUpperCase(p_stringToCipher[c])) - 64][
						Conversion::ToASCII(Conversion::ToUpperCase(result[c])) - 64];
				}
			}

			for (short i = 0; i < 27; ++i)
			{
				delete[] vigenereTable[i];
			}
			delete[] vigenereTable;
			return result;
		}

		char* Encryption::VigenereDecipher(const char* const p_stringToDecipher, char* const p_key)
		{
			char** vigenereTable = VignereSquare();
			size_t stringToDecipherLength = Utility::LengthOf(p_stringToDecipher);
			char* result = Utility::CopyOf(p_stringToDecipher, stringToDecipherLength);
			size_t c = 0;

			for (size_t i = 0; i < stringToDecipherLength; ++i)
			{
				if (Validation::IsAlpha(result[i]))
				{
					if (c == Utility::LengthOf(p_key))
					{
						c = 0;
					}
					result[i] = p_key[c];
					++c;
				}
			}

			for (c = 0; c < stringToDecipherLength; ++c)
			{
				if (Validation::IsAlpha(result[c]))
				{
					for (size_t j = 1; j < 27; ++j)
					{
						if (vigenereTable[Conversion::ToASCII(Conversion::ToUpperCase(result[c])) - 64][j] == Conversion
							::ToUpperCase(p_stringToDecipher[c]))
						{
							result[c] = vigenereTable[0][j];
							break;
						}
					}
				}
			}

			for (short i = 0; i < 27; ++i)
				delete[] vigenereTable[i];
			delete[] vigenereTable;

			return result;
		}

		char** Encryption::VignereSquare()
		{
			char k = '@';
			char** result = new char* [27];

			for (size_t i = 0; i < 27; ++i, ++k)
			{
				result[i] = new char[27];
				result[i][0] = '@' + static_cast<char>(i);
				result[0][i] = result[i][0];

				for (size_t c = 1; c < 27; ++c)
				{
					if (k + c > 90)
					{
						result[i][c] = k + static_cast<char>(c) - 26;
					}
					else
					{
						result[i][c] = k + static_cast<char>(c);
					}
				}
			}
			result[0][0] = 0;
			return result;
		}
	}
}
