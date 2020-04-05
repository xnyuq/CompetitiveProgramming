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
    int n, i = 0, current_x = 1, d = 0;
    string s;
    cin >> n >> s;
    while (i < n) {
        while (i < n && s[i] != 'x') i++;
        if (i == n) break;
        current_x = 1;
        while (i < n - 1 && s[i+1] == 'x') {
            i++;
            current_x++;
        }
        i++;
        if (current_x >= 3) d += current_x - 2;
    }
    cout << d << "\n";
    return 0;
}

