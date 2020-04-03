#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000
#define mod 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, rs;
    cin >> n;
    if (n == 0) {
        cout << 1 << "\n";
        return 0;
    }
    n %= 4;
    if (n == 0) rs = 6;
    else if (n == 1) rs = 8;
    else if (n == 2) rs = 4;
    else rs = 2;
    cout << rs << "\n";
    return 0;
}

