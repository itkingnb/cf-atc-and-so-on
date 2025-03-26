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
    //map<int,vector<int>>mp;
    vector<vector<int>>mp(4);
    vector<array<int,4>>pre(n+1);
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i-1>=0)
        pre[i]=pre[i-1];
        pre[i][a[i]]++;
        mp[a[i]].push_back(i);
    }
    ll ans=0;
    ll mod=998244353;
    vector<ll>pow2(n);
    pow2[1]=2;
    for(int i=2;i<n;i++){
        pow2[i]=pow2[i-1]*2%mod;
    }
    sort(mp[3].begin(),mp[3].end(),greater<int>());
    for(auto x:mp[1]){
        if(mp[3].size()==0||pre[mp[3][0]][2]-pre[x][2]<=0){
            break;
        }
        for(auto y:mp[3]){
            ll cnt2=pre[y][2]-pre[x][2];
            if(cnt2<=0){
                break;
            }
            ans+=pow2[cnt2]-1;
            ans%=mod;
        }
    }
    cout<<ans;
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