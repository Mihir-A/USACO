/*
ID: mihiran1
LANG: C++
TASK: numtri
*/

#include <fstream>
#include <array>
#include <vector>

std::vector<std::vector<int>> triangle;
std::vector<std::vector<int>> maxVals;

int findMax(int x, int y, int val) {
	if (maxVals[y][x] != -1) {
		return val + maxVals[y][x];
	}
	else if (y < triangle.size() - 1) {
		maxVals[y][x] = std::max(findMax(x, y + 1, triangle[y][x]), findMax(x + 1, y + 1, triangle[y][x]));
		return maxVals[y][x] + val;
	}
	else {
		return val + triangle[y][x];
	}
}

int main() {
	std::ifstream fin("numtri.in");
	int rowNum;
	fin >> rowNum;
	
	triangle.resize(rowNum);
	maxVals.resize(rowNum);

	for (int i = 1; i <= rowNum; i++) {
		triangle[i - 1].reserve(i);
		maxVals[i - 1].reserve(i);

		for (int j = 0; j < i; j++) {
			int tmp;
			fin >> tmp;
			triangle[i - 1].push_back(tmp);
			maxVals[i - 1].push_back(-1);
		}
	}

	std::ofstream fout("numtri.out");
	fout << findMax(0, 0, 0) << '\n';
	return 0;
}