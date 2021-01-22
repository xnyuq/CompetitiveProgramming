/*
ID: youngbo4
TASK: task
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    //freopen("task.in", "r", stdin);
    //freopen("task.out", "w", stdout);
    string a,b;
    cin >> a >> b;
    map<char, int> ma, mb;
    int cnt = 0;
    for (int i = 0; i < (int)a.length(); ++i) {
        if (ma[a[i]] != mb[b[i]]) {
            cout << "No\n";
            return 0;
        }
        else ma[a[i]] = mb[b[i]] = cnt++;
    }
    cout << "Yes\n";
}

