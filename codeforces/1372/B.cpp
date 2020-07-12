#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef array<int, 2> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000
#define MOD 1000000007

void solve() {
    int n;
    cin >> n;
    if (n == 2) {
        cout << "1 1\n";
        return;
    }
    else {
        for (int i = 2; i*i <= n; ++i) {
            if (n % i == 0) {
                cout << n/i << " " << n - n / i << "\n";
                return;
            }
        }
        cout << 1 << " " << n - 1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

