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
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> rank(5, vector<int>(N+1));
        for (int i = 1; i <= N; ++i) {
            for (int j = 0; j < 5; ++j) {
                cin >> rank[j][i];
            }
        }
        int potentialWinner = 1;
        for (int i = 2; i <= N; ++i) {
            int cnt = 0;
            for (int j = 0; j < 5; ++j) {
                cnt += rank[j][i] < rank[j][potentialWinner];
            }
            if (cnt > 2) potentialWinner = i;
        }
        bool win = true;
        for (int i = 1; i <= N; ++i) {
            if (potentialWinner == i) continue;
            int cnt = 0;
            for (int j = 0; j < 5; ++j) {
                cnt += rank[j][i] < rank[j][potentialWinner];
            }
            if (cnt > 2) {
                win = false;
                break;
            }
        }
        cout << (win ? potentialWinner : -1) << "\n";
    }
}

