#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int H, W, ans = 0;
    cin >> H >> W;
    vector<vector<char>> S(H, vector<char>(W));
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            cin >> S[i][j];
    for (int i = 0; i < H - 1; ++i)
        for (int j = 0; j < W - 1; ++j) {
            int cnt = (S[i][j] == S[i][j + 1]) + (S[i][j] == S[i + 1][j]) + (S[i][j] == S[i + 1][j + 1]);
            ans += (cnt == 0) || (cnt == 2);
        }
    cout << ans << "\n";
}
