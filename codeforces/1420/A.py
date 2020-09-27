def sol():
    n = int(input())
    arr = [int(x) for x in input().split()]
    for i, val in enumerate(arr):
        if i == n - 1:
            print("NO")
        elif val <= arr[i+1]:
            print("YES")
            break
def main():
    t = int(input())
    for _ in range(t):
        sol()
if __name__ == "__main__":
    main()

