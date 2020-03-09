#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, flag(0), cnt(0), fel(-1);
        cin >> n;
        vector <int> v;
        for (int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            v.push_back(tmp);
        }
        for (int i = 0; i < n; ++i) {
            if (v[i] % 2 == 0) {
                cout << 1 << "\n" << i+1 << "\n";
                flag = 1;
                break;
            }
            else {
                ++cnt;
                if (fel == -1) fel = i+1;
                }
            if (cnt == 2) {
                flag = 1;
                cout << 2  << "\n" << fel << " " << i+1 << "\n";
                break;
            }
        }
        if (!flag) cout << -1 << "\n"; 
    }
}