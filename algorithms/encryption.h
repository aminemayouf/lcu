#pragma once


namespace lcu
{
	inline namespace algorithms
	{
		/**
		 * Encryption Class
		 *
		 * @project Algorithms
		 * @author Amine MAYOUF
		 */
		class Encryption
		{
		public:
			Encryption() = delete;
			~Encryption() = delete;

			// C
			static char* CaesarCipher(const char* p_stringToCipher, int p_shift);
			static char* CaesarDecipher(const char* p_stringToDecipher, int p_shift);
			// V
			static char* VigenereCipher(const char* p_stringToCipher, char* p_key);
			static char* VigenereDecipher(const char* p_stringToDecipher, char* p_key);
		private:
			static char** VignereSquare();
		};
	}
}
