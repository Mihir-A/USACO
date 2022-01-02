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

int findLongestTime(std::vector<std::pair<int, int>>& times) {
	std::sort(times.begin(), times.end());
	int start = times[0].first, end = times[0].second, maxTime = 0;

	for (int i = 1; i < times.size(); i++) {
		if (times[i].first <= end && times[i].second > end) {
			end = times[i].second;
		}
		else {
			maxTime = std::max(maxTime, end - start);
			end = times[i].second;
			start = times[i].first;
			maxTime = std::max(maxTime, end - start);
		}
	}
	maxTime = std::max(maxTime, end - start);

	return maxTime;
}

int findLongestIdleTime(std::vector<std::pair<int, int>>& times) {
	for (int i = 0; i < times.size(); i++) {
		int temp;
		temp = times[i].first;
		times[i].first = times[i].second;
		times[i].second = temp;
	}

	std::sort(times.begin(), times.end());

	for (int i = 0; i < times.size(); i++) {
		int temp;
		temp = times[i].first;
		times[i].first = times[i].second;
		times[i].second = temp;
	}

	int max = 0, start = 0, end;
	for (int i = 0; i < times.size() - 1; i++) {
		if (times[i].second < times[i + 1].first) {
			max = std::max(max, times[i + 1].first - times[i].second);
			start = times[i].second;
			end = times[i + 1].first;
		}if (start > times[i + 1].first && end < times[i + 1].second) {
			max = 0;
		}
	}

	return max;
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

	outfile << findLongestTime(times) << " " << findLongestIdleTime(times) << "\n";
	return 0;
}