#include "config.h"

#include "algorithms/algorithms.h"
#include "data_structures/data_structures.h"
#include "events/events.h"
#include "system/system.h"

#include <iostream>
#include <chrono>
#include <cstring>

#define N 100

void Hello() {
	std::cout << "Hello";
}

void World() {
	std::cout << "World!" << std::endl;
}

int main(int argc, int argv[]) {

	std::cout << "LCU version " << LCU_VERSION_MAJOR << "." << LCU_VERSION_MINOR << std::endl << std::endl;

#ifdef USE_ALGORITHMS
	char* str = "Hello world!";
	char c = str[4];

	std::cout << "ToLowerCase(" << c << ") = " << lcu::algorithms::Conversion::ToLowerCase(c) << std::endl;

	char* estr = lcu::algorithms::Encryption::CaesarCipher(str, 5);
	std::cout << "CaesarCipher(" << str << ") = " << estr << std::endl;
	std::cout << "CaesarDecypher(" << estr << ") = " << lcu::algorithms::Encryption::CaesarDecipher(estr, 5) << std::endl;
	estr = lcu::algorithms::Encryption::VigenereCipher(str, "MyKey");
	std::cout << "VigenereCypher(" << str << ") = " << estr << std::endl;
	std::cout << "VigenereDecypher(" << estr << ") = " << lcu::algorithms::Encryption::VigenereDecipher(estr, "MyKey") << std::endl;

	std::cout << "BinarySearch(" << c << ") = " << lcu::algorithms::Searching<char>::BinarySearch(str, strlen(str), c) << std::endl;
	std::cout << "SequentialSearch(" << c << ") = " << lcu::algorithms::Searching<char>::SequentialSearch(str, strlen(str), c) << std::endl;

	int* ints = new int[N];
	for (size_t i = 0; i < N; ++i) {
		ints[i] = lcu::algorithms::Utility::RandomInt(0, 9);
	}
	std::cout << "QuickSort(";
	for (int i = 0; i < N; ++i) {
		std::cout << ints[i];
	}
	std::cout << ") = ";
	auto start = std::chrono::high_resolution_clock::now();
	lcu::algorithms::Sorting<int>::QuickSort(ints, 0, N-1);
	auto stop = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < N; ++i) {
		std::cout << ints[i];
	}
	std::cout << " | " << std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() << "µs" << std::endl;

	int rint = lcu::algorithms::Utility::RandomInt()%10;
	std::cout << "RandomInt() = " << rint << std::endl;

	std::cout << "IsLowerCase(" << c << ") = " << lcu::algorithms::Validation::IsLowerCase(c) << std::endl;

	delete[] ints;

	std::cout << "Sqrt(" << rint << ") = " << lcu::algorithms::MathFunctions::Sqrt(rint) << std::endl;

#endif // USE_ALGORITHMS

#ifdef USE_data_structures
	lcu::Map<lcu::String, int> map;
	map.InsertRecursive("H10", 10);
	map.InsertRecursive("H15", 15);
	map.InsertRecursive("H10", 10);
	map.InsertRecursive("H8", 8);
	map.Insert("H1", 1);
	map.Insert("H9", 9);
	map.Insert("H2", 2);
	map["H10"] = 20;
	std::cout << map << std::endl;

	lcu::Matrix<double> matrix(10, 10);
	matrix.FillWith(5);
	std::cout << matrix << std::endl;
	std::cout << matrix.Determinant() << std::endl;

#endif // USE_data_structures

#ifdef USE_EVENTS
	lcu::Event<void> randomEvent;
	randomEvent += lcu::EventHandler::Bind(Hello);
	randomEvent += lcu::EventHandler::Bind(World);
	randomEvent -= lcu::EventHandler::Bind(Hello);
	randomEvent();
#endif // USE_EVENTS

#ifdef USE_SYSTEM
	lcu::system::Display::Resolution desktopResolution = lcu::system::Display::DesktopResolution();
	std::cout << "Display resolution is " << desktopResolution.horizontal << "x" << desktopResolution.vertical << std::endl;
#endif // USE_SYSTEM

	return 0;
}
