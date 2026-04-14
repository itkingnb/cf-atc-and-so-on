#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
using namespace std;
int maxint = INT_MAX;// 2147483647
int minint = INT_MIN;// -2147483648
long long maxll = LLONG_MAX;// 9223372036854775807
long long minll = LLONG_MIN;// -9223372036854775808
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
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
ll qpow(ll a, ll k, ll p=maxll)
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
void solve(){
    int n,m;
    cin>>n>>m;
    int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
    int a,b;
    cin>>a>>b;
    vector<vector<int>>mp(n,vector<int>(m,0));
    vector<vector<bool>>vis(n,vector<bool>(m,0));
    auto check=[&](int x,int y)->bool{
        return x>=0&&y>=0&&x<n&&y<m;
    };
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
    for(int i=0;i<a;i++){
        int x,y;
        cin>>x>>y;
        pq.push({0,x-1,y-1});
    }
    for(int i=0;i<b;i++){
        int x,y,t;
        cin>>x>>y>>t;
        mp[x-1][y-1]=t;
    }
    int ans=0;
    while(pq.size()){
        auto [t,x,y]=pq.top();pq.pop();
        if(vis[x][y]){
            continue;
        }
        vis[x][y]=1;
        mp[x][y]=max(mp[x][y],t);
        ans=max(ans,mp[x][y]);
        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(check(nx,ny)){
                pq.push({mp[x][y]+1,nx,ny});
            }
        }
    }
    cout<<ans;
    
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