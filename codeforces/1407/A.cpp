#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, cnt[2]{};
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        cnt[tmp]++;
    }
    if (cnt[0] >= n / 2) {
        cout << n / 2 << "\n";
        for (int i = 0; i < n / 2; ++i)
            cout << "0 ";
        cout << "\n";
    }
    else {
        int n = cnt[1]/2*2;
        cout << n << "\n";
        while (n--) {
            cout << "1 ";
        }
        cout << "\n";
    }
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
