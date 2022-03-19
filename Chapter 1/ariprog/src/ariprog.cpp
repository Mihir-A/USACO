/*
ID: mihiran1
LANG: C++
TASK: ariprog
*/
#include <fstream>
#include <array>
#include <vector>
#include <algorithm>

int n, m;
std::array<int, 251 * 251 * 2> arr;


bool checkProg(int start, int difference) {
	for (int i = 0; i < n; i++) {
		if (arr[start + i * difference] == 0) return false;
	}
	return true;
}

int main() {
	std::ifstream fin("ariprog.in");
	fin >> n >> m;
	fin.close();
	arr.fill(0);

	for (int p = 0; p <= m; p++) {
		for (int q = 0; q <= m; q++) {
			arr[p * p + q * q] = 1;
		}
	}

	std::vector<std::pair<int, int>> solutions;

	for (int start = 0; start <= 2 * m * m; start ++) {
		for (int difference = 1; difference <= (2 * m * m - start) / (n - 1); difference++) {
			if (checkProg(start, difference)) {
				solutions.emplace_back(difference, start);
			}
		}
	}
	std::sort(solutions.begin(), solutions.end());

	std::ofstream fout("ariprog.out");
	if (solutions.size() != 0) {
		for (auto& pair : solutions) {
			fout << pair.second << ' ' << pair.first << '\n';
		}
	}
	else {
		fout << "NONE" << '\n';
	}
	return 0;
}