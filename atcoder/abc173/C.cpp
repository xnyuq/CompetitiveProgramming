#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000
#define mod 1000000007

char a[10][10];
void solve() {
    int n, m , k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];
    }
    int ans = 0;
    for (int x = 0; x < (1 << n); ++x) {
        for (int y = 1; y < (1 << m); ++y) {
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (!(x & 1 << i)) continue; 
                for (int j = 0; j < m; ++j) {
                    if (!(y & 1 << j)) continue;
                    if (a[i][j] == '#') cnt++;
                }
            }
            if (cnt == k) ++ans;
        }
    }
    cout << ans << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
