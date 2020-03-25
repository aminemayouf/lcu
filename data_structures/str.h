#pragma once

#include "char.h"

#include "../algorithms/utility.h"
#include "../interfaces/comparable.h"

namespace lcu
{
	inline namespace data_structures
	{
		/**
		 * String Class
		 *
		 * @project data_structures
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

		inline String::String() : m_pCharT(nullptr), m_capacity(0), m_length(0)
		{
		}

		inline String::String(size_t p_size)
		{
			m_capacity = Utility::AdaptedCapacity(p_size);
			m_length = p_size;
			m_pCharT = new Char[m_capacity + 1];
			m_pCharT[m_capacity] = '\0';
		}

		inline String::String(const char* const p_pPrimitiveCharT)
		{
			m_length = Utility::LengthOf(p_pPrimitiveCharT);
			m_capacity = Utility::AdaptedCapacity(m_length);
			m_pCharT = new Char[m_capacity + 1];
			for (size_t i = 0; i < m_length; ++i)
			{
				m_pCharT[i] = p_pPrimitiveCharT[i];
			}
			m_pCharT[m_capacity] = '\0';
		}

		String::String(const char* const p_pPrimitiveCharT, size_t p_length)
		{
			m_length = p_length;
			m_capacity = Utility::AdaptedCapacity(m_length);
			m_pCharT = new Char[m_capacity + 1];
			for (size_t i = 0; i < m_length; ++i)
			{
				m_pCharT[i] = p_pPrimitiveCharT[i];
			}
			m_pCharT[m_capacity] = '\0';
		}

		inline String::String(const String& p_string)
		{
			m_pCharT = new Char[p_string.m_capacity + 1];
			m_pCharT[p_string.m_capacity] = '\0';
			m_capacity = p_string.m_capacity;
			for (size_t i = 0; i < p_string.m_length; ++i)
			{
				m_pCharT[i] = p_string[i];
			}
			m_length = p_string.m_length;
		}

		inline String::~String()
		{
			delete[] m_pCharT;
		}

		inline size_t String::Capacity() const
		{
			return m_capacity;
		}

		inline size_t String::Length() const
		{
			return m_length;
		}

		inline void String::Append(char p_primitiveChar, size_t p_n)
		{
			Append(Char(p_primitiveChar), p_n);
		}

		inline void String::Append(Char p_char, size_t p_n)
		{
			if (m_length + p_n <= m_capacity)
			{
				for (size_t i = m_length; i < m_length + p_n; ++i)
				{
					m_pCharT[i] = p_char;
				}
			}
			else
			{
				m_capacity = Utility::AdaptedCapacity(m_length + p_n);

				Char* p_pCharT = new Char[m_capacity + 1];
				for (size_t i = 0; i < m_length; ++i)
				{
					p_pCharT[i] = m_pCharT[i];
				}
				delete[] m_pCharT;

				for (size_t i = 0; i < m_length + p_n; ++i)
				{
					p_pCharT[m_length + i] = p_char;
				}
				p_pCharT[m_capacity] = '\0';
				m_pCharT = p_pCharT;
			}
			m_length += p_n;
		}

		inline void String::Append(const char* const p_pPrimitiveCharT)
		{
			size_t newLength = Utility::LengthOf(p_pPrimitiveCharT);
			if (m_length + newLength <= m_capacity)
			{
				for (size_t i = m_length; i < m_length + newLength; ++i)
				{
					m_pCharT[i] = p_pPrimitiveCharT[i - m_length];
				}
			}
			else
			{
				m_capacity = Utility::AdaptedCapacity(m_length + newLength);

				Char* p_pCharT = new Char[m_capacity + 1];
				for (size_t i = 0; i < m_length; ++i)
				{
					p_pCharT[i] = m_pCharT[i];
				}
				delete[] m_pCharT;

				for (size_t i = m_length; i < m_length + newLength; ++i)
				{
					p_pCharT[i] = p_pPrimitiveCharT[i - m_length];
				}
				p_pCharT[m_capacity] = '\0';
				m_pCharT = p_pCharT;
			}
			m_length += newLength;
		}

		inline void String::Append(const String& p_string)
		{
			if (m_length + p_string.m_length <= m_capacity)
			{
				for (size_t i = m_length; i < m_length + p_string.m_length; ++i)
				{
					m_pCharT[i] = p_string[i - m_length];
				}
			}
			else
			{
				m_capacity = Utility::AdaptedCapacity(m_length + p_string.m_length);

				Char* p_pCharT = new Char[m_capacity + 1];
				for (size_t i = 0; i < m_length; ++i)
				{
					p_pCharT[i] = m_pCharT[i];
				}
				delete[] m_pCharT;

				for (size_t i = m_length; i < m_length + p_string.m_length; ++i)
				{
					p_pCharT[i] = p_string[i - m_length];
				}
				p_pCharT[m_capacity] = '\0';
				m_pCharT = p_pCharT;
			}
			m_length += p_string.m_length;
		}

		inline void String::Assign(char p_primitiveChar, size_t p_index) const
		{
			Assign(Char(p_primitiveChar), p_index);
		}

		inline void String::Assign(Char p_char, size_t p_index) const
		{
			/*if (!m_pCharT)
			{
				throw NullPointerException();
			}*/
			/*if (p_index > m_length)
			{
				throw ArgumentOutOfRangeException();
			}*/
			m_pCharT[p_index] = p_char;
		}

