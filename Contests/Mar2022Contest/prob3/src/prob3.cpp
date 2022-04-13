#include <iostream>
#include <vector>

int n;
std::vector<std::vector<int>> recipes;
std::vector<int> ammounts;

int findIndex(std::vector<int>* recipe) {
	for (int i = 0; i < recipes.size(); i++) {
		if (recipes[i] == *recipe) {
			return i;
		}
	}
}

std::vector<int>* findRecipe(int i) {
	for (auto& a : recipes) {
		if (a[0] == i) {
			return &a;
		}
	}
	return nullptr;
}

bool canMake(const std::vector<int>* recipe) {
	for (int i = 1; i < recipe->size(); i++) {
		if (ammounts[(*recipe)[i] - 1] == 0) {
			return false;
		}
	}
	return true;
}

void makeRecipe(const std::vector<int>* recipe) {
	for (int i = 1; i < recipe->size(); i++) {
		ammounts[(*recipe)[i] - 1] --;
	}
	ammounts[(*recipe)[0] - 1]++;
}


bool solve(int ammount) {
	std::vector<int>* recipe = findRecipe(ammount);
	if (recipe) {
		if (canMake(recipe)) {
			makeRecipe(recipe);
			return true;
		}
		else {
			for (int i = 1; i < recipe->size(); i++) {
				if (ammounts[(*recipe)[i] - 1] == 0) {
					if (!solve((*recipe)[i])) {
						return false;
					}
				}
			}
			if (canMake(recipe)) {
				makeRecipe(recipe);
				return true;
			}
			
		}
	}
	return false;
}


int main() {
	
	std::cin >> n;
	ammounts.reserve(n);

	for (int i = 0; i < n; i++) {
		int tmp;
		std::cin >> tmp;
		ammounts.push_back(tmp);
	}

	int k;
	std::cin >> k;
	recipes.resize(k);
	for (int i = 0; i < k; i++) {
		int produce;
		int m;
		std::cin >> produce >> m;

		recipes[i].reserve(m + 1);
		recipes[i].push_back(produce);

		for (int j = 0; j < m; j++) {
			int tmp;
			std::cin >> tmp;
			recipes[i].push_back(tmp);
		}
	}

	while (solve(n));

	std::cout << ammounts[n - 1];
	return 0;
}