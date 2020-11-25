    // time-limit: 2000
    #include <bits/stdc++.h>
    using namespace std;
     
    void solve() {
        long long n, passedTime = 0;
        cin >> n;
        vector<pair<int, int>> arr(n);
        for (auto &i : arr)
            cin >> i.first;
        for (auto &i : arr)
            cin >> i.second;
        sort(arr.rbegin(), arr.rend());
        int i =0;
        for (; i < n && passedTime + arr[i].second < arr[i].first; ++i)
            passedTime += arr[i].second;
        long long ans = passedTime;
        if (i < n) ans = max(ans, 1ll*arr[i].first);
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