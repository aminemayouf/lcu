#include "encoding.h"


namespace lcu
{
	inline namespace algorithms
	{
		String Encoding::RunLengthEncodingDecode(const String& p_stringToDecode)
		{
			const char flag = '@';
			String result;

			for (size_t i = 0; i < p_stringToDecode.Length(); ++i)
			{
				if (!p_stringToDecode[i].IsNumeric())
				{
					result += p_stringToDecode[i];
					if (p_stringToDecode[i] == flag)
					{
						++i;
					}
				}
				else if (p_stringToDecode[i].IsNumeric() && p_stringToDecode[i + 1].IsNumeric()
					|| i == p_stringToDecode.Length() - 1)
				{
					result += p_stringToDecode[i];
				}
				else if (p_stringToDecode[i].IsNumeric() && i + 2 < p_stringToDecode.Length())
				{
					if (p_stringToDecode[i + 1] == flag)
					{
						result.Append(p_stringToDecode[i + 2], p_stringToDecode[i].ToASCII() - 48);
						i += 2;
					}
				}
			}
			return result;
		}

		String Encoding::RunLengthEncodingEncode(const String& p_stringToEncode)
		{
			const char flag = '@';
			String result;

			int c = 1;

			for (size_t i = 0; i < p_stringToEncode.Length(); ++i)
			{
				if (p_stringToEncode[i] == p_stringToEncode[i + 1])
				{
					++c;
				}
				else
				{
					if (c <= 2)
					{
						for (size_t j = 0; j < static_cast<size_t>(c); ++j)
						{
							result += p_stringToEncode[i];
						}
					}
					else
					{
						if (c <= 9)
						{
							result += String::ValueOf(c);
							result += flag;
							result += p_stringToEncode[i];
						}
						else
						{
							for (int j = 0; j < static_cast<int>(c / 9); ++j)
							{
								result += String::ValueOf(9);
								result += flag;
								result += p_stringToEncode[i];
							}
							if (c % 9 != 0)
							{
								result += String::ValueOf(c % 9);
								result += flag;
								result += p_stringToEncode[i];
							}
						}
					}
					c = 1;
				}
			}
			return result;
		}

		String Encoding::RunLengthEncodingEncode(const String& p_stringToEncode, float& p_ratio)
		{
			String result = RunLengthEncodingEncode(p_stringToEncode);
			p_ratio = 100 - static_cast<float>(result.Length()) * 100 / p_stringToEncode.Length();
			return result;
		}
	}
}
