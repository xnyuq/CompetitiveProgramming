//ISP
#include <stdio.h>

int main() {
    int D, N;
    scanf("%d%d", &D, &N);
    int cnt = 0, val = 0;
    while (cnt < N) {
        ++val;
        int tmp = val, times = 0;
        while (tmp % 100 == 0) {
            tmp /= 100;
            ++times;
        }
        if (times == D) ++cnt;
    }
    printf("%d\n", val);
    return 0;
}
