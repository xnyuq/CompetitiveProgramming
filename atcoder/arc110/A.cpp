#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    int64_t ans = 1;
    for (int64_t i = 2; i <= N; ++i) {
        ans = ans*i/__gcd(ans,i);
    }
    cout << ans + 1 << "\n";
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
