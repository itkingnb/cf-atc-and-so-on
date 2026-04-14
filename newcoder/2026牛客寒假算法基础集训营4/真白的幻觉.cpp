#include<bits/stdc++.h>
#define ll unsigned long long
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
    auto f=[&](ll x)->ll{
        ll res=1;
        while(x){
            res*=(x%10);
            x/=10;
        }
        return res;
    };
    auto g=[&](ll x)->ll{
        int ans=0;
        while(x!=f(x)){
            x=f(x);
            ans++;
        }
        return ans;
    };
    map<int,vector<ll>>mp;
    int a[5]={2,3,7,8,9};
    map<ll,bool>vis;
    auto dfs=[&](auto &&self,ll x)->void{
        if(vis[x]){
            return ;
        }
        vis[x]=1;
        if(to_string(x).size()==18){
            mp[g(x)].push_back(x);
            return ;
        }
        for(int i=0;i<5;i++){
            if(a[i]>=(x%10)){
                self(self,x*10+a[i]);
            }
        }
    };
    for(int i=0;i<5;i++){
        dfs(dfs,a[i]);
    }
    auto [x,y]=*mp.rbegin();
    cerr<<x<<'\n';
    for(auto u:y){
        cout<<u<<' ';
    }
    cerr<<g(69999499769779797)<<" "<<g(62747786744647867);
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