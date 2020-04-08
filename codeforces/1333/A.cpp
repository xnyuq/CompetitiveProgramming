#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000
#define mod 1000000007

int m,n, nb, arr[100][100]{0};

void solve() {
    cin >> n >> m;
    for (int i = 0; i <n; ++i)
        for (int j = 0; j < m; ++j)
            if (i == 0 && j == 0) arr[i][j] = 0;
            else if (j == 0) arr[i][j] = arr[i-1][j]^1;
            else arr[i][j] = arr[i][j-1]^1;
    if (n % 2 ==0 || m % 2 == 0) arr[0][1] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            if (arr[i][j]) cout << "W";
            else cout << "B";
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

