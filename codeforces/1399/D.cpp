// time-limit: 2000
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, cnt[2]{}, count = 1;
    stack<int> last[2];
    cin >> n;
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        if (c == '0') {
            if (cnt[1]) {
                cnt[1]--; cnt[0]++;
                ans[i] = ans[last[1].top()];
                last[1].pop();
                last[0].emplace(i);
            }
            else {
                ans[i] = count++;
                last[0].emplace(i);
                cnt[0]++;
            }
        }
        else {
            if (cnt[0]) {
                cnt[0]--; cnt[1]++;
                ans[i] = ans[last[0].top()];
                last[0].pop();
                last[1].emplace(i);
            }
            else {
                ans[i] = count++;
                last[1].emplace(i);
                cnt[1]++;
            }
        }
    }
    cout << count -1 << "\n";
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    } 
    cout << "\n";
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
