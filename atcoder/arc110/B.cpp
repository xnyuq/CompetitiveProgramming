#include <bits/stdc++.h>
using namespace std;

const int64_t mxN = 3e10;

void solve() {
    int n;
    string t;
    cin >> n >> t;
    int64_t ans = 0;
    string init = "110";
    for (int start = 0; start < 3; ++start) {
        bool valid = true;
        for (int i = 0; i < n; ++i) {
            char want = init[(start+i)%3];
            valid = valid && t[i] == want;
        }
        if (valid) {
            int64_t end = mxN - n;
            while (start != end % 3) --end;
            ans += (end - start) / 3 + 1;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
// 110110110110110110
