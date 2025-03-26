#include<iostream>
#include<cmath>
#include<string>
#include <algorithm>
#include<vector>
#include<queue>
#include<map>
#include<numeric>
#include<cstring>
#define pii pair<int,int>
#define mii map<int,int>
#define msi map<string,int>
#define ll long long
#define all(x) (x).begin(), (x).end()
using namespace std;
ll jc(ll n){
    if(n==1||n==0)
    return (ll)1;
    else
    return n*jc(n-1);
}
void yes(){
    cout<<"Yes\n";
}
void no(){
    cout<<"No\n";
}
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
int lcm(int a,int b){
    return (a*b)/gcd(a,b);
}
ll qpow(ll a, ll k, ll p)
{
    ll res = 1;
    while (k)
    {
        if (k & 1)
            res = (ll)res * a % p;
        a = (ll)a * a % p;
        k >>= 1;
    }
    return res;
}
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
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>arr[i];
    build(1,1,n);
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int op;
        cin>>op;
        if(op==1){
            int l,r,d;
            cin>>l>>r>>d;
            update(1,l,r,d);
        }
        else{
            int x;
            cin>>x;
            if(i!=q-1)
            cout<<query(1,x,x)<<'\n';
            else
            cout<<query(1,x,x);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //int t;
    //cin>>t;
    //for(int i=0;i<t;i++){
        solve();
        //cout<<'\n';
    //}
    return 0;
}