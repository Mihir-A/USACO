/*
ID: mihiran1
LANG: C++
TASK: combo
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <algorithm>

int dialNum;

template<size_t size, class type>
std::ostream& operator<<(std::ostream & stream, std::array<type, size>& arr) {
	for (auto &a : arr) {
		stream << a << ", ";
	}
	stream << "\n";
	return stream;
}

template< class type>
std::ostream& operator<<(std::ostream& stream, std::vector<type>& arr) {
	for (auto& a : arr) {
		stream << a << "\n";
	}
	stream << "\n";
	return stream;
}

//void printarr(std::array<int, 3>& arr) {
//	for (int a : arr) {
//		std::cout << a << ", ";
//	}
//	std::cout << "\n";
//}

int wrap(int num) {
	if (dialNum == 1) {
		return 1;
	}
	if (num < 1) {
		return dialNum + num;
	}
	else if (num > dialNum) {
		return num - dialNum;
	}
	return num;
}

void pushBackCheck(std::vector<std::array<int, 3>>& vec, std::array<int, 3>& arr) {
	for (auto& a : vec) {
		if (a == arr) {
			return;
		}
	}
	vec.push_back(arr);
}

int findCombos(const std::array<int, 3>& farmerCombo, const std::array<int, 3>& masterCombo) {
	std::vector<std::array<int, 3>> combos;
	combos.reserve(200);
	//const std::array<int, 3> mins = { wrap(farmerCombo[0] - 2), wrap(farmerCombo[1] - 2), wrap(farmerCombo[2] - 2) };
	std::array<int, 3> combo({farmerCombo[0] - 2,farmerCombo[1] - 2,farmerCombo[2] - 2 });

	bool done = false;
	int maxPos = 0;
	while (!done) {
		combos.push_back(combo);
		combo[0] = wrap(combo[0] + 1);

		for (int j = 0; j <= maxPos; j++) {
			if (combo[j] == wrap(farmerCombo[j] + 3)) {
				if (j == 2) {
					done = true;
					break;
				}
				combo[j] = wrap(farmerCombo[j] - 2);
				combo[j + 1] = wrap(combo[j + 1] + 1);
				maxPos = j + 1;
			}
		}
	}
	

	done = false;
	maxPos = 0;
	combo = { masterCombo[0] - 2,masterCombo[1] - 2,masterCombo[2] - 2 };
	while (!done) {
		pushBackCheck(combos, combo);
		combo[0] = wrap(combo[0] + 1);

		for (int j = 0; j <= maxPos; j++) {
			if (combo[j] == wrap(masterCombo[j] + 3)) {
				if (j == 2) {
					done = true;
					break;
				}
				combo[j] = combo[j] = wrap(masterCombo[j] - 2);
				combo[j + 1] = wrap(combo[j + 1] + 1);
				maxPos = j + 1;
			}
		}
	}
	std::sort(combos.begin(), combos.end());
	std::cout << combos.size() << "\n\n\n" << combos;
	return combos.size();
}

int main() {
	std::ifstream fin("combo.in");
	std::array<int, 3> farmerCombo;
	std::array<int, 3> masterCombo;

	fin >> dialNum;

	for (int i = 0; i < 3; i++) {
		int tmp;
		fin >> tmp;
		farmerCombo[i] = tmp;
	}
	for (int i = 0; i < 3; i++) {
		int tmp;
		fin >> tmp;
		masterCombo[i] = tmp;
	}

	std::ofstream fout("combo.out");
	fout << findCombos(farmerCombo, masterCombo) << '\n';
	return 0;
}