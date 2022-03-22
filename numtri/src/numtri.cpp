/*
ID: mihiran1
LANG: C++
TASK: numtri
*/

#include <iostream>
#include <fstream>
#include <vector>


template< class type>
std::ostream& operator<<(std::ostream& stream, std::vector<type>& arr) {
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

class Num
{
public:
	int value;
	Num* left = nullptr;
	Num* right = nullptr;
	Num(int n) {
		value = n;
	}
	Num(){}
};

int main() {
	std::ifstream fin("numtri.in");
	int rowNum;
	fin >> rowNum;

	Num* first = new Num;

	std::vector<int> row;
	std::vector<Num*> prevRow;
	std::vector<Num*> curRow;
	for (int i = 1; i <= rowNum; i++) {
		
		row.clear();
		for (int j = 0; j < i; j++) {
			int tmp;
			fin >> tmp;
			row.push_back(tmp);

			curRow.push_back(new Num(tmp));
		}
		std::cout << row << '\n';
	}


	return 0;
}