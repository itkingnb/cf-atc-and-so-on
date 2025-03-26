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
int a[5]={0};

bool cmp(string aa,string b){
    int x=0,y=0;
    for(int i=0;i<aa.size();i++){
        x+=a[aa[i]-'A'];
    }
    for(int i=0;i<b.size();i++)
        y+=a[b[i]-'A'];
    if(x!=y)
    return x>y;
    else
    return aa<b;
}

void solve(){
    for(int i=0;i<5;i++){
        cin>>a[i];
    }
    vector<string>ans;
    string a="A ",b="B ",c="C ",d="D ",e="E ";
    string temp;
    string ss[]={"ABCDE","BCDE","ACDE","ABDE","ABCE","ABCD","CDE","BDE","ADE","BCE","ACE","BCD","ABE","ACD","ABD","ABC","DE","CE","BE","CD","AE","BD","AD","BC","AC","AB","E","D","C","B","A"};
    for(auto s:ss){
        ans.push_back(s);
    }
    sort(ans.begin(),ans.end(),cmp);
    for(auto s:ans){
        cout<<s<<'\n';
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