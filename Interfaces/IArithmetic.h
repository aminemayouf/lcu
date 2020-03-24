#pragma once


namespace LCU
{
	inline namespace Interfaces
	{
		/**
		 * IArithmetic Interface
		 *
		 * @project Interfaces
		 * @author Amine MAYOUF
		 */
		template <typename Type>
		class IArithmetic
		{
		public:
			IArithmetic() = default;
			virtual ~IArithmetic() = default;

			// #
			virtual Type operator +(const Type& p_other) const = 0;
			virtual Type operator -(const Type& p_other) const = 0;
			virtual Type operator *(const Type& p_other) const = 0;
			virtual Type operator /(const Type& p_other) const = 0;
			virtual Type& operator +=(const Type& p_other) = 0;
			virtual Type& operator -=(const Type& p_other) = 0;
			virtual Type& operator *=(const Type& p_other) = 0;
			virtual Type& operator /=(const Type& p_other) = 0;
		};
	}
}
