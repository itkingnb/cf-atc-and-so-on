#include<iostream>
#include<cmath>
#include<string>
#include <algorithm>
#include<vector>
#include<queue>
#include<map>
#include<numeric>
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
    int k=0;
    int ii=0;
    int m=0;
    int flag=1;
    vector<int>a(n,0);
    for(int&i:a)
        cin>>i;
    for(int i=0;i<n-1;i++){
        int p=gcd(a[i],a[i+1]);
        if(p>=k)
        k=p;
        else
        {
            flag=0;
            ii=i;
            break;
        }
    }
    if(flag){
        yes();
        return;
    }
    for(int cnt=0;cnt<3;cnt++){
    vector<int>b(n,0);
    b=a;
    k=0;
    flag=1;
    b.erase(b.begin()+ii-1+cnt,b.begin()+ii+cnt);
    for(int i=0;i<n-2;i++){
        int p=gcd(b[i],b[i+1]);
        if(p>=k)
        k=p;
        else{
            flag=0;
            break;
        }
    }
        if(flag){
            yes();
            return;
        }
}
    no();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
        //cout<<'\n';
    }
    return 0;
}