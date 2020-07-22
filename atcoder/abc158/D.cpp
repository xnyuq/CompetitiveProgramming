#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;
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
    string s;
    int q;
    cin >> s >> q;
    deque<char> s1(all(s));
    bool st = 0;
    rep(i,0,q) {
        int t, f;
        char c;
        cin >> t;
        if (t == 1) {
            st ^= 1;
        }
        else if (t == 2) {
            cin >> f >> c;
            --f;
            if (f^st) {
                s1.pb(c);
            } 
            else {
                s1.push_front(c);
            }
        }
    }
    if (st) reverse(all(s1));
    for (auto&i: s1) {
        cout << i;
    }
    cout << "\n";
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

