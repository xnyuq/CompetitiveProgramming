#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000
#define mod 1000000007

void solve() {
    string s,r;
    int n,a,b;
    cin >> n >> a >> b;
    for (int i = 0; i < a-b+1; ++i)
        s += 'a';
    for (int i = 0; i < b - 1; ++i)
        s += 'a'+i+1;
    for (int i = 0; i < n; ++i)
        r += s[i%a];
    cout << r << "\n";
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

