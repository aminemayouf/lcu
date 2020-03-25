#pragma once


namespace lcu
{
	inline namespace algorithms
	{
		/**
		 * Validation Class
		 *
		 * @project Algorithms
		 * @author Amine MAYOUF
		 */
		class Validation
		{
		public:
			Validation() = delete;
			~Validation() = delete;

			static bool IsAlpha(char);
			static bool IsNumeric(char);
			static bool IsAlphaNumeric(char);
			static bool IsPunctuation(char);
			static bool IsLowerCase(char);
			static bool IsUpperCase(char);
		};
	}
}
