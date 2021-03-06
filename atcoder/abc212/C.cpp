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

int main() {
    ios_base::sync_with_stdio(false);
#ifndef QUYNX_DEBUG 
    cin.tie(nullptr);
#endif
    int N, M; cin >> N >> M;
    vector<int> A(N), B(M);
    for (auto& i: A) cin >> i;
    for (auto& i: B) cin >> i;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int ans = abs(A[0] - B[0]);
    for (auto& i: A) {
        auto it = lower_bound(B.begin(), B.end(), i);
        if (it != B.end()) ans = min(ans, abs(*it - i));
        if (it != B.begin()) --it, ans = min(ans, abs(*it - i));
    }
    cout << ans <<"\n";
}

