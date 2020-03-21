#pragma once


namespace LCU {
	inline namespace DataStructures {
		class Object;
	}
	inline namespace Interfaces {
		/**
		 * IClonable Interface
		 *
		 * @project Interfaces
		 * @author Amine MAYOUF
		 */
		class IClonable {

		public:
			IClonable() = default;
			virtual ~IClonable() = default;

			virtual Object Clone() const = 0;
		};
	}
}
