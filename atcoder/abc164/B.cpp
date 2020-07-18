#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    while (1) {
        if (b >= c) {
            cout << "Yes\n";
            return 0;
        }
        c -= b;
        if (d >= a) {
            cout << "No\n";
            return 0;
        }
        a -= d;
    }
}
