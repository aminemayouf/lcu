#include "Config.h"

#include "Algorithms/Conversion.h"
#include "Algorithms/Encryption.h"
#include "Algorithms/Searching.h"
#include "Algorithms/Sorting.h"
#include "Algorithms/Utility.h"
#include "Algorithms/Validation.h"

#include <iostream>
#include <chrono>

#define N 100

int main(int argc, int argv[]) {

	std::cout << "LCU version " << LCU_VERSION_MAJOR << "." << LCU_VERSION_MINOR << std::endl << std::endl;

	char* str = "Hello world!";
	char c = str[4];

	std::cout << "ToLowerCase(" << c << ") = " << LCU::Algorithms::Conversion::ToLowerCase(c) << std::endl;

	char* estr = LCU::Algorithms::Encryption::CaesarCipher(str, 5);
	std::cout << "CaesarCipher(" << str << ") = " << estr << std::endl;
	std::cout << "CaesarDecypher(" << estr << ") = " << LCU::Algorithms::Encryption::CaesarDecipher(estr, 5) << std::endl;
	estr = LCU::Algorithms::Encryption::VigenereCipher(str, "MyKey");
	std::cout << "VigenereCypher(" << str << ") = " << estr << std::endl;
	std::cout << "VigenereDecypher(" << estr << ") = " << LCU::Algorithms::Encryption::VigenereDecipher(estr, "MyKey") << std::endl;

	std::cout << "BinarySearch(" << c << ") = " << LCU::Algorithms::Searching<char>::BinarySearch(str, strlen(str), c) << std::endl;
	std::cout << "SequentialSearch(" << c << ") = " << LCU::Algorithms::Searching<char>::SequentialSearch(str, strlen(str), c) << std::endl;

	int* ints = new int[N];
	for (size_t i = 0; i < N; ++i) {
		ints[i] = LCU::Algorithms::Utility::RandomInt(0, 9);
	}
	std::cout << "QuickSort(";
	for (int i = 0; i < N; ++i) {
		std::cout << ints[i];
	}
	std::cout << ") = ";
	auto start = std::chrono::high_resolution_clock::now();
	LCU::Algorithms::Sorting<int>::QuickSort(ints, 0, N-1);
	auto stop = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < N; ++i) {
		std::cout << ints[i];
	}
	std::cout << " | " << std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() << "µs" << std::endl;

	std::cout << "RandomInt() = " << LCU::Algorithms::Utility::RandomInt() << std::endl;

	std::cout << "IsLowerCase(" << c << ") = " << LCU::Algorithms::Validation::IsLowerCase(c) << std::endl;

	delete[] ints;
	return 0;
}
