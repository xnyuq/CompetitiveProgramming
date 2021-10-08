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

using mat = vector<vector<bool>>;
void strip(mat &a) {
    int mini = (int)a.size() - 1, maxi = 0;
    int minj = (int)a.size() - 1, maxj = 0;
    for (int i = 0; i < (int)a.size(); ++i) {
        for (int j = 0; j < (int)a[0].size(); ++j) {
            if (a[i][j]) {
                mini = min(mini, i);
                maxi = max(maxi, i);
                minj = min(minj, j);
                maxj = max(maxj, j);
            } 
        }
    }
    mat b;
    for (int i = mini; i <= maxi; ++i) {
        vector<bool> tmp;
        for (int j = minj; j <= maxj; ++j) tmp.push_back(a[i][j]);
        b.push_back(tmp);
    }
    a.swap(b);
}
void rotate(mat &a) {
    int n = a.size(), m = a[0].size();
    mat b(m, vector<bool>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            b[i][j] = a[j][m-i-1];
        }
    }
    a.swap(b);
}

int main() {
    ios_base::sync_with_stdio(false);
#ifndef QUYNX_DEBUG 
    cin.tie(nullptr);
#endif
    int n; cin >> n;
    mat a(n, vector<bool>(n)), b(n, vector<bool>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char tmp; cin >> tmp;
            a[i][j] = tmp == '#';
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char tmp; cin >> tmp;
            b[i][j] = tmp == '#';
        }
    }
    strip(a); strip(b);
    bool ans = a == b;
    for (int i = 0; i < 3; ++i) {
        rotate(a);
        if (a == b) ans = true;
    }
    cout << (ans ? "Yes" : "No");
}

