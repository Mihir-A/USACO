/*
ID: mihiran1
LANG: C++
TASK: transform
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

typedef std::vector<std::vector<bool>> GRID;

void printGrid(GRID& vectorIn, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vectorIn[i][j]) {
				std::cout << "@";
			}
			else {
				std::cout << "-";
			}
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}

bool check90(GRID& vectorIn, GRID& vectorOut, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vectorIn[n - 1 - j][i] != vectorOut[i][j]) {
				return 0;
			}
		}
	}
	return 1;
}

bool check180(GRID& vectorIn, GRID& vectorOut, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vectorIn[n - 1 - i][n - 1 - j] != vectorOut[i][j]) {
				return 0;
			}
		}
	}
	return 1;
}

bool check270(GRID& vectorIn, GRID& vectorOut, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vectorIn[j][n - 1 - i] != vectorOut[i][j]) {
				return 0;
			}
		}
	}
	return 1;
}

GRID reflect(GRID& vectorIn, int n) {
	GRID reflected = vectorIn;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n / 2; j++) {
			reflected[i][j] = vectorIn[i][n - 1 - j];
			reflected[i][n - 1 - j] = vectorIn[i][j];
		}
	}

	return reflected;
}

bool checkIfEqual(GRID& vectorIn, GRID& vectorOut, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vectorIn[i][j] != vectorOut[i][j]) {
				return false;
			}
		}
	}
	return true;
}

int checkGrid(GRID& vectorIn, GRID& vectorOut, int n) {
	if (check90(vectorIn, vectorOut, n)) {
		return 1;
	}
	if (check180(vectorIn, vectorOut, n)) {
		return 2;
	}
	if (check270(vectorIn, vectorOut, n)) {
		return 3;
	}

	GRID reflected = reflect(vectorIn, n);
	if (checkIfEqual(vectorOut, reflected, n)) {
		return 4;
	}
	if (check90(reflected, vectorOut, n) || check180(reflected, vectorOut, n) || check270(reflected, vectorOut, n)) {
		return 5;
	}
	if (checkIfEqual(vectorIn, vectorOut, n)) {
		return 6;
	}
	return 7;
}

int main() {
	std::ifstream fin("transform.in");
	int n;
	fin >> n;

	GRID vectorIn;
	GRID vectorOut;

	vectorIn.resize(n);
	vectorOut.resize(n);

	for (int i = 0; i < n; i++) {
		vectorIn[i].resize(n);
		std::string line;
		if (i == 0) {
			std::getline(fin, line);
		}

		std::getline(fin, line);
		for (int j = 0; j < n; j++) {
			if (line[j] == '@') {
				vectorIn[i][j] = true;
			}
			else {
				vectorIn[i][j] = false;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		vectorOut[i].resize(n);
		std::string line;

		std::getline(fin, line);
		for (int j = 0; j < n; j++) {
			if (line[j] == '@') {
				vectorOut[i][j] = true;
			}
			else {
				vectorOut[i][j] = false;
			}
		}
	}

	std::ofstream fout("transform.out");

	fout << checkGrid(vectorIn, vectorOut, n) << '\n';

	return 0;
}