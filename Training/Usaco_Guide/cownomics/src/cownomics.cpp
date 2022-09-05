#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;



int main() {
	
	ifstream fin("cownomics.in");
	int n, m, sol = 0;

	fin >> n >> m;

	vector<string> cows;
	cows.resize(n * 2);

	for (int i = 0; i < n * 2; i++)
	{
		fin >> cows[i];
	}

	for (int i = 0; i < m; i++)
	{
		string spotyletters = "";

		for (int j = 0; j < n; j++) {
			if (spotyletters.find(cows[j][i]) == string::npos) {
				spotyletters += cows[j][i];
			}
		}

		for (int j = n; j < 2 * n; j++) {
			if (spotyletters.find(cows[j][i]) != string::npos) {
				break;
			}
			else if (j == 2 * n - 1) {
				sol++;
			}
		}
	}

	ofstream fout("cownomics.out");

	fout << sol << '\n';

	return 0;
}