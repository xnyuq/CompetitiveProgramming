if __name__ == "__main__":
    n = int(input())
    ls = [int(i) for i in input().split()]
    d = dict()
    for i in range(len(ls)):
        if ls[i] - i not in d:
            d[ls[i]-i] = ls[i]
        else:
            d[ls[i]-i] += ls[i]
    print(max(d.values()))