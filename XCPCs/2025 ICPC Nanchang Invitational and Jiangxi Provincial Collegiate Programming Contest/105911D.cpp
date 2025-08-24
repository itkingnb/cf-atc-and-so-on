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
    int n,a,b,c;
    cin>>n;
    cin>>a>>b>>c;
    map<int,int>mp1,mp2,mp3;
    for(int i=0;i<n;i++){
        int aa,bb,cc,dd,ee,ff;
        cin>>aa>>bb>>cc>>dd>>ee>>ff;
        if(aa>dd){
            swap(aa,dd);
        }
        if(bb>ee){
            swap(bb,ee);
        }
        if(cc>ff){
            swap(cc,ff);
        }
        mp1[aa]++;
        mp1[dd+1]--;
        mp2[bb]++;
        mp2[ee+1]--;
        mp3[cc]++;
        mp3[ff+1]--;
    }
    int ans=0;
    int res=0;
    for(auto [x,y]:mp1){
        res+=y;
        ans=max(ans,res);
    }
    res=0;
    for(auto [x,y]:mp2){
        res+=y;
        ans=max(ans,res);
    }
    res=0;
    for(auto [x,y]:mp3){
        res+=y;
        ans=max(ans,res);
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