n = int(input())
for i in range(n):
	_ = input()
	ls = list(map(int,input().split()))
	check = False
	for i in range(len(ls)-2):
		if ls[i] in ls[i+2:]:
			check = True
			break
	if check:
		print("YES")
	else:
		print("NO")