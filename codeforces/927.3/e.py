def solve():
    n = map(int,input().split())
    s =str(input())
    now = len(s)
    ans = 0
    cnt = 0
    tmp_s = str(s[0])
    for i in range(1,len(s)):
        now -= 1 
        tmp = int(s[i])+9*int(tmp_s)
        ans += tmp*now
        tmp_s += s[i]
    ans += int(s[0])*len(s)
    print(ans)
for _ in range(int(input())):
    solve()