#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000
#define mod 1000000007
int n,a[100000],b[100000];
void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    if (a[0]!=b[0]) {
        cout << "NO\n";
        return;
    }
    int s[]={0,0};
    if (a[0] == -1) s[0]=1;
    else if (a[0] == 1) s[1]=1;
    for (int i = 0; i < n; ++i) {
        if ((a[i] < b[i] && s[1] == 0) || (a[i] > b[i] && s[0] == 0)) {
            cout << "NO\n";
            return;
        }
        if (a[i] == -1) s[0]=1;
        else if (a[i] == 1) s[1]=1;
    }
    cout << "YES\n";
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

