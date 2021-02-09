#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        int64_t ans = 0;
        cin >> n >> m;
        vector<int> k(n), c(m);
        for (auto &i: k) {
            cin >> i;
            --i;
        }
        for (auto& i: c) cin >> i;
        sort(k.rbegin(), k.rend());
        int cnt = 0;
        for (auto& num: k) {
            if (cnt < m && c[cnt] < c[num]) ans += c[cnt++];
            else {
                ans += c[num];
            }
        }
        cout << ans << "\n";
    }
}

