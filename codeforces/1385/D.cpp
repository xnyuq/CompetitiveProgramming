#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef array<int, 2> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000
#define MOD 1000000007

string s;
int n;

int ans(int l, int r, char c) {
    if (l == r) {
        return c != s[l];
    }
    int m = (l + r) / 2;
    int ans1 = ans(l, m, c + 1), ans2 = ans(m + 1, r, c + 1);
    for (int i = l; i <= m; ++i)
        ans2 += s[i] != c;
    for (int i = m + 1; i <= r; ++i)
        ans1 += s[i] != c;
    return min(ans1, ans2);
}

void solve() {
    cin >> n >> s;
    cout << ans(0, n - 1, 'a') << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

