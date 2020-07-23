#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;
#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define sz(x) ((int)(x).size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define INF 1000000000
#define MOD 1000000007

void solve() {
    int n,q;
    cin >> n;
    vi ar(n);
    ll s = 0;
    map<int, int> mp;
    for (auto& i: ar) {
        cin >> i;
        mp[i]++;
        s += i;
    }
    cin >> q;
    rep(i,0,q) {
        int a,b;
        cin >> a >> b;
        s += (b-a) * mp[a];
        mp[b] += mp[a];
        mp[a] = 0;
        cout << s << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
