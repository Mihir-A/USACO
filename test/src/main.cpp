#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--) {
        vector<char> cows;
        int n, k;
        cin >> n >> k;
        vector<char> sol(n, '.');
        cows.reserve(n);

        for (int i = 0; i < n; i++) {
            char c;
            cin >> c;
            cows.push_back(c);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (sol[i] != '.') continue;
            sol[i] = cows[i];
            ans++;
            for (int j = max(0, i - k); j <= min(n - 1, i + k); j++) {
                if (cows[j] == cows[i]) {
                    sol[j] = cows[i];
                }
            }
        }
        cout << ans << '\n';
        for (auto c : sol) {
            cout << c;
        }
        cout << '\n';
    }

    return 0;
}