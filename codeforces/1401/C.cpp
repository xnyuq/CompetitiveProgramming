// time-limit: 2000
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &i: arr) cin >> i;
    vector<int> buArr(arr.begin(), arr.end());
    sort(arr.begin(), arr.end());
    int m = arr[0];
    for (int i = 0; i < (int)arr.size(); ++i) {
        if (arr[i] % m && arr[i] != buArr[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