		void String::Backspace()
		{
			if (m_length > 0)
			{
				--m_length;
			}
		}

		inline Char String::CharAt(size_t p_index) const
		{
			/*if (!m_pCharT)
			{
				throw NullPointerException();
			}*/
			/*if (p_index > m_length)
			{
				throw ArgumentOutOfRangeException();
			}*/
			return m_pCharT[p_index];
		}

		inline bool String::Contains(char p_primitiveChar) const
		{
			return Contains(Char(p_primitiveChar));
		}

		inline bool String::Contains(Char p_char) const
		{
			for (size_t i = 0; i < m_length; ++i)
			{
				if (m_pCharT[i] == p_char)
				{
					return true;
				}
			}
			return false;
		}

		inline bool String::Contains(const char* const p_pPrimitiveCharT) const
		{
			size_t primitiveCharTLength = Utility::LengthOf(p_pPrimitiveCharT);
			if (m_length < primitiveCharTLength)
			{
				return false;
			}

			size_t j = 0;
			bool match = false;

			for (size_t i = 0; i < m_length; ++i)
			{
				if (j < primitiveCharTLength)
				{
					if (m_pCharT[i] == p_pPrimitiveCharT[j])
					{
						match = true;
						++j;
					}
					else if (m_pCharT[i] != p_pPrimitiveCharT[j] &
						match)
					{
						match = false;
						j = 0;
					}
				}
				else
				{
					break;
				}
			}

			if (j < primitiveCharTLength)
			{
				match = false;
			}

			return match;
		}

		inline bool String::Contains(const String& p_string) const
		{
			if (m_length < p_string.m_length)
			{
				return false;
			}

			size_t j = 0;
			bool match = false;

			for (size_t i = 0; i < m_length; ++i)
			{
				if (j < p_string.m_length)
				{
					if (m_pCharT[i] == p_string.m_pCharT[j])
					{
						match = true;
						++j;
					}
					else if (m_pCharT[i] != p_string.m_pCharT[j] && match)
					{
						match = false;
						j = 0;
					}
				}
				else
				{
					break;
				}
			}

			if (j < p_string.m_length)
			{
				match = false;
			}

			return match;
		}

		inline bool String::EndsWith(char p_primitiveChar) const
		{
			return EndsWith(Char(p_primitiveChar));
		}

		inline bool String::EndsWith(Char p_char) const
		{
			return (m_pCharT[m_length - 1] == p_char) ? true : false;
		}

		inline bool String::EndsWith(const char* const p_pPrimitiveCharT) const
		{
			size_t primitiveCharTLength = Utility::LengthOf(p_pPrimitiveCharT);
			if (m_length < primitiveCharTLength)
			{
				return false;
			}
			for (size_t i = m_length - primitiveCharTLength; i < m_length; ++i)
			{
				if (m_pCharT[i] != p_pPrimitiveCharT[i - (m_length - primitiveCharTLength)])
				{
					return false;
				}
			}
			return true;
		}

