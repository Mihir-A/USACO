/*
ID: mihiran1
LANG: C++
TASK: friday
*/
#include <iostream>
#include <array>
#include <fstream>

void calcMonth(int month, int& dayOfWeek, std::array<int, 7>& daysOf13th, bool leap) {
	int dayOf13th = dayOfWeek - 2;
	
	if (dayOf13th <= 0) {
		dayOf13th = 7 + dayOf13th;
	}

	daysOf13th[dayOf13th - 1] += 1;

	if (month == 4 || month == 6 || month == 9 || month == 11) {
		dayOfWeek = ((dayOfWeek + 29) % 7) + 1;
	}
	else if (month == 2 && leap == true) {
		dayOfWeek = ((dayOfWeek + 28) % 7) + 1;
	}
	else if (month == 2 && leap == false) {
		dayOfWeek = ((dayOfWeek + 27) % 7) + 1;
	}
	else {
		dayOfWeek = ((dayOfWeek + 30) % 7) + 1;
	}
}

int main() {
	std::array<int, 7> daysOf13th = {0, 0, 0, 0, 0, 0};
	std::ifstream infile("friday.in");
	int numOfYears, month = 1, dayOfWeek = 3, year = 1900;
	bool leap;

	infile >> numOfYears;

	while (year < (1900 + numOfYears)) {
		if (year % 4 == 0 && !(year % 100 == 0)) {
			leap = true;
		}
		else if (year % 400 == 0) {
			leap = true;
		}
		else {
			leap = false;
		}

		calcMonth(month, dayOfWeek, daysOf13th, leap);
		month++;
		if (month == 13) {
			year++;
			month = 1;
		}
	}

	std::ofstream outfile("friday.out");
	for (int i = 0; i < 7; i++) {
		outfile << daysOf13th[i];
		if (i < 6) {
			outfile << ' ';
		}
	}
	outfile << "\n";

	outfile.close();

	return 0;
}