// time-limit: 2000
#include <bits/stdc++.h>
using namespace std;

string s,t;
int sLen, tLen, ans = 1e9;
int compare(int x) {
    int res = 0;
    for (int i = 0; i < tLen; ++i) {
        res += (t[i] != s[i+x]);
    }
    return res;
}

void solve() {
    cin >> s >> t;
    sLen = s.length(); tLen = t.length();
    for (int i = 0; i <= sLen-tLen; ++i) {
        int diff = compare(i);
        ans = min(ans, diff);
    }
    cout << ans << "\n";
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
