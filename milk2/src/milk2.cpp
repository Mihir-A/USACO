/*
ID: mihiran1
LANG: C++
TASK: milk2
*/
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <fstream>
#include <sstream>
#include <algorithm>

void findLongestTimes(std::vector<std::pair<int, int>>& times, int& maxWork, int& maxIdle) {
	std::sort(times.begin(), times.end());

	for (int j = 0; j < times.size() - 1; j++) {
		if (times[j].second >= times[j + 1].first) {
			times[j].second = std::max(times[j + 1].second, times[j].second);
			times[j].first = std::min(times[j + 1].first, times[j].first);
			times.erase(times.begin() + j + 1);
			j = -1;
		}
	}

	maxWork = 0, maxIdle = 0;
	for (int i = 0; i < times.size(); i++) {
		maxWork = std::max(times[i].second - times[i].first, maxWork);

		if (i < times.size() - 1) {
			maxIdle = std::max(times[i + 1].first - times[i].second, maxIdle);
		}
	}
}

int main() {
	std::ifstream infile("milk2.in");
	int numOfFarmers;
	infile >> numOfFarmers;

	std::vector<std::pair<int, int>> times;
	times.resize(numOfFarmers);

	for (int i = 0; i < numOfFarmers; i++) {
		if (i == 0) {
			std::string temp;
			std::getline(infile, temp);
		}
		std::string read;
		std::getline(infile, read);
		std::stringstream stream(read);

		stream >> times[i].first >> times[i].second;
	}

	std::ofstream outfile("milk2.out");

	int work, idle;
	findLongestTimes(times, work, idle);

	outfile << work << " " << idle << "\n";
	return 0;
}