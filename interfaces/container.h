#pragma once


namespace lcu
{
	inline namespace interfaces
	{
		/**
		 * IContainer Interface
		 *
		 * @project Interfaces
		 * @author Amine MAYOUF
		 */
		template <typename Type>
		class IContainer
		{
		public:
			virtual ~IContainer() = default;

			// C
			virtual bool Contains(const Type& p_value) const = 0;
			// I
			virtual bool IsEmpty() const = 0;
			// P
			virtual void Purge() = 0;
		};
	}
}
