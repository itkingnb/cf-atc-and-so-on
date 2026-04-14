def solve():
    # n,k = map(int,input().split())
    n=int(input())
    a = list(map(int,input().split()))
    print(max(a)*n)
for _ in range(int(input())):
    solve()