		inline bool String::EndsWith(const String& p_string) const
		{
			if (m_length < p_string.m_length)
			{
				return false;
			}
			for (size_t i = m_length - p_string.m_length; i < m_length; ++i)
			{
				if (m_pCharT[i] != p_string[i - (m_length - p_string.m_length)])
				{
					return false;
				}
			}
			return true;
		}

		inline void String::InsertAt(char p_primitiveChar, size_t p_index)
		{
			InsertAt(Char(p_primitiveChar), p_index);
		}

		inline void String::InsertAt(Char p_char, size_t p_index)
		{
			/*if (p_index > m_length)
			{
				throw ArgumentOutOfRangeException();
			}*/

			if (p_index == m_length)
			{
				Append(p_char);
			}
			else
			{
				if (m_capacity >= m_length + 1)
				{
					for (size_t i = m_length; i > p_index; i--)
					{
						m_pCharT[i] = m_pCharT[i - 1];
					}
					m_pCharT[p_index] = p_char;
				}
				else
				{
					m_capacity = Utility::AdaptedCapacity(m_length + 1);

					size_t i;
					Char* pCharT = new Char[m_capacity + 1];
					for (i = 0; i != p_index; ++i)
					{
						pCharT[i] = m_pCharT[i];
					}
					pCharT[i] = p_char;
					for (size_t j = i + 1; j < m_length + 1; ++j)
					{
						pCharT[j] = m_pCharT[j - 1];
					}
					pCharT[m_capacity] = '\0';
					delete[] m_pCharT;
					m_pCharT = pCharT;
				}
				++m_length;
			}
		}

		inline void String::InsertAt(const char* const p_pPrimitiveCharT, size_t p_index)
		{
			/*if (p_index > m_length)
			{
				throw ArgumentOutOfRangeException();
			}*/

			if (p_index == m_length)
			{
				Append(p_pPrimitiveCharT);
			}
			else
			{
				size_t primitiveCharTLength = Utility::LengthOf(p_pPrimitiveCharT);
				size_t charTLength = m_length + primitiveCharTLength;
				if (m_capacity >= charTLength)
				{
					for (size_t i = m_length + primitiveCharTLength - 1; i > primitiveCharTLength; i--)
					{
						m_pCharT[i] = m_pCharT[i - primitiveCharTLength];
					}
					for (size_t i = p_index; i < p_index + primitiveCharTLength; ++i)
					{
						m_pCharT[i] = p_pPrimitiveCharT[i - p_index];
					}
				}
				else
				{
					m_capacity = Utility::AdaptedCapacity(charTLength);

					size_t i, j;
					Char* pCharT = new Char[m_capacity + 1];
					for (i = 0; i != p_index; ++i)
					{
						pCharT[i] = m_pCharT[i];
					}
					for (j = i; j < primitiveCharTLength + i; ++j)
					{
						pCharT[j] = p_pPrimitiveCharT[j - i];
					}
					for (size_t k = j; k < charTLength; ++k, ++i)
					{
						pCharT[k] = m_pCharT[i];
					}
					pCharT[m_capacity] = '\0';
					delete[] m_pCharT;
					m_pCharT = pCharT;
				}
				m_length += primitiveCharTLength;
			}
		}

		inline void String::InsertAt(const String& p_string, size_t p_index)
		{
			/*if (p_index > m_length)
			{
				throw ArgumentOutOfRangeException();
			}*/

			if (p_index == m_length)
			{
				Append(p_string);
			}
			else
			{
				size_t charTLength = m_length + p_string.m_length;
				if (m_capacity >= charTLength)
				{
					for (size_t i = m_length + p_string.m_length - 1; i > p_string.m_length; i--)
					{
						m_pCharT[i] = m_pCharT[i - p_string.m_length];
					}
					for (size_t i = p_index; i < p_index + p_string.m_length; ++i)
					{
						m_pCharT[i] = p_string[i - p_index];
					}
				}
				else
				{
					m_capacity = Utility::AdaptedCapacity(charTLength);

					size_t i, j;
					Char* pCharT = new Char[m_capacity + 1];
					for (i = 0; i != p_index; ++i)
					{
						pCharT[i] = m_pCharT[i];
					}
					for (j = i; j < p_string.m_length + i; ++j)
					{
						pCharT[j] = p_string[j - i];
					}
					for (size_t k = j; k < charTLength; ++k, ++i)
					{
						pCharT[k] = m_pCharT[i];
					}
					pCharT[m_capacity] = '\0';
					delete[] m_pCharT;
					m_pCharT = pCharT;
				}
				m_length += p_string.m_length;
			}
		}

