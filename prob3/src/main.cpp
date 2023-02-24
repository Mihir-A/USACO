#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct ifS
{
    int index, value, returnVal;
};

struct ans
{
    string input;
    int output;
};

int main() {

    vector<ifS> ifsVec;

    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<ans> ansVec;
        ansVec.resize(m);

        for (int i = 0; i < m; i++) {
            string s;
            cin >> s;
            ansVec[i].input = s;

            int sol;
            cin >> sol;
            ansVec[i].output = sol;
        }
    }

    return 0;
}
