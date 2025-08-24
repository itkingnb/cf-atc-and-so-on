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
    int n;
    cin>>n;
    vector<int>a(n);
    // vector<int>fa(2e5+10,0);
    // iota(fa.begin(),fa.end(),0);
    vector<int>vis(2e5+10,0);
    // auto findfa=[&](auto&&findfa,int x)->int{
    //     if(x==fa[x]){
    //         return x;
    //     }
    //     return fa[x]=findfa(findfa,fa[x]);
    // };
    for(int i=0;i<n;i++){
        cin>>a[i];
        vis[a[i]]++;
    }
    int ans=0;
    for(int i=1;i<=(int)2e5+5;i++){
        if(vis[i]){
            if(!vis[i-1]&&!vis[i+1]){
                ans+=vis[i];
            }else{
                if(vis[i+1]){
                    continue;
                }else{
                    ans++;
                }
            }
        }
    }
    cout<<ans-1;
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