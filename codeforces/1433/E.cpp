#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    long long fact[21];
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = fact[i-1]*i;
    }
    cout << 2*fact[n]/n/n<<"\n";
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
