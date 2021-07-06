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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> c(n);
        for (auto& i: c) cin >> i;
        int64_t sumOdd = c[1], sumEven = c[0], cntOdd = 1, cntEven = 1, minOdd = c[1], minEven = c[0];
        int64_t ans = int64_t(n) * c[0] + int64_t(n) * c[1];
        for (int k = 2; k < n; ++k) {
            if (k % 2 == 0) sumEven += c[k], ++cntEven, minEven = min(minEven, int64_t(c[k]));
            else sumOdd += c[k], ++cntOdd, minOdd = min(minOdd, int64_t(c[k]));
            int64_t cur = sumOdd + minOdd * (n - cntOdd) + sumEven + minEven * (n - cntEven);
            ans = min(ans, cur);
        }
        cout << ans << "\n";
    }
}

