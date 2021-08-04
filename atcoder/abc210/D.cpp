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
    int64_t H, W, C; cin >> H >> W >> C;
    const int64_t INF = 10000000000000000;
    vector<vector<int64_t>> A(H, vector<int64_t>(W));
    vector<vector<int64_t>> preMin(H, vector<int64_t>(W, INF));
    vector<vector<int64_t>> sufMin(H, vector<int64_t>(W, INF));
    for (auto& row: A) {
        for (auto& cell: row) {
            cin >> cell;
        }
    }
    int64_t ans = INF;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            preMin[i][j] = A[i][j] - C * (i + j);
            if (i) preMin[i][j] = min(preMin[i][j], preMin[i-1][j]);
            if (j) preMin[i][j] = min(preMin[i][j], preMin[i][j-1]);
        }
    }
    for (int i = 0; i < H; ++i) {
        for (int j = W - 1; ~j; --j) {
            sufMin[i][j] = A[i][j] - C * (i - j);
            if (i) sufMin[i][j] = min(sufMin[i][j], sufMin[i-1][j]);
            if (j + 1 < W) sufMin[i][j] = min(sufMin[i][j], sufMin[i][j+1]);
        }
    }
    dbg(sufMin);
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 && j == 0) continue;
            int64_t c1 = INF, c2 = INF;
            if (i) c1 = preMin[i-1][j], c2 = sufMin[i-1][j];
            if (j) c1 = min(c1, preMin[i][j-1]);
            if (j + 1 < W) c2 = min(c2, sufMin[i][j+1]);
            ans = min({ans, A[i][j] + C*(i+j) + c1, A[i][j] + C*(i-j) + c2});
        }
    }
    cout << ans << "\n";
}

