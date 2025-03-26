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
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll>a(n);
    vector<ll>pre(n+1,0LL);
    for(int i=0;i<n;i++){
        cin>>a[i];
        pre[i+1]=pre[i]+a[i];
    }
    vector<ll>pdp(n+10,0);
    for(int i=0;i<n;i++){
        pdp[i+2]=pdp[i+1];
        auto x=upper_bound(pre.begin(),pre.end(),pre[i+1]-k)-pre.begin();
        x--;
        if(x<0){
            continue;
        }else{
            pdp[i+2]=max(pdp[i+2],1+pdp[x+1]);
        }
    }
    vector<ll>bdp(n+1,0);
    for(int i=n-1;i>=0;i--){
        bdp[i]=bdp[i+1];
        auto x=lower_bound(pre.begin(),pre.end(),k+pre[i])-pre.begin();
        x++;
        if(x>n+1){
            continue;
        }else{
            bdp[i]=max(bdp[i],1+bdp[x-1]);
        }
    }
    
    bool flag=false;
    ll ans=0;
    for(int i=1;i<n+1;i++){
        if(bdp[i-1]+pdp[i]>=m){
            flag=true;
        }
    }
    reverse(bdp.begin(),bdp.end());
    for(int i=1;i<=n;i++){
        ll mx=0;
        auto j=lower_bound(bdp.begin(),bdp.end(),m-pdp[i])-bdp.begin();
        // j--;
        j=n-j;
        if(j>=i-1)
        mx=pre[j]-pre[i-1];
        /*while(pdp[i]+bdp[j]>=m&&j-1<n){
            mx+=a[j-1];
            j++;
        }*/
        ans=max(ans,mx);
    }

    flag?cout<<ans:cout<<-1;
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