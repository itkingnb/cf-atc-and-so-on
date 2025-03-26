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
ll get(ll x){
    ll ans=0;
    while(x){
        ans+=x%10;
        x/=10;
    }
    return ans;
}
int gt(int x){
    int ans=0;
    while(x%10==0){
    ans++;
    x/=10;
    }
    return ans;
}
void solve(){
    int n;
    ll sum=0;
    cin>>n;
    int cnt=0,cc=0;
    vector<ll>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]){
            cc=max(gt(a[i]),cc);
        }
        if(a[i]==0)
        cnt++;
        sum+=get(a[i]);
    }
    if(cnt+cc>=2&&sum%9==0){
        cout<<"Yes";
    }else{
        cout<<"No";
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