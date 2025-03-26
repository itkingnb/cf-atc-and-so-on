#// LUOGU_RID: 155311611
#include<bits/stdc++.h>
// #define int long long
using namespace std;
const int N=1e6+10,mod=1e9+7;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll,ll> PII;
ll n,m,k,x,y;
ll a[N],dp[N];
ll cnt[N];
ll s[N];



void __(){
	scanf("%lld",&n);
	for(int i=0;i<=n;i++) cnt[i]=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		cnt[a[i]]++;
	}
	ll mex=0;
	while(cnt[mex]){
		cnt[mex]--;
		mex++;
	}
	
	ll tot=0;
	tot=(mex-1)*mex/2;
	tot+=(n-mex)*mex;
	tot+=cnt[0];
	printf("%lld\n",tot);
}

signed main(){
	int _;
	cin>>_;
	while(_--){
		__();
	}
	
}
