// time-limit: 1000
#include <bits/stdc++.h>
using namespace std;
int len(int n) {
    stringstream ss;
    ss << n;
    return ss.str().length();
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
