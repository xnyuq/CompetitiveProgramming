// time-limit: 2000
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    set<int> diff;
    for (auto& i: arr) {
        cin >> i;
        diff.emplace(i);
    }
    if (diff.size() == 1) {
        cout << "-1\n";
        return;
    }
    int m = *max_element(arr.begin(), arr.end());
    for (int i = 0; i < n; ++i) {
        if (arr[i] == m && ((i > 0 && arr[i] != arr[i-1]) || (i < n - 1 && arr[i] != arr[i+1]))) {
            cout << i + 1 << "\n";
            return;
        }
    }
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
