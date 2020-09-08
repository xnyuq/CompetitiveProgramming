// time-limit: 2000
#include <bits/stdc++.h>
using namespace std;

int sumOfDigits(long long n) {
    int res = 0;
    while (n) {
        res += n % 10;
        n /= 10;
    }
    return res;
}

void solve() {
    long long n, ans = 0, s, base = 1;
    cin >> n >> s;
    while (sumOfDigits(n) > s) {
        int d = n % 10;
        ans += (10 - d) * base;
        base *= 10;
        n += 10 - d;
        n /= 10;
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
