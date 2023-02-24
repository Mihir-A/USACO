#include <iostream>
#include <vector>

using namespace std;

struct Cow
{
    bool isFull;
    char type;
};

int checkFull(const vector<Cow>& cows, int i, int k, char cowT)
{
    int count = 0;
    for (int j = i - k; j <= i + k; j++)
    {
        if (j >= 0 && j < cows.size() && cows[j].type == cowT && !cows[j].isFull)
        {
            count++;
        }
    }
    return count;
}

void makeFull(vector<Cow>& cows, int i, int k, char cowT)
{
    for (int j = i - k; j <= i + k; j++)
    {
        if (j >= 0 && j < cows.size() && cows[j].type == cowT && !cows[j].isFull)
        {
            cows[j].isFull = true;
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--) {
        vector<Cow> cows;
        int n, k;
        cin >> n >> k;
        vector<char> sol(n, '.');
        cows.reserve(n);

        for (int i = 0; i < n; i++) {
            char c;
            cin >> c;
            cows.push_back({ false, c });
        }
        int ans = 0;
        while(true) {
            int maxFull = 0;
            int place = -1;
            char type = ' ';
            for (int i = 0; i < n; i++) {
                if (sol[i] != '.') continue;
                const int fullG = checkFull(cows, i, k, 'G');
                if (fullG > maxFull) {
                    maxFull = fullG;
                    place = i;
                    type = 'G';
                }

                const int fullH = checkFull(cows, i, k, 'H');
                if (fullH > maxFull) {
                    maxFull = fullH;
                    place = i;
                    type = 'H';
                }
            }
            if (place == -1) {
                break;
            }
            sol[place] = type;
            ans++;
            makeFull(cows, place, k, type);
        }
        cout << ans << '\n';
        for (auto c : sol) {
            cout << c;
        }
        cout << '\n';
    }

    return 0;
}
