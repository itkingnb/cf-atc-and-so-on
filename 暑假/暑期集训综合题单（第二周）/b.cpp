// Problem: B. Plus and Multiply
// Contest: Codeforces - Codeforces Round 729 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1542/B
// Memory Limit: 512 MB
// Time Limit: 3000 ms
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
void solve(){
	ll n,a,b;
	cin>>n>>a>>b;
	if(a==1){
		if(n==1||b==1||(n-1)%b==0)
		yes();
		else
		no();
		return;
	}
	for(ll i=1;i<=n;i*=a){
		if((n-i)%b==0){
			yes();
			return;
		}
	}
	no();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
        //cout<<'\n';
    }
    return 0;
}