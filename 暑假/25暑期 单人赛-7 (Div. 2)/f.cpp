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
    string s[2];
    cin>>s[0]>>s[1];
    bool f1=0,f2=0;
    int last=2;
    bool f=0;
    int ans=0;
    int pre=0;
    for(int i=0;i<n;i++){
        if(f){
            ans++;
            pre++;
        }
        if(s[0][i]=='*'&&s[1][i]=='*'){
            f=1;
            pre=0;
            if(last==2){
                ans++;
            }else if(last==1){
                last=2;
                ans++;
            }else{
                ans++;
                last=2;
            }
        }else if(s[0][i]=='*'){
            f=1;
            pre=0;
            if(last==1){
                ans++;
                last=2;
                continue;
            }
            last=0;
        }else if(s[1][i]=='*'){
            f=1;
            pre=0;
            if(last==0){
                ans++;
                last=2;
                continue;
            }
            last=1;
        }
    }
    cout<<ans-pre;
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