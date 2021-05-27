/**
 * @author      : xnyuq
 * @created     : 27/05/2021 17:53:14 +07
 * @filename    : 1521B
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
        vector<int> arr(n);
        for (auto& i: arr) cin >> i;
        int pos = min_element(arr.begin(), arr.end()) - arr.begin(), minE = arr[pos], k = 0;
        for (int i = 0; i < n; ++i)
            if (arr[i] != minE + abs(pos-i)) ++k;
        cout << k << "\n";
        for (int i = 0; i < n; ++i) {
            if (arr[i] != minE + abs(pos-i)) cout << i+1 << " " << pos+1 << " " << minE + abs(pos-i) << " " << minE << "\n";
        }
    }
}

