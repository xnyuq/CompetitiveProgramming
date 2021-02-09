#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        int64_t ans = 0;
        cin >> n >> x;
        vector<pair<int,int>> arr;
        for (int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            if (i == 0) arr.push_back({tmp,1});
            else if (tmp == arr.back().first) ++arr.back().second;
            else arr.push_back({tmp,1});
        }
        bool gen = true;
        for (int i = 0; i < (int)arr.size(); ++i) {
            int f,s;
            tie(f,s) = arr[i];
            ans += f*s;
            if (gen && f%x==0) arr.push_back({f/x,s*x});
            else if (f%x) gen = false;
        }
        cout << ans << "\n";
    }
}


