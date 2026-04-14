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
    int n;
    cin>>n;
    vector<vector<int>>adj(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>>dep(n+1);
    vector<int>f(n);
    vector<int>sz(n,0);
    auto dfs=[&](auto &&self,int x,int fa,int deep)->void{
        dep[deep].push_back(x);
        f[x]=fa;
        if(fa!=-1){
            sz[fa]++;
        }
        for(auto u:adj[x]){
            if(u==fa){
                continue;
            }else{
                self(self,u,x,deep+1);
            }
        }
    };
    int ans=0;
    dfs(dfs,0,-1,1);
    int mxd=0;
    for(int i=2;i<=n;i++){
        if(dep[i].size()){
            if(sz[f[dep[i][0]]]==dep[i].size()){
                ans=max(ans,(int)dep[i].size()+1);
            }else{
                ans=max(ans,(int)dep[i].size());
            }
            mxd=i;
        }else{
            break;
        }
    }
    cout<<ans<<'\n';
    vector<vector<int>>op(ans);
    vector<int>id(n,-1);
    // op[0].push_back(0);
    id[0]=0;
    queue<int>q;
    for(int i=2;i<=mxd;i++){
        int idx=0;
        for(int j=0;j<dep[i].size();j++){
            if(idx==id[f[dep[i][j]]]){
                q.push(dep[i][j]);
                id[dep[i][j]]=idx++;
            }else{
                // op[idx].push_back(dep[j][i]);
                id[dep[i][j]]=idx++;
            }
        }
        while(q.size()){
            auto x=q.front();q.pop();
            bool ok=0;
            if(id[x]!=id[f[x]]){
                continue;
            }
            for(int j=0;j<dep[i].size();j++){
                if(dep[i][j]!=x&&id[dep[i][j]]!=id[f[x]]&&id[f[dep[i][j]]]!=id[x]){
                    ok=1;
                    // id[x]=id[f[x]];
                    swap(id[x],id[dep[i][j]]);
                    break;
                }
            }
            if(!ok){
                if(idx==id[f[x]]){
                    idx++;
                }
                id[x]=idx++;
            }
        }
    }
    for(int i=0;i<n;i++){
        op[id[i]].push_back(i);
    }
    for(int i=0;i<ans;i++){
        cout<<op[i].size()<<" ";
        for(auto x:op[i]){
            cout<<x+1<<" ";
        }
        cout<<"\n";
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