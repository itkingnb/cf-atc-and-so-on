#include<iostream>
#include<cmath>
#include<string>
#include <algorithm>
#include<vector>
#include<queue>
#include<map>
#include<numeric>
#include<cstring>
#include<stack>
#include<queue>
#define pii pair<int,int>;
#define ll long long
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
int fa[200010];
int flag=0;
int tt;
queue<int>roots;
void dfs(int x,vector<vector<int>>& adj1){
    if(adj1[x].size()==0&&x==adj1[fa[x]][adj1[fa[x]].size()-1]){
        roots.push(x);
        adj1[fa[x]].clear();
    }
    else{
        if(adj1[x].size()){
            for(int i=0;i<adj1[x].size();i++){
                dfs(adj1[x][i],adj1);
            }
        dfs(fa[x],adj1);
        }
    }
}
void solve(){
    int n;
    cin>>n;
    int m;
    ll ans=0;
    vector<int>a(n+1);
    vector<vector<int>>adj(n+1);
    fa[1]=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=2;i<=n;i++){
        cin>>m;
        adj[m].push_back(i);
        fa[i]=m;
    }
    vector<vector<int>>adj1(n+1);
    adj1=adj;
    dfs(1,adj1);
    //roots.push(1);
    //int root=findroot(1,adj);
    while (!roots.empty())
    {   
        int root=roots.front();
        //cout<<root<<'\n';
        roots.pop();
        int cnt=0;
        int father=fa[root];
        if(father!=1){
            int mx=maxint;
            for(int i=0;i<adj[father].size();i++){
                if(a[father]>a[adj[father][i]]){
                a[father]=a[adj[father][i]];
                cnt++;
                }
                mx=min(mx,(a[father]+a[adj[father][i]])>>1);
            }
            if(cnt==0)
            a[father]=mx;
            adj[father].clear();
            flag=0;
        }
        else{
            int mx=a[adj[father][0]];
            for(int i=1;i<adj[father].size();i++)
            mx=min(mx,a[adj[father][i]]);
            a[1]+=mx;
            adj[father].clear();
        }
    }
    cout<<a[1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
        cout<<'\n';
    }
    return 0;
}
