/*
ID: mihiran1
LANG: C++
TASK: palsquare
*/
#include <fstream>
#include <cmath>
#include <vector>
#include <string>

std::string convVtoS(const std::vector<int>& vec) {
    std::string s;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] >= 10) {
            s.push_back('A' + (vec[i] - 10));
        }
        else {
            s.push_back('0' + vec[i]);
        }
        
    }
    return s;
}

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
    std::ifstream fin("palsquare.in");
    int base;
    fin >> base;
    fin.close();

    std::ofstream fout("palsquare.out");
    std::vector<int> num;
    std::vector<int> numSq;

    for (int i = 1; i <= 300; i++) {
        convToBase((int)pow(i, 2), base, numSq);

        if (isPal(numSq)) {
            convToBase(i, base, num);
            fout << convVtoS(num) << " " << convVtoS(numSq) << "\n";
        }
    }
    fout.close();
}