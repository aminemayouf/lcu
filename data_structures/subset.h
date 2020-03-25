#pragma once


namespace lcu
{
	inline namespace data_structures
	{
		/**
		 * Subset Class
		 * A structure to represent a subset for union-find
		 *
		 * @project data_structures
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
