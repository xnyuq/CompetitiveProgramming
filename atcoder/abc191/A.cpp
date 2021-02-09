#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int v,t,s,d;
    cin >> v >> t >> s >> d;
    if (d >= v*t && d <= v*s) {
        cout << "No\n";
    }
    else
        cout << "Yes\n";
}

