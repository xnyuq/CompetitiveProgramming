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
        vector<bool> direct(n); // if the road directs from i to n or opposite
        for (int i = 0; i < n; ++i) {
            int tmp; cin >> tmp;
            if (tmp == 0) direct[i] = true;
        }
        dbg(direct);
        if (!direct[0]) {
            cout << n + 1;
            for (int i = 1; i <= n; ++i) cout << " " << i;
            cout << "\n";
        }
        else if (direct[n-1]) {
            for (int i = 1; i <= n; ++i) cout << i << " ";
            cout << n + 1 << "\n";
        }
        else {
            int ans = -1;
            for (int i = 0; i < n-1; ++i) {
                if (direct[i] && !direct[i+1]) {
                    ans = i + 1;
                    break;
                }
            }
            if (ans == -1) cout << ans << "\n";
            else {
                for (int i = 1; i <= ans; ++i) cout << i << " ";
                cout << n + 1;
                for (int i = ans + 1; i <= n; ++i) cout << " " << i;
                cout << "\n";
            }

        }
    }
}
