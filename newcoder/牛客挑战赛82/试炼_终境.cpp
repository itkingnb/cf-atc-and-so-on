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
    vector<vector<int>>tree(n*40,vector<int>(2));
    vector<vector<int>>cnt(n*40,vector<int>(2));
    vector<int>ans(n);
    int idx=0;
    auto build=[&](int x)->void{
        int p=0;
        for(int i=31;i>=0;i--){
            int m=(x>>i)&1;
            if(!tree[p][m]) tree[p][m]=++idx;
            cnt[p][m]++;
            p=tree[p][m];
        }
    };
    auto query=[&](int x)->int{
        int p=0,ans=0;
        for(int i=31;i>=0;i--){
            int m=(x>>i)&1;
            if(tree[p][!m]&&cnt[p][!m]){
                ans += (!m)<<i;
                cnt[p][!m]--;
                p=tree[p][!m];
            }
            else{
                ans+=(m)<<i;
                cnt[p][m]--;
                p=tree[p][m];
            }
        }
        return ans;
    };
    for(int i=1;i<=n;i++){
        build(i);
    }
    vector<bool>vis(n+1,0);
    vis[0]=1;
    for(int i=0;i<n;i++){
        ans[i]=query(i+1);
        vis[ans[i]]=1;
        cout<<ans[i]<<" ";
    }
    assert(vis==vector<bool>(n+1,1));
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