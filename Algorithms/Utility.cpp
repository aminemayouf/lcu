#include "Utility.h"

namespace lcu
{
	inline namespace algorithms
	{
		size_t Utility::AdaptedCapacity(size_t p_size)
		{
			if (p_size <= 1)
				return p_size;

			size_t capacity = 2;

			while (p_size > capacity)
				capacity *= 2;

			return capacity;
		}

		char* Utility::CopyOf(const char* const p_pPrimitiveCharT)
		{
			return CopyOf(p_pPrimitiveCharT, LengthOf(p_pPrimitiveCharT));
		}

		char* Utility::CopyOf(const char* const p_pPrimitiveCharT, size_t p_size)
		{
			char* result = new char[p_size + 1];
			for (size_t i = 0; i < p_size; ++i)
				result[i] = p_pPrimitiveCharT[i];
			result[p_size] = '\0';
			return result;
		}

		size_t Utility::LengthOf(const char* const p_pPrimitiveCharT)
		{
			if (p_pPrimitiveCharT == nullptr)
				return 0;

			size_t i = 0;

			while (p_pPrimitiveCharT[i] != '\0')
				++i;

			return i;
		}

		int Utility::RandomInt(int p_min, int p_max)
		{
			std::random_device device;
			std::mt19937 range(device());
			std::uniform_int_distribution<std::mt19937::result_type> distribution(p_min, p_max);
			// distribution in range [min, max]
			return distribution(range);
		}
	}
}
