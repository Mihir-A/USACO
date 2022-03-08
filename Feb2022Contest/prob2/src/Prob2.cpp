#include <iostream>
#include <vector>

void move(std::vector<int>& vec, int e, int s) {
	int count = e + 1;
	int tmp = vec[e];

	vec[e] = vec[s];

	for (; count <= s; count ++) {
		int tmp1 = vec[count];
		vec[count] = tmp;
		tmp = tmp1;
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> start;
	std::vector<int> end;
	start.reserve(n);
	end.reserve(n);

	int nSol = 0;

	for (int w = 0; w < n; w++) {
		int tmp;
		std::cin >> tmp;
		start.push_back(tmp);
	}

	for (int w = 0; w < n; w++) {
		int tmp;
		std::cin >> tmp;
		end.push_back(tmp);
	}

	for (int i = 0; i < n; i ++) {
		if (start[i] != end[i]) {
			for (int j = i; j < n; j++) {
				if (start[j] == end[i]) {
					move(start, i, j);
					nSol++;
				}
			}
			
		}
	}

	std::cout << nSol;

	return 0;
}