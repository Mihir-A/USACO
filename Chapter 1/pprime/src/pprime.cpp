/*
ID: mihiran1
LANG: C++
TASK: pprime
*/

#include <iostream>
#include <fstream>
#include <string>

int lower, upper;

bool isPal(int num) {
	std::string s = std::to_string(num);

	for (int i = 0; i < s.size(); i++) {
		if (s[i] != s[s.size() - i - 1]) return false;
	}
	return true;
}

bool isPrime(int num) {
	for (int i = 3; i < num / 2; i += 2) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	std::ifstream fin("pprime.in");
	fin >> lower >> upper;

	std::ofstream fout("pprime.out");

	for (int i = lower % 2 == 0 ? lower + 1 : lower; i <= upper; i += 2) {
		if (isPal(i)) {
			if (isPrime(i)) {
				fout << i << '\n';
			}
		}
	}

	__debugbreak();

	return 0;
}