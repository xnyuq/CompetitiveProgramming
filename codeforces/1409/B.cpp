// time-limit: 1000
#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long a,b,x,y,n,n1;
    cin >> a >> b >> x >> y >> n;
    int a1 = a, b1 = b; n1 = n;
    int k = 2;
    long long ans = 1e18+1;
    while (k--) {
        n = n1;
        a = a1;
        b = b1;
        int change = min(a-x,n);
        n -= change;
        a -= change;
        b -= min(n, b-y);
        ans = min(ans, a*b);
        swap(a1,b1);
        swap(x,y);
    }
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
