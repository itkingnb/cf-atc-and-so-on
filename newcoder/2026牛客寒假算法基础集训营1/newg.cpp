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
//uniform_int_distribution<ll> r1(l, r);
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
    ll l,r;
    cin>>l>>r;
    if(l==r){
        string s=to_string(l);
        reverse(s.begin(),s.end());
        bool ok=0;
        for(int i=0;i<s.size();i++){
            if(ok){
                cout<<s[i];
            }else if(s[i]!='0'){
                cout<<s[i];
                ok=1;
            }
        }
        return ;
    }
    auto get=[&](ll x)->ll{
        string s=to_string(x);
        while(s.size()&&s.back()=='0') s.pop_back();
        reverse(s.begin(),s.end());
        return stoll(s);
    };
    ll base=1;
    ll ans=0;
    ans=max(get(l),get(r));
    while(1){
        while(r>=l&&(r/base)%10!=9){
            r-=base;
        }
        if(r<l){
            break;
        }
        ans=max(ans,get(r));
        base*=10;
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