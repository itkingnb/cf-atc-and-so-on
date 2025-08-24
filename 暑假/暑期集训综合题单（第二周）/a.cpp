// Problem: D. a-Good String
// Contest: Codeforces - Codeforces Round 656 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1385/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
int ans(string s,char a){
	if(s.size()==1){
		if(s[0]==a)
		return 0;
		return 1;
	}
	int a1=0,a2=0;
	string ss(s.substr(0,s.size()/2)),sss(s.substr(s.size()/2,s.size()/2));
	a1=ss.size()-count(ss.begin(),ss.end(),a)+ans(sss,a+1);
	a2=sss.size()-count(sss.begin(),sss.end(),a)+ans(ss,a+1);
	return min(a1,a2);
}
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    cout<<ans(s,'a');
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