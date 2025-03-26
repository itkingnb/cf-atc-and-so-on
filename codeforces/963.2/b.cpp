#include<iostream>
#include<cmath>
#include<string>
#include <algorithm>
#include<vector>
#include<queue>
#include<map>
#include<numeric>
#include<cstring>
#define pii pair<int,int>
#define mii map<int,int>
#define msi map<string,int>
#define ll long long
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
    int cnto=0;
    int cntj=0;
    vector<ll>oushu;
    vector<ll>jishu;
    for(int i=0;i<n;i++){
        ll m;
        cin>>m;
        if(m&1){
            cntj++;
            jishu.push_back(m);
        }
        else
        {
            cnto++;
            oushu.push_back(m);
        }
    }
    if(cntj==n||cnto==n){
        cout<<0;
        return;
    }
    sort(jishu.begin(),jishu.end(),greater<ll>());
    sort(oushu.begin(),oushu.end(),greater<ll>());
    int ans=0;
    ll max1=jishu[0];
    while (oushu.size())
    {
        if(max1>oushu[oushu.size()-1]){
        max1=max1+oushu[oushu.size()-1];
        ans++;
        oushu.pop_back();
        continue;
        }
        max1=max1+oushu[0];
        ans++;
    }
    cout<<ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
        cout<<'\n';
    }
    return 0;
}