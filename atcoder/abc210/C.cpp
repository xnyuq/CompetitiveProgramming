#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    vector<int> arr(N);
    for (auto& i: arr) cin >> i;
    int ans = 0;
    map<int, int> cnt;
    for (int i = 0; i < K; ++i) {
        ++cnt[arr[i]];
    }
    ans = cnt.size();
    for (int i = K, j = 0; i < N; ++i, ++j) {
        ++cnt[arr[i]];
        --cnt[arr[j]];
        if (cnt[arr[j]] == 0) cnt.erase(arr[j]);
        ans = max(ans, (int)cnt.size());
    }
    cout << ans << "\n";
}

