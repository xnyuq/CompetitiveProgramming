#include<stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  ( (n%2) ? (printf("Black")) : (printf("White")) );
  return 0;
}