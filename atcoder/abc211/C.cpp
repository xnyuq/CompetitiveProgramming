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
    string S; cin >> S;
    const int MOD = 1e9 + 7;
    map<char, int> hash;
    vector<int> dp(8);
    string key = "chokudai";
    for (int i = 0; i < 8; ++i) {
        hash[key[i]] = i;
    }
    for (auto& c: S) {
        if (hash.find(c) != hash.end()) {
            if (c == 'c') dp[0] = (dp[0] + 1) % MOD;
            else dp[hash[c]] = (dp[hash[c]-1] + dp[hash[c]]) % MOD;
        }
    }
    dbg(dp);
    cout << dp[7] << "\n";
}

