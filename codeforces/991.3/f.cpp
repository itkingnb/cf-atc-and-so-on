#include<iostream>
#include<cmath>
#include<string>
#include <algorithm>
#include<vector>
#include<queue>
#include<map>
#include<numeric>
#include<cstring>
#include<bits/stdc++.h>
#define pii pair<int,int>
#define mii map<int,int>
#define msi map<string,int>
#define ll long long
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
    cout<<"Yes\n";
}
void no(){
    cout<<"No\n";
}
ll gcd(ll a,ll b){
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
#define N 300010
int arr[N];
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
    tr[p].sum=gcd(tr[ls(p)].sum,tr[rs(p)].sum);
}
void build(int p,int l,int r){
    //p是父节点编号
    tr[p]={l,r,arr[l],0};
    if(l==r)
    return ;
    int m=(l+r)>>1;
    build(ls(p),l,m);
    tr[p].sum=gcd(tr[p].sum,tr[ls(p)].sum);
    build(rs(p),m+1,r);
    tr[p].sum=gcd(tr[p].sum,tr[rs(p)].sum);
    //pushup(p);
}

ll query(int p,int x,int y){
    if(x<=tr[p].l&&tr[p].r<=y)
    return tr[p].sum;
    ll sum=0;
    ll m=(tr[p].l+tr[p].r)>>1;
    if(x<=m) sum=query(ls(p),x,y);
    if(y>m) sum=gcd(sum,query(rs(p),x,y));
    return sum;
}
void solve(){
    int n,q;
    cin>>n>>q;
    vector<ll>a(n+1);
    vector<ll>d(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    //ll ans=1;
    for(int i=2;i<=n;i++){
        arr[i-1]=abs(a[i]-a[i-1]);
        //ans*=d[i-1];
    }
    if(n==1){
        while(q--){
            int l,r;
            cin>>l>>r;
            cout<<0<<" ";
        }
        return;
    }
    build(1,1,n-1);
    while(q--){
        int l,r;
        cin>>l>>r;
        if(l==r){
            cout<<0<<" ";
            continue;
        }
        cout<<query(1,l,r-1)<<' ';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
        cout<<'\n';
    }
    return 0;
}