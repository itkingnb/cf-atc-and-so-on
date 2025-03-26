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
    string s;
    cin>>s;
    vector<array<int,26>>odd(n+1);
    vector<array<int,26>>even(n+1);
    for(int i=0;i<n;i++){
        even[i+1]=even[i];
        odd[i+1]=odd[i];
        if(i&1)//偶数位
        even[i+1][s[i]-'a']++;
        else
        odd[i+1][s[i]-'a']++;
    }
    if(n&1){//要删一个
        int  mx=0;
        for(int i=0;i<n;i++){//遍历要删的
            int mx1=0,mx2=0;
            for(int j=0;j<26;j++){
                mx1=max(mx1,odd[i][j]+even[n][j]-even[i+1][j]);
                mx2=max(mx2,even[i][j]+odd[n][j]-odd[i+1][j]);
            }
            mx=max(mx,mx1+mx2);
        }
        cout<<1+(n-1)-mx;
    }
    else{
        int mx1=0,mx2=0;
        for(int i=0;i<26;i++){
            mx1=max(odd[n][i],mx1);
            mx2=max(even[n][i],mx2);
        }
        cout<<n-mx1-mx2;
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