		inline bool String::IsEmpty() const
		{
			return !m_pCharT ? true : false;
		}

		inline bool String::IsNumber() const
		{
			for (size_t i = 0; i < m_length; ++i)
			{
				if (!m_pCharT[i].IsNumeric() && m_pCharT[i] != '.')
				{
					return false;
				}
			}
			return true;
		}

		inline size_t String::LengthOf(const Char* const p_pCharT)
		{
			size_t i = 0;
			while (p_pCharT[i] != '\0')
			{
				++i;
			}
			return i;
		}

		inline size_t String::Occurrences(char p_primitiveChar) const
		{
			return Occurrences(Char(p_primitiveChar));
		}

		inline size_t String::Occurrences(Char p_char) const
		{
			size_t count = 0;
			for (size_t i = 0; i < m_length; ++i)
			{
				if (m_pCharT[i] == p_char)
				{
					++count;
				}
			}
			return count;
		}

		inline size_t String::Occurrences(const char* const p_pPrimitiveCharT) const
		{
			size_t primitiveCharTLength = Utility::LengthOf(p_pPrimitiveCharT);
			if (m_length < primitiveCharTLength)
			{
				return 0;
			}

			size_t j = 0;
			size_t count = 0;
			for (size_t i = 0; i <= m_length; ++i)
			{
				if (j == primitiveCharTLength)
				{
					++count;
					j = 0;
				}
				else
				{
					if (m_pCharT[i] == p_pPrimitiveCharT[j])
					{
						++j;
						for (size_t k = i + 1; k < primitiveCharTLength; ++k)
						{
							if (m_pCharT[k] == p_pPrimitiveCharT[j])
							{
								++j;
							}
							else
							{
								j = 0;
								break;
							}
						}
					}
				}
			}
			return count;
		}

		inline size_t String::Occurrences(const String& p_string) const
		{
			size_t j = 0;
			size_t count = 0;
			for (size_t i = 0; i <= m_length; ++i)
			{
				if (j == p_string.m_length)
				{
					++count;
					j = 0;
				}
				else
				{
					if (m_pCharT[i] == p_string[j])
					{
						++j;
						for (size_t k = i + 1; k < p_string.m_length; ++k)
						{
							if (m_pCharT[k] == p_string[j])
							{
								++j;
							}
							else
							{
								j = 0;
								break;
							}
						}
					}
				}
			}
			return count;
		}

		inline void String::Purge()
		{
			delete[] m_pCharT;
			m_pCharT = nullptr;
			m_capacity = 0;
			m_length = 0;
		}

		inline void String::ReplaceAll(Char p_charToReplace, Char p_replacementChar) const
		{
			for (size_t i = 0; i < m_length; ++i)
			{
				if (m_pCharT[i] == p_charToReplace)
				{
					m_pCharT[i] = p_replacementChar;
				}
			}
		}

		inline void String::ReplaceAll(Char p_charToReplace, const String& p_replacementString)
		{
			if (p_replacementString.m_length == 1)
			{
				ReplaceAll(p_charToReplace, p_replacementString[0]);
			}
			else
			{
				size_t k = 0;
				size_t charOccurrences = Occurrences(p_charToReplace);
				size_t charTLength = (p_replacementString.m_length * charOccurrences) + (m_length - charOccurrences);
				Char* pCharT = new Char[charTLength + 1];

				for (size_t i = 0; i < m_length; ++i)
				{
					if (m_pCharT[i] != p_charToReplace)
					{
						pCharT[k] = m_pCharT[i];
						++k;
					}
					else
					{
						for (size_t j = 0; j < p_replacementString.m_length; ++j)
						{
							pCharT[k] = p_replacementString[j];
							++k;
						}
					}
				}

				delete[] m_pCharT;
				pCharT[charTLength] = '\0';
				m_pCharT = pCharT;
				m_length = charTLength;
			}
		}

