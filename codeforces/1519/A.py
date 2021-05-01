def main():
    for _ in range(int(input())):
        a, b, c = (int(x) for x in input().split())
        if a > b:
            a, b = b, a
        if c >= (b+a-1)//a-1:
            print("Yes")
        else:
            print("No")

if __name__ == "__main__":
    main()

