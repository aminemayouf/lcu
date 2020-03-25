#pragma once


namespace lcu
{
	inline namespace interfaces
	{
		/**
		 * IComparable Interface
		 *
		 * @project Interfaces
		 * @author Amine MAYOUF
		 */
		template <class Class>
		class IComparable
		{
		public:
			IComparable() = default;
			virtual ~IComparable() = default;

			virtual int CompareTo(const Class& p_other) const;

			virtual bool operator <(const Class& p_other) const = 0;
			virtual bool operator <=(const Class& p_other) const;
			virtual bool operator >(const Class& p_other) const = 0;
			virtual bool operator >=(const Class& p_other) const;
			virtual bool operator ==(const Class& p_other) const = 0;
			virtual bool operator !=(const Class& p_other) const;
		};

		template <class Class>
		int IComparable<Class>::CompareTo(const Class& p_other) const
		{
			if (*this < p_other)
			{
				return -1;
			}
			if (*this > p_other)
			{
				return 1;
			}
			return 0;
		}

		template <class Class>
		bool IComparable<Class>::operator<=(const Class& p_other) const
		{
			return (*this < p_other) || (*this == p_other);
		}

		template <class Class>
		bool IComparable<Class>::operator>=(const Class& p_other) const
		{
			return (*this > p_other) || (*this == p_other);
		}

		template <class Class>
		bool IComparable<Class>::operator !=(const Class& p_other) const
		{
			return !(*this == p_other);
		}
	}
}
