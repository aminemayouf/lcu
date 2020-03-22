#pragma once

#include "PrimitiveObject.h"

#include "../Interfaces/IComparable.h"

namespace LCU
{
	inline namespace DataStructures
	{
		/**
		 * Char Class
		 * 
		 * @project DataStructures
		 * @author Amine MAYOUF
		 */
		class Char : public PrimitiveObject, public IComparable<Char>
		{
			char m_char;

		public:
			Char();
			explicit Char(int p_ascii);
			Char(char p_primitiveChar);

			char ToPrimitiveChar() const;
			// A
			void Assign(char p_primitiveChar);
			void Assign(const Char& p_char);
			// E
			void Erase();
			// I
			bool IsAlpha() const;
			bool IsAlphanumeric() const;
			bool IsLowerCase() const;
			bool IsNumeric() const;
			bool IsPunctuation() const;
			bool IsUpperCase() const;
			// T
			int ToASCII() const;
			Char ToLowerCase() const;
			const char* ToPrimitiveString() const override;
			Char ToUpperCase() const;
			// #
			Char& operator =(char p_primitiveChar);
			Char& operator =(const Char& p_char);
			char* operator +(char p_primitiveChar) const;
			char* operator +(const Char& p_char) const;
			Char& operator +=(int i);
			Char& operator -=(int i);
			bool operator <(const Char& p_char) const override;
			bool operator >(const Char& p_char) const override;
			bool operator ==(const Char& p_char) const override;
		};
	}
}
