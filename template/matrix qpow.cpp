#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k;
const int mod=1e9+7;
struct matrix 
{
    ll a[101][101];
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
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>A.a[i][j];
        }
    }
    qpow(k);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cout<<res.a[i][j]<<" ";
        cout<<'\n';
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}