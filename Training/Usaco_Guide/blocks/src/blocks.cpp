#include <iostream>
#include <array>
#include <algorithm>
#include <fstream>
#include <vector>

template<typename T, size_t size>
void setArr(std::array<T, size>& arr, T val) {
	for (auto& i : arr) {
		i = val;
	}
}

int main() {
	std::array<int, 26> letters{ 0 };
	std::vector<std::pair<std::string, std::string>> words;
	std::ifstream fin("blocks.in");
	int n;

	setArr(letters, 0);
	fin >> n;

	for (int i = 0; i < n; i++) {
		std::string word1, word2;
		fin >> word1 >> word2;
		words.emplace_back(word1, word2);
	}

	std::array<int, 26> tmp1{ 0 };
	std::array<int, 26> tmp2{ 0 };
	for (int i = 0; i < n; i++) {
		setArr(tmp1, 0);
		setArr(tmp2, 0);
		
		for (char c : words[i].first) {
			tmp1[(int)c - 97] ++;
		}

		for (char c : words[i].second) {
			tmp2[(int)c - 97] ++;
		}
		
		for(int k = 0; k < 26; k++) {
			letters[k] += std::max(tmp1[k], tmp2[k]);
		}
	}

	std::ofstream fout("blocks.out");
	for (int i = 0; i < 26; i++) {
		fout << letters[i] << "\n";
	}
	
	return 0;
}