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
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<int>>mp(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mp[i][j];
        }
    }
    auto check=[&](int x,int y)->bool{
        return x>=0&&y>=0&&x<n&&y<m;
    };
    map<int,int>mpp;
    vector<vector<bool>>vis(n,vector<bool>(m,0));
    priority_queue<tuple<int,int,int>>pq;
    for(int i=0;i<m;i++){
        // mpp[mp[0][i]]++;
        pq.push({-mp[0][i],0,i});   
        vis[0][i]=1;
        
    }
    int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
    while(pq.size()){
        auto [num,x,y]=pq.top();
        pq.pop();
        mpp[-num]++;
        for(int k=0;k<=4;k++){
            int nx=x+dx[k],ny=y+dy[k];
            if(check(nx,ny)&&!vis[nx][ny]){
                pq.push({-max(mp[nx][ny],-num),nx,ny});
                vis[nx][ny]=1;
            }
        }
    }
    // for(int i=1;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         int mx=mp[i][j],mn=(int)1e9+10;
    //         for(int k=0;k<4;k++){
    //             int nx=i+dx[k],ny=j+dy[k];
    //             if(check(nx,ny)){
    //                 mn=min(mn,mp[nx][ny]);
    //             }
    //         }
    //         if(mn!=(int)1e9+10){
    //             mp[i][j]=max(mp[i][j],mn);
    //         }
    //         mpp[mp[i][j]]++;
    //     }
    // }
    int last=-1;
    vector<int>t,b;
    for(auto &[x,y]:mpp){
        t.push_back(x);
        if(last!=-1){
            y+=last;
        }
        b.push_back(y);
        last=y;
    }
    while(q--){
        int x;
        cin>>x;
        auto p=upper_bound(all(t),x)-t.begin();
        p--;
        cout<<b[p]<<'\n';
    }
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