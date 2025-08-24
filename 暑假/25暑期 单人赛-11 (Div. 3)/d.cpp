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
    vector<vector<int>>a(n);
    vector<pii>t(n);
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        a[i].resize(k);
        int now=0,mn=0;
        for(int j=0;j<k;j++){
            cin>>a[i][j];
            mn=max(mn,a[i][j]+1-j);
            // if(now>a[i][j]){
            //     now++;
            // }else{
            //     mn=a[i][j]+1-j;
            //     now=mn+1;
            // }
        }
        t[i].first=mn;t[i].second=k;
    }
    sort(all(t));
    int l=0,r=1e9+10;
    int ans=0;
    auto check=[&](int x)->bool{
        for(int i=0;i<n;i++){
            if(x>=t[i].first){
                x+=t[i].second;
            }else{
                return 0;
            }
        }
        return 1;
    };  
    check(43);
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<ans;
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