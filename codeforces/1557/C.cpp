#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef QUYNX_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

const int MOD = 1e9 + 7;
const int MX = 2e5+10;
int fact[MX];
int64_t binPow(int64_t a, int64_t b) {
    a %= MOD;
    int64_t res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int64_t inv(int64_t x) {
    return binPow(x, MOD - 2);
}

int64_t nCk(int n, int k) {
    return fact[n] * inv(int64_t(fact[k]) * fact[n-k] % MOD) % MOD;
}


int main() {
    ios_base::sync_with_stdio(false);
#ifndef QUYNX_DEBUG 
    cin.tie(nullptr);
#endif
    int t; cin >> t;
    fact[1] = fact[0] = 1;
    for (int i = 2; i <= 200000; ++i) {
        fact[i] = (fact[i-1] * int64_t(i)) % MOD;
    }
    while (t--) {
        int n, k;
        cin >> n >> k;
        int64_t ans = 0, nCkSum = 0;
        for (int i = 0; i < n; i += 2) nCkSum = (nCkSum + nCk(n, i)) % MOD;
        if (n & 1) {
            ans = binPow(1 + nCkSum, k) % MOD;
        }
        else {
            ans = binPow(nCkSum, k);
            for (int i = k - 1; i >= 0; --i) {
                ans = (ans + binPow(nCkSum, k - i - 1) * binPow(2, int64_t(i) * n) % MOD) % MOD;
            }
        }
        cout << ans << "\n";
    }
}
