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
    vector<pair<int,string>>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }
    int p=0;
    for(int i=0;i<m;i++){
        int c,b;
        cin>>c>>b;
        if(c==a[p].first){
            if(b>p){
                int left=b-p;
                p=n-left;
            }
            else
            p-=b;
        }
        else{
            p+=b;
            if(p>n-1)
            p-=n;
        }
    }
    cout<<a[p].second;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}