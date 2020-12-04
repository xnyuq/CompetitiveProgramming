#include <stdio.h>

int main() {
	long long a,b,c,d;
  	long long ans;
  	scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
  	ans = (a * c > a * d) ? a * c : a * d;
  	ans = (ans > b * c) ? ans : b * c;
  	ans = (ans > b * d) ? ans : b * d;
  	printf("%lld", ans);
  	return 0;
}