#include <bits/stdc++.h>
using namespace std;

void solve() {
    int sum = 0, n, digit = 9;
    vector<int> num;
    cin >> n;
    while (sum < n && digit > 0) {
        num.push_back(min(digit, n - sum));
        sum += digit;
        --digit;
    }
    if (sum < n) {
        cout << "-1";
    }
    else
        for (int i = (int)num.size() - 1; ~i; --i) cout << num[i];
    cout << "\n";
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
