#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5 + 10;
const int MOD = 1e9 + 7;

int64_t fact[mxN], inv[mxN];

int64_t C(int n, int r) {
    if (r > n) return 0;
    return fact[n] * inv[n - r] % MOD * inv[r] % MOD;
}

int64_t binpow(int64_t a, int64_t b) {
    int64_t res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n, m, k;
    int64_t ans = 0;
    cin >> n >> m >> k;
    vector<int> arr(n);
    for (auto& i : arr) cin >> i;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; ++i) {
        int cnt =
            upper_bound(arr.begin(), arr.end(), arr[i] + k) - arr.begin() - i;
        ans = (ans + C(cnt - 1, m - 1)) % MOD;
        //cerr << "ans += C(" << cnt-1<<","<<m-1<<") = "<<C(cnt-1, m-1) << "\n";
        //cerr << "ans = " << ans << "\n";
    }
    cout << ans << "\n";
}

int main() {
    fact[0] = inv[0] = 1;
    for (int i = 1; i < mxN; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = binpow(fact[i], MOD - 2);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