		inline void String::ReplaceAll(const String& p_stringToReplace, Char p_replacementChar)
		{
			if (p_stringToReplace.m_length > m_length)
			{
				return;
			}

			size_t j = 0;
			size_t k = 0;
			size_t l = 0;
			size_t stringToReplaceOccurences = Occurrences(p_stringToReplace);
			size_t charTLength = stringToReplaceOccurences + (m_length - (p_stringToReplace.m_length *
				stringToReplaceOccurences));
			Char* pCharT = new Char[charTLength + 1];

			for (size_t i = 0; i <= m_length; ++i)
			{
				if (j == p_stringToReplace.m_length)
				{
					pCharT[k] = p_replacementChar;
					++k;
					l = i;
					j = 0;
				}
				else
				{
					if (m_pCharT[i] == p_stringToReplace[j])
					{
						++j;
					}
					else
					{
						for (size_t m = l; m < i; ++m)
						{
							pCharT[k] = m_pCharT[m];
							++k;
						}
						j = 0;
					}
				}
			}

			delete[] m_pCharT;
			pCharT[charTLength] = '\0';
			m_pCharT = pCharT;
			m_length = charTLength;
		}

		inline void String::ReplaceAll(const String& p_stringToReplace, const String& p_replacementString)
		{
			size_t j = 0;
			size_t k = 0;
			size_t l = 0;
			size_t stringOccurrences = Occurrences(p_stringToReplace);
			size_t charTLength = (stringOccurrences * p_replacementString.m_length) + (m_length - (p_stringToReplace.
				m_length * stringOccurrences));
			Char* pCharT = new Char[charTLength + 1];

			for (size_t i = 0; i <= m_length; ++i)
			{
				if (j == p_stringToReplace.m_length)
				{
					for (size_t p_n = 0; p_n < p_replacementString.m_length; ++p_n)
					{
						pCharT[k] = p_replacementString[p_n];
						++k;
					}
					l = i;
					j = 0;
				}
				else
				{
					if (m_pCharT[i] == p_stringToReplace[j])
					{
						++j;
					}
					else
					{
						for (size_t m = l; m <= i; ++m)
						{
							pCharT[k] = m_pCharT[m];
							++k;
						}
						l = i + 1;
						j = 0;
					}
				}
			}

			delete[] m_pCharT;
			pCharT[charTLength] = '\0';
			m_pCharT = pCharT;
			m_length = charTLength;
		}

		inline void String::Reserve(size_t p_newCapacity)
		{
			if (p_newCapacity <= m_capacity)
			{
				return;
			}

			m_capacity = p_newCapacity;
			m_length = 0;
			Char* pCharT = new Char[m_capacity + 1];
			for (size_t i = 0; i < m_length; ++i)
			{
				pCharT[i] = m_pCharT[i];
			}
			pCharT[m_length] = '\0';
			delete[] m_pCharT;
			m_pCharT = pCharT;
		}

		inline void String::Resize(size_t p_newLength)
		{
			if (p_newLength <= m_capacity)
			{
				m_length = p_newLength;
			}
			else
			{
				m_capacity = Utility::AdaptedCapacity(p_newLength);

				Char* pCharT = new Char[m_capacity + 1];
				for (size_t i = 0; i < m_length; ++i)
				{
					pCharT[i] = m_pCharT[i];
				}
				delete[] m_pCharT;
				pCharT[p_newLength] = '\0';
				m_pCharT = pCharT;
				m_length = p_newLength;
			}
		}

		inline bool String::StartsWith(char p_primitiveChar) const
		{
			return StartsWith(Char(p_primitiveChar));
		}

		inline bool String::StartsWith(Char p_char) const
		{
			return (m_pCharT[0] == p_char) ? true : false;
		}

		inline bool String::StartsWith(const char* const p_pPrimitiveCharT) const
		{
			size_t primitiveCharTLength = Utility::LengthOf(p_pPrimitiveCharT);
			if (m_length < primitiveCharTLength)
			{
				return false;
			}
			for (size_t i = 0; i < primitiveCharTLength; ++i)
			{
				if (m_pCharT[i] != p_pPrimitiveCharT[i])
				{
					return false;
				}
			}
			return true;
		}

