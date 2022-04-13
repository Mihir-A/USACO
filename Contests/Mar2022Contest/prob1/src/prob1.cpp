#include <iostream>
#include <string>
#include <array>
#include <vector>

std::string s;
int n;

bool isRight(int index) {
	if ((index + 1) % 2 == 0) {
		if (s[index] == 'G') {
			return true;
		}
	}
	else if (s[index] == 'H') {
		return true;
	}
	return false;
}

bool shouldSwap(int index) {

	int right = 0, wrong = 0;
	for (int i = index; index >= 0; index--) {
		if (isRight(index)) {
			right++;
		}
		else {
			wrong++;
		}
	}
	return (((double)right) / wrong < 0.5);
}

void swap(int index) {
	for (int i = 0; i < (index + 1)/ 2; i ++) {
		char tmp = s[i];
		s[i] = s[index - i];
		s[index - i] = tmp;
	}
}

int main() {
	std::cin >> n >> s;
	//n = 14;
	//s = "GGGHGHHGHHHGHG";

	std::string w = s.substr(0, 10);

	int index = (n % 2 == 0) ? n - 1 : n - 2;

	int numSwaps = 0;
	for (; index >= 0; index -= 2) {
		if (shouldSwap(index) && !(isRight(index) || isRight(index - 1))) {
			swap(index);
			numSwaps++;
		}
	}

	std::cout << numSwaps << '\n';

	return 0;
}