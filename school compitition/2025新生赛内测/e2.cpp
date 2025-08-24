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
    vector<int>a(n);
    int ans=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i){
            ans=max(ans,abs(a[i]-a[i-1]));
        }
    }
    int l=0,r=ans-1;
    vector<int>t=a;
    auto check=[&](int x)->bool{
        int idx=-1;
        for(int i=1;i<n;i++){
            if(abs(a[i]-a[i-1])<=x){
                continue;
            }else{
                idx=i;
                break;
            }
        }
        for(int j=idx+1;j<n;j++){
            bool ok=1;
            swap(t[j],t[idx-1]);
            if(idx-1-1>=0&&abs(t[idx-1]-t[idx-1-1])>x){
                ok=0;
            }
            if(idx<n&&abs(t[idx-1]-t[idx])>x){
                ok=0;
            }
            if(j-1>=0&&abs(t[j]-t[j-1])>x){
                ok=0;
            }
            if(j+1<n&&abs(t[j+1]-t[j])>x){
                ok=0;
            }
            // swap(t[j],t[idx-1]);
            if(ok){
                cout<<t.size();
                for(auto x:t){
                    cout<<x<<" ";
                }
                return 1;
            }
        }
        for(int j=idx+1;j<n;j++){
            bool ok=1;
            swap(t[j],t[idx]);
            if(idx-1>=0&&abs(t[idx]-t[idx-1])>x){
                ok=0;
            }
            if(idx+1<n&&abs(t[idx+1]-t[idx])>x){
                ok=0;
            }
            if(j-1>=0&&abs(t[j]-t[j-1])>x){
                ok=0;
            }
            if(j+1<n&&abs(t[j+1]-t[j])>x){
                ok=0;
            }
            // swap(t[j],t[idx]);
            if(ok){
                cout<<t.size();
                for(auto x:t){
                    cout<<x<<" ";
                }
                return 1;
            }
        }
        return 0;
    };
    while(l<=r){
        int mid=(l+r)>>1;
        // cout<<mid<<'\n';
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<ans;
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