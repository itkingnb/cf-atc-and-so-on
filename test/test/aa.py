pre=[0]*1000001
def init():
    for i in range(1,101):
        for j in range(i+1,1001):
            if i*j>1e6:
                break
            for k in range(j+1,1000001):
                if(i*j*k>1e6):
                    break
                if k<i+j:
                    pre[i*j*k]+=1
    for i in range(1,1000000+1):
        pre[i]+=pre[i-1]
if __name__ == "__main__":
    init()
    t=int(input())
    for i in range(t):  
        l,r=map(int,input().split())
        print(pre[r]-pre[l-1])