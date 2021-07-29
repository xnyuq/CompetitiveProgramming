/**
 * @author      : xnyuq
 * @created     : 24/05/2021 19:47:41 +07
 * @filename    : abc202c
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
#include <unordered_map>
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
    vector<int> a(n), b(n), c(n);
    for (auto& i: a) {
        cin >> i;
        --i;
    }
    for (auto& i: b) {
        cin >> i;
        --i;
    }
    for (auto& i: c) {
        cin >> i;
        --i;
    }
    int64_t ans = 0;
    unordered_map<int, int> cnt;
    for (auto& i: c) {
        cnt[b[i]]++;
    }
    for (auto& i: a) {
        ans += cnt[i];
    }
    cout << ans << "\n";
}

