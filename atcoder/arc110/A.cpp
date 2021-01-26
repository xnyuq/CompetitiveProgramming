#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    //freopen("task.in", "r", stdin);
    //freopen("task.out", "w", stdout);
    int64_t n;
    cin >> n;
    int64_t ans = 1;
    for (int64_t i = 2; i <= n; ++i) {
        ans = ans * i / __gcd(ans,i);
    }
    cout << ans + 1;
}

