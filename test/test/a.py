# 前缀和
# n=int(input())
# a=list(map(int, input().split()))
# pre=[0]*(len(a)+1)
# for i in range(len(a)):
#     pre[i+1]=pre[i]+a[i]
# l,r=map(int, input().split())
# print(pre[r]-pre[l-1])

#差分
# a=[0]*5
# d=[0]*6
# q=int(input())
# while q > 0:
#     l,r,k=map(int, input().split())
#     l-=1        #实际下标偏移
#     r-=1        #实际下标偏移
#     d[l]+=k
#     d[r+1]-=k
#     q=q-1
# for i in range(5):
#     if i > 0:
#         d[i]+=d[i-1]
#     a[i]+=d[i]
# print(a)

# # 二分答案
# def check(mid):
#     ##主要思路：
#     # 从左往右遍历石头 
#     # 当前石头如果与上一块石头距离<mid 如果当前这个石头存在最短距离就达不到mid 
#     # 因此这块石头必须搬走 
#     # 用一个计数器cnt记录要搬走的石头数
#     last=0#上一块石头距离起点的位置
#     cnt=0
#     for i in range(len(a)):
#         if a[i]-last < mid:
#             cnt+=1
#             continue
#         last=a[i] #不搬走他就是下一个石头的上一个石头
#     return cnt<=M   #返回要搬走的石头是不是小于等于最多可搬走石头戍数

# ####数据读入####
# L,N,M=map(int, input().split())
# a=list()#石头位置数组
# for i in range(N):
#     x=int(input())
#     a.append(x)
# a.append(L)#最后一个石头到岸也算一段跳跃 这里把岸也算一个石头就不用考虑岸和石头 好算点
# l=0#下界是0 显然
# r=L#上界是起点到终点的距离 显然
# ans=0#存答案
# # my 二分答案模板
# while l<=r:
#     mid=(l+r)>>1 #等价于(l+r)/2向下取整 
#     if check(mid): #如果当前距离可以达到 记录答案 然后下界就是这个数+1
#         l=mid+1
#         ans=mid
#     else:          #反之上界是这个数-1
#         r=mid-1
# print(ans)
