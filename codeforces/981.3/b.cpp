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
    int pos=n-1;
    vector<array<int,10000>>a(2*n-1);
    for(int i=pos;i<pos+n;i++){
        cin>>a[0][i];
        if(a[0][i]>0){
            a[0][i]=0;
        }else{
            a[0][i]=abs(a[0][i]);
        }
    }
    pos--;
    for(int i=1;i<n;i++){
        a[i]=a[i-1];
        for(int j=pos;j<pos+n;j++){
            cin>>a[i][j];
            if(a[i][j]<0){
                a[i][j]=max(abs(a[i][j]),a[i-1][j]);
            }else{
                a[i][j]=0;
                a[i][j]=max(abs(a[i][j]),a[i-1][j]);
            }
        }
        pos--;
    }
    cout<<accumulate(a[n-1].begin(),a[n-1].end(),0);
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