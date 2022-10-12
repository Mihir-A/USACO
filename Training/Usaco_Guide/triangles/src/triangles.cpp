#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int n, ans = 0; 
vector<pair<int, int>> points;

int main() {
	ifstream fin("triangles.in");
	fin >> n;
	points.reserve(n);

	for (int i = 0; i < n; i++)
	{
		int pointx, pointy;
		fin >> pointx >> pointy;
		points.emplace_back(pointx, pointy);
	}

	for (int i = 0; i < points.size(); i++)
	{
		for (int j = i + 1; j < points.size(); j++)
		{
			for (int w = j + 1; w < points.size(); w++)
			{
				int x1, y1, x2, y2, x3, y3;
				x1 = points[i].first;
				y1 = points[i].second;
				x2 = points[j].first;
				y2 = points[j].second;
				x3 = points[w].first;
				y3 = points[w].second;

				if (y1 - y2 == 0 || y2 - y3 == 0 || y1 - y3 == 0 && x1 - x2 == 0 || x2 - x3 == 0 || x1 - x3)
				ans = max(ans, abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)));

				//cout << i + 1 << " " << j + 1<< " " << w + 1<< '\n';
			}
		}
	}
	ofstream fout("triangles.out");

	fout << ans << '\n';
	
	return 0;
}