#pragma once

#include "primitive_object.h"

#include "../algorithms/conversion.h"
#include "../algorithms/validation.h"
#include "../interfaces/comparable.h"

namespace lcu
{
	inline namespace data_structures
	{
		/**
		 * Char Class
		 * 
		 * @project data_structures
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

		inline Char::Char() : m_char(0)
		{
		}

		inline Char::Char(int p_ascii) : m_char(static_cast<char>(p_ascii))
		{
		}

		inline Char::Char(char p_primitiveChar) : m_char(p_primitiveChar)
		{
		}

		inline char Char::ToPrimitiveChar() const
		{
			return m_char;
		}

		inline void Char::Assign(char p_primitiveChar)
		{
			m_char = p_primitiveChar;
		}

		inline void Char::Assign(const Char& p_char)
		{
			m_char = p_char.m_char;
		}

		inline void Char::Erase()
		{
			m_char = 0;
		}

		inline bool Char::IsAlpha() const
		{
			return Validation::IsAlpha(m_char);
		}

		inline bool Char::IsAlphanumeric() const
		{
			return Validation::IsAlphaNumeric(m_char);
		}

		inline bool Char::IsLowerCase() const
		{
			return Validation::IsLowerCase(m_char);
		}

		inline bool Char::IsNumeric() const
		{
			return Validation::IsNumeric(m_char);
		}

		inline bool Char::IsPunctuation() const
		{
			return Validation::IsPunctuation(m_char);
		}

		inline bool Char::IsUpperCase() const
		{
			return Validation::IsUpperCase(m_char);
		}

		inline int Char::ToASCII() const
		{
			return Conversion::ToASCII(m_char);
		}

		inline Char Char::ToLowerCase() const
		{
			return Char(Conversion::ToLowerCase(m_char));
		}

		const char* Char::ToPrimitiveString() const
		{
			char* pResult = new char[2];
			pResult[0] = m_char;
			pResult[1] = '\0';
			return pResult;
		}

		inline Char Char::ToUpperCase() const
		{
			return Char(Conversion::ToUpperCase(m_char));
		}

		inline Char& Char::operator=(char p_primitiveChar)
		{
			m_char = p_primitiveChar;
			return *this;
		}

		inline Char& Char::operator =(const Char& p_char)
		{
			if (&p_char != this)
			{
				m_char = p_char.m_char;
			}
			return *this;
		}

		inline char* Char::operator+(char p_primitiveChar) const
		{
			char* resultCharT = new char[3];
			resultCharT[0] = m_char;
			resultCharT[1] = p_primitiveChar;
			resultCharT[2] = '\0';
			return resultCharT;
		}

		inline char* Char::operator +(const Char& p_char) const
		{
			char* resultCharT = new char[3];
			resultCharT[0] = m_char;
			resultCharT[1] = p_char.m_char;
			resultCharT[2] = '\0';
			return resultCharT;
		}

		inline Char& Char::operator +=(int p_i)
		{
			m_char += p_i;
			return *this;
		}

		inline Char& Char::operator -=(int p_i)
		{
			m_char -= p_i;
			return *this;
		}

		inline bool Char::operator<(const Char& p_char) const
		{
			return m_char < p_char.m_char;
		}

		inline bool Char::operator>(const Char& p_char) const
		{
			return m_char > p_char.m_char;
		}

		inline bool Char::operator ==(const Char& p_char) const
		{
			return m_char == p_char.m_char;
		}
	}
}
