/*
ID: mihiran1
LANG: C++
TASK: namenum
*/

#include <fstream>
#include <vector>
#include <array>
#include <string>


std::vector<std::vector<char>> dict({ {'A', 'B', 'C'},
                                     {'D', 'E', 'F'},
                                     {'G', 'H', 'I'},
                                     {'J', 'K', 'L'},
                                     {'M', 'N', 'O'},
                                     {'P', 'R', 'S'},
                                     {'T', 'U', 'V'},
                                     {'W', 'X', 'Y'} });

bool checkName(std::string& name, long long inputNum) {
    std::string inputStr = std::to_string(inputNum);
    size_t len = inputStr.length();

    bool check = false;

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < 3; j++) {
            if (name[i] == dict[(inputStr[i] - '0') - 2][j]) {
                check = true;
            }
        }
        if (check == false) {
            return false;
        }
        check = false;
    }
    return true;
}

std::vector<std::string> findName(long long inputNum) {
    size_t len = std::to_string(inputNum).length();

    std::ifstream dictTxt("dict.txt");
    std::string name;

    std::vector<std::string> names;

    while (std::getline(dictTxt, name)) {
        if (name.length() == len) {
            if (checkName(name, inputNum)) {
                names.push_back(name);
            }
        }
    }

    dictTxt.close();
    return names;
}


int main() {
    long long inputNum;
    std::string inputStr;
    std::ifstream fin("namenum.in");
    fin >> inputStr;
    fin.close();

    inputNum = std::stoll(inputStr);

    auto names = findName(inputNum);

    std::ofstream fout("namenum.out");

    if (names.size() == 0) {
        fout << "NONE" << "\n";
        return 0;
    }

    for (std::string name : names) {
        fout << name << "\n";
    }
    
	return 0;
}