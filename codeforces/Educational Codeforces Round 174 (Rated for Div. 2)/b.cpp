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
    cout<<"Yes";
}
void no(){
    cout<<"No";
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
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>a(n,vector<int>(m,0));
    vector<vector<bool>>vis(n,vector<bool>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    mii mp;
    int ans=0;
    int dx[]={0,0,1,-1};
    int dy[]={1,-1,0,0};
    auto check=[&](int x,int y)->bool{
        return x>=0&&y>=0&&x<n&&y<m&&vis[x][y]==0;
    };
    auto dfs=[&](auto &&dfs,int num,int x,int y)->void{
        if(a[x][y]==num){
            ++mp[num];
            vis[x][y]=true;
            for(int i=0;i<4;i++){
                if(check(x+dx[i],y+dy[i])){
                    dfs(dfs,num,x+dx[i],y+dy[i]);
                }
            }
        }
        return ;
    };
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]){
                continue;
            }
            vis[i][j]=1;
            if(mp[a[i][j]]==0){
                ++mp[a[i][j]];
            }
            for(int k=0;k<4;k++){
                if(check(i+dx[k],j+dy[k]))
                dfs(dfs,a[i][j],i+dx[k],j+dy[k]);
            }
        }
    }
    int mx=0;
    for(auto [x,y]:mp){
        ans+=y;
        mx=max(mx,y);
    }
    cout<<ans-mx;
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