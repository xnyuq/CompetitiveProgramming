// time-limit: 1000
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a,b;
    cin >> a >> b;
    int ans = ceil(abs(b-a)/10.0);
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
