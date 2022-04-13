#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

bool checkEqual(const std::vector<int>& vec) {
	int a = vec[0];
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] != a) {
			return false;
		}
	}
	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(0);
	int t;
	std::cin >> t;

	for (int i = 0; i < t; i++) {
		int ans = 0;
		int n;
		std::cin >> n;
		std::vector<int> vec;
		vec.reserve(n);

		for (int w = 0; w < n; w++) {
			int tmp;
			std::cin >> tmp;
			vec.push_back(tmp);
		}

		while (!checkEqual(vec)) {
			int min_e = *std::min_element(vec.begin(), vec.end());
			//int min = vec[0] + vec[1];
			//int minPos = 0;
			std::vector<int> occ;
			occ.resize((*std::max_element(vec.begin(), vec.end())) * 2 + 1);

			for (int k = 0; k < vec.size() - 1; k++) {
				if (vec[k] > min_e) {
					occ[vec[k]] ++;
				}
				occ[vec[k] + vec[k + 1]]++;
			}

			int pos1 = std::distance(occ.begin(), std::max_element(occ.begin(), occ.end()));

			int pos = 0;
			for (int k = 0; k < vec.size() - 1; k++) {
				if (vec[k] + vec[k + 1] == pos1) {
					pos = k;
					break;
				}
			}

			
			vec[pos] = vec[pos] + vec[pos + 1];
			for (int j = pos + 1; j < vec.size() - 1; j++) {
				vec[j] = vec[j + 1];
			}
			vec.pop_back();
			ans++;
		}

		std::cout << ans << '\n';
	}

	return 0;
}