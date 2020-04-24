#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000
#define mod 1000000007

void solve() {
    int n, m;
    float x;
    cin >> x >> n >> m;
    while (n-- && (ceil(x/2) - 10 > 0))
        x = floor(x/2) + 10; 
    if (x > 10 * m) cout << "NO\n";
    else cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve(); 
    return 0;
}

