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
    int n;
    cin>>n;
    vector<int>a(n+1),b(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=2*a[i];
    }
    int l,r;
    auto check=[&](int x)->bool{
        int i=l,j=i+x,ei=i+x;
        while (i!=ei&&j<=r)
        {
            if(a[j]>=b[i]){
                i++;j++;
            }else{
                j++;
            }
        }
        return i==ei;
    };
    int q;
    cin>>q;
    while(q--){
        cin>>l>>r;
        int lo=0,hi=(r-l)>>1;
        while(lo<=hi){
            int mid=(lo+hi)>>1;
            if(check(mid)) lo=mid+1;
            else hi=mid-1;
        }
        check(lo)?cout<<lo<<'\n':cout<<lo-1<<'\n';
    }   
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    //cin>>t;
    for(int i=0;i<t;i++){
        solve();
        cout<<'\n';
    }
    return 0;
}