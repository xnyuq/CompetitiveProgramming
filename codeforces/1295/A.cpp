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
    int socs = n / 2;
    if (n % 2 == 0) {
        while (socs--) cout << 1;
        cout << "\n";
    }
    else {
        cout << 7;
        while (--socs) cout << 1;
        cout << "\n";
    }
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

