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
    int N, Q;
    cin >> N >> Q;
    vector<int64_t> countNums(N), arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
        countNums[i] = arr[i] - (i + 1);
    }
    dbg(countNums);
    for (int i = 0; i < Q; ++i) {
        int64_t K; cin >> K;
        if (K > countNums.back()) cout << arr.back() + (K - countNums.back()) << "\n";
        else {
            int j = lower_bound(countNums.begin(), countNums.end(), K) - countNums.begin();
            dbg(j);
            cout << arr[j] - 1 - (countNums[j] - K) << "\n";
        }
    }
}

