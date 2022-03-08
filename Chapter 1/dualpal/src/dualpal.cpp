/*
ID: mihiran1
LANG: C++
TASK: dualpal
*/
#include <fstream>
#include <cmath>
#include <vector>

bool isPal(std::vector<int>& num) {
    for (int i = 0; i < num.size() / 2; i++) {
        if (!(num[i] == num[num.size() - i - 1])) {
            return false;
        }
    }
    return true;
}

void convToBase(int num, int base, std::vector<int>& convNum) {
    convNum.erase(convNum.begin(), convNum.end());
    bool first = true;
    while (num != 0) {
        int i;
        for (i = 0; pow(base, i) <= num; i++) {}
        i--;
        int j;
        for (j = 0; j * pow(base, i) <= num; j++) {}
        j--;

        if (first == true) {
            convNum.resize(i + 1);
            first = false;
        }

        convNum[convNum.size() - i - 1] = j;
        num -= j * (int)pow(base, i);
    }
}

int main() {
    std::ifstream fin("dualpal.in");
    int num, s;
    fin >> num >> s;
    fin.close();

    std::ofstream fout("dualpal.out");
    int numOfPal = 0;
    std::vector<int> vec;

    for (int i = s + 1; numOfPal < num; i++){
        int numOfbasesPal = 0;
        for (int j = 2; j <= 10 ; j ++){
            convToBase(i, j, vec);

            if(isPal(vec)){
                numOfbasesPal ++;
            }
        }
        if (numOfbasesPal >= 2){
            fout << i << std::endl;
            numOfPal ++;
        }
    }
    fout.close();

    return 0;
}