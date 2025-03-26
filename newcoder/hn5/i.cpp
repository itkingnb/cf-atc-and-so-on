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
    vector<int>a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    sort(all(a));
    ll cnt=0;
    ll ans=0;
    if(n==1){
        cout<<1;
        return;
    }
    if(n&1){
        int mid=a[n/2];
        for(int i=0;i<n;i++)
        cnt+=abs(a[i]-mid);
        ans=max(ans,cnt);
        mid=a[n/2-1];
        cnt=0;
        for(int i=0;i<n;i++)
        cnt+=abs(a[i]-mid);
        ans=max(ans,cnt);        
    }else{
        int mid=a[n/2];
        for(int i=0;i<n;i++)
        cnt+=abs(a[i]-mid);
        ans=max(ans,cnt);
    }
    cout<<++ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    //cin>>t;
    for(int i=0;i<t;i++){
        solve();
        //cout<<'\n';
    }
    return 0;
}