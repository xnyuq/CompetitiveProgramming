/**
 * @author      : quynx
 * @created     : 24/03/2021 18:06:00 +07
 * @filename    : A
 * @source      : https://codeforces.com/contest/1483/problem/A
 */

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
    //freopen("A.in", "r", stdin);
    //freopen("A.out", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int N, M; cin >> N >> M;
        int upr = (M+1)/2;
        vector<int> day[M], cnt(N+1), ans(M);
        for (int i = 0; i < M; ++i) {
            int k; cin >> k;
            day[i].resize(k);
            for (auto& v: day[i]) cin >> v;
        }
        for (int i = 0; i < M; ++i) {
            ans[i] = day[i][0];
            ++cnt[day[i][0]];
        }
        bool flag = true;
        for (int i = 1; i <= N; ++i) {
            if (cnt[i] > upr) {
                for (int j = 0; j < M && cnt[i] > upr; ++j) {
                    if (ans[j] == i && (int)day[j].size() > 1) {
                        ans[j] = day[j][1];
                        --cnt[i]; ++cnt[ans[j]];
                    }
                }
                if (cnt[i] > upr) {
                    flag = false;
                    break;
                }
                else flag = true;
            }
        }
        if (!flag) cout << "NO";
        else {
            cout << "YES\n";
            for (auto& i: ans) cout<< i << " ";
        } 
        cout <<"\n";
    }
}

