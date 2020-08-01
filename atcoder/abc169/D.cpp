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
    ll n;
    cin >> n;
    bool flag = false;
    for(ll i = 2; i*i <= n; ++i) {
        if (!(n%i)) {
            flag = 1;
            break;
        }
    }
    if (!flag && n^1) {
        cout << 1 << "\n";
        return;
    }
    unordered_map<ll, int> div;
    int ans = 0;
    while (!(n%2)) {
        n /= 2;
        div[2]++;
    }
    for (ll i = 3; i*i <= n; i += 2) {
        while (!(n%i)){
            ++div[i];
            n /= i;
        }
    }
    if (n > 1) div[n]++;
    for (auto& i: div) {
        int k = 1;
        while (i.se >= k) {
            ++ans;
            i.se -= k;
            ++k;
        }
    }
    cout << ans << "\n";
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

