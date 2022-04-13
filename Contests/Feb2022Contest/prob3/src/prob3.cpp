#include <iostream>
#include <functional>
#include <vector>
#include <string>

bool test(const std::vector<std::string*>& blocks, std::vector<bool>& available, const std::string& s, int l) {
	if (l == s.size()) {
		return true;
	}
	for (int i = 0; i < blocks.size(); i++) {
		if (blocks[i]->find(s[l]) != std::string::npos && available[i] == true) {
			available[i] = false;
			if (test(blocks, available, s, l + 1)) {
				return true;
			}
			available[i] = true;
		}
	}
	return false;
}

int main() {
	std::string b1, b2, b3, b4;
	std::vector<std::string*> blocks = { &b1, &b2, &b3, &b4 };
	std::vector<bool> available = { true, true, true, true };
	int n;
	std::cin >> n;

	for (auto& s : blocks) {
		std::cin >> *s;
	}

	for (int i = 0; i < n; i++) {
		std::string s;
		std::cin >> s;
		std::cout << (test(blocks, available, s, 0) ? "YES" : "NO") << '\n';
		available = { true, true, true, true };
	}

	return 0;
}