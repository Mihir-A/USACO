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

int numSol = 0, maxSize = 0, total = 0;

Wormhole* findWormHole(int x, int y, std::vector<Wormhole>& wormholes) {
	for (auto& w : wormholes) {
		if (w.x == x && w.y == y) {
			return &w;
		}
	}
	return nullptr;
}

bool checkSol(std::vector<Wormhole>& wormholes) {
	std::cout << total << "\n";
	total++;
	for (int i = 0; i < wormholes.size(); i++) {

		int originalX = wormholes[i].x, originalY = wormholes[i].y;
		int cowX = wormholes[i].x;
		int cowY = wormholes[i].y;

		while (true) {
			int tmpX = cowX;
			cowX = findWormHole(cowX, cowY, wormholes)->paired->x;
			cowY = findWormHole(tmpX, cowY, wormholes)->paired->y;
			
			int tmp = cowX;
			cowX = 2147483647;
			for (auto& a : wormholes) {
				if (a.x > tmp && a.y == cowY) {
					cowX = std::min(cowX, a.x);
				}
			}
			if (cowX == 2147483647) {
				break;
			}
			if (originalX == cowX && originalY == cowY) {
				return true;
			}
		}
	}
	return false;
}

void findSol(std::vector<Wormhole> wormholes, int n) {
	for (int i = n + 1; i < wormholes.size(); i++) {
		if (wormholes[i].paired == nullptr) {
			wormholes[i].paired = &wormholes[n];
			wormholes[n].paired = &wormholes[i];
			for (int w = n; w < wormholes.size(); w++) {
				if (wormholes[w].paired == nullptr) {
					findSol(wormholes, w);
					break;
				}
			}
			for (int g = 0; g < wormholes.size(); g++) {
				if (wormholes[g].paired == nullptr) {
					break;
				}
				if (g == wormholes.size() - 1) {
					if (checkSol(wormholes)) {
						numSol++;
					}
				}
			}
			wormholes[i].paired = nullptr;
		}
	}
	for (int i = n; i < wormholes.size(); i++) {
		wormholes[i].paired = nullptr;
	}
}

int main() {
	std::vector<Wormhole> wormholes;
	std::ifstream fin("wormhole.in");
	int n;
	fin >> n;
	wormholes.reserve(n);
	int p = 0;
	for (int tmp1, tmp2; fin >> tmp1 >> tmp2;) {
		
		wormholes.emplace_back(tmp1, tmp2, p, true);
		p++;
	}

	for (auto& w : wormholes) {
		maxSize = std::max(w.x, maxSize);
		maxSize = std::max(w.y, maxSize);
	}
	maxSize++;

	std::ofstream fout("wormhole.out");
	findSol(wormholes, 0);
	fout << numSol << "\n";
	return 0;
}