		inline bool String::StartsWith(const String& p_string) const
		{
			if (m_length < p_string.m_length)
			{
				return false;
			}
			for (size_t i = 0; i < p_string.m_length; ++i)
			{
				if (m_pCharT[i] != p_string[i])
				{
					return false;
				}
			}
			return true;
		}

		inline String String::SubString(size_t p_startIndex, size_t p_endIndex) const
		{
			if (!m_pCharT)
			{
				//throw NullPointerException();
				return String();
			}
			if (p_endIndex > m_length || p_startIndex > p_endIndex)
			{
				//throw ArgumentOutOfRangeException();
				return String();
			}

			String result((p_endIndex - p_startIndex) + 1);
			for (size_t i = p_startIndex; i <= p_endIndex; ++i)
			{
				result[i - p_startIndex] = m_pCharT[i];
			}

			return result;
		}

		inline const char* String::ToPrimitiveString() const
		{
			char* primitiveCharT = new char[m_length + 1];
			for (size_t i = 0; i < m_length; ++i)
			{
				primitiveCharT[i] = m_pCharT[i].ToPrimitiveChar();
			}
			primitiveCharT[m_length] = '\0';
			return primitiveCharT;
		}

		inline String String::ToLowerCase() const
		{
			String result(m_length);
			for (size_t i = 0; i < m_length; ++i)
			{
				if (m_pCharT[i].IsAlpha())
				{
					result[i] = m_pCharT[i].ToLowerCase();
				}
				else
				{
					result[i] = m_pCharT[i];
				}
			}
			return result;
		}

		inline String String::ToUpperCase() const
		{
			String result(m_length);
			for (size_t i = 0; i < m_length; ++i)
			{
				if (m_pCharT[i].IsAlpha())
				{
					result[i] = m_pCharT[i].ToUpperCase();
				}
				else
				{
					result[i] = m_pCharT[i];
				}
			}
			return result;
		}

		inline String String::ValueOf(bool p_boolean)
		{
			return p_boolean ? "True" : "False";
		}

		inline String String::ValueOf(int p_integer)
		{
			char staticCharT[16];
			sprintf_s(staticCharT, "%d", p_integer);
			return String(staticCharT);
		}

		inline String String::ValueOf(size_t p_unsigned)
		{
			char staticCharT[16];
			sprintf_s(staticCharT, "%zu", p_unsigned);
			return String(staticCharT);
		}

		inline String String::ValueOf(float p_float)
		{
			char staticCharT[16];
			sprintf_s(staticCharT, "%g", p_float);
			return String(staticCharT);
		}

		inline String String::ValueOf(double p_double)
		{
			char staticCharT[16];
			sprintf_s(staticCharT, "%lg", p_double);
			return String(staticCharT);
		}

		String String::ValueOf(const PrimitiveObject& p_primitiveObject)
		{
			return String(p_primitiveObject.ToPrimitiveString());
		}

		inline Char& String::operator [](size_t p_index) const
		{
			return m_pCharT[p_index];
		}

		inline String& String::operator =(const char* const p_pPrimitiveCharT)
		{
			delete[] m_pCharT;
			m_length = Utility::LengthOf(p_pPrimitiveCharT);
			m_capacity = Utility::AdaptedCapacity(m_length);
			m_pCharT = new Char[m_capacity + 1];
			for (size_t i = 0; i < m_length; ++i)
			{
				m_pCharT[i] = p_pPrimitiveCharT[i];
			}
			m_pCharT[m_capacity] = '\0';
			return *this;
		}

		inline String& String::operator =(const String& p_string)
		{
			if (&p_string != this)
			{
				if (m_capacity != p_string.m_capacity)
				{
					delete[] m_pCharT;
					m_pCharT = new Char[p_string.m_capacity + 1];
					m_pCharT[p_string.m_capacity] = '\0';
					m_capacity = p_string.m_capacity;
				}
				for (size_t i = 0; i < p_string.m_length; ++i)
				{
					m_pCharT[i] = p_string[i];
				}
				m_length = p_string.m_length;
			}
			return *this;
		}

		inline String String::operator +(char p_primitiveChar) const
		{
			return *this + Char(p_primitiveChar);
		}

