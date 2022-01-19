#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

typedef std::vector<std::vector<bool>> GRID;

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

	std::cout << check90(vectorIn, vectorOut, n);

	return 0;
}