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
int64_t binpow(int64_t a, int b) {
    int64_t res = 1;
    a %= MOD;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
int N;

int maxVal;
const int MX = 3e5+10;
vector<int64_t> bit;
int sum(int k) { int64_t res = 0; for (; k > 0; k -= k & -k) res += bit[k], res %= MOD; return res; }
void add(int i, int val) { for (; i <= maxVal; i += i & -i) bit[i] = bit[i] + val; bit[i] %=MOD; }

int comp(vector<int> &arr) {
    int t = 1;
    map<int,int> mp;
    for (auto &i: arr) mp[i] = 0;
    for (auto &p: mp) p.second = t++;
    for (auto &i: arr) i = mp[i];
    return t;
}

int64_t inv(int x) {
    return binpow(x, MOD-2);
}

int main() {
    ios_base::sync_with_stdio(false);
#ifndef QUYNX_DEBUG 
    cin.tie(nullptr);
#endif
    cin >> N;
    vector<int> A(N);
    for (auto& i: A) cin >> i;
    maxVal = comp(A);
    bit.assign(2 * maxVal, 0);
    int64_t ans = 0;
    add(A[0], 1);
    for (int i = 1; i < N; ++i) {
        dbg(i,A[i],sum(A[i]), binpow(2, i-1) * sum(A[i]));
        ans = (ans + binpow(2, i-1) * sum(A[i]) % MOD) % MOD;
        add(A[i], inv(binpow(2, i)));
    }
    cout << ans << "\n";
}

