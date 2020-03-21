#pragma once


namespace LCU {
	inline namespace Algorithms {
		/**
		 * Encryption Class

		 * @project Algorithms
		 * @author Amine MAYOUF
		 */
		class Encryption {
			/*
			 * Methods
			 */
		public:
			Encryption() = delete;
			~Encryption() = delete;

			// C
			static char* CaesarCipher(const char*const p_stringToCipher, int p_shift);
			static char* CaesarDecipher(const char*const p_stringToDecipher, int p_shift);

			// V
			static char* VigenereCipher(const char*const p_stringToCipher, char*const p_key);
			static char* VigenereDecipher(const char*const p_stringToDecipher, char*const p_key);

		private:
			static char** VignereSquare();
		};
	}
}
