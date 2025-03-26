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
#define N 2010
int n,q;
vector<vector<char>>a(N,vector<char>(2));
int cost[N][N];
bool able[N][N];
bool check(int x,int y){
    if(a[x][0]==a[y][0]||a[x][0]==a[y][1]||a[x][1]==a[y][0]||a[x][1]==a[y][1])
    return true;
    return false;
}
void floyd(){
    for(int i=1;i<n;i++)
        cost[i][i]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(check(i,j)){
                cost[i][j]=cost[j][i]=min(abs(j-i),cost[i][j]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(check(j,i)&&check(i,k)){
                    cost[j][k]=cost[k][j]=min({cost[j][k],cost[k][j],cost[j][i]+cost[i][k]});
                }
            }
        }
    }
}
void solve(){
    memset(cost,0x3f3f3f3f,sizeof(cost));
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        a[i][0]=s[0];
        a[i][1]=s[1];
        //cin>>s;
    }   
    floyd();
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        if(cost[l][r]!=0x3f3f3f3f)
        cout<<cost[l][r]<<'\n';
        else
        cout<<-1<<'\n';
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
        //cout<<'\n';
    }
    return 0;
}