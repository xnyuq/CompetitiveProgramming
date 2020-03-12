#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, flag(1);
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i];
        if (n == 1) cout << "YES\n";
        else {
            int mod(v[0]%2);
            for (int i = 1; i < n; ++i) 
                if (v[i]%2!=mod) {
                    flag = 0;
                    break;
                }
            if (flag) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}