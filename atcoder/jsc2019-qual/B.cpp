#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <chrono>
#include <random>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iomanip>
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
    int N; int64_t K; cin >> N >> K;
    vector<int> A(N), a(N), b(N);
    int64_t ans = 0;
    const int MOD = 1e9 + 7;
    const int inv = (MOD + 1) / 2;
    for (auto& i: A) cin >> i;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;
            if (A[i] > A[j]) {
                if (i < j) ++a[i];
                ++b[i];
            }
        }
    }
    dbg(a,b);
    for (int i = 0; i < N; ++i) {
        ans += a[i] * K % MOD;
        ans += b[i] * (K*(K-1)%MOD*inv%MOD) % MOD;
        ans %= MOD;
    }
    cout << ans << "\n";
}

// 2 1 2 1
// 2 0 1 0
