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

map<int,int> win;
bool cmp(int a, int b) {
    if (win[a] == win[b]) return a < b;
    return win[a] > win[b];
}

int main() {
    ios_base::sync_with_stdio(false);
#ifndef QUYNX_DEBUG 
    cin.tie(nullptr);
#endif
    int N, M; cin >> N >> M;
    vector<vector<char>> A(2*N, vector<char> (M));
    vector<int> rank(2*N);
    for (int i = 0; i < 2*N; ++i) for (int j = 0; j < M; ++j) cin >> A[i][j], rank[i] = i;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            dbg(i, rank[j<<1], rank[j<<1|1]);
            // match between rank[j*2] and rank[j*2+1]
            // G-rock, C-Scissor, P-Paper;
            if (A[rank[j<<1]][i] == 'G' && A[rank[j<<1|1]][i] == 'C') win[rank[j<<1]]++;
            else if (A[rank[j<<1]][i] == 'G' && A[rank[j<<1|1]][i] == 'P') win[rank[j<<1|1]]++;
            else if (A[rank[j<<1]][i] == 'C' && A[rank[j<<1|1]][i] == 'G') win[rank[j<<1|1]]++;
            else if (A[rank[j<<1]][i] == 'C' && A[rank[j<<1|1]][i] == 'P') win[rank[j<<1]]++;
            else if (A[rank[j<<1]][i] == 'P' && A[rank[j<<1|1]][i] == 'G') win[rank[j<<1]]++;
            else if (A[rank[j<<1]][i] == 'P' && A[rank[j<<1|1]][i] == 'C') win[rank[j<<1|1]]++;
        }
        sort(rank.begin(), rank.end(), cmp);
        dbg(rank, win);
    }
    for (auto &p: rank) cout << p + 1 << "\n";
}

