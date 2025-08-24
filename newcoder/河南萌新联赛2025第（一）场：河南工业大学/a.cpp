#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod=998244353;
#define N 5010
int S[N][N];
int cal(int nn, int mm)
{
    S[0][0] = 1;
    for(int n = 1; n <= nn; n ++)
        for(int k = 1; k <= mm; k++)
            S[n][k] = (S[n - 1][k - 1] + (ll)k * S[n - 1][k] % mod) % mod;
    return S[nn][mm];
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<ll>f(m+1,1);  
    for(int i=1;i<=m;i++){
        f[i]=f[i-1]*i%mod;
    }
    cout<<(cal(n,m)*f[m])%mod;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
        cout<<'\n';
    }
    
}