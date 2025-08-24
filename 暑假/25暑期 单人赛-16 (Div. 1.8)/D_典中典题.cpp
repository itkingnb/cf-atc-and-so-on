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
    vector<ll>a(n);
    ll sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i%2==0){
            sum+=a[i];
        }
    }
    // cout<<sum<<"\n";
    if(n==1){
        cout<<a[0];
        return ;
    }else if(n==2){
        cout<<max(a[0],a[1]);
        return ;
    }
    ll pre=a[1]-a[0];
    ll mx=pre;
    ll mn=pre;
    // cout<<pre;
    for(int i=2;i+1<n;i+=2){
        pre+=a[i+1]-a[i];
        mx=max({mx,pre,pre-mn});
        mn=min(mn,pre);
        // cout<<i<<" "<<mx<<"\n";
    }
    pre=a[1]-a[2];
    mx=max(pre,mx);
    mn=pre;
    for(int i=3;i+1<n;i+=2){
        pre+=a[i]-a[i+1];
        mx=max({mx,pre-mn,pre});
        mn=min(mn,pre);
    }
    cout<<max(sum,sum+mx);
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