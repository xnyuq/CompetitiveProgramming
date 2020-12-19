#include <bits/stdc++.h>
using namespace std;

void solve() {
    int arr[4];
    for (auto& i: arr) cin >> i;
    cout << *min_element(arr, arr+4);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}

