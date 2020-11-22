// time-limit: 2000
#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
int64_t binpow(int a, int b) {
    if (b == 0) return 1;
    int64_t res = binpow(a,b/2);
    if (b&1) return res*res%MOD*(a%MOD)%MOD;
    else return res*res%MOD;
}

int divMod(int a,int b) {
    a %= MOD;
    return a * binpow(b, MOD-2) % MOD;
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
