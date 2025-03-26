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
    vector<vector<int>>d(n+2,vector<int>(n+2));
    for(int i=0;i<m;i++){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        //y1--;
        for(int j=x1;j<=x2;j++){
            d[j][y1]++;
            d[j][y2+1]--;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            d[i][j]+=d[i][j-1];
            cout<<d[i][j]<<" ";
        }
        cout<<'\n';
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}