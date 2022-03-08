/*
ID: mihiran1
LANG: C++
TASK: combo
*/
#include <fstream>
#include <vector>
#include <array>

int dialNum;

int wrap(int num) {
	if (num < 1) {
		return wrap(dialNum + num);
	}
	else if (num > dialNum) {
		return wrap(num - dialNum);
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
	std::array<int, 3> combo;
	combos.reserve(200);
	
	for (int i = farmerCombo[0] - 2; i <= farmerCombo[0] + 2; i++) {
		for (int j = farmerCombo[1] - 2; j <= farmerCombo[1] + 2; j++) {
			for (int w = farmerCombo[2] - 2; w <= farmerCombo[2] + 2; w++) {
				combo[0] = wrap(i);
				combo[1] = wrap(j);
				combo[2] = wrap(w);
				pushBackCheck(combos, combo);
			}
		}
	}

	for (int i = masterCombo[0] - 2; i <= masterCombo[0] + 2; i++) {
		for (int j = masterCombo[1] - 2; j <= masterCombo[1] + 2; j++) {
			for (int w = masterCombo[2] - 2; w <= masterCombo[2] + 2; w++) {
				combo[0] = wrap(i);
				combo[1] = wrap(j);
				combo[2] = wrap(w);
				pushBackCheck(combos, combo);
			}
		}
	}

	return (int)combos.size();
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