#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000
#define mod 1000000007

void solve() {
    int n, m, d = INF;
    cin >> n >> m;
    vi pz(m);
    for (int i = 0; i < m; ++i) cin >> pz[i];
    sort(pz.begin(), pz.end());
    for (int i = 0; i < m-n+1; ++i) {
        d = min(d, pz[i+n-1] - pz[i]);
    }
    cout << d << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int t;
    //cin >> t;
    //while (t--)
        solve(); 
    return 0;
}

