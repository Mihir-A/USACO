/*
ID: mihiran1
LANG: C++
TASK: barn1
*/
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

typedef std::vector<int> Cows;

int checkGapSize(int num, std::vector<int>& maxGaps, int storedMin) {
	if (storedMin > num) {
		return storedMin;
	}
	int minPos = 0;
	int min = maxGaps[0];
	for (int j = 0; j < maxGaps.size(); j++) {
		if (maxGaps[j] <= min) {
			min = maxGaps[j];
			minPos = j;
		}
	}

	if (min < num) {
		maxGaps[minPos] = num;
	}
	return min;
}

int findStallsBlocked(const Cows &cows, const int numBoards, const int numStalls) {
	if (numBoards == 1) {
		return cows[cows.size() - 1] - cows[0] + 1;
	}

	if (cows.size() < numBoards) {
		return cows.size() - 1;
	}

	std::vector<int> maxGaps(numBoards - 1, 0);

	int storedMin = 0;
	for (int i = 1; i < cows.size(); i++) {

		storedMin = checkGapSize(cows[i] - cows[i - 1], maxGaps, storedMin);
	}

	int stallsOpen = 0;
	for (int j = 0; j < maxGaps.size(); j++) {
		stallsOpen += maxGaps[j] - 1;
	}

	stallsOpen += cows[0] - 1;
	stallsOpen += numStalls - cows[cows.size() - 1];

	return numStalls - stallsOpen;
}

int main() {
	std::ifstream fin("barn1.in");
	int numBoards, numStalls, numCows;
	fin >> numBoards >> numStalls >> numCows;
	Cows cows;
	cows.reserve(numCows);

	for (std::string s; std::getline(fin, s);) {
		int tmp;
		fin >> tmp;
		cows.push_back(tmp);
	}

	std::sort(cows.begin(), cows.end());
	
	std::ofstream fout("barn1.out");
	fout << findStallsBlocked(cows, numBoards, numStalls) << '\n';

	return 0;
}