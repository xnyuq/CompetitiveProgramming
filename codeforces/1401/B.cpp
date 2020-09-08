// time-limit: 2000
#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int ans = 0,x1,y1,z1,x2,y2,z2;
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    int m = min(z1, y2);
    ans += 2 * m;
    m = min(y1, x2);
    y1 -= m;
    z2 -= min(z2,x1);
    ans -= 2*min(z2, y1);
    cout << ans << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
