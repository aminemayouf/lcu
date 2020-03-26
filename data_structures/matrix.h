#pragma once

#include "array.h"

namespace lcu
{
	inline namespace data_structures
	{
		/**
		 * Matrix Class
		 *
		 * @project data_structures
		 * @author Amine MAYOUF
		 */
		template <typename Type>
		class Matrix : public Object, public IContainer<Type>, public IComparable<Matrix<Type>>
		{
		protected:
			Type** m_pDataM;
			size_t m_rows;
			size_t m_cols;

		public:
			Matrix();
			Matrix(size_t p_rows, size_t p_cols);
			Matrix(size_t p_rows, size_t p_cols, const Type& p_defaultValue);
			Matrix(const Matrix& p_matrix);
			virtual ~Matrix();

			// Type** DataM() const;
			size_t Rows() const;
			size_t Cols() const;
			Type ValueAt(size_t p_rowIndex, size_t p_columnIndex) const;
			void Assign(const Type& p_value, size_t p_rowIndex, size_t p_columnIndex);
			// A
			Matrix Adjoint() const;
			Type** AllocateMemory(size_t p_rows, size_t p_cols);
			// C
			Array<Type> ColumnAt(size_t p_index) const;
			bool Contains(const Type& p_value) const override;
			static Type** CopyOf(Type** p_pDataM, size_t p_rows, size_t p_cols);
			static void CopyValue(const Type& p_value, Type** p_pTo, size_t p_rows, size_t p_cols);
			static void CopyValues(const Type** p_pFrom, Type** p_pTo, size_t p_rows, size_t p_cols);
			// D
			Type Determinant() const;
			// F
			void FillWith(const Type& p_value);
			static void FreeMemory(Type** p_pDataM, size_t p_rows);
			static void FreeMemorySafe(Type** p_pDataM, size_t p_rows);
			// I
			bool IsEmpty() const override;
			bool IsSorted() const;
			bool IsSquare() const;
			// L
			Array<Type> LineAt(size_t p_index) const;
			// M
			Type Max() const;
			Type Min() const;
			// P
			void Purge() override;
			// R		
			void ReplaceAll(const Type& p_valueToReplace, const Type& p_replacementValue);
			void ReplaceFirst(const Type& p_valueToReplace, const Type& p_replacementValue);
			void Reverse();
			Matrix Reversed() const;
			// S
			// void Sort(); // TODO : Implement
			Matrix SubMatrix(size_t p_rowToSubstract, size_t p_columnToSubstract) const;
			// T
			String ToString() const override;
			void Transpose();
			Matrix Transposed() const;
			// #
			Matrix& operator =(const Matrix& p_matrix);
			bool operator <(const Matrix& p_matrix) const override;
			bool operator >(const Matrix& p_matrix) const override;
			bool operator ==(const Matrix& p_matrix) const override;

			Matrix operator +(const double& p_value) const;
			Matrix operator +(const Matrix& p_matrix) const;
			Matrix operator -(const double& p_value) const;
			Matrix operator -(const Matrix& p_matrix) const;
			Matrix operator *(const double& p_value) const;
			Matrix operator *(const Matrix& p_matrix) const;
			Matrix operator /(const double& p_value) const;
			Matrix operator /(const Matrix& p_matrix) const;
			Matrix& operator +=(const double& p_value);
			Matrix& operator +=(const Matrix& p_matrix);
			Matrix& operator -=(const double& p_value);
			Matrix& operator -=(const Matrix& p_matrix);
			Matrix& operator *=(const double& p_value);
			Matrix& operator *=(const Matrix& p_matrix);
			Matrix& operator /=(const double& p_value);
			Matrix& operator /=(const Matrix& p_matrix);
		};

		template <typename Type>
		Matrix<Type>::Matrix() : m_pDataM(nullptr), m_rows(0), m_cols(0)
		{
		}

		template <typename Type>
		Matrix<Type>::Matrix(size_t p_rows, size_t p_cols)
			: m_rows(p_rows),
			  m_cols(p_cols)
		{
			m_pDataM = AllocateMemory(m_rows, m_cols);
		}

		template <typename Type>
		Matrix<Type>::Matrix(size_t p_rows, size_t p_cols, const Type& p_defaultValue)
			: m_rows(p_rows),
			  m_cols(p_cols)
		{
			m_pDataM = new Type*[m_rows];
			for (size_t i = 0; i < m_rows; ++i)
			{
				m_pDataM[i] = new Type[m_cols];
				for (size_t j = 0; j < m_cols; ++j)
				{
					m_pDataM[i][j] = p_defaultValue;
				}
			}
		}

		template <typename Type>
		Matrix<Type>::Matrix(const Matrix& p_matrix) :
			m_rows(p_matrix.m_rows),
			m_cols(p_matrix.m_cols)
		{
			m_pDataM = CopyOf(p_matrix.m_pDataM, p_matrix.m_rows, p_matrix.m_cols);
		}

		template <typename Type>
		Matrix<Type>::~Matrix()
		{
			FreeMemory(m_pDataM, m_rows);
		}

		template <typename Type>
		size_t Matrix<Type>::Rows() const
		{
			return m_rows;
		}

		template <typename Type>
		size_t Matrix<Type>::Cols() const
		{
			return m_cols;
		}

		template <typename Type>
		Type Matrix<Type>::ValueAt(size_t p_rowIndex, size_t p_columnIndex) const
		{
			/*if (p_rowIndex < 0 || p_rowIndex >= m_rows || p_columnIndex < 0 || p_columnIndex >= m_cols) 
			{
				throw ArgumentOutOfRangeException();
			}*/
			return m_pDataM[p_rowIndex][p_columnIndex];
		}

		template <typename Type>
		void Matrix<Type>::Assign(const Type& p_value, size_t p_rowIndex, size_t p_columnIndex)
		{
			/*if (p_rowIndex < 0 || p_rowIndex >= m_rows || p_columnIndex < 0 || p_columnIndex >= m_cols) 
			{
				throw ArgumentOutOfRangeException();
			}*/
			m_pDataM[p_rowIndex][p_columnIndex] = p_value;
		}

		template <typename Type>
		Matrix<Type> Matrix<Type>::Adjoint() const
		{
			Matrix result(m_rows, m_cols);
			double cofactor;
			for (size_t i = 0; i < m_rows; ++i)
			{
				for (size_t j = 0; j < m_cols; ++j)
				{
					cofactor = MathFunctions::Pow(-1, static_cast<double>(i + j)) * SubMatrix(i, j).Determinant();
					result.m_pDataM[i][j] = cofactor;
				}
			}
			return result;
		}

		template <typename Type>
		Type** Matrix<Type>::AllocateMemory(size_t p_rows, size_t p_cols)
		{
			Type** pDataM = new Type*[p_rows];
			for (size_t i = 0; i < p_rows; ++i)
			{
				pDataM[i] = new Type[p_cols];
			}
			return pDataM;
		}

		template <typename Type>
		Array<Type> Matrix<Type>::ColumnAt(size_t p_index) const
		{
			if (p_index < 0 || p_index >= m_cols)
			{
				// throw ArgumentOutOfRangeException();
				return Array<Type>();
			}

			Array<Type> result(m_rows);
			for (size_t i = 0; i < m_rows; ++i)
			{
				result[i] = m_pDataM[i][p_index];
			}

			return result;
		}

		template <typename Type>
		bool Matrix<Type>::Contains(const Type& p_value) const
		{
			/*if (IsEmpty()) 
			{
				throw NullPointerException();
			}*/

			for (size_t i = 0; i < m_rows; ++i)
			{
				for (size_t j = 0; j < m_cols; ++j)
				{
					if (m_pDataM[i][j] == p_value)
					{
						return true;
					}
				}
			}

			return false;
		}

		template <typename Type>
		Type** Matrix<Type>::CopyOf(Type** p_pDataM, size_t p_rows, size_t p_cols)
		{
			if (!p_pDataM)
			{
				// throw ArgumentNullException();
				return nullptr;
			}

			Type** pResult = new Type*[p_rows];
			for (size_t i = 0; i < p_rows; ++i)
			{
				pResult[i] = new Type[p_cols];

				for (size_t j = 0; j < p_cols; ++j)
				{
					pResult[i][j] = p_pDataM[i][j];
				}
			}

			return pResult;
		}

		template <typename Type>
		void Matrix<Type>::CopyValue(const Type& p_value, Type** const p_pTo, size_t p_rows, size_t p_cols)
		{
			for (size_t i = 0; i < p_rows; ++i)
			{
				for (size_t j = 0; j < p_cols; ++j)
				{
					p_pTo[i][j] = p_value;
				}
			}
		}

		template <typename Type>
		void Matrix<Type>::CopyValues(const Type** const p_pFrom, Type** const p_pTo, size_t p_rows, size_t p_cols)
		{
			for (size_t i = 0; i < p_rows; ++i)
			{
				for (size_t j = 0; j < p_cols; ++j)
				{
					p_pTo[i][j] = p_pFrom[i][j];
				}
			}
		}

		template <typename Type>
		Type Matrix<Type>::Determinant() const
		{
			Type** pMatrix = new Type* [m_rows];
			for (size_t i = 0; i < m_rows; ++i)
			{
				pMatrix[i] = new Type[m_cols];
				for (size_t j = 0; j < m_cols; ++j)
				{
					pMatrix[i][j] = m_pDataM[i][j];
				}
			}

			size_t rank, highestRank;
			Type coefficient, highestCoefficient;
			Type result = 1;

			for (size_t i = 0; i < m_rows - 1; ++i)
			{
				highestRank = i;
				for (rank = i + 1; rank < m_rows; ++rank)
				{
					if (MathFunctions::Abs(pMatrix[highestRank][i]) < MathFunctions::Abs(pMatrix[rank][i]))
					{
						highestRank = rank;
					}
				}

				highestCoefficient = pMatrix[highestRank][i];

				if (MathFunctions::Abs(highestCoefficient) <= 1e-10)
				{
					return 0;
				}

				if (highestRank != i)
				{
					for (size_t j = i; j < m_cols; ++j)
					{
						Utility::Swap(pMatrix[i][j], pMatrix[highestRank][j]);
					}
					result *= -1.;
				}
				result *= highestCoefficient;

				for (rank = i + 1; rank < m_rows; ++rank)
				{
					coefficient = pMatrix[rank][i] / highestCoefficient;
					for (size_t j = i; j < m_rows; ++j)
					{
						pMatrix[rank][j] -= coefficient * pMatrix[i][j];
					}
				}
			}

			result *= pMatrix[m_rows - 1][m_rows - 1];
			return result;
		}

		template <typename Type>
		void Matrix<Type>::FillWith(const Type& p_value)
		{
			CopyValue(p_value, m_pDataM, m_rows, m_cols);
		}

		template <typename Type>
		void Matrix<Type>::FreeMemory(Type** p_pDataM, size_t p_rows)
		{
			for (size_t i = 0; i < p_rows; ++i)
			{
				delete[] p_pDataM[i];
			}
			delete[] p_pDataM;
		}

		template <typename Type>
		void Matrix<Type>::FreeMemorySafe(Type** p_pDataM, size_t p_rows)
		{
			FreeMemory(p_pDataM, p_rows);
			p_pDataM = nullptr;
		}

		template <typename Type>
		bool Matrix<Type>::IsSquare() const
		{
			return m_rows == m_cols ? true : false;
		}

		template <typename Type>
		bool Matrix<Type>::IsEmpty() const
		{
			return !m_pDataM ? true : false;
		}

		template <typename Type>
		bool Matrix<Type>::IsSorted() const
		{
			for (size_t i = 0; i < m_rows; ++i)
			{
				for (size_t j = 0; j < m_cols; ++j)
				{
					if (j != m_cols - 1)
					{
						if (m_pDataM[i][j] > m_pDataM[i][j + 1])
						{
							return false;
						}
					}
					else
					{
						if (i != m_rows - 1)
						{
							if (m_pDataM[i][j] > m_pDataM[i + 1][0])
							{
								return false;
							}
						}
					}
				}
			}
			return true;
		}

		template <typename Type>
		Array<Type> Matrix<Type>::LineAt(size_t p_index) const
		{
			if (p_index < 0 || p_index >= m_rows)
			{
				// throw ArgumentOutOfRangeException();
				return Array<Type>();
			}

			Array<Type> result(m_cols);
			for (size_t j = 0; j < m_cols; ++j)
			{
				result[j] = m_pDataM[p_index][j];
			}

			return result;
		}

		template <typename Type>
		Type Matrix<Type>::Max() const
		{
			/*if (IsEmpty()) 
			{
				throw NullPointerException();
			}*/

			Type max = m_pDataM[0][0];
			for (size_t i = 0; i < m_rows; ++i)
			{
				for (size_t j = 0; j < m_cols; ++j)
				{
					if (m_pDataM[i][j] > max)
					{
						max = m_pDataM[i][j];
					}
				}
			}

			return max;
		}

		template <typename Type>
		Type Matrix<Type>::Min() const
		{
			/*if (IsEmpty()) 
			{
				throw NullPointerException();
			}*/

			Type min = m_pDataM[0][0];
			for (size_t i = 0; i < m_rows; ++i)
			{
				for (size_t j = 0; j < m_cols; ++j)
				{
					if (m_pDataM[i][j] < min)
					{
						min = m_pDataM[i][j];
					}
				}
			}

			return min;
		}

		template <typename Type>
		void Matrix<Type>::Purge()
		{
			FreeMemorySafe(m_pDataM, m_rows);

			m_rows = 0;
			m_cols = 0;
		}

		template <typename Type>
		void Matrix<Type>::ReplaceAll(const Type& p_valueToReplace, const Type& p_replacementValue)
		{
			for (size_t i = 0; i < m_rows; ++i)
			{
				for (size_t j = 0; j < m_cols; ++j)
				{
					if (m_pDataM[i][j] == p_valueToReplace)
					{
						m_pDataM[i][j] = p_replacementValue;
					}
				}
			}
		}

		template <typename Type>
		void Matrix<Type>::ReplaceFirst(const Type& p_valueToReplace, const Type& p_replacementValue)
		{
			for (size_t i = 0; i < m_rows; ++i)
			{
				for (size_t j = 0; j < m_cols; ++j)
				{
					if (m_pDataM[i][j] == p_valueToReplace)
					{
						m_pDataM[i][j] = p_replacementValue;
						return;
					}
				}
			}
		}

		template <typename Type>
		void Matrix<Type>::Reverse()
		{
			*this = Reversed();
		}

		template <typename Type>
		Matrix<Type> Matrix<Type>::Reversed() const
		{
			Matrix result;
			const double determinant = Determinant();
			if (determinant != 0)
			{
				result = Adjoint();
				result.Transpose();
				result *= 1 / determinant;
			}
			return result;
		}

		template <typename Type>
		Matrix<Type> Matrix<Type>::SubMatrix(size_t p_rowToSubstract, size_t p_columnToSubstract) const
		{
			if (p_rowToSubstract > m_rows || p_columnToSubstract > m_cols)
			{
				//throw ArgumentOutOfRangeException();
				return Matrix();
			}
			Matrix result(m_rows - 1, m_cols - 1);
			size_t row = 0, column = 0;
			for (size_t i = 0; i < m_rows; ++i)
			{
				if (i != p_rowToSubstract)
				{
					for (size_t j = 0; j < m_cols; ++j)
					{
						if (j != p_columnToSubstract)
						{
							result.m_pDataM[row][column] = m_pDataM[i][j];
							++column;
							if (column == m_cols - 1)
							{
								column = 0;
								++row;
							}
						}
					}
				}
			}
			return result;
		}

		template <typename Type>
		String Matrix<Type>::ToString() const
		{
			String result;
			for (size_t i = 0; i < m_rows; ++i)
			{
				for (size_t j = 0; j < m_cols; ++j)
				{
					result += " ";
					result += String::ValueOf(m_pDataM[i][j]);
					result += " |";
				}
				result += "\n";
			}
			return result.SubString(0, result.Length() - 2);
		}

		template <typename Type>
		void Matrix<Type>::Transpose()
		{
			*this = Transposed();
		}

		template <typename Type>
		Matrix<Type> Matrix<Type>::Transposed() const
		{
			Matrix result(m_cols, m_rows);
			for (size_t i = 0; i < m_rows; ++i)
			{
				for (size_t j = 0; j < m_cols; ++j)
				{
					result.m_pDataM[j][i] = m_pDataM[i][j];
				}
			}
			return result;
		}

		template <typename Type>
		Matrix<Type>& Matrix<Type>::operator =(const Matrix<Type>& p_matrix)
		{
			if (&p_matrix != this)
			{
				if (m_rows == p_matrix.m_rows && m_cols == p_matrix.m_cols)
				{
					for (size_t i = 0; i < p_matrix.m_rows; ++i)
					{
						for (size_t j = 0; j < p_matrix.m_cols; ++j)
						{
							m_pDataM[i][j] = p_matrix.m_pDataM[i][j];
						}
					}
				}
				else if (m_rows == p_matrix.m_rows && m_cols != p_matrix.m_cols)
				{
					for (size_t i = 0; i < m_rows; ++i)
					{
						delete[] m_pDataM[i];
						m_pDataM[i] = new Type[p_matrix.m_cols];
						m_cols = p_matrix.m_cols;
					}
				}
				else if (m_rows != p_matrix.m_rows || m_cols != p_matrix.m_cols)
				{
					FreeMemorySafe(m_pDataM, m_rows);
					m_pDataM = CopyOf(p_matrix.m_pDataM, p_matrix.m_rows, p_matrix.m_cols);
					m_rows = p_matrix.m_rows;
					m_cols = p_matrix.m_cols;
				}
			}
			return *this;
		}

		template <typename Type>
		bool Matrix<Type>::operator<(const Matrix& p_matrix) const
		{
			return m_rows * m_cols < p_matrix.m_rows * p_matrix.m_cols;
		}

		template <typename Type>
		bool Matrix<Type>::operator>(const Matrix& p_matrix) const
		{
			return m_rows * m_cols > p_matrix.m_rows * p_matrix.m_cols;
		}

		template <typename Type>
		bool Matrix<Type>::operator ==(const Matrix& p_matrix) const
		{
			if (m_rows != p_matrix.m_rows || m_cols != p_matrix.m_cols)
			{
				return false;
			}

			for (size_t i = 0; i < m_rows; ++i)
			{
				for (size_t j = 0; j < m_cols; ++j)
				{
					if (m_pDataM[i][j] != p_matrix.m_pDataM[i][j])
					{
						return false;
					}
				}
			}

			return true;
		}

		template <typename Type>
		Matrix<Type> Matrix<Type>::operator+(const double& p_value) const
		{
			Matrix result(*this);
			for (size_t i = 0; i < m_rows; ++i)
			{
				for (size_t j = 0; j < m_cols; ++j)
				{
					result.m_pDataM[i][j] += p_value;
				}
			}
			return result;
		}

		template <typename Type>
		Matrix<Type> Matrix<Type>::operator+(const Matrix& p_matrix) const
		{
			/*if (m_rows != pMatrix.m_rows || m_cols != pMatrix.m_cols)
			{
				throw UnsupportedOperationException();
			}*/

			Matrix result(*this);
			for (size_t i = 0; i < m_rows; ++i)
			{
				for (size_t j = 0; j < m_cols; ++j)
				{
					result.m_pDataM[i][j] += p_matrix.m_pDataM[i][j];
				}
			}
			return result;
		}

		template <typename Type>
		Matrix<Type> Matrix<Type>::operator-(const double& p_value) const
		{
			/*if (m_rows != pMatrix.m_rows || m_cols != pMatrix.m_cols)
			{
				throw UnsupportedOperationException();
			}*/

			Matrix result(*this);
			for (size_t i = 0; i < m_rows; ++i)
			{
				for (size_t j = 0; j < m_cols; ++j)
				{
					result.m_pDataM[i][j] -= p_value;
				}
			}
			return result;
		}

		template <typename Type>
		Matrix<Type> Matrix<Type>::operator-(const Matrix& p_matrix) const
		{
			Matrix result(*this);
			for (size_t i = 0; i < m_rows; ++i)
			{
				for (size_t j = 0; j < m_cols; ++j)
				{
					result.m_pDataM[i][j] -= p_matrix.m_pDataM[i][j];
				}
			}
			return result;
		}

		template <typename Type>
		Matrix<Type> Matrix<Type>::operator*(const double& p_value) const
		{
			Matrix result(*this);
			for (size_t i = 0; i < m_rows; ++i)
			{
				for (size_t j = 0; j < m_cols; ++j)
				{
					result.m_pDataM[i][j] *= p_value;
				}
			}
			return result;
		}

		template <typename Type>
		Matrix<Type> Matrix<Type>::operator*(const Matrix& p_matrix) const
		{
			/*if (m_rows != pMatrix.m_cols || m_cols != pMatrix.m_rows)
			{
				throw ArgumentOutOfRangeException();
			}*/

			Matrix result(*this);
			for (size_t i = 0; i < m_rows; ++i)
			{
				for (size_t j = 0; j < p_matrix.m_cols; ++j)
				{
					result.m_pDataM[i][j] = 0;
					for (size_t k = 0; k < m_cols; ++k)
					{
						result.m_pDataM[i][j] += m_pDataM[i][k] * p_matrix.m_pDataM[k][j];
					}
				}
			}
			return result;
		}

		template <typename Type>
		Matrix<Type> Matrix<Type>::operator/(const double& p_value) const
		{
			// TODO: Implement
			Matrix result;
			return result;
		}

		template <typename Type>
		Matrix<Type> Matrix<Type>::operator/(const Matrix& p_matrix) const
		{
			// TODO: Implement
			Matrix result;
			return result;
		}

		template <typename Type>
		Matrix<Type>& Matrix<Type>::operator+=(const double& p_value)
		{
			for (size_t i = 0; i < m_rows; ++i)
			{
				for (size_t j = 0; j < m_cols; ++j)
				{
					m_pDataM[i][j] += p_value;
				}
			}
			return *this;
		}

		template <typename Type>
		Matrix<Type>& Matrix<Type>::operator+=(const Matrix& p_matrix)
		{
			/*if (m_rows != pMatrix.m_rows || m_cols != pMatrix.m_cols)
			{
				throw UnsupportedOperationException();
			}*/

			for (size_t i = 0; i < m_rows; ++i)
			{
				for (size_t j = 0; j < m_cols; ++j)
				{
					m_pDataM[i][j] += p_matrix.m_pDataM[i][j];
				}
			}
			return *this;
		}

		template <typename Type>
		Matrix<Type>& Matrix<Type>::operator-=(const double& p_value)
		{
			for (size_t i = 0; i < m_rows; ++i)
			{
				for (size_t j = 0; j < m_cols; ++j)
				{
					m_pDataM[i][j] -= p_value;
				}
			}
			return *this;
		}

		template <typename Type>
		Matrix<Type>& Matrix<Type>::operator-=(const Matrix& p_matrix)
		{
			/*if (m_rows != pMatrix.m_rows || m_cols != pMatrix.m_cols)
			{
				throw UnsupportedOperationException();
			}*/

			for (size_t i = 0; i < m_rows; ++i)
			{
				for (size_t j = 0; j < m_cols; ++j)
				{
					m_pDataM[i][j] -= p_matrix.m_pDataM[i][j];
				}
			}
			return *this;
		}

		template <typename Type>
		Matrix<Type>& Matrix<Type>::operator*=(const double& p_value)
		{
			for (size_t i = 0; i < m_rows; ++i)
			{
				for (size_t j = 0; j < m_cols; ++j)
				{
					m_pDataM[i][j] *= p_value;
				}
			}
			return *this;
		}

		template <typename Type>
		Matrix<Type>& Matrix<Type>::operator*=(const Matrix& p_matrix)
		{
			/*if (m_rows != pMatrix.m_cols || m_cols != pMatrix.m_rows)  {
				throw UnsupportedOperationException();
			}*/

			double** pTemp = CopyOf(m_pDataM, m_rows, m_cols);
			for (size_t i = 0; i < m_rows; ++i)
			{
				delete[] m_pDataM[i];
				m_pDataM[i] = new double[p_matrix.m_cols];
			}

			for (size_t i = 0; i < m_rows; ++i)
			{
				for (size_t j = 0; j < p_matrix.m_cols; ++j)
				{
					m_pDataM[i][j] = 0;
					for (size_t k = 0; k < m_cols; ++k)
					{
						m_pDataM[i][j] += pTemp[i][k] * p_matrix.m_pDataM[k][j];
					}
				}
			}

			m_cols = p_matrix.m_cols;
			return *this;
		}

		template <typename Type>
		Matrix<Type>& Matrix<Type>::operator/=(const double& p_value)
		{
			// TODO: Implement
			return *this;
		}

		template <typename Type>
		Matrix<Type>& Matrix<Type>::operator/=(const Matrix& p_matrix)
		{
			// TODO: Implement
			return *this;
		}
	}
}
