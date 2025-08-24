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
    cin>>n;
    vector<long double>a(n),b(n);
    vector<ll>c(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    sort(all(c));
    auto check=[&](ll x)->bool{
        vector<ll>z,f;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(a[i]==0){
                cnt+=(b[i]>=x);
            }else if(a[i]>0){
                if(ceil(((x-b[i])*1.0/a[i]))<=(int)1e9)
                    z.push_back(ceil((x-b[i])*1.0/a[i]));
                
            }else{
                if(floor((x-b[i])*1.0/a[i])>=(int)-1e9)
                    f.push_back(floor((x-b[i])*1.0/a[i]));
            }
        }
        sort(all(z),greater<ll>());
        sort(all(f));
        vector<bool>vis(n,0);
        int pi=0;
        for(auto &xx:f){
            if(pi<n&&c[pi]<=xx){
                cnt++;
                vis[pi]=1;
                pi++;
            }
        }
        pi=n-1;
        for(auto &xx:z){
            while(pi>=0&&vis[pi]) pi--;
            if(pi>=0&&!vis[pi]&&c[pi]>=xx){
                cnt++;
                pi--;
            }
        }
        return cnt>=((n+1)/2);
    };
    ll ans=-maxll;
    ll l=-3e18-10,r=3e18+10;
    check(9);
    // ll last=0;
    while(l<=r){
        ll mid=(l+r)>>1;
        if(check(mid)){
            // last=ans;
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<ans;
}
/*
3
5
0 5 -2 1 2
9 -4 0 10 5
-4 -1 4 -2 4
10
-6 3 1 0 6 -2 -4 3 0 10
22 65 11 1 -34 -1 -39 -28 25 24
10 9 1 -2 -5 8 -7 -10 -7 -7
1
101
48763
651

*/
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