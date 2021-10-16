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

const int MX = 3e3+10;
const int MOD = 998244353;
void add(vector<int> &bit, int i, int k) {
    for (i += 1; i < MX; i += i & -i)
        bit[i] = (bit[i] + k) % MOD;
}

int64_t query(vector<int> &bit, int i) {
    int64_t res = 0;
    for (i += 1; i > 0; i -= i & -i)
        res = (res + bit[i]) % MOD;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
#ifndef QUYNX_DEBUG 
    cin.tie(nullptr);
#endif
    int N; cin >> N;
    vector<int> bit(MX);
    vector<int> l(N), r(N);
    for (auto& i: l) cin >> i;
    for (auto& i: r) cin >> i;
    for (int i = l[0]; i <= r[0]; ++i) add(bit, i, 1);
    for (int i = 1; i < N; ++i) {
        vector<int> tmp(MX);
        for (int j = l[i]; j <= r[i]; ++j) {
            add(tmp, j, query(bit, j));
        }
        tmp.swap(bit);
    }
    cout << query(bit, 3000) << "\n";
}

