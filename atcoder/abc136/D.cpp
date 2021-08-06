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
    string s;
    cin >> s;
    int n = s.length();
    int cnt = 0;
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'R') ++cnt;
        else {
            ans[i-1] = cnt;
            cnt = 0;
        }
    }
    dbg(s);
    cnt = 0;
    for (int i = n - 1; ~i; --i) {
        if (s[i] == 'L') ++cnt;
        else {
            if (!ans[i+1]) ans[i+1] = cnt;
            cnt = 0;
        }
    }
    dbg(ans);
    for (int i = 0; i < n - 1; ++i) {
        if (!ans[i] || !ans[i+1]) continue;
        int sum = ans[i] + ans[i+1];
        if (sum & 1) {
            if (ans[i] & 1) {
                ans[i] = (sum+1)/2;
            }
            else {
                ans[i] = sum/2;
            }
            ans[i+1] = sum - ans[i];
        }
        else {
            ans[i] = ans[i+1] = sum / 2;
        }
        ++i;
    }
    for (auto& i: ans) cout << i << " ";
    cout << "\n";
}

