#include<iostream>
#include<cmath>
#include<string>
#include <algorithm>
#include<vector>
#include<queue>
#include<map>
#include<numeric>
#include<cstring>
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
int n;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
string mp[2];
int men[200010][2]={0};
//vector<vector<int>>men(2,vector<int>(200010,0));
int flag=0;
int flag1=0;
void dfs(int x,int y){
    if(y>=2||x>=n||x<0||y<0||men[x][y]&&flag||flag1){
    flag=0;
    return ;
    }
    if(x==0&&y==0){
        flag=0;
        men[x][y]++;
        for(int i=0;i<4;i++){
            dfs(x+dx[i],y+dy[i]);
        }
    }
    if(x==n-1&&y==1&&flag){
        yes();
        flag1++;
        return;
    }
    if(flag){
        flag=0;
        men[x][y]++;
        for(int i=0;i<4;i++){
            dfs(x+dx[i],y+dy[i]);
        }
    }
    else{
        flag=1;
        if(mp[y][x]=='>')
        dfs(x+1,y);
        else
        dfs(x-1,y);
    }
}
void solve(){
    memset(men,0,sizeof(men));
    flag=0;
    flag1=0;
    cin>>n;
    for(int i=0;i<2;i++)
    cin>>mp[i];
    dfs(0,0);
    if(flag1==0)
    no();
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