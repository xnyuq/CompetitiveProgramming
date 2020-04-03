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
    int n, ml(0), cl(1);
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int i = 0;
    while (i<n-1) {
        if (a[i+1] >= a[i]) cl++;
        else {
            ml = max(ml, cl);
            cl = 1;
        }
        i++;
    }
    cout << max(ml, cl) << "\n";
    return 0;
}

