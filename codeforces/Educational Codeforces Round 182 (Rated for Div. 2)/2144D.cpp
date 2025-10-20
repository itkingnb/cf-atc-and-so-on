#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
using namespace std;
int maxint = INT_MAX;// 2147483647
int minint = INT_MIN;// -2147483648
long long maxll = LLONG_MAX;// 9223372036854775807
long long minll = LLONG_MIN;// -9223372036854775808
#define int ll
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
    ll y;
    cin>>n>>y;
    vector<int>a(n);
    // map<ll,int>mp;
    vector<int>cnt((int)2e5+10,0);
    int mx=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        cnt[a[i]]++;
        mx=max(mx,a[i]);
    }
    int l=2,r=mx;
    ll ans=-2e18;
    vector<int>cnt2((int)2e5+10,0);
    auto check=[&](int x)->ll{
        for(int i=0;i<=(mx+x-1)/x;i++){
            cnt2[i]=0;
        }
        int sum=0;
        ll res=0;
        for(int i=0;i<n;i++){
            int t=(a[i]+x-1)/x;
            cnt2[t]++;
            if(cnt2[t]>cnt[t]){
                sum++;
            }
            res+=t;
        }
        return res-1LL*sum*y;
    };
    // for(int i=2;i<200;i++){
    //     cout<<i<<" "<<check(i)<<"\n";
    // }
    // // cerr<<check(111);
    while(r-l>200){
        int l1=l+(r-l)/3;
        int r1=r-(r-l)/3;
        ll res1=check(l1),res2=check(r1);
        ans=max({ans,res1,res2});
        if(res1>res2){
            r=r1-1;
        }else{
            l=l1+1;
        }
    }
    int ok=0;
    ll last=-4e18;
    for(int i=l;i<=max(2LL,r);i++){
        ll res=check(i);
        ans=max(ans,res);
        if(res>last&&ok>=15){
            break;
        }else if(res>last){
            // cerr<<i<<endl;
            ok++;
        }
        last=res;
        
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