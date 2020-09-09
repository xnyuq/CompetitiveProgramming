// time-limit: 1000
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    cin >> arr[0];
    for (int i = 1; i < n; ++i)
        cin >> arr[i];
    sort(arr.rbegin(), arr.rend());
    int tmp = arr[0];
    arr[0] = 0;
    cout << tmp << " ";
    for (int i = 0; i < n - 1; ++i) {
        int maxGCD = 0, maxIndex = 0;
        for (int j = 1; j < n; ++j) {
            if (!arr[j])
                continue;
            int k;
            if ((k = __gcd(arr[j], tmp)) > maxGCD) {
                maxIndex = j;
                maxGCD = k;
            }
        }
        tmp = maxGCD;
        cout << arr[maxIndex] << " ";
        arr[maxIndex] = 0;
    }
    cout << "\n";
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
