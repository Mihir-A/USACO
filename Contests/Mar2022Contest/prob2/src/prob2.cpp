#include <iostream>
#include <algorithm>
#include <vector>

int n;
std::vector<std::pair<int, char>> vec;

int main() {
	std::cin >> n;
	
	{
		std::vector<std::pair<int, char>> tmpVec;
		for (int i = 0; i < n; i++) {
			char c;
			int tmp;
			std::cin >> c >> tmp;

			tmpVec.emplace_back(tmp, c);
		}
		std::sort(tmpVec.begin(), tmpVec.end());
		
		int start = 0;
		for (int i = 0; i < tmpVec.size(); i++) {
			if (tmpVec[i].second == 'G' && tmpVec[i + 1].second == 'G') {
				start++;
			}
			else {
				break;
			}
		}

		int end = tmpVec.size();
		for (int i = tmpVec.size() - 1; i >= 0; i--) {
			if (tmpVec[i].second == 'L' && tmpVec[i - 1].second == 'L') {
				end --;
			}
			else {
				break;
			}
		}

		std::vector<std::pair<int, char>>::const_iterator first = tmpVec.begin() + start;
		std::vector<std::pair<int, char>>::const_iterator last = tmpVec.begin() + end;

		vec = std::vector<std::pair<int, char>>(first, last);
	}

	unsigned int minLie = 0 - 1;
	
	for (int bottomPos = 0; bottomPos < vec.size() - 1; bottomPos++) {
		if (vec[bottomPos].second == 'G') {

			for (int topPos = bottomPos; topPos < vec.size(); topPos++) {
				if (vec[topPos].second == 'L') {

					unsigned int lies = 0;
					for (int w = 0; w < vec.size(); w++) {

						if (vec[w].second == 'G') {
							if (vec[bottomPos].first < vec[w].first) {
								lies++;
							}
						}
						else {
							if (vec[topPos].first > vec[w].first) {
								lies++;
							}
						}
					}
					minLie = std::min(minLie, lies);
				}
			}
		}
	}

	if (minLie == (unsigned int)(-1)) {
		std::cout << 1 << '\n';
	}
	else {
		std::cout << minLie << '\n';
	}

	return 0;
}