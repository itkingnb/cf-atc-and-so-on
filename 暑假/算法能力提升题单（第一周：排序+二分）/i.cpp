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
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>mp(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mp[i][j];
        }
    }
    int mid;
    int ans=0,l=0,r=1010;
    int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
    auto check=[&](int x)->bool{
        queue<pii>q;
        q.push({0,0});
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        auto check2=[&](int x,int y)->bool{
            return x>=0&&y>=0&&x<n&&y<m&&mp[x][y]<=mid&&!vis[x][y];
        };
        while(q.size()){
            auto [x,y]=q.front();q.pop();
            if(x==n-1){
                return 1;
            }
            for(int i=0;i<4;i++){
                int nx=x+dx[i],ny=y+dy[i];
                if(check2(nx,ny)){
                    vis[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
        return 0;
    };
    check(3);
    while(l<=r){
        mid=(l+r)>>1;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
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