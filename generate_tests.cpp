/*
	CS373 Spring 2023 Programming Assignment 4 Test Case Generator 
	by James Lefer
*/

#include <iostream>
#include <fstream>
#include <random>
#include <bitset>
#include <chrono>

#define CASES_PER_SET 10

int main(int argc, char const *argv[]){

	std::ofstream output("test_cases.txt"/*, std::ios_base::app*/);
	std::mt19937_64 rng( static_cast<unsigned int>( std::chrono::steady_clock::now().time_since_epoch().count() ) );
	unsigned long long firsthalf;
	unsigned long long secondhalf;

	// reject because x = y
	output << "Set0r\n";
	for(auto i = 0; i < CASES_PER_SET; i++){
		firsthalf = static_cast<unsigned long long>(rng());
		secondhalf = static_cast<unsigned long long>(rng());
		output << std::bitset<64>(firsthalf) << std::bitset<64>(secondhalf);
		output << '#' << std::bitset<64>(firsthalf) << std::bitset<64>(secondhalf) << '\n';
	}

	// reject because x != y but xi != yi for every 1 <= i <= |x| (|x| == |y|)
	output << "\nSet1r\n";
	for(auto i = 0; i < CASES_PER_SET; i++){
		firsthalf = static_cast<unsigned long long>(rng());
		secondhalf = static_cast<unsigned long long>(rng());
		output << std::bitset<64>(firsthalf) << std::bitset<64>(secondhalf);
		output << '#' << std::bitset<64>(~firsthalf) << std::bitset<64>(~secondhalf) << '\n';
	}

	// reject because x != y but xi != yi for every 1 <= i <= |x| (|x| < |y|)
	output << "\nSet2r\n";
	for(auto i = 0; i < CASES_PER_SET; i++){
		firsthalf = static_cast<unsigned long long>(rng());
		secondhalf = static_cast<unsigned long long>(rng());
		output << std::bitset<64>(firsthalf) << std::bitset<64>(secondhalf);
		output << '#' << std::bitset<64>(~firsthalf) << std::bitset<64>(~secondhalf) << std::bitset<5>(secondhalf) << '\n';
	}

	// reject because x != y but xi != yi for every 1 <= i <= |y| (|x| > |y|)
	output << "\nSet3r\n";
	for(auto i = 0; i < CASES_PER_SET; i++){
		firsthalf = static_cast<unsigned long long>(rng());
		secondhalf = static_cast<unsigned long long>(rng());
		output << std::bitset<64>(firsthalf) << std::bitset<64>(secondhalf) << std::bitset<5>(secondhalf);
		output << '#' << std::bitset<64>(~firsthalf) << std::bitset<64>(~secondhalf) << '\n';
	}


	// accept where |x| == |y|
	output << "\nSet4a\n";
	for(auto i = 0; i < CASES_PER_SET / 2; i++){ // xi != yi for a singular i
		firsthalf = static_cast<unsigned long long>(rng());
		secondhalf = static_cast<unsigned long long>(rng());
		output << std::bitset<64>(firsthalf) << std::bitset<64>(secondhalf);
		output << '#' << std::bitset<64>(firsthalf ^ (1 << (firsthalf % 64))) << std::bitset<64>(secondhalf) << '\n';
	}
	for(auto i = 0; i < CASES_PER_SET / 2; i++){ // xi == yi for a singular i
		firsthalf = static_cast<unsigned long long>(rng());
		secondhalf = static_cast<unsigned long long>(rng());
		output << std::bitset<64>(firsthalf) << std::bitset<64>(secondhalf);
		output << '#' << std::bitset<64>((~firsthalf) ^ (1 << (firsthalf % 64))) << std::bitset<64>(~secondhalf) << '\n';
	}

	// accept where |x| < |y|
	output << "\nSet5a\n";
	for(auto i = 0; i < CASES_PER_SET / 2; i++){ // xi != yi for a singular i
		firsthalf = static_cast<unsigned long long>(rng());
		secondhalf = static_cast<unsigned long long>(rng());
		output << std::bitset<64>(firsthalf) << std::bitset<64>(secondhalf);
		output << '#' << std::bitset<64>(firsthalf ^ (1 << (firsthalf % 64))) << std::bitset<64>(secondhalf) << std::bitset<5>(secondhalf) << '\n';
	}
	for(auto i = 0; i < CASES_PER_SET / 2; i++){ // xi == yi for a singular i
		firsthalf = static_cast<unsigned long long>(rng());
		secondhalf = static_cast<unsigned long long>(rng());
		output << std::bitset<64>(firsthalf) << std::bitset<64>(secondhalf);
		output << '#' << std::bitset<64>((~firsthalf) ^ (1 << (firsthalf % 64))) << std::bitset<64>(~secondhalf) << std::bitset<5>(secondhalf) << '\n';
	}

	// accept where |x| < |y|, xi == xi for every 1 <= i <= |x| 
	output << "\nSet6a\n";
	for(auto i = 0; i < CASES_PER_SET; i++){
		firsthalf = static_cast<unsigned long long>(rng());
		secondhalf = static_cast<unsigned long long>(rng());
		output << std::bitset<64>(firsthalf) << std::bitset<64>(secondhalf);
		output << '#' << std::bitset<64>(firsthalf) << std::bitset<64>(secondhalf) << std::bitset<5>(secondhalf) << '\n';
	}

	// accept where |x| > |y|
	output << "\nSet7a\n";
	for(auto i = 0; i < CASES_PER_SET / 2; i++){ // xi != yi for a singular i
		firsthalf = static_cast<unsigned long long>(rng());
		secondhalf = static_cast<unsigned long long>(rng());
		output << std::bitset<64>(firsthalf) << std::bitset<64>(secondhalf) << std::bitset<5>(secondhalf);
		output << '#' << std::bitset<64>(firsthalf ^ (1 << (firsthalf % 64))) << std::bitset<64>(secondhalf) << '\n';
	}
	for(auto i = 0; i < CASES_PER_SET / 2; i++){ // xi == yi for a singular i
		firsthalf = static_cast<unsigned long long>(rng());
		secondhalf = static_cast<unsigned long long>(rng());
		output << std::bitset<64>(firsthalf) << std::bitset<64>(secondhalf) << std::bitset<5>(secondhalf);
		output << '#' << std::bitset<64>((~firsthalf) ^ (1 << (firsthalf % 64))) << std::bitset<64>(~secondhalf) << '\n';
	}

	// accept where |x| > |y|, xi == xi for every 1 <= i <= |y| 
	output << "\nSet8a\n";
	for(auto i = 0; i < CASES_PER_SET; i++){
		firsthalf = static_cast<unsigned long long>(rng());
		secondhalf = static_cast<unsigned long long>(rng());
		output << std::bitset<64>(firsthalf) << std::bitset<64>(secondhalf) << std::bitset<5>(secondhalf);
		output << '#' << std::bitset<64>(firsthalf) << std::bitset<64>(secondhalf) << '\n';
	}

	output.flush();
	output.close();
	return 0;
}
