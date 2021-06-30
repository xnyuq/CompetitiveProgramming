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
#include <climits>
#include <unordered_map>
#include <unordered_set>
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
        int N;
        cin >> N;
        vector<int> q(N);
        for (auto& i: q) cin >> i;
        set<int> s1, s2;
        for (int i = 1; i <= N; ++i) s1.insert(i), s2.insert(i);
        vector<int> res1(N, -1), res2(N, -1);
        res1[0] = res2[0] = q[0];
        s1.erase(q[0]);
        s2.erase(q[0]);
        for (int i = 1; i < N; ++i) {
            if (q[i] == q[i-1]) {
                res1[i] = *s1.begin();
                s1.erase(s1.begin());
                auto it = prev(s2.lower_bound(q[i]), 1);
                res2[i] = *it;
                s2.erase(it);
            }
            else res1[i] = res2[i] = q[i], s1.erase(q[i]), s2.erase(q[i]);
        }
        for (auto& i: res1) cout << i << " "; cout << "\n";
        for (auto& i: res2) cout << i << " "; cout << "\n";
    }
}
