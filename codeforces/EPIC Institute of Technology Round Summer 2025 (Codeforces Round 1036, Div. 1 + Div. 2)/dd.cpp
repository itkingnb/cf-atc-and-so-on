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
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    vector<int>t;
    vector<int>cnt(n+1,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    int mx=1;
    int sum=cnt[1];
    for(int i=2;i<=n;i++){
        if(sum>=k){
            break;
        }else{
            sum+=cnt[i];
            mx++;
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]<=mx){
            t.push_back(a[i]);
        }
    }
    int l=0,r=t.size()-1;
    while(l<=r){
        if(t[l]==t[r]){
            l++;
            r--;
        }else if(t[l]==mx&&sum>=k){
            sum--;
            l++;
        }else if(t[r]==mx&&sum>=k){
            sum--;
            r--;
        }else{
            no();
            return ;
        }
    }
    yes();
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