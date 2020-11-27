// time-limit: 1000
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, cnt = 0;
    cin >> n >> m;
    vector<pair<int, int>> ans;
    vector<vector<bool>> arr(n, vector<bool>(m));
    char c;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            cin >> c;
            if (c == '1') arr[i][j] = true;
        }
    //iterate through every 2x2 square
    for (int startRow = 0, endRow = 1; endRow < n; ++startRow, ++endRow)
        for (int startCol = 0, endCol = 1; endCol < m; ++startCol, ++endCol) {
            vector<pair<int,int>> t, f;
            // examine number of 1 and 0 in 2x2 square
            for (int i = startRow; i <= endRow; ++i) {
                for (int j = startCol; j <= endCol; ++j) {
                    if (arr[i][j]) t.push_back({i,j});
                    else f.push_back({i,j});
                    arr[i][j] = 0;
                }
            }
            if ((int)f.size() == 4) continue;
            else {
                switch ((int)t.size()) {
                    case 1:
                        cnt += 3;
                        ans.emplace_back(t[0]); ans.emplace_back(f[0]); ans.emplace_back(f[1]);
                        ans.emplace_back(t[0]); ans.emplace_back(f[0]); ans.emplace_back(f[2]);
                        ans.emplace_back(t[0]); ans.emplace_back(f[1]); ans.emplace_back(f[2]);
                        break;
                    case 2:
                        cnt += 2;
                        ans.emplace_back(t[0]); ans.emplace_back(f[0]); ans.emplace_back(f[1]);
                        ans.emplace_back(t[1]); ans.emplace_back(f[0]); ans.emplace_back(f[1]);
                        break;
                    case 3:
                        cnt += 1;
                        ans.emplace_back(t[0]); ans.emplace_back(t[1]); ans.emplace_back(t[2]);
                        break;
                    case 4:
                        cnt += 4; // 1 1 1 1
                        ans.emplace_back(t[1]); ans.emplace_back(t[2]); ans.emplace_back(t[3]); // 1 0 0 0
                        ans.emplace_back(t[0]); ans.emplace_back(t[1]); ans.emplace_back(t[2]); // 0 1 1 0
                        ans.emplace_back(t[0]); ans.emplace_back(t[1]); ans.emplace_back(t[3]); // 1 0 1 1
                        ans.emplace_back(t[0]); ans.emplace_back(t[2]); ans.emplace_back(t[3]); // 1 0 1 1
                        break;
                }
            }
        }
    cout << cnt << "\n";
    for (int i = 0; i < (int)ans.size(); ++i) {
        if (i && i % 3 == 0) cout << "\n";
        cout << ans[i].first+1 << " " << ans[i].second+1 << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
