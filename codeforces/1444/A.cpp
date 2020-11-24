#include <bits/stdc++.h>
using namespace std;

void solve() {
    int q;
    int64_t p, ans = 0;
    cin >> p >> q;
    if (p % q)
        ans = p;
    else {
        vector<int> div;
        int64_t tmp = q;
        if (tmp % 2 == 0) {
            while (!(tmp % 2)) tmp /= 2;
            div.emplace_back(2);
        }
        for (int i = 3; i*i <= tmp; i += 2)
            if (!(tmp % i)) {
                while (!(tmp % i)) tmp /= i;
                div.emplace_back(i);
            }
        if (tmp > 1) div.emplace_back(tmp);
        for (auto& i: div) {
            tmp = p;
            while (!(tmp % q)) tmp /= i;
            ans = max(ans, tmp);
        }
    }
    cout << ans << "\n";
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
