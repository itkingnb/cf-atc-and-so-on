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
    ll k;
    cin>>k;
    ll l=0,r=1e14;
    ll mx=0;
    auto check=[&](ll x)->bool{
        if(x<=9){
            return x<=k;
        }
        ll cnt=9;
        ll now=99;
        ll t=2;
        while(x>=now){
            // cerr<<now<<'\n';
            cnt+=(now+1-(now+1)/10)*t;
            t++;
            now=now*10+9;
        }
        cnt+=(x-qpow(10,t-1)+1)*t;
        return cnt<=k;
    };
    // check(50000000000);
    while(l<=r){
        ll mid=(l+r)>>1;
        // cerr<<mid<<" ";
        if(check(mid)){
            mx=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    // mx=2125;
    // cout<<mx<<" ";
    ll ans=0;
    for(ll i=1;i<=9;i++){
        ll t=i*10;
        ll mod=10;
        // if(mx>)
        if(mx>=i){
            ans+=((mx-i)/10+1)*i;
        }
        // cerr<<ans<<" ";
        while(t<=mx){
            ll hi=mx/(mod*10);
            ans+=(i*mod)*hi;
            hi=max(0LL,hi-1);
            ll tmp=mx-(hi)*(mod*10);
            ll l=t,r=l+mod-1;
            ans-=max(0LL,min(mod,tmp-l+1));
            mod*=10;
            t*=10;
            // cerr<<t<<" ";
        }
        cerr<<i<<" "<<ans<<'\n';
    }
    auto cal=[&](ll x)->ll{
        if(x<=9){
            return x;
        }
        ll cnt=9;
        ll now=99;
        ll t=2;
        while(x>=now){
            // cerr<<now<<'\n';
            cnt+=(now+1-(now+1)/10)*t;
            t++;
            now=now*10+9;
        }
        cnt+=(x-qpow(10,t-1)+1)*t;
        return cnt;
    };
    // cout<<cal(mx)<<" ";
    k-=cal(mx);
    string s=to_string(mx+1);
    for(int i=0;i<k;i++){
        ans+=s[i]-'0';
    }
    cout<<ans;
    // cout<<mx<<" ";

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