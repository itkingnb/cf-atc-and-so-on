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
    cout<<"Yes";
}
void no(){
    cout<<"No";
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
    ll n,x,k;
    cin>>n>>x>>k;
    string s;
    cin>>s;
    ll l=0,r=0;
    ll t=(ll)1e18+10;
    ll reset=n+10;
    for(int i=0;i<n;i++){
        if(s[i]=='L'){
            l++;
        }else{
            r++;
        }
        if(l==r){
            t=min(t,(ll)i+1);
        }
        if(x>0){
            if(l-r==x){
                reset=min((ll)i+1,reset);
            }
        }else if(x<0){
            if(r-l==abs(x)){
                reset=min((ll)i+1,reset);
            }
        }
    }
    ll ans=0;
    if(x){
        if(reset==n+10){
            cout<<ans;
        }else{
            k-=reset;
            ans++;
            ans+=k/t;
            cout<<ans;
        }
    }else{
        cout<<k/t;
    }

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