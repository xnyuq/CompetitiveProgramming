#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, jumps = 0;
    cin >> x;
    while (x > 0) {
        x -= ++jumps;
    }
    if (x == -1) ++jumps;
    cout << jumps << "\n";
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
