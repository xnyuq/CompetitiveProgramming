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
    int x, cnt(0);
    cin >> x;
    for (int i = 0; i < 30;i++) {
        bool check = x & (1 << i);
        if (check) cnt++;
    }
    cout << cnt << "\n";
    return 0;
}

