#include <bits/stdc++.h>
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
    int N; cin >> N;
    map<int, map<int, int>> mp;
    vector<array<int,2>> points(N);
    for (auto& p: points) cin >> p[0] >> p[1];
    int64_t cnt = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;
            if (points[i][1] == points[j][1] && points[i][0] < points[j][0]) {
                ++mp[points[i][0]][points[j][0]];
            } 
        }
    }
    for (auto& m: mp) {
        for (auto& p: m.second) {
            int cur = p.second;
            cnt += cur * (cur - 1) /2;
        }
    }
    cout << cnt << "\n";
}

