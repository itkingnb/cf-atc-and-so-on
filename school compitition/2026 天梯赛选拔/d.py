s=input()
cnt=0
last=0
for x in s:
    if x>='a' and x<='z' or x>='A' and x<='Z':
        cnt+=1
    else:
        if cnt>0:
            print(cnt%10,end="")
        cnt=0
    last=x
if x>='a' and x<='z' or x>='A' and x<='Z':
    print(cnt%10,end="") 
