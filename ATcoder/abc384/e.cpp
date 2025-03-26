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
vector<vector<ll>>mp(510,vector<ll>(510));
struct node{
	int x,y;
    friend bool operator<(const node &a, const node &b){
        return mp[a.x][a.y]>mp[b.x][b.y];
    }
};
void solve(){
    int n,m,d,x,y;
    ll now;
    cin>>n>>m>>d>>x>>y;;
    vector<vector<bool>>vis(n+10,vector<bool>(m+10,false));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
        }
    }
    now=mp[x][y];vis[x][y]=1;
    int dx[]={0,0,1,-1},dy[]={-1,1,0,0};
    priority_queue<pii>q;
    auto check=[=](int x,int y)->bool{
        return x>=1&&y>=1&&x<=n&&y<=m;
    };
    priority_queue<node,vector<node>>temp;
    for(int i=0;i<4;i++){
        if(check(x+dx[i],y+dy[i])&&now*1.0/d>mp[x+dx[i]][y+dy[i]]){
            q.push({x+dx[i],y+dy[i]});
            vis[x+dx[i]][y+dy[i]]=1;
        }else if(check(x+dx[i],y+dy[y])){
            temp.push({x+dx[i],y+dy[i]});
            vis[x+dx[i]][y+dy[i]]=1;
        } 
    }
    while(q.size()){
        auto u=q.top();q.pop();
        x=u.first;y=u.second;now+=mp[x][y];
        while(temp.size()){
            auto uu=temp.top();
            if(now*1.0/d>mp[uu.x][uu.y]){
                q.push({uu.x,uu.y});
                temp.pop();
            }else{
                break;
            }
        }
        for(int i=0;i<4;i++){
            if(check(x+dx[i],y+dy[i])&&now*1.0/d>mp[x+dx[i]][y+dy[i]]&&!vis[x+dx[i]][y+dy[i]]){
                q.push({x+dx[i],y+dy[i]});
                vis[x+dx[i]][y+dy[i]]=1;
            }else if(check(x+dx[i],y+dy[i])&&!vis[x+dx[i]][y+dy[i]]){
                temp.push({x+dx[i],y+dy[i]});
                vis[x+dx[i]][y+dy[i]]=1;
            }
        }
        //cout<<now<<'\n';
    }
    cout<<now;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    //cin>>t;
    for(int i=0;i<t;i++){
        solve();
        cout<<'\n';
    }
    return 0;
}