		inline String String::operator +(Char p_char) const
		{
			String result(*this);
			result.Append(p_char);
			return result;
		}

		inline String String::operator +(const char* const p_pPrimitiveCharT) const
		{
			return *this + String(p_pPrimitiveCharT);
		}

		inline String operator +(const char* const p_pPrimitiveCharT, const String& p_string)
		{
			return String(p_pPrimitiveCharT) + p_string;
		}

		inline String String::operator +(const String& p_string) const
		{
			String result(*this);
			result.Append(p_string);
			return result;
		}

		String String::operator+(const PrimitiveObject& p_primitiveObject) const
		{
			return *this + p_primitiveObject.ToPrimitiveString();
		}

		inline String& String::operator +=(char p_primitiveChar)
		{
			Append(p_primitiveChar);
			return *this;
		}

		inline String& String::operator +=(Char p_char)
		{
			Append(p_char);
			return *this;
		}

		inline String& String::operator +=(const char* const p_pPrimitiveCharT)
		{
			Append(p_pPrimitiveCharT);
			return *this;
		}

		inline String& String::operator +=(const String& p_string)
		{
			Append(p_string);
			return *this;
		}

		String& String::operator+=(const PrimitiveObject& p_primitiveObject)
		{
			Append(p_primitiveObject.ToPrimitiveString());
			return *this;
		}

		/*bool String::operator<(const String& p_string) const
		{
			if (m_capacity < p_string.m_capacity)
			{
				return true;
			}
			if (m_capacity == p_string.m_capacity)
			{
				return m_length < p_string.m_length;
			}
			return false;
		}*/

		bool String::operator<(const String& p_string) const
		{
			size_t n = m_length < p_string.m_length ? m_length : p_string.m_length;
			for (size_t i = 0; i < n; ++i)
			{
				if (m_pCharT[i] < p_string.m_pCharT[i])
				{
					return true;
				}
				if (m_pCharT[i] > p_string.m_pCharT[i])
				{
					return false;
				}
			}
			return m_length < p_string.m_length;
		}

		/*bool String::operator>(const String& p_string) const
		{
			if (m_capacity > p_string.m_capacity)
			{
				return true;
			}
			if (m_capacity == p_string.m_capacity)
			{
				return m_length > p_string.m_length;
			}
			return false;
		}*/

		bool String::operator>(const String& p_string) const
		{
			size_t n = m_length < p_string.m_length ? m_length : p_string.m_length;
			for (size_t i = 0; i < n; ++i)
			{
				if (m_pCharT[i] < p_string.m_pCharT[i])
				{
					return false;
				}
				if (m_pCharT[i] > p_string.m_pCharT[i])
				{
					return true;
				}
			}
			return m_length > p_string.m_length;
		}

		inline bool String::operator ==(const char* const p_pPrimitiveCharT) const
		{
			size_t otherLength = Utility::LengthOf(p_pPrimitiveCharT);
			if (m_length != otherLength)
			{
				return false;
			}
			for (size_t i = 0; i < m_length; ++i)
			{
				if (m_pCharT[i] != p_pPrimitiveCharT[i])
				{
					return false;
				}
			}
			return true;
		}

		inline bool String::operator ==(const String& p_string) const
		{
			if (m_length != p_string.m_length)
			{
				return false;
			}
			for (size_t i = 0; i < m_length; ++i)
			{
				if (m_pCharT[i] != p_string.m_pCharT[i])
				{
					return false;
				}
			}
			return true;
		}

		inline bool String::operator !=(const char* const p_pPrimitiveCharT) const
		{
			size_t otherLength = Utility::LengthOf(p_pPrimitiveCharT);
			if (m_length != otherLength)
			{
				return true;
			}
			for (size_t i = 0; i < m_length; ++i)
			{
				if (m_pCharT[i] != p_pPrimitiveCharT[i])
				{
					return true;
				}
			}
			return false;
		}

		inline bool String::operator !=(const String& p_string) const
		{
			if (m_length != p_string.m_length)
			{
				return true;
			}
			for (size_t i = 0; i < m_length; ++i)
			{
				if (m_pCharT[i] != p_string.m_pCharT[i])
				{
					return true;
				}
			}
			return false;
		}
	}
}
