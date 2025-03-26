#include<bits/stdc++.h>
#define pii pair<int,int>
#define mii map<int,int>
#define msi map<string,int>
#define ll long long
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
    vector<ll>a(n);
    map<ll,int>mp;
    int pmx=-1;
    ll mx=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]++;
        if(mp[a[i]]==2){
            mx=max(mx,a[i]);
        }
    }
    mp[mx]-=2;
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    for(int i=0;i<a.size();i++){
        if(a[i]==mx){
            pmx=i;
            break;
        }
    }
    if(!mp[mx]){
        a.erase(a.begin()+pmx,a.begin()+pmx+1);
    }
    for(int i=0;i<a.size();i++){
        if((i&&a[i]-a[i-1]<2*mx)){
            cout<<mx<<" "<<mx<<" "<<a[i]<<" "<<a[i-1];
            return ;
        }else if(mp[a[i]]>=2){
            cout<<mx<<" "<<mx<<" "<<a[i]<<" "<<a[i];
            return ;
        }
    }
    cout<<-1;
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