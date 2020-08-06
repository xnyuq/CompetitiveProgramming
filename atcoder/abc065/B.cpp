#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<ll> vll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
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
    int n;
    cin >> n;
    vi a(n+1);
    rep(i,1,n+1) {
        cin >> a[i];
    }
    int ans = 1, i = 1;
    set<int> s{1};
    while (a[i] != 2) {
        if (i == a[i]) {
            cout << -1;
            return;
        }
        i = a[i];
        if (i != 2 && s.find(i) != s.end()) {
            cout << -1;
            return;
        }
        s.emplace(i);
        ++ans;
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}

