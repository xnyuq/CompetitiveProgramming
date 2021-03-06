// time-limit: 2000
#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, passedTime = 0;
    cin >> n;
    vector<array<int, 2>> arr(n);
    for (auto &i : arr)
        cin >> i[0];
    for (auto &i : arr)
        cin >> i[1];
    sort(arr.rbegin(), arr.rend());
    int i =0;
    for (; i < n && passedTime + arr[i][1] < arr[i][0]; ++i)
        passedTime += arr[i][1];
    long long ans = passedTime;
    if (i < n) ans = max(ans, 1ll*arr[i][0]);
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
