#include <stdio.h>

int main() {
    int x[1000], y[1000], n;
    int flag = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &x[i], &y[i]);
    }
    for (int i = 0; i < n; ++i) {
        if (flag) break;
        for (int j = i + 1; j < n;++j) {
            if (flag) break;
            for (int k = j + 1; k < n; ++k) {
                if ((x[i] - x[j]) * (y[i] - y[k]) == (x[i] - x[k]) * (y[i] - y[j])) {
                    flag = 1;
                    break;
                }
            }
        }
    }
    if (flag) printf("Yes\n");
    else printf("No\n");
    return 0;
}
