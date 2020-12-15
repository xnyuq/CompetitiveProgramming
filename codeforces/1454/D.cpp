#include <bits/stdc++.h>
using namespace std;

void solve() {
    int64_t n;
    cin >> n;
    int64_t reserved = n;
    map<int64_t, int> div;
    while (n%2==0) ++div[2],n/=2;
    for (int i = 3; 1LL*i*i <= n; i += 2)
        while (n % i == 0) ++div[i], n /= i;
    if (n > 1) ++div[n];
    pair<int64_t, int> mostDiv;
    int maxDivOcc = -1;
    for (auto& p: div) {
        if (p.second > maxDivOcc) {
            maxDivOcc = p.second;
            mostDiv = p;
        }
    }
    cout << mostDiv.second << "\n";
    for (int i = 0; i < mostDiv.second - 1; ++i)
        cout << mostDiv.first << " ";
    while (--mostDiv.second) reserved /= mostDiv.first;
    cout << reserved << "\n";
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

