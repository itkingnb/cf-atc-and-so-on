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
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    s='$'+s;
    vector<int>pre(n+10,-1);
    vector<int>suf(n+10,-1);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1];
        if(s[i]=='#'){
            pre[i]=i;
        }
    }
    for(int i=n;i>=1;i--){
        suf[i]=suf[i+1];
        if(s[i]=='#'){
            suf[i]=i;
        }
    }
    int x,y;
    while(q--){
        cin>>x>>y;
        if(x>y){
            swap(x,y);
        }
        int xx=suf[x];
        int yy=pre[y];
        cout<<xx<<" "<<yy<<endl;
        if(xx==-1||yy==-1||xx>y||yy<x){
            cout<<0<<'\n';
        }else{
            cout<<max(0,yy-xx+1)<<'\n';
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    // cin>>t;
    for(int i=0;i<t;i++){
        solve();
        cout<<'\n';
    }
    return 0;
}