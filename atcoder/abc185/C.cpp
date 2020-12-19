#include <bits/stdc++.h>
using namespace std;

void solve() {
    int l;
    cin >> l; --l;
    vector<int64_t> C(12);
    C[0] = 1;
    for (int i = 1; i <= l; ++i) {
        for (int j = min(i,11); j; --j) {
            C[j] += C[j-1];
        }
    }
    cout << C[11] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}

