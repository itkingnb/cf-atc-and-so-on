#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
int es[210];
int me[210];
int k[210];
int n,a,b;
bool check(int x){
    if(x>=1&&x<=n)
    return true;
    return false;
}
void bfs(int x){
    es[x]=0;
    me[x]=1;
    queue<int>a;
    a.push(x);
    while(!a.empty()){
        int aa=a.front();
        a.pop();
        if(check(aa+k[aa])&&me[aa+k[aa]]==0){
            es[aa+k[aa]]=es[aa]+1;
            a.push(aa+k[aa]);
            me[aa+k[aa]]=1;
        }
        if(check(aa-k[aa])&&me[aa-k[aa]]==0){
            es[aa-k[aa]]=es[aa]+1;
            a.push(aa-k[aa]);
            me[aa-k[aa]]=1;            
        }
    }
}
void solve(){
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++)
    cin>>k[i];
    memset(es,-1,sizeof(es));
    bfs(a);
    cout<<es[b];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}