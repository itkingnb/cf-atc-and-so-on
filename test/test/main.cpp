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
	cout<<"Yes";
}
void no(){
	cout<<"No";
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
ll mod=998244353;
ll ans[(int)2e5+10];
ll pre[(int)2e5+10];
void init(){
	ans[1]=1;
	for(int i=2;i<2e5+10;i++){
		ans[i]=ans[i-1]*2;
		ans[i]%=mod;
	}
	for(int i=1;i<2e5+10;i++){
		pre[i]=ans[i]+pre[i-1];
		pre[i]%=mod;
	}
}
void solve(){	
	int n;
	cin>>n;
	ll mx=0;
	for(int i=1;i<=n;i++){
		mx+=abs(n-i+1-i);
	}
	cout<<mx/2+1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t=1;
	cin>>t;
	init();
	for(int i=0;i<t;i++){
		solve();
		cout<<'\n';
	}
	return 0;
}