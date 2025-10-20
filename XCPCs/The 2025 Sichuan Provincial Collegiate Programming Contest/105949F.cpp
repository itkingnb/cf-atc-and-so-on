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
    string s;
    cin>>s;
    vector<ll>suf(n,0);
    reverse(s.begin(),s.end());
    for(int i=0;i<n;i++){
        if(i){
            suf[i]=suf[i-1]+(s[i]!='1');
        }else{
            suf[i]=(s[i]!='1');
        }
    }    
    reverse(suf.begin(),suf.end());
    reverse(s.begin(),s.end());
    ll ans=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            ans+=suf[i];
        }
    }
    ll pre=0;
    ll now=ans;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            pre++;
        }else if(s[i]=='?'){
            now=now-pre+suf[i]-1;
            ans=max(ans,now);
            pre++;
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