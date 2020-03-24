#pragma once


namespace LCU
{
	inline namespace Algorithms
	{
		class Conversion
		{
		public:
			Conversion() = delete;
			~Conversion() = delete;

			static int ToASCII(char p_primitiveChar);
			static char ToLowerCase(char p_primitiveChar);
			static char ToUpperCase(char p_primitiveChar);
		};
	}
}
