// time-limit: 2000
#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
int binpow(int a, int b) {
    a %= MOD;
    b %= MOD - 1;
    int64_t res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = 1ll * a * a % MOD;
        b >>= 1;
    }
    return res;
}

int divMod(int a,int b) {
    a %= MOD;
    return a * 1ll * binpow(b, MOD-2) % MOD;
}

void solve() {
    int n;
    cin >> n;
    vector<int> fib(n+1);
    fib[1] = 1;
    for (int i = 2; i <= n; ++i)
        fib[i] = (fib[i-1]+fib[i-2]) % MOD;
    cout << divMod(fib[n],binpow(2,n)) << "\n";
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
