#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,m,t,maxCap, prev = 0;
    cin >> n >> m >> t;
    maxCap = n;
    bool flag = true;
    while (m--) {
        int a,b;
        cin >> a >> b;
        n = max(0,n-a+prev);
        flag &= n != 0;
        n = min(maxCap, n + b - a);
        prev = b;
    }
    n = max(0,n-t+prev);
    flag &= n != 0;
    cout << (flag?"Yes\n":"No\n");
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

