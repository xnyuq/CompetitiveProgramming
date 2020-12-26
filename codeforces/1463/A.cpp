#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a,b,c;
    cin >> a >> b >> c;
    if ((a+b+c) % 9 || (a+b+c)/9 > min(min(a,b),c)) cout << "NO\n";
    else cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}

