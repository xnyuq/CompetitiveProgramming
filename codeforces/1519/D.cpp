/**
 * @author      : xnyuq
 * @created     : 08/05/2021 08:32:04 +07
 * @filename    : 1519D
 */

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
#include <climits>
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
    int n;
    cin >> n;
    vector<int64_t> a(n), b(n), prod(n);
    for (auto& i: a) cin >> i;
    for (auto& i: b) cin >> i;
    prod[0] = a[0] * b[0];
    for (int i = 1; i < n; ++i) prod[i] = prod[i-1] + a[i] * b[i];
    int64_t ans = prod.back();
    for (int mid = 0; mid < n - 1; ++mid) {
        int64_t sum =  a[mid] * b[mid];
        for (int l = mid - 1, r = mid + 1; l >= 0 && r < n; --l, ++r) {
            sum +=  a[l] * b[r] +  a[r] * b[l];
            ans = max(ans, prod[l] -  a[l] * b[l] + sum + prod[n-1] - prod[r]);
        }
        sum = 0;
        for (int l = mid, r = mid + 1; l >= 0 && r < n; --l, ++r) {
            sum +=  a[l] * b[r] +  a[r] * b[l];
            ans = max(ans, prod[l] - a[l] * b[l] + sum + prod[n-1] - prod[r]);
        }
    }
    cout << ans << "\n";
}
