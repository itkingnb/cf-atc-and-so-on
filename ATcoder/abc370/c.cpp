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
bool cmp(string a,string b){
    for(int i=0;i<a.size();i++){
        if(a[i]!=b[i])
        return a[i]<b[i];
    }
    return 0;
}
void solve(){
    string s,t;
    cin>>s>>t;
    vector<string>ans;
    vector<int>tmp;
    for(int i=0;i<s.size();i++){
        if(s[i]!=t[i]&&s[i]>t[i]){
            swap(s[i],t[i]);
            ans.push_back(s);
        }else if(s[i]!=t[i]){
            tmp.push_back(i);
        }
    }
    for(int i=tmp.size()-1;i>=0;i--){
        swap(s[tmp[i]],t[tmp[i]]);
        ans.push_back(s);
    }
    //sort(ans.begin(),ans.end(),cmp);
    cout<<ans.size()<<'\n';
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<'\n';
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    //cin>>t;
    for(int i=0;i<t;i++){
        solve();
    }
    return 0;
}