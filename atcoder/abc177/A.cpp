// time-limit: 2000
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int d,t,s;
    cin >> d >> t >> s;
    cout << (t*s >= d ? "Yes\n" : "No\n");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}
