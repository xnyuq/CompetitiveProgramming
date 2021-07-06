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
        vector<int> dp(n);
        dp[0] = arr[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = dp[i-1] ^ arr[i];
        }
        bool found = false;
        if (n % 2 == 0 && dp[n-1] == 0) {
            found = true;
        }
        else {
            for (int i = 1; i < n - 1; ++i) {
                for (int j = i+1; j < n; ++j) {
                    array<int, 3> sub = {dp[i-1], dp[j-1] ^ dp[i-1], dp[n-1] ^ dp[j-1]};
                    if ((sub[0] == sub[1] && sub[1] == sub[2]) || (sub[0] ^ sub[1]) == sub[2] || sub[0] == (sub[1] ^ sub[2])) {
                        dbg("hehe");
                        found = true;
                        break;
                    }
                }
            }
        }
        cout << (found ? "YES\n" : "NO\n");

    }
}

