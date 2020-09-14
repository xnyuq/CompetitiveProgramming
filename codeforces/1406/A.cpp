// time-limit: 1000
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, ans = 0;
    cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        ++cnt[tmp];
    }
    int i = 0;
    while (cnt[i] >= 2)
        ++i;
    if (cnt[i] == 0)
        ans = 2*i;
    else {
        ans += i;
        while (cnt[i]) ++i;
        ans += i; 
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
