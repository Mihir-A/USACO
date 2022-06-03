#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
	std::ifstream fin("speeding.in");
	std::vector<std::pair<int, int>> speedLimits;
	std::vector<std::pair<int, int>> cowSpeeds;
	int n, m;
	fin >> n >> m;

	speedLimits.reserve(n);
	cowSpeeds.reserve(n);

	for (int i = 0; i < n; i++) {
		int tmp1, tmp2;
		fin >> tmp1 >> tmp2;
		speedLimits.emplace_back(tmp1, tmp2);
	}

	for (int i = 0; i < m; i++) {
		int tmp1, tmp2;
		fin >> tmp1 >> tmp2;
		cowSpeeds.emplace_back(tmp1, tmp2);
	}

	int ans = 0;
	int curSpeedI = 0, cowSpeedI = 0;
	int curSpeedlow = 0, cowSpeedLow = 0;
	for (int mile = 0; mile < 100; mile++) {
		if (speedLimits[curSpeedI].second < cowSpeeds[cowSpeedI].second) {
			ans = std::max(ans, -(speedLimits[curSpeedI].second) + cowSpeeds[cowSpeedI].second);
		}
		if (curSpeedlow + speedLimits[curSpeedI].first == mile + 1) {
			curSpeedI++;
			curSpeedlow = mile + 1;
		}
		if (cowSpeedLow + cowSpeeds[cowSpeedI].first == mile + 1) {
			cowSpeedI++;
			cowSpeedLow = mile + 1;
		}
	}
	
	std::ofstream fout("speeding.out");
	fout << ans;
	

	return 0;
}