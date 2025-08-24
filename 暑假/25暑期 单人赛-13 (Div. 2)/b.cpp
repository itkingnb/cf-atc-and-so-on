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
    cout<<"Yes\n";
}
void no(){
    cout<<"No\n";
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
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n-1;i++){
        bool f1=0,f2=0;
        int ans1=-1,ans2=-1;
        for(int j=i-1;j>=0;j--){
            if(a[j]<a[i]){
                f1=1;
                ans1=j+1;
            }
        }
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                f2=1;
                ans2=j+1;
            }
        }
        if(f1&&f2){
            yes();
            cout<<ans1<<" "<<i+1<<" "<<ans2<<'\n';
            return ;
        }
    }
    no();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
        // cout<<'\n';
    }
    return 0;
}