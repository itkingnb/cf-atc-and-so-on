#include<bits/stdc++.h>
#define ll long long
#define int ll 
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
    int n;
    cin>>n;
    vector<int>a(n);
    vector<vector<int>>pre(n+1,vector<int>(n+10,0));
    map<int,vector<int>>mp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        pre[i+1]=pre[i];
        pre[i+1][a[i]]++;
        mp[a[i]].push_back(i);
    }   
    vector<vector<ll>>mpp(n+10,vector<ll>(n+10,0));
    ll ans=0;
    for(int i=0;i<n;i++){
        auto it=upper_bound(mp[a[i]].begin(),mp[a[i]].end(),i);
        int x;
        if(it!=mp[a[i]].end()){
            x=*it;
        }else{
            continue;
        }
        for(int j=1;j<=n;j++){
            // pre[x][j]+=mpp[a[i]][j];
            ans+=(pre[x][j]-pre[i+1][j]+mpp[a[i]][j])*(pre[n][j]-pre[x+1][j]);
            if(next(it)!=mp[a[i]].end()){
                mpp[a[i]][j]+=pre[*next(it)][j]-pre[mp[a[i]][0]+1][j];
            }
        }
        // cerr<<ans<<'\n';
        // cerr<<mpp[2][2]<<'\n';
    }
    cout<<ans;
}

signed main(){
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