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
    int n;
    cin>>n;
    int a[120][120];
    vector<vector<int>>pre(n+1,vector<int>(n+1,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            pre[i+1][j+1]=-pre[i][j]+pre[i][j+1]+pre[i+1][j]+a[i][j];
        }
    }
    int maxn=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int q=i+1;q<=n;q++){
        	    for(int w=j+1;w<=n;w++){
        		int tmp=pre[q][w]-pre[i][w]-pre[q][j]+pre[i][j];//以得公式
                maxn=max(maxn,tmp);//贪心
                }
            }
        }
    }
    cout<<maxn;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}