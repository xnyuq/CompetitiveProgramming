#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000
#define mod 1000000007

void solve() {
    int n;
    cin >> n;
    if (n==1 || n == 2) {
        cout << 0 << "\n";
        return;
    }
    cout <<n - n/2-1 << "\n";
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

