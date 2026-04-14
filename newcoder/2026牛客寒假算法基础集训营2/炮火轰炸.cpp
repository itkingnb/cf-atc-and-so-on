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
    cout<<"YES";
}
void no(){
    cout<<"NO";
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
constexpr int N=1e6+10;
void solve(){
    int n,q;
    cin>>n>>q;
    vector<set<int>>mx(N),my(N);
    vector<map<int,bool>>mp(N);
    vector<set<int>>st(N);
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        st[x].insert(y);
    }
    auto in=[&](int x,int y)->bool{
        auto itx=mx[x].lower_bound(y);
        auto ity=my[y].lower_bound(x);
        if(itx==mx[x].end()||ity==my[y].end()){
            return 0;
        }
        return min(mp[x][*itx],mp[*ity][y]);
    };
    auto dfs=[&](auto &&self,int x,int y,bool statue)->void{
        mp[x][y]=statue;
        mx[x].insert(y);
        my[y].insert(x);
        int dx[]={-1,1,0,0};
        int dy[]={0,0,1,-1};
        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(nx<0||ny<0) continue;
            if(mp[nx].count(ny)) continue;
            if(st[nx].count(ny)) continue;
            bool ok=0;
            for(int dx=-1;dx<=1;dx++){
                for(int dy=-1;dy<=1;dy++){
                    int xx=nx+dx,yy=ny+dy;
                    if(xx>0) ok|=st[xx].count(yy);
                }
            }
            if(ok) self(self,nx,ny,statue);
        } 
    };
    for(int i=0;i<=1e6;i++){
        for(auto y:st[i]){
            if(in(i,y)){
                continue;
            } 
            for(int dx=-1;dx<=1;dx++){
                for(int dy=-1;dy<=1;dy++){
                    int nx=i+dx,ny=y+dy;
                    if(nx<0||ny<0) continue;
                    if(mp[nx].count(ny)) continue;
                    if(st[nx].count(ny)) continue;
                    if(min(dx,dy)<0) dfs(dfs,nx,ny,0);
                    else dfs(dfs,nx,ny,1);
                }
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        if(in(x,y)){
            yes();
        }else{
            no();
        }
        cout<<'\n';
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