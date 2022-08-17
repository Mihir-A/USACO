#include <iostream>
#include <array>
#include<vector>
#include<fstream>


template<size_t size, class type>
std::ostream& operator<<(std::ostream& stream, const std::array<type, size>& arr) {
	stream << "[";
	for (int i = 0; i < arr.size(); i++) {
		if (i == arr.size() - 1) {
			stream << arr[i] << "]";
		}
		else {
			stream << arr[i] << ", ";
		}
	}
	return stream;
}

template<class type>
std::ostream& operator<<(std::ostream& stream, const std::vector<type>& arr) {
	stream << "[";
	for (int i = 0; i < arr.size(); i++) {
		if (i == arr.size() - 1) {
			stream << arr[i] << "]";
		}
		else {
			stream << arr[i] << ", ";
		}
	}
	return stream;
}

template<class type>
std::ostream& operator<<(std::ostream& stream, const std::vector<std::vector<type>>& arr) {
	stream << "[";
	for (int i = 0; i < arr.size(); i++) {
		if (i == arr.size() - 1) {
			stream << arr[i] << "]";
		}
		else {
			stream << arr[i] << ",\n ";
		}
	}
	return stream;
}

int m, n, k;
using namespace std;
vector<vector<char>> orig;
vector<vector<char>> extended;
vector<vector<char>> real;

int main() {
	ifstream fin("cowsignal.in");
	ofstream fout("cowsignal.out");
	
	fin >> m >> n >> k;
	
	orig.resize(m);
	for (int i = 0; i < m; i++) {
		orig[i].resize(n);
		for (int j = 0; j < n; j++) {
			fin >> orig[i][j];
		}
	}
	cout << orig << endl;
	
	extended.resize(m);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int p = 0; p < k; p++) {
				extended[i].push_back(orig[i][j]);
			}
			
		}
	}
	for (int i = 0; i < extended.size(); i++)
	{
		for (int j = 0; j < extended[0].size(); j++)
		{
			cout << extended[i][j];
		}
		cout << '\n';
	}

	real.reserve(m * k);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			real.push_back(extended[i]);
		}
	}

	for (int i = 0; i < real.size(); i++)
	{
		for (int j = 0; j < real[0].size(); j++)
		{
			fout << real[i][j];
		}
		fout << '\n';
	}
	
	cout << extended << endl;
	fout.close();
	return 0;
}