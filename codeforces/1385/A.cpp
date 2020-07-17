#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef array<int, 2> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000
#define MOD 1000000007

void solve() {
    int ans = 0;
    vi a(3);
    cin >> a[0] >> a[1] >> a[2];
    sort(a.begin(), a.end());
    if (a[1] == a[2]) ans = 1;
    if (ans) {
        cout << "Yes\n" << a[1] << " " << a[0] << " " << a[0]<< "\n";
    }
    else cout << "NO\n";
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

