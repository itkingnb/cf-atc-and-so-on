from itertools import combinations
a = [1,1,4,5,1,4]
s = [i for i in range(1,len(a)+1)]
d = {str(i):0 for i in s}
for i in range(1,len(s)+1):
    d_t = {str(i):0 for i in s}
    s_c = combinations(s,i)
    for j in s_c:
        j_l = sorted(list(j))
        for k,m in enumerate(j_l):
            d[str(m)] += 1 if k == 0 else k
            d_t[str(m)] += 1 if k == 0 else k
    print(d.values())
    print(d_t.values())
    print(sum([c*e for c, e in zip(a,list(d_t.values()))]))
a.sort()
res = 0
for i,j in zip(a, list(d.values())):
    res += i*j
print(res)
print(1266-res)