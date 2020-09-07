// time-limit: 1000
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x, y, p, numInRange;
    cin >> n >> x >> y;
    int dif = y - x;
    vector<int> div;
    for (p = 1; p <= dif; ++p)
        if (dif % p == 0)
            div.emplace_back(p);
    for (auto& i : div) {
        numInRange = dif / i + 1;
        if (numInRange <= n) {
            p = i;
            break;
        }
    }
    //cout << p << " " << numInRange << "\n";
    //return;
    n -= numInRange;
    for (int i = x - p; i > 0 && n > 0; i -= p, --n) {
        cout << i << " ";
    }
    for (int i = x; i <= y; i += p)
        cout << i << " ";
    while (n--)
        cout << (y += p) << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
