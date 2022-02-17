/*
ID: mihiran1
LANG: C++
TASK: beads
*/

#include <fstream>
#include <string>

int breakNecklace(std::string& necklace, int length) {

    int max = 0;
    for (int pos = 0; pos < length; pos++) {
        char letter = necklace[pos];
        int beads = 0;
        int j = pos;

        int t;
        if (letter != 'w') {
            t = 1;
        }
        else {
            t = 0;
        }
        while (t <= 2) {
            while (j < length + pos) {
                if ((necklace[j] == letter || necklace[j] == 'w')) {
                    beads++;
                    j++;
                }
                else {
                    break;
                }
            }
            letter = necklace[j];
            t++;
        }

        max = std::max(max, beads);
    }
    return max;
}

int main() {
    std::ofstream outfile("beads.out");
    std::ifstream infile("beads.in");

    int length;
    std::string necklace;

    infile >> length >> necklace;
    necklace += necklace;

    outfile << breakNecklace(necklace, length) << "\n";
    return 0;
}