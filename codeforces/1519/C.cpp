/**
 * @author      : xnyuq
 * @created     : 05/05/2021 15:59:22 +07
 * @filename    : 1519C
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
        int n, tmp;
        cin >> n;
        vector<int> team(n);
        vector<vector<int>> uni(n);
        for (int i = 0; i < n; ++i) {
            cin >> team[i];
            --team[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            uni[team[i]].emplace_back(tmp);
        }
        vector<vector<int64_t>> preS(n);
        for (int i = 0; i < n; ++i) {
            if (uni[i].empty()) continue;
            sort(uni[i].rbegin(), uni[i].rend());
            preS[i].resize(uni[i].size());
            preS[i][0] = uni[i][0];
            for (int j = 1; j < (int)preS[i].size(); ++j) {
                preS[i][j] = preS[i][j-1] + uni[i][j];
            }
        }
        vector<int64_t> ans(n);
        dbg(uni); dbg(preS);
        for (int i = 0; i < n; ++i) {
            for (int k = 1; k <= (int)uni[i].size(); ++k) {
                ans[k-1] += preS[i][(int)uni[i].size() / k * k - 1];
            }
        }
        for (auto& i: ans) cout << i << " ";
        cout << "\n";
    }
}

