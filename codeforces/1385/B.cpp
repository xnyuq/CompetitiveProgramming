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
    vi s;
    unordered_map<int, int> mp;
    int tmp;
    for (int i = 0; i <2 * n; ++i) {
        cin >> tmp;
        if (!mp[tmp]) {
            ++mp[tmp];
            s.push_back(tmp);
        }
        else ++mp[tmp];
    }
    for (auto& i : s) {
        cout << i << " ";
    }
    cout << "\n";
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

