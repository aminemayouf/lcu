#pragma once

#include <limits>
#include <random>


namespace LCU {
	inline namespace Algorithms {
		/**
		 * Utility Class
		 * 
		 * @project Algorithms
		 * @author Amine MAYOUF
		 */
		class Utility {
			/*
			 * Methods
			 */
		public:
			Utility() = delete;
			~Utility() = delete;

			// A

			/**
			 * Calculates the adapted capacity for a given p_size to amortize the cost of any additions.
			 */
			static size_t AdaptedCapacity(size_t p_size);

			/**
			 * @return A copy of p_pPrimitiveCharT
			 * @complexity o(2LengthOf(p_pPrimitiveCharT+1))
			 */
			static char* CopyOf(const char*const p_pPrimitiveCharT);
			/**
			 * @return A copy of p_pPrimitiveCharT
			 * @complexity o(LengthOf(p_pPrimitiveCharT+1))
			 */
			static char* CopyOf(const char*const p_pPrimitiveCharT, size_t p_size);

			// H
			template <typename Type>
			static size_t HashCode();
			template <typename Type>
			static size_t HashCodeOf(const Type& p_type);

			// L
			template <typename Type, size_t length>
			static size_t LengthOf(Type (&)[length]);
			/**
			 * @return The length of a string excluding minus end of sequence character \0
			 */
			static size_t LengthOf(const char*const p_pPrimitiveCharT);

			// M
			template <typename Type>
			static Type Max(const Type& p_a, const Type& p_b);
			template <typename Type>
			static Type Min(const Type& p_a, const Type& p_b);

			// N
			template <typename Type>
			static const char* Name();
			template <typename Type>
			static const char* NameOf(const Type& p_type);

			// R
			static int RandomInt(int p_min = 0, int p_max = std::numeric_limits<int>::max());

			template <typename Type>
			static const char* RawName();
			template <typename Type>
			static const char* RawNameOf(const Type& p_type);

			// S
			template <typename Type>
			static void Swap(Type& x, Type& y);
		};

		template <typename Type>
		size_t Utility::HashCode() { return typeid(Type).hash_code(); }

		template <typename Type>
		size_t Utility::HashCodeOf(const Type& p_type) { return typeid(p_type).hash_code(); }

		/**
		 * @return The size of an array
		 */
		template <typename Type, size_t length>
		size_t Utility::LengthOf(Type (&)[length]) { return length; }

		template <typename Type>
		Type Utility::Max(const Type& p_a, const Type& p_b) { }

		template <typename Type>
		Type Utility::Min(const Type& p_a, const Type& p_b) { return p_a < p_a ? p_a : p_b; }

		template <typename Type>
		const char* Utility::Name() { return typeid(Type).name(); }

		template <typename Type>
		const char* Utility::NameOf(const Type& p_type) { return typeid(p_type).name(); }

		template <typename Type>
		const char* Utility::RawName() { return typeid(Type).raw_name(); }

		template <typename Type>
		const char* Utility::RawNameOf(const Type& p_type) { return typeid(p_type).raw_name(); }

		template <typename Type>
		void Utility::Swap(Type& p_x, Type& p_y) {
			Type tmp = p_x;
			p_x = p_y;
			p_y = tmp;
		}
	}
}
