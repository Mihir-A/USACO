#include <iostream>
#include <fstream>
#include <vector>

int main(){
    std::ifstream fin("skidesign.in");
    std::vector<int> hills;
    int n;

    fin >> n;
    hills.reserve(n);
    for (int tmp; fin >> tmp;){
        hills.push_back(tmp);
    }
    std::sort(hills.begin(), hills.end());

    const std::vector<int> hillsOrig = hills;

    while (hills[n - 1] - hills[0] > 17){
        int costA = 0, costB = 0;
        for (int i = 1; i < hills.size(); i ++){
            if (hills[0] != hills[i]){
                for(int j = 0; j < i; j ++){
                    cost += hills[j] - hills[i];
                }
            }
        }
    }

    std::cin.get();
}