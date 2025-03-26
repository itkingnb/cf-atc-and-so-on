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
struct node{
    int a,b,c,d;
    int id;
};
bool cmp(node n1,node n2){
    if(n1.a==n2.a&&n1.b==n2.b&&n1.c==n2.c){
        return (n1.c&1)?n1.d<n2.d:n1.d>n2.d;
    }else if(n1.a==n2.a&&n1.b==n2.b){
        return n1.c<n2.c;
    }else if(n1.a==n2.a){
        return (n1.a&1)?n1.b<n2.b:n1.b>n2.b;
    }
    return n1.a<n2.a;
}

void solve(){
    int n,q;
    cin>>n>>q;
    ll all=0;
    int t=1;
    vector<vector<ll>>a(n+10,vector<ll>(n+10,0));
    vector<vector<ll>>dp(n+10,vector<ll>(n+10,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            //all+=a[i][j]*(t++);
            dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+a[i][j];
        }
    }
    int pa=1,pb=1,pc=1,pd=1;
    all=a[1][1];
    auto sum=[=](int a,int b,int c,int d)->ll{
        return dp[c][d]+dp[a-1][b-1]-dp[a-1][d]-dp[c][b-1];
    };
    vector<node>asks(q);
    for(int i=0;i<q;i++){
        cin>>asks[i].a>>asks[i].b>>asks[i].c>>asks[i].d;
        asks[i].id=i;
    }
    sort(asks.begin(),asks.end(),cmp);
    vector<ll>ans(q,0);
    for(int i=0;i<q;i++){
        while(asks[i].b<pb){
            int t=1,tt=1;
            for(int j=pa;j<=pc;j++){
                all+=t*sum(j,pb,j,pd);
                t++;
            }
            pb--;
            for(int j=pa;j<=pc;j++){
                all+=tt*a[j][pb];
                tt+=pd-pb+1;
            }
        }
        while(asks[i].b>pb){
            int t=1,tt=1;
            for(int j=pa;j<=pc;j++){
                all-=tt*a[j][pb];
                tt+=pd-pb+1;
            }
            pb++;
            for(int j=pa;j<=pc;j++){
                all-=t*sum(j,pb,j,pd);
                t++;
            }
        }
        while(pd<asks[i].d){
            int tt=0;
            for(int j=pa;j<=pc;j++){
                all+=sum(j,pb,j,pd)*(tt++);
            }
            pd++;
            int t=pd-pb+1;;
            for(int j=pa;j<=pc;j++){
                all+=(pb-pb+1)*a[j][pd]*t;
                t+=pd-pb+1;
            }
        }
        while(pd>asks[i].d){
            int t=pd-pb+1;
            for(int j=pa;j<=pc;j++){
                all-=(pb-pb+1)*a[j][pd]*t;
                t+=pd-pb+1;
            }
            pd--;
            int tt=0;
            for(int j=pa;j<=pc;j++){
                all-=sum(j,pb,j,pd)*(tt++);
            }
        }
        while(asks[i].a>pa){
            int t=1;
            for(int j=pb;j<=pd;j++){
                all-=(t++)*a[pa][j];
            }
            pa++;
            all-=(pd-pb+1)*sum(pa,pb,pc,pd);
        }
        while(asks[i].a<pa){
            all+=(pd-pb+1)*sum(pa,pb,pc,pd);
            pa--;
            int t=1;
            for(int j=pb;j<=pd;j++){
                all+=(t++)*a[pa][j];
            }
        }
        while(pc<asks[i].c){
            int t=(pd-pb+1)*(pc-pa+1)+1;
            pc++;
            for(int j=pb;j<=pd;j++){
                all+=a[pc][j]*(t++);
            }
        }
        while(pc>asks[i].c){
            pc--;            
            int t=(pd-pb+1)*(pc-pa+1)+1;
            for(int j=pb;j<=pd;j++){
                all-=a[pc+1][j]*(t++);
            }
        }
        ans[asks[i].id]=all;
    }
    for(int i=0;i<q;i++){
        cout<<ans[i]<<" ";
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