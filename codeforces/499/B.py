#https://codeforces.com/problemset/problem/499/B
n, m = map(int,input().split())
ls = {}
for _ in range(m):
    line = input().split()
    ls[line[0]] = line[1]
lecture = input().split()
for i in range(len(lecture)):
    word = lecture[i]
    if len(ls[word]) < len(word):
        lecture[i] = ls[word]
print(" ".join(lecture))

