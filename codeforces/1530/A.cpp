#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        string digits;
        cin >> digits;
        cout << *max_element(digits.begin(), digits.end()) << "\n";
    }
}

