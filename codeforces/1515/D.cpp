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
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> left(n+1), right(n+1);
        int tmp;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            if (i < l) {
                ++left[tmp];
            }
            else ++right[tmp];
        }
        if (l > r) {
            left.swap(right);
            swap(l, r);
        }
        vector<int> s;
        for (int i = 0; i <= n; ++i) {
            int mn = min(left[i], right[i]);
            l -= mn; r -= mn;
            right[i] -= mn;
            if (right[i]) s.push_back(right[i]);
        }
        int ans = r;
        for (auto &i: s) {
            if (l == r) break;
            if (i >= 2) {
                int sw = min(i/2, (r-l)/2);
                ans -= sw;
                r -= sw*2;
            }
        }
        cout << ans << "\n";
    }
}

