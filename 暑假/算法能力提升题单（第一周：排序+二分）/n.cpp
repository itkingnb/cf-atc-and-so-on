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
        int n;
        ll m;
        cin>>n>>m;
        vector<ll>a(n+1,0);
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        ll l=0,r=1e18;
        ll ans=0;
        auto check=[&](ll x)->bool{
            vector<ll>b(n+2,0);
            int pi=0;
            ll mm=m;
            while(pi<n+1&&mm>0){
                // b[pi+1]+=a[pi+1];
                ll mx=min(mm,max(0LL,(ll)ceil((x-b[pi])*1.0/a[pi])*2LL));
                mm-=mx;
                b[pi+1]+=(mx+1)/2*a[pi+1];
                b[pi]+=(mx/2)*a[pi];
                if(mm>0){
                    mm--;
                    b[pi+1]+=a[pi+1];
                    // pi++;
                }
                pi++;
            }
            for(int i=1;i<=n;i++){
                if(b[i]<x){
                    return 0;
                }
            }
            return 1;
        };
        // check(6);
        // cerr<<check(4)<<endl;
        while(l<=r){
            ll mid=(l+r)>>1;
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