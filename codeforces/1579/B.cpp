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
        int n;
        cin >> n;
        vector<int> arr(n);
        for (auto& i: arr) cin >> i;
        vector<pair<int,int>> ans;
        vector<int> sorted(arr.begin(), arr.end());
        sort(sorted.begin(), sorted.end());
        for (int i = n - 1; ~i; --i) {
            if (arr[i] == sorted[i]) continue;
            int found = find(arr.begin(), arr.begin() + i + 1, sorted[i]) - arr.begin();
            int right = arr[i];
            arr[i] = arr[found];
            for (int j = i - 1; j >= found; --j) {
                int tmp = arr[j];
                arr[j] = right;
                right = tmp;
            }
            ans.push_back({found + 1, i + 1});
        }
        cout << ans.size() << "\n";
        for (auto& i: ans) cout << i.first << " " << i.second << " 1\n";
    }
}

