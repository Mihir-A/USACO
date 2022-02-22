/*
ID: mihiran1
LANG: C++
TASK: crypt1
*/
#include <fstream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>

bool checkNum(int num, const std::vector<int>& digits) {
	do {
		int digit = num % 10;
		bool checked = false;
		for (int i = 0; i < digits.size(); i++) {
			if (digit == digits[i]) {
				checked = true;
				i = digits.size();
			}
		}
		if (checked == false) {
			return false;
		}
	} while (num /= 10);
	return true;
}

bool testSol(const std::array<int, 5>& multipliers, const std::vector<int>& digits) {
	const int a = multipliers[0];
	const int b = multipliers[1];
	const int c = multipliers[2];
	const int d = multipliers[3];
	const int e = multipliers[4];

	if (checkNum(e * (c + b * 10 + a * 100), digits) && std::to_string(e * (c + b * 10 + a * 100)).size() == 3) {
		if (checkNum(d * (c + b * 10 + a * 100), digits) && std::to_string(d * (c + b * 10 + a * 100)).size() == 3) {
			if (checkNum((a * 100 + b * 10 + c) * (d * 10 + e), digits) && std::to_string((a * 100 + b * 10 + c) * (d * 10 + e)).size() == 4) {
				return true;
			}
		}
	}
	return false;
}

void setArr(std::array<int, 5>& arr, int num) {
	for (int i = 0; i < 5; i++) {
		arr[i] = num;
	}
}

int findNumPos(const std::vector<int>& digits) {
	std::array<int, 5> multipliers = {}; // a, b, c, d, e
	std::array<int, 5> multipliyPosition = { 0 };
	setArr(multipliers, digits[0]);

	int maxPos = 0;
	bool notDone = true;
	int numSol = 0;
	while(notDone) {
		
		multipliers[0] = digits[multipliyPosition[0]];
		multipliyPosition[0]++;
		numSol = testSol(multipliers, digits) ? numSol + 1: numSol;

		for (int j = 0; j <= maxPos; j++) {
			if (multipliyPosition[j] == digits.size()) {
				if (j == 4) {
					notDone = false;
					break;
				}
				multipliyPosition[j] = 0;;
				multipliyPosition[j + 1]++;

				multipliers[j] = digits[0];
				if (multipliyPosition[j + 1] < digits.size()) {
					multipliers[j + 1] = digits[multipliyPosition[j + 1]];
				}
				maxPos = j + 1;
			}
		}
	}
	return numSol;
}

int main() {
	std::ifstream fin("crypt1.in");
	int n;
	fin >> n;
	std::vector<int> digits;
	digits.reserve(n);

	for (int tmp = 0; fin >> tmp;) {
		digits.push_back(tmp);
	}

	std::sort(digits.begin(), digits.end());

	std::ofstream fout("crypt1.out");
	fout << findNumPos(digits) << '\n';

	return 0;
}