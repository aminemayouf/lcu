#pragma once


namespace lcu
{
	inline namespace data_structures
	{
		/**
		 * Subset Class
		 * A structure to represent a subset for union-find
		 *
		 * @project DataStructures
		 * @author Amine MAYOUF
		 */
		template <typename Type>
		class Subset
		{
		public:
			int parent;
			int rank;

			Subset() = default;
		};
	}
}
