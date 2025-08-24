#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define mii map<int,int>
#define msi map<string,int>
#define all(x) (x).begin(), (x).end()
using namespace std;
int maxint = INT_MAX;// 2147483647
int minint = INT_MIN;// -2147483648
long long maxll = LLONG_MAX;// 9223372036854775807
long long minll = LLONG_MIN;// -9223372036854775808
ll jc(ll n){
    if(n==1||n==0)
    return (ll)1;
    else
    return n*jc(n-1);
}
void yes(){
    cout<<"Yes";
}
void no(){
    cout<<"No";
}
ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}
ll lcm(ll a,ll b){
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
#define N 200050//数组长度
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
    vector<ll>s(n);
    for(int i=0;i<n;i++){
        cin>>s[i];
    }    
    vector<int>ans(n+1,0);
    vector<int>next(n,-1);
    build(1,1,n+10);
    auto check=[&](ll x,int i)->bool{
        return (1+x)*(x)/2-query(1,1,x)>s[i];
    };
    for(int i=n-1;i>=0;i--){
        int l=1,r=n;
        while(l<=r){
            ll mid=(l+r)>>1;
            if(check(mid,i)){
                ans[i+1]=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        // while(vis[ans[i+1]]){
        //     ans[i+1]++;
        // }
        // vis[ans[i+1]]=1;
        update(1,ans[i+1],ans[i+1],ans[i+1]);
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    // cin>>t;
    for(int i=0;i<t;i++){
        solve();
        cout<<'\n';
    }
    return 0;
}