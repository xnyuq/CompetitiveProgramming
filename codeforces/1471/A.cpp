#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int64_t n,x;
        cin >> n >> x;
        vector<int64_t> arr(n);
        int64_t min,max = 0;
        for (auto& i: arr) {
            cin >> i;
            max += (i+x-1)/x;
        }
        min = (accumulate(arr.begin(), arr.end(), (int64_t)0)+x-1)/x;
        cout << min << " " << max << "\n";
    }
}

