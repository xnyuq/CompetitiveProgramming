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
    string q;
    int n,t;
    cin >> n >> t >> q;
    int i(0);
    while (t--) {
        i = 0;
        while (1) {
            while (i < n - 1 && (q[i] != 'B' || q[i+1] != 'G')) i++;
            if (i >= n - 1) break;
            q[i] = 'G'; q[i+1] = 'B';
            i += 2;
        }
    }
    cout << q << "\n";
    return 0;
}

