#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

std::vector<int> convToBase(int num, int base){
    std::vector<int> convNum;
    bool first = true;
    while(num != 0){
        int i;
        for(i = 0; pow(base, i) <= num; i ++){}
        i --;
        int j;
        for(j = 0; j * pow(base, i) <= num; j++){}
        j --;

        if (first == true){
            convNum.resize(i + 1);
            first = false;
        }

        convNum[convNum.size() - i - 1] = j;
        num -= j * pow(base, i);
    }
    return convNum;
}

int main(){
    std::ifstream fin("palsquare.in");
    int base;
    fin >> base;
    convToBase(107, 9);
}