#include<iostream>
#include<cmath>
#include<string>
#include <algorithm>
#include<vector>
#include<queue>
#include<map>
#include<numeric>
#include<cstring>
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
    vector<ll>a(n);
    vector<ll>d1,d2;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==1){
        cout<<1;
        return ;
    }
    for(int i=1;i<n;i+=2){
        d1.push_back(a[i]-a[i-1]);
    }
    sort(d1.begin(),d1.end());
    if(n&1){
        ll ans=1e18;
        for(int i=0;i<n;i++){
            vector<ll>temp(n);
            temp=a;
            temp.erase(temp.begin()+i);
            vector<ll>d;
            for(int j=1;j<n;j+=2){
                d.push_back(temp[j]-temp[j-1]);
            }
            ans=min(ans,*max_element(d.begin(),d.end()));
        }
        cout<<ans;
    }else{
        cout<<d1[d1.size()-1];
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