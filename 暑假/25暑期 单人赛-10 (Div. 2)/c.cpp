#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define mii map<int,int>
#define msi map<string,int>
#define all(x) (x).begin(), (x).end()
using namespace std;
int maxint = INT_MAX;// 2147483647
int minint = INT_MIN;// -2147483648
long long maxll = LLONG_MAX;// 9223372036854775807
long long minll = LLONG_MIN;// -9223372036854775808
ll jc(ll n){
    if(n==1||n==0)
    return (ll)1;
    else
    return n*jc(n-1);
}
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
    vector<int>l(n);
    ll sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    ll slc=0;
    vector<int>pre(n+1,0);
    vector<int>t;
    for(int i=0;i<n;i++){
        cin>>l[i];
        slc+=l[i]*a[i];
        pre[i+1]=pre[i]+l[i]*a[i];
        if(!l[i]){
            t.push_back(a[i]);
        }
    }
    sort(all(t));
    bool f=(sum<0);
    vector<int>ans(n,0);
    for(int i=n-1;i>=0;i--){
        if(l[i]){
            ans[i]=a[i];
            sum-=a[i];
        }else if(f){
            ans[i]=t.back();
            sum-=ans[i];
            t.pop_back();
        }else{
            ans[i]=t[0];
            sum-=t[0];
            t.erase(t.begin());
        }
        f|=(sum<0);
    }
    for(auto x:ans){
        cout<<x<<" ";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
        cout<<'\n';
    }
    return 0;
}