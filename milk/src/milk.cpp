#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

class Farmer
{
public:
	int maxAmo;
	int price;
	int AmoBought;
};

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

	sortFarm(farmers);

	return 0;
}