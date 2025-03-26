/*
题目描述
如题，已知一个数列，你需要进行下面两种操作：将某区间每一个数加上 k。求出某区间每一个数的和。
输入格式
第一行包含两个整数 n,m，分别表示该数列数字的个数和操作的总个数。
第二行包含 n 个用空格分隔的整数，其中第 i 个数字表示数列第 i 项的初始值。
接下来 m 行每行包含 3 或 4 个整数，表示一个操作，具体如下：
1 x y k：将区间 
[x,y] 内每个数加上 k。
2 x y：输出区间 [x,y] 内每个数的和。
输出格式
输出包含若干行整数，即为所有操作 2 的结果。
输入输出样例
输入 #1
5 5
1 5 4 2 3
2 2 4
1 2 3 2
2 3 4
1 1 5 1
2 1 4
输出 #1
11
8
20
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005//数组长度
int arr[N];//维护的一维数组
int ls(int p){
    return p<<1;//左儿子
}
int rs(int p){
    return (p<<1)|1;//右儿子
}
struct node
{
    int l,r;
    ll sum;
    int add;//l:左区间 r:右区间 sum：区间和 add:懒标记
}tr[N*4+2];
void pushup(int p){
    tr[p].sum=tr[ls(p)].sum+tr[rs(p)].sum;
}
void pushdown(int p){
    if(tr[p].add){
        tr[ls(p)].sum+=tr[p].add*(tr[ls(p)].r-tr[ls(p)].l+1);
        tr[rs(p)].sum+=tr[p].add*(tr[rs(p)].r-tr[rs(p)].l+1);
        tr[ls(p)].add+=tr[p].add;
        tr[rs(p)].add+=tr[p].add;
        tr[p].add=0;
    }
}

void update(int p,int x,int y,int k){
    if(tr[p].l>=x&&tr[p].r<=y){
        tr[p].sum+=(tr[p].r-tr[p].l+1)*k;
        tr[p].add+=k;
        return ;
    }
    int m=(tr[p].l+tr[p].r)>>1;
    pushdown(p);
    if(x<=m) update(ls(p),x,y,k);
    if(y>m) update(rs(p),x,y,k);
    pushup(p);
}
void build(int p,int l,int r){
    //p是父节点编号
    tr[p]={l,r,arr[l],0};
    if(l==r)
    return ;
    int m=(l+r)>>1;
    build(ls(p),l,m);
    build(rs(p),m+1,r);
    pushup(p);
}

ll query(int p,int x,int y){
    if(x<=tr[p].l&&tr[p].r<=y)
    return tr[p].sum;
    pushdown(p);
    ll sum=0;
    ll m=(tr[p].l+tr[p].r)>>1;
    if(x<=m) sum+=query(ls(p),x,y);
    if(y>m) sum+=query(rs(p),x,y);
    return sum;
}
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    cin>>arr[i];
    build(1,1,n);
    for(int i=0;i<m;i++){
        int q=0;
        cin>>q;
        if(q==1){
            int x,y,k;
            cin>>x>>y>>k;
            update(1,x,y,k);
        }
        if(q==2){
            int x,y;
            cin>>x>>y;
            cout<<query(1,x,y)<<endl;
        }
    }
}
int main(){
    solve();
    return 0;
}