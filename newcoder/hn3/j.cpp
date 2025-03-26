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
    int n,m;
    cin>>n>>m;
    vector<vector<int>>b(n,vector<int>(n));
    vector<vector<int>>a(m,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>b[i][j];
        }
    }    
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<=m-n;i++){
        for(int j=0;j<=m-n;j++){
            int ans=0;
            for(int ii=0;ii<n;ii++){
                for(int jj=0;jj<n;jj++){
                    ans+=b[ii][jj]*a[i+ii][j+jj];
                }
            }
            cout<<ans<<" ";
        }
        cout<<'\n';
    }
}
int main(){
    solve();
    return 0;
}