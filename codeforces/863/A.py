#https://codeforces.com/problemset/problem/863/A
def main():
    n = list(input())
    while (len(n) > 0 and n[-1] == '0'):
        n.pop()
    for i in range(len(n)//2):
        if n[i] != n[-i-1]:
            print("NO")
            return
    print("YES")
if __name__ == "__main__":
    main()

