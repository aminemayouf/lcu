#pragma once

#include "Char.h"

#include "../Interfaces/IComparable.h"

namespace LCU
{
	inline namespace DataStructures
	{
		/**
		 * String Class
		 *
		 * @project DataStructures
		 * @author Amine MAYOUF
		 */
		class String : public PrimitiveObject, public IComparable<String>
		{
			Char* m_pCharT;
			size_t m_capacity;
			size_t m_length;

		public:
			String();
			explicit String(size_t p_size);
			String(const char* p_pPrimitiveCharT);
			explicit String(const char* p_pPrimitiveCharT, size_t p_length);
			String(const String& p_string);
			~String();

			// Accessors and mutators
			size_t Capacity() const;
			size_t Length() const;

			// A
			void Append(char p_primitiveChar, size_t p_n = 1);
			void Append(Char p_char, size_t p_n = 1);
			void Append(const char* p_pPrimitiveCharT);
			void Append(const String& p_string);
			void Assign(char p_primitiveChar, size_t p_index) const;
			void Assign(Char p_char, size_t p_index) const;
			// B
			void Backspace();
			// C
			Char CharAt(size_t p_index) const;
			bool Contains(char p_primitiveChar) const;
			bool Contains(Char p_char) const;
			bool Contains(const char* p_pPrimitiveCharT) const;
			bool Contains(const String& p_string) const;
			// E
			bool EndsWith(char p_primitiveChar) const;
			bool EndsWith(Char p_char) const;
			bool EndsWith(const char* p_pPrimitiveCharT) const;
			bool EndsWith(const String& p_string) const;
			// I
			void InsertAt(char p_primitiveChar, size_t p_index);
			void InsertAt(Char p_char, size_t p_index);
			void InsertAt(const char* p_pPrimitiveCharT, size_t p_index);
			void InsertAt(const String& p_string, size_t p_index);
			bool IsEmpty() const;
			bool IsNumber() const;
			// L
			static size_t LengthOf(const Char* p_pCharT);
			// O
			size_t Occurrences(char p_primitiveChar) const;
			size_t Occurrences(Char p_char) const;
			size_t Occurrences(const char* p_pPrimitiveCharT) const;
			size_t Occurrences(const String& p_string) const;
			// P
			void Purge();
			// R
			void ReplaceAll(Char p_charToReplace, Char p_replacementChar) const;
			void ReplaceAll(Char p_charToReplace, const String& p_replacementString);
			void ReplaceAll(const String& p_stringToReplace, Char p_replacementChar);
			void ReplaceAll(const String& p_stringToReplace, const String& p_replacementString);
			void Reserve(size_t p_newCapacity);
			void Resize(size_t p_newLength);
			bool StartsWith(char p_primitiveChar) const;
			bool StartsWith(Char p_char) const;
			bool StartsWith(const char* p_pPrimitiveCharT) const;
			bool StartsWith(const String& p_string) const;
			String SubString(size_t p_startIndex, size_t p_endIndex) const;
			// T
			const char* ToPrimitiveString() const override;
			String ToLowerCase() const;
			String ToUpperCase() const;
			// V
			static String ValueOf(bool p_boolean);
			static String ValueOf(int p_integer);
			static String ValueOf(size_t p_unsigned);
			static String ValueOf(float p_float);
			static String ValueOf(double p_double);
			static String ValueOf(const PrimitiveObject& p_primitiveObject);
			// #
			Char& operator [](size_t p_index) const;
			String& operator =(const char* p_pPrimitiveCharT);
			String& operator =(const String& p_string);
			String operator +(char p_primitiveChar) const;
			String operator +(Char p_char) const;
			String operator +(const char* p_pPrimitiveCharT) const;
			friend String operator +(const char* p_pPrimitiveCharT, const String& p_string);
			String operator +(const String& p_string) const;
			String operator +(const PrimitiveObject& p_primitiveObject) const;
			String& operator +=(char p_primitiveChar);
			String& operator +=(Char p_char);
			String& operator +=(const char* p_pPrimitiveCharT);
			String& operator +=(const String& p_string);
			String& operator +=(const PrimitiveObject& p_primitiveObject);
			bool operator <(const String& p_string) const override;
			bool operator >(const String& p_string) const override;
			bool operator ==(const char* p_pPrimitiveCharT) const;
			bool operator ==(const String& p_string) const override;
			bool operator !=(const char* p_pPrimitiveCharT) const;
			bool operator !=(const String& p_string) const override;
		};
	}
}
