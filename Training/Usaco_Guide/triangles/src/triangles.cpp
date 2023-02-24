#include <iostream>
#include <array>

using namespace std;

std::array<int, 1000000> field{ 0 };

int getSum(int s, int e) {
    int sum = 0;
    for (int i = s; i <= e; i++) {
        sum += field[i];
    }
    return sum;
}

int main() {
    int n, k;
    cin >> n >> k;


    for (int i = 0; i < n; i++) {
        int g_i, x_i;
        cin >> g_i >> x_i;
        field[x_i] = g_i;
    }
    int ans = 0;
    for (int i = 0; i < field.size(); i++) {
        ans = max(ans, getSum(i, i + 2 * k));
    }
    cout << ans;

}