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

int main() {
    ios_base::sync_with_stdio(false);
#ifndef QUYNX_DEBUG 
    cin.tie(nullptr);
#endif
    int n; cin >> n;
    vector<int> arr(n);
    for (auto& i: arr) cin >> i;
    const int MOD = 998244353;
    vector<int64_t> cnt(10);
    cnt[arr[0]] = 1;
    for (int i = 1; i < n; ++i) {
        vector<int64_t> tmp(10);
        for (int j = 0; j < 10; ++j) {
            tmp[(j * arr[i]) % 10] = (tmp[(j * arr[i]) % 10] + cnt[j]) % MOD;
            tmp[(j + arr[i]) % 10] = (tmp[(j + arr[i]) % 10] + cnt[j]) % MOD;
        }
        cnt.swap(tmp);
    }
    for (int i = 0; i <= 9; ++i) cout << cnt[i] << "\n";
}

