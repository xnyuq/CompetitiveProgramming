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
    int N;
    int64_t K;
    cin >> N >> K;
    vector<pair<int,int>> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr.begin(), arr.end());
    vector<int64_t> ans(N);
    for (int i = 0; i < K % N; ++i) {
        ans[arr[i].second] = K / N + 1;
    }
    for (int i = K % N; i < N; ++i) {
        ans[arr[i].second] = K / N;
    }
    for (auto& i: ans) cout << i << "\n";
}

