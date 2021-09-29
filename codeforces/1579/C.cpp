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

int n, m, k;
int dx[] = {-1, -1, 1, 1}, dy[] = {-1, 1, 1, -1};
vector<vector<bool>> mat;
bool valid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m && mat[i][j];
}

int countDir(int i, int j, int dir) {
    int cnt = 0;
    while (valid(i+dx[dir],j+dy[dir])) {
        ++cnt;
        i += dx[dir];
        j += dy[dir];
    }
    return cnt;
}



int main() {

    ios_base::sync_with_stdio(false);
#ifndef QUYNX_DEBUG 
    cin.tie(nullptr);
#endif
    int t; cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        char c;
        mat = vector<vector<bool>>(n, vector<bool>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> c;
                mat[i][j] = c == '*';
            }
        }
        bool ans = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!mat[i][j]) continue;
                array<int, 4> cnt = {};
                for (int l = 0; l < 4; ++l) cnt[l] = countDir(i, j, l);
                // is bottom of check
                if (cnt[0] >= k && cnt[1] >= k) continue;
                if (i == n - 1 || (cnt[0] + cnt[2] < k && cnt[1] + cnt[3] < k)) {
                    ans = false;
                    goto fns;
                }
                bool valid = false;
                if (cnt[0] + cnt[2] >= k) {
                    for (int I = i + k - cnt[0], J = j + k - cnt[0]; I < n && I >= 0 && J < m && J >= 0 && mat[I][J]; ++I, ++J) {
                        if (countDir(I, J, 1) >= max(I-i, k)) {
                            valid = true;
                            break;
                        }
                    }
                }
                if (!valid && cnt[1] + cnt[3] >= k) {
                    for (int I = i + k - cnt[1], J = j - (k - cnt[1]); I < n && I >= 0 && J < m && J >= 0 && mat[I][J]; ++I, --J) {
                        if (countDir(I, J, 0) >= max(I-i, k)) {
                            valid = true;
                            break;
                        }
                    }
                }
                if (valid == false) {
                    ans = false;
                    goto fns;
                }
            }
        }
fns:cout << (ans ? "YES\n" : "NO\n");
    }
}

