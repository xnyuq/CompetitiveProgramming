#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> arr(N);
    for (auto& i: arr) cin >> i;
    sort(arr.begin(), arr.end());
    int64_t ans = 1;
    const int MOD = 1e9 + 7;
    for (int i = 0; i < N; ++i) {
        ans = ans * (arr[i] - i) % MOD;
    }
    cout << ans << "\n";
}

