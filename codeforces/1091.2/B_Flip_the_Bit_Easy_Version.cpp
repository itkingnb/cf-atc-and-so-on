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
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int p;
    cin>>p;
    p--;
    auto get=[&](int t)->int{
        int ans=0;
        int l=0,r=n-1;
        while(l<=r){
            if(ans&1){
                while(l<n&&a[l]==1-t){
                    l++;
                }
                while(r>=0&&a[r]==1-t){
                    r--;
                }
            }else{
                while(l<n&&a[l]==t){
                    l++;
                }
                while(r>=0&&a[r]==t){
                    r--;
                }
            }
            l=min(l,p);
            r=max(r,p);
            if(l<r){
                ans++;
                continue;
            }
            if(l==r){
                assert(l==p);
                if(ans&1){
                    if(a[p]==1-t){
                        return ans;
                    }else{
                        ans++;
                    }
                }else{
                    if(a[p]==t){
                        return ans;
                    }else{
                        ans++;
                    }
                }
            }
        }
        return ans;
    };
    // cout<<min(get(0),get(1));
    cout<<get(a[p]);
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