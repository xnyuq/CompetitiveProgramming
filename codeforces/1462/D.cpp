#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto& i: arr) cin >> i;
    int sum = accumulate(arr.begin(), arr.end(), 0), maxElement = *max_element(arr.begin(), arr.end());
    
    int op = 0;
    for (; op < n; ++op) {
        bool valid = true;
        int remain = n - op, sumOfIndice = sum/remain;
        if (sum%remain || sumOfIndice < maxElement) continue;
        for (int i = 0; i < n;) {
            int curSum = 0;
            while (curSum < sumOfIndice && i < n) curSum+=arr[i++];
            valid &= curSum == sumOfIndice;
            if (!valid) break;
        }
        if (valid) break;
    }
    cout << op << "\n";
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

