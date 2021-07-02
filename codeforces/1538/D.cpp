#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <chrono>
#include <random>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iomanip>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef QUYNX_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

int factorize(int& n) {
    int ret = 0;
    while (!(n&1)) n >>= 1, ++ret;
    for (int i = 3; i*i <= n; i += 2) {
        while (n % i == 0) n /= i, ++ret;
    }
    return ret + (n != 1);
}

int main() {
    ios_base::sync_with_stdio(false);
#ifndef QUYNX_DEBUG 
    cin.tie(nullptr);
#endif
    int t;
    cin >> t;
    while (t--) {
        int a, b, k;
        cin >>  a >> b >> k;
        int gcd = __gcd(a,b);
        int l, r;
        if (a == b) l = 0;
        else if (gcd == a || gcd == b) l = 1;
        else l = 2;
        r = factorize(a) + factorize(b);
        if (l <= k && k <= r && (k != 1 || (k == l))) cout << "YES\n";
        else cout << "NO\n";
    }
}

