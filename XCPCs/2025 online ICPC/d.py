from itertools import combinations
a = [1,1,4,5,1,4]
s = [1,1,4,5,1,4]
d = {str(i):0 for i in s}
for i in range(1,len(s)+1):
    d_t = {str(i):0 for i in s}
    s_c = combinations(s,i)
    for j in s_c:
        print(j)