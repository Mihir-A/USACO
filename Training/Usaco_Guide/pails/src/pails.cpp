#include <iostream>
#include <fstream>

using namespace std;

int x, y, m;
int ans = 0;

void solve(){
    for (int i = 0; i < m / x + 1; i++)
    {
        if (i * x + (((m - i * x) / y) * y) <= m){
            ans = max(ans, i * x + (((m - i * x) / y) * y));
        }
    }
    
}


int main(){
    ifstream fin("pails.in");
    ofstream fout("pails.out");
    fin >> x >> y >> m;
    solve();
    fout << ans << '\n';
}