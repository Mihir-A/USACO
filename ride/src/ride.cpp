/*
ID: mihiran1
LANG: C++
TASK: ride
*/

#include <iostream>
#include <fstream>
#include <string>

int main() {

	int num1 = 1, num2 = 1;
	std::ifstream infile("ride.in");
	std::string line;

	std::getline(infile, line);

	for (int i = 0; i < line.length(); i++) {
		num1 *= ((int)line[i]) - 64;
	}


	std::getline(infile, line);

	for (int i = 0; i < line.length(); i++) {
		num2 *= ((int)line[i]) - 64;
	}

	std::fstream outfile("ride.out", std::ios::trunc | std::ios::out);

	if (num1 % 47 == num2 % 47) {
		outfile << "GO\n";
	}
	else {
		outfile << "STAY\n";
	}

	return 0;
}