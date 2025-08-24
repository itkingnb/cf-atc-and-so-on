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
    cin>>m>>n;
    vector<vector<ll>>a(m,vector<ll>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    int l=0,r=1e9+10;
    int ans=0;
    auto check=[&](int x)->bool{
        vector<bool>vis(n,0);
        bool ok=false;
        for(int i=0;i<m;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                cnt+=(a[i][j]>=x);
                vis[j]=vis[j]|(a[i][j]>=x);
            }
            ok=ok|cnt>=2;
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=vis[i];
        }
        return cnt==n&&ok;
    };
    check(3);
    while(l<=r){
        int mid=(l+r)>>1;
        // cout<<mid<<'\n';
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
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