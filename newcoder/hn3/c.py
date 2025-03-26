n = int(input())
a = list(map(int,input().split()))
for i in range(n):
    if a[i]!=0:
        print(a[i]**2-a[i]+2,end=' ')
    else:
        print(1,end=' ')