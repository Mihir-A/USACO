#include <iostream>
#include <vector>
#include <algorithm>

using ull = unsigned long long;
using namespace std;

int main() {
    ull n;
    cin >> n;

    vector<ull> maxP;
    maxP.reserve(n);

    for (ull i = 0; i < n; i ++) {
        ull tmp;
        cin >> tmp;
        maxP.push_back(tmp);
    }

    sort(maxP.begin(), maxP.end());

    ull maxRev = 0;
    ull maxPrice = 0;
    for(ull i = 0; i < n; i ++) {
        ull cost = maxP[i];
        ull rev = cost * (n - i);

        if (rev > maxRev) {
            maxRev = rev;
            maxPrice = cost;
        }
    }

    cout << maxRev << ' ' << maxPrice;

    return 0;

}