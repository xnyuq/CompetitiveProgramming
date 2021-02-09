#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n,x;
    cin >> n >> x;
    vector<int> arr(n);
    for (auto& i: arr) {
        cin >> i;
        if (i != x) cout << i << " ";
    }
    cout << "\n";
}

