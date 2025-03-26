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
    cout<<"Yes";
}
void no(){
    cout<<"No";
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
    vector<vector<int>>big(n+1,vector<int>(n+1,0));
    // vector<int>small(n+1,0);
    vector<vector<int>>small(n+1,vector<int>(n+1,0));
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ansi=1,ansj=1;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            big[i+1][j+1]=big[i+1][j]+(a[j]>a[i]);
            small[i+1][j+1]=small[i+1][j]+(a[j]<a[i]);
            if(small[i+1][j+1]-big[i+1][j+1]>small[ansi][ansj]-big[ansi][ansj]){
                ansi=i+1,ansj=j+1;
            }
        }
    }
    cout<<ansi<<' '<<ansj;
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