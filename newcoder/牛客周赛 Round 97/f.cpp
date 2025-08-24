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
ll mod=998244353;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int>b(m);
    ll ans=1;
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    int i=0,j=0;
    while(i<m){
        while(a[j]!=b[i]){
            if(a[j]>b[i]){
                cout<<0;
                return ;
            }
            j++;
        }
        ll cnt=0;
        if(i+1!=m){
            j++;
            while(a[j]!=b[i+1]){
                if(a[j]>b[i+1]&&a[j]>b[i]){
                    cout<<0;
                    return ;
                }
                if(a[j]<b[i]&&a[j]<b[i+1]){
                    cnt++;
                }else if(a[j]>b[i+1]){
                    cnt=0;
                }else if(a[j]>b[i]){
                    break;
                }
                j++;
            }
        }
        ans=ans*(cnt+1)%mod;
        i++;
    }
    for(j;j<n;j++){
        if(a[j]>b.back()){
            cout<<0;
            return ;
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