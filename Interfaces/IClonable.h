#pragma once


namespace lcu
{
	inline namespace data_structures
	{
		class Object;
	}

	inline namespace interfaces
	{
		/**
		 * IClonable Interface
		 *
		 * @project Interfaces
		 * @author Amine MAYOUF
		 */
		class IClonable
		{
		public:
			IClonable() = default;
			virtual ~IClonable() = default;

			virtual Object Clone() const = 0;
		};
	}
}
