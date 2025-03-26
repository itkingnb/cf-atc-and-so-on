#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>>a(n,vector<int>(m));
    vector<vector<int>>pre(n+1,vector<int>(m+1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            pre[i+1][j+1]=pre[i+1][j]+pre[i][j+1]-pre[i][j]+a[i][j];
        }
    }
    int ans=-1e9,ii,jj;
    for(int i=1;i<=n-k+1;i++){
        for(int j=1;j<=m-k+1;j++){
            int aa=i+k-1,bb=j+k-1;
            int res=pre[aa][bb]-pre[aa-k][bb]-pre[aa][bb-k]+pre[i-1][j-1];
            if(res>ans){
                ans=res;
                ii=i;jj=j;
            }
        }
    }
    cout<<ii<<" "<<jj;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}