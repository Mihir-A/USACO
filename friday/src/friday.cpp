/*
ID: mihiran1
LANG: C++
TASK: friday
*/
#include <iostream>
#include <array>
#include <fstream>
#define DAYS_OF_WEEK 7

typedef enum month {
	jan = 1,
	feb,
	mar,
	apr,
	may,
	jun,
	jul,
	aug,
	sep,
	oct,
	nov,
	dec,
	maxMonth
} month_t;

void calcMonth(month_t month, int& dayOfWeek, std::array<int, 7>& daysOf13th, bool leap) {
	int dayOf13th = dayOfWeek - 2;

	if (dayOf13th <= 0) {
		dayOf13th = DAYS_OF_WEEK + dayOf13th;
	}

	daysOf13th[dayOf13th - 1] += 1;

	if (month == apr || month == jun || month == sep || month == nov) {
		dayOfWeek = ((dayOfWeek + 29) % DAYS_OF_WEEK) + 1;
	}
	else if (month == feb && leap == true) {
		dayOfWeek = ((dayOfWeek + 28) % DAYS_OF_WEEK) + 1;
	}
	else if (month == feb && leap == false) {
		dayOfWeek = ((dayOfWeek + 27) % DAYS_OF_WEEK) + 1;
	}
	else {
		dayOfWeek = ((dayOfWeek + 30) % DAYS_OF_WEEK) + 1;
	}
}

int main() {
	std::array<int, 7> daysOf13th = { 0, 0, 0, 0, 0, 0 };
	std::ifstream infile("friday.in");
	int numOfYears, dayOfWeek = 3, year = 1900;
	month_t month = jan;
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
		month = (month_t)((int)month + 1);
		if (month == maxMonth) {
			year++;
			month = jan;
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