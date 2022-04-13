/*
ID: mihiran1
LANG: C++
TASK: milk
*/
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

class Farmer
{
public:
	int maxAmo = 0;
	int price = 0;
	bool boughtAll = false;
};

int findPrices(std::vector<Farmer>& farmers, const int ammOfMilk) {
	int bought = 0;
	int price = 0;

	for (int i = 0; bought < ammOfMilk; i ++) {
		if (farmers[i].maxAmo + bought > ammOfMilk) {
			price += farmers[i].price * (ammOfMilk - bought);
			bought = ammOfMilk;
		}
		else {
			price += farmers[i].price * farmers[i].maxAmo;
			bought += farmers[i].maxAmo;
			farmers[i].boughtAll = true;
		}
	}
	return price;
}

void sortFarm(std::vector<Farmer>& farmers) {
	bool sorted = false;
	while (true) {
		for (int i = 0; i < farmers.size() - 1; i++) {

			if (farmers[i].price > farmers[i + 1].price) {
				Farmer tmp = farmers[i];
				farmers[i] = farmers[i + 1];
				farmers[i + 1] = tmp;
				sorted = false;
			}
		}
		if (sorted == true) {
			break;
		}
		sorted = true;
	}
}

int main() {
	std::vector<Farmer> farmers;
	std::ifstream fin("milk.in");

	std::string s;
	getline(fin, s);
	std::stringstream sStream(s);
	int ammOfMilk, numOfFarm;

	sStream >> ammOfMilk >> numOfFarm;

	farmers.resize(numOfFarm);
	for (int i = 0; std::getline(fin, s); i ++) {
		int p, a;
		std::stringstream sStream(s);
		sStream >> p >> a;
		farmers[i].price = p;
		farmers[i].maxAmo = a;
	}

	std::ofstream fout("milk.out");
	if (farmers.size() == 0) {
		fout << '0' << '\n';
	}
	else {
		sortFarm(farmers);
		fout << findPrices(farmers, ammOfMilk) << '\n';
		fout.close();
	}

	return 0;
}