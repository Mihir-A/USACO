/*
ID: mihiran1
LANG: C++
TASK: wormhole
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <utility>

class Wormhole {
public:
	int num;
	const int x, y;
	bool existing = false;
	Wormhole* paired = nullptr;

	Wormhole()
		: x(0), y(0), existing(false) {}

	Wormhole(int x, int y, int num, bool existing = false)
		: x(x), y(y), existing(existing), num(num) {}
};

std::ostream& operator<<(std::ostream& stream, Wormhole& w) {

	stream << w.x << " " << w.y;
	return stream;
}


template< class type>
std::ostream& operator<<(std::ostream& stream, std::vector<std::vector<type>>& arr) {
	for (auto& a : arr) {
		stream << a << "\n";
	}
	stream << "\n";
	return stream;
}

std::ostream& operator<<(std::ostream& stream, std::vector<Wormhole*>& arr) {
	for (Wormhole*& a : arr) {
		if (a) {
			stream << *a << ", ";
		}
		else {
			stream << "NA" << ", ";
		}
		
	}
	return stream;
}

int findPosib(std::vector<std::vector<Wormhole>>& grid, std::vector<Wormhole>& wormholes) {


	return 0;
}

void findPairs(std::vector<Wormhole>& wormholes, int n) {
	for (int i = n + 1; i < wormholes.size(); i++) {
		if (wormholes[i].paired == nullptr) {
			wormholes[i].paired = &wormholes[n];
			wormholes[n].paired = &wormholes[i];
			for (int w = n; w < wormholes.size(); w++) {
				if (wormholes[w].paired == nullptr) {
					findPairs(wormholes, w);
					break;
				}
			}
			for (int g = 0; g < wormholes.size(); g++) {
				if (wormholes[g].paired == nullptr) {
					break;
				}
				if (g == wormholes.size() - 1) {
					for (auto& dbg : wormholes) {
						std::cout << dbg.num << " is paired with " << dbg.paired->num << "\n";
					}
				}
			}
			std::cout << " n is " << i << "\n\n\n\n\n";

			wormholes[i].paired = nullptr;
		}
	}

	

	for (int i = n; i < wormholes.size(); i++) {
		wormholes[i].paired = nullptr;
	}
}

int main() {
	std::vector<Wormhole> wormholes;
	std::vector<std::vector<Wormhole*>> grid;
	std::ifstream fin("wormhole.in");
	int n;
	fin >> n;
	wormholes.reserve(n);
	int p = 0;
	for (int tmp1, tmp2; fin >> tmp1 >> tmp2;) {
		
		wormholes.emplace_back(tmp1, tmp2, p, true);
		p++;
	}

	int max = 0;
	for (auto& w : wormholes) {
		max = std::max(w.x, max);
		max = std::max(w.y, max);
	}

	grid.resize(max + 2);
	for (auto& vec : grid) {
		vec.resize(max + 2);
	}
	
	for (int i = 0; i < wormholes.size(); i++ ) {
		grid[wormholes[i].x][wormholes[i].y] = &(wormholes[i]);
	}
	
	std::cout << grid;

	findPairs(wormholes, 0);
	std::cout << "Hello World" << "\n";

	return 0;
}