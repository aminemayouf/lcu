#pragma once

#include "../data_structures/str.h"

namespace lcu
{
	inline namespace algorithms
	{
		/**
		 * Encoding Class
		 *
		 * @project Algorithms
		 * @author Amine MAYOUF
		 */
		class Encoding
		{
		public:
			Encoding() = delete;
			~Encoding() = delete;

			static String RunLengthEncodingDecode(const String& p_stringToDecode);
			static String RunLengthEncodingEncode(const String& p_stringToEncode);
			static String RunLengthEncodingEncode(const String& p_stringToEncode, float& p_ratio);
		};
	}
}
