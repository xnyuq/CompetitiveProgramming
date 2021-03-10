"""
  @author      : quynx
  @created     : 10/03/2021 20:35:11 +07
  @filename    : 27E
  @source      : https://codeforces.com/problemset/problem/27/E
"""
from math import sqrt

def isPrime(n):
    for i in range(2, int(sqrt(n))+1):
        if n%i==0:
            return False
    return n > 1

def main():
    prime = []
    i = 2
    while len(prime) < 10:
        if isPrime(i):
            prime.append(i)
        i += 1
    dp = [[int(1e18+10) for __ in range(1001)] for _ in range(15)]
    n = int(input())
    for i in range(10):
        dp[i][1] = 1
        for j in range(2,n+1):
            primePower = 1
            for k in range(j):
                if j % (k+1):
                    primePower *= prime[i]
                    continue
                if i:
                    dp[i][j] = min([dp[i][j], dp[i-1][j//(k+1)]*primePower])
                else:
                    dp[i][j] = primePower
                primePower *= prime[i]
    print(dp[9][n])

if __name__ == "__main__":
    main()

