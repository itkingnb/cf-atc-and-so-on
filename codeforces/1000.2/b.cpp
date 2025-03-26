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
    cout<<"Yes\n";
}
void no(){
    cout<<"No\n";
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
    int n,r,l;
    cin>>n>>l>>r;
    vector<ll>a(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    r++;
    ll sum1=accumulate(a.begin()+l,a.begin()+r,0LL);
    ll sum2=sum1;
    sort(a.begin(),a.begin()+l);
    sort(a.begin()+l,a.begin()+r,greater<ll>());
    sort(a.begin()+r,a.end());
    int idx=1;
    int lll=l;
    while(idx<l&&lll<r&&a[idx]<a[lll]){
        sum1-=a[lll++];
        sum1+=a[idx++];
    }
    lll=l;
    idx=r;
    while(idx<=n&&lll<r&&a[idx]<a[lll]){
        sum2-=a[lll++];
        sum2+=a[idx++];
    }
    cout<<min(sum1,sum2);
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