// time-limit: 1000
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,k,ans;
    cin >> n >> k;
    if (k <= n) {
        if ((n-k)%2 == 0) ans = 0;
        else ans = 1;
    }
    else {
        ans = k - n;
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
