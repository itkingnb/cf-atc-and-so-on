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
#define int long long
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
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first; 
}
void solve(){
    int n,k;
    cin>>n>>k;
    vector<pii>a(n);
    for(int i=0;i<n;i++)
    cin>>a[i].first;
    for(int i=0;i<n;i++)
    cin>>a[i].second;
    sort(a.begin(),a.end(),cmp);
    int ans=0;
    for(int i=0;i<n;i++){
        if(a[i].second==1){
            int p;
            if(i<(n>>1))
            p=n>>1;
            else
            p=(n-2)>>1;
            int res=a[i].first+k+a[p].first;
            ans=max(ans,res);
        }
    }
    int l=0,r=1e9+65;
    int maxmid=0;
    while(l<r){
        int kk=k;
        int cnt=0;
        int mid=(l+r)>>1;
        for(int i=n-2;i>=0;i--){
            if(a[i].first>=mid)
            cnt++;
            else{
                if(a[i].second==1){
                    kk-=(mid-a[i].first);
                    if(kk>=0)
                    cnt++;
                    else
                    break;
                }
            }
        }
        if(cnt>=((n+1)/2)){
            maxmid=max(mid,maxmid);
            l=mid+1;
        }
        else
        r=mid;
    }
    ans=max(ans,a[n-1].first+maxmid);
    cout<<ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
        cout<<'\n';
    }
    return 0;
}