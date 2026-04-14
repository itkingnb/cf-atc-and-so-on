def solve():
    # n,k = map(int,input().split())
    n=int(input())
    a = list(map(int,input().split()))
    a = list(set(a))
    ans = 1
    a.sort()
    tmp = 1
    for i in range(len(set(a))):
        if i>0 and a[i]==a[i-1]+1:
            tmp = tmp + 1
        else:
            ans = max(ans,tmp)
            tmp = 1
    ans = max(ans,tmp)
    print(ans)
for _ in range(int(input())):
    solve()