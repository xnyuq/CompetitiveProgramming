#include <bits/stdc++.h>
using namespace std;

void solve() {
    long double b = 0;
    long long n,a = 0,c = 0;
    scanf("%lld", &n);
    while (n--) {
        long long tmp;
        scanf("%lld", &tmp);
        a += abs(tmp);
        b += tmp*tmp;
        c = max(c, abs(tmp));
    }
    b =  sqrt(b);
    printf("%lld\n%.12Lf\n%lld\n",a,b,c);
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}


