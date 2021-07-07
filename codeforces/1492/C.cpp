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
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    vector<int> left(m), right(m);
    for (int i = 0, j = 0; i < m; ++i) {
        while (s[j] != t[i]) ++j;
        left[i] = j++;
    }
    for (int i = m - 1, j = n - 1; i >= 0; --i) {
        while (s[j] != t[i]) --j;
        right[i] = j--;
    }
    dbg(left, right);
    int ans = 1;
    for (int i = 0; i < m - 1; ++i) ans = max(ans, right[i+1] - left[i]);
    cout << ans << "\n";
}

