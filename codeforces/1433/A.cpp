// time-limit: 1000
#include <bits/stdc++.h>
using namespace std;
int len(int n) {
    int cnt = 0;
    while (n) {
        ++cnt;
        n /= 10;
    }
    return cnt;
}
void solve() {
    int n;
    cin >> n;
    int l = len(n), ans = l*(l+1)/2+10*(n%10-1);
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
