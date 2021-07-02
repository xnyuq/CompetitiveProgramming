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
    int n;
    cin >> n;
    vector<pair<int64_t,int64_t>> pr(n);
    for (int i = 0; i < n; ++i) cin >> pr[i].second >> pr[i].first;
    sort(pr.begin(), pr.end());
    int i = 0, j = n - 1;
    int64_t ans = 0, cnt = 0;
    while (i < j) {
        if (cnt >= pr[i].first) {
            ans += pr[i].second;
            cnt += pr[i].second;
            ++i;
        }
        else {
            if (cnt + pr[j].second >= pr[i].first) {
                int64_t buy = pr[i].first - cnt;
                ans += buy * 2 + pr[i].second;
                cnt += buy + pr[i].second;
                pr[j].second -= buy;
                ++i;
                if (pr[j].second == 0) --j;
            }
            else {
                ans += pr[j].second * 2;
                cnt += pr[j].second;
                --j;
            }
        }
    }
    if (i == j) {
        int64_t buy = max(0LL, min(pr[i].first - cnt, pr[i].second));
        ans += 2 * buy;
        pr[i].second -= buy;
        ans += pr[i].second;
    }
    cout << ans << "\n";
}

