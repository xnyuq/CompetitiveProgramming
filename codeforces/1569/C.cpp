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

const int MOD = 998244353;

int64_t binpow(int64_t a, int64_t b) {
    a %= MOD;
    int64_t res = 1;
    while (b > 0) {
        if (b&1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
#ifndef QUYNX_DEBUG 
    cin.tie(nullptr);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (auto &i: arr) cin >> i;
        int64_t ans;
        int mx = *max_element(arr.begin(), arr.end());
        int sec = 0;
        int cnt = 0, k = 0;
        for (auto &i: arr) {
            if (i == mx) ++cnt;
            else sec = max(sec, i);
            if (i == mx-1) ++k;
        }

        if (sec && sec != mx - 1 && cnt == 1) ans = 0;
        else {
            ans = 1;
            for (int i = 2; i <= n; ++i) ans = (ans * i) % MOD;
            if (cnt == 1) {
                ans -= ans*binpow(k+1, MOD - 2)%MOD-MOD;
                ans %= MOD;
            }
        }

        cout << ans << "\n";
    }
}
// secCnt * (n-1)!
