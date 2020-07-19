#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000
#define mod 1000000007
 
void solve() {
    unordered_map<string, int> mp;
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        mp[s]++;
    }
    cout << "AC x " << mp["AC"] << "\nWA x " << mp["WA"] << "\nTLE x " << mp["TLE"] <<"\nRE x " << mp["RE"];
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
