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
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    vi b(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    int i = 0;
    map<int, int> Map;
    Map[b[i]] = 1;
    for (i = 1; i < n; i++)
        if (b[i] != b[i-1]) Map[b[i]] = i+1;
    for (auto& e : a) cout << Map[e] << " ";
    cout << "\n";
    return 0;
}

