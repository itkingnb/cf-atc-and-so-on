#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
using namespace std;
int maxint = INT_MAX;// 2147483647
int minint = INT_MIN;// -2147483648
long long maxll = LLONG_MAX;// 9223372036854775807
long long minll = LLONG_MIN;// -9223372036854775808
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
void yes(){
	cout<<"Yes";
}
void no(){
	cout<<"No";
}
ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}
ll lcm(ll a,ll b){
	return (a*b)/gcd(a,b);
}
ll qpow(ll a, ll k, ll p=maxll)
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
ll mod;
int n=2;
struct matrix 
{
    ll a[3][3];
    matrix(){memset(a,0,sizeof(a));}
}A,res;
matrix operator*(matrix &x,matrix &y){
    matrix ans;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                ans.a[i][j]=(ans.a[i][j]+x.a[i][k]*y.a[k][j])%mod;
            }
        }
    }
    return ans;
}
void qpow(ll k){
    for(int i=1;i<=n;i++) res.a[i][i]=1;
    while (k){
        if(k&1) res=res*A;
        A=A*A;
        k>>=1;
    }
}
void solve(){
	ll l,r,k;
	cin>>mod>>l>>r>>k;
	ll ans=0;
	for(ll i=1;i*i<=r;i++){
		ll x=r/i;
		if(r/i-(l-1)/i>=k){
			ans=max(ans,i);
		}
		if(r/x-(l-1)/x>=k){
			ans=max(ans,x);
		}
	}
	// cerr<<ans;
	A.a[1][1]=0;A.a[1][2]=1;A.a[2][1]=1;A.a[2][2]=1;
	qpow(ans-1);
	cout<<(res.a[1][1]+res.a[2][1])%mod;

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t=1;
	// cin>>t;
	for(int i=0;i<t;i++){
		solve();
		cout<<'\n';
	}
	return 0;
}