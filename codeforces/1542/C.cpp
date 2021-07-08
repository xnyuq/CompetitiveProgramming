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


const int64_t MOD = 1e9+7;

int main() {

    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int64_t N;
        cin >> N;
        int64_t ans = N % MOD;
        int64_t cur = 1;
        for (int i = 1;; ++i) {
            cur = lcm(cur, i);
            if (cur > N) break;
            ans += N / cur;
            ans %= MOD;
        }
        cout << ans << "\n";
    }
}

