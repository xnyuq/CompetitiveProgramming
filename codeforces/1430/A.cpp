#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    for (int i = 0; 7*i <= n; ++i) {
        for (int j = 0; 5 * j <= n-7*i; ++j)
            for (int k = 0; 3*k<=n-7*i-5*j; ++k) {
                if (7*i+5*j+3*k ==n) {
                    cout << k << " " << j << " " << i << "\n";
                    return;
                }
            }
    }
    cout << "-1\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

