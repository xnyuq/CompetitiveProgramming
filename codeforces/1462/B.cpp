#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int del = n - 4;
    for (int i= 0, j = i+del-1; j < n; ++i,++j) {
        if (s.substr(0, i) + s.substr(j+1, n-j) == "2020") {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
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

