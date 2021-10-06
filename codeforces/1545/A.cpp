#include <bits/stdc++.h>
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
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> arr(n);
        map<int, pair<int,int>> mp, sortedMp;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            if (i%2 == 0) ++mp[arr[i]].first;
            else ++mp[arr[i]].second;
        }
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; ++i) {
            if (i%2 == 0) ++sortedMp[arr[i]].first;
            else ++sortedMp[arr[i]].second;
        }
        bool ans = true;
        for (auto& pr: mp) {
            if (pr.second != sortedMp[pr.first]) {
                ans = false;
                break;
            }
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}

