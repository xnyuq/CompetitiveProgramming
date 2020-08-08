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
#define endl "\n"
#define INF 1000000000
#define MOD 1000000007
//#define cerr if (false) cerr

string s;
int occ(char c1, char c2) {
    int st = 0, cnt = 0;
    rep(i,0,sz(s)) {
        if (st == 0 && s[i] == c1) {
            st ^= 1;
        }
        else if (st == 1 && s[i] == c2) {
            ++cnt;
            st ^= 1;
        }
    }
    return cnt;
}

void solve() {
    cin >> s;
    int ans = INF;
    map<char, int> mp;
    rep(i,0,sz(s)) {
        ++mp[s[i]];
        ans = min(ans, sz(s) - mp[s[i]]);
    }
    for (char c1 = '0'; c1 <= '9'; ++c1) {
        for (char c2 = '0'; c2 <= '9'; ++c2) {
            if (c1 == c2) {
                continue;
            }
            ans = min(ans, sz(s) - 2 * occ(c1,c2));
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
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
