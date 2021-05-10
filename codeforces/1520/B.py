def main():
    for _ in range(int(input())):
        n = int(input())
        last = 0
        d = str(n)[0]
        l = len(str(n))
        last =int(d*l)
        if last > n:
            if int(d) != 1:
                last = int(str(int(d)-1)*l)
            else:
                l -= 1
                if (l == 0):
                    last = 0
                else:
                    last = int('9'*l)
        if last == 0:
            print(0)
        else:
            ans = 9*(l-1)+last%10
            print(ans)

if __name__ == "__main__":
    main()