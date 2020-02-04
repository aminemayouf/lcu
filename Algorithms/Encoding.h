#pragma once


namespace LCU {
	inline namespace Algorithms {
		/**
		 * Encoding Class
		 *
		 * @project Algorithms
		 * @author Amine MAYOUF
		 */
		class Encoding {
			/*
			* Methods
			*/
		public:
			Encoding() = delete;
			~Encoding() = delete;

			static String RunLengthEncodingDecode(const String& p_stringToDecode);

			static String RunLengthEncodingEncode(const String& p_stringToEncode);
			static String RunLengthEncodingEncode(const String& p_stringToEncode, float& p_ratio);
		};
	}
}
