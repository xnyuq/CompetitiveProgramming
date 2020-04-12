#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000
#define mod 1000000007

void solve() {
    long long s = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
    for (int k = 1; k <= n; ++k)
        s += __gcd(__gcd(i,j),k);
    cout << s << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve(); 
    return 0;
}

