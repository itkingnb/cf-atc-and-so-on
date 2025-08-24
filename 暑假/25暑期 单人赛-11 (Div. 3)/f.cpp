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
    int t=1;
    int idx=0;
    vector<vector<int>>ans(n,vector<int>(n,0));
    vector<int>hang(n,0),lie(n,0);
    auto make=[&](int x,int y)->void{
        for(int i=x;i<x+4;i++){
            for(int j=y;j<y+4;j++){
                ans[i][j]=idx++;
                hang[x]^=ans[i][j];
                lie[x]^=ans[i][j];
            }
        }
    };
    for(int i=0;i<n;i+=4){
        for(int j=0;j<n;j+=4){
            // cerr<<i<<j<<'\n';
            make(i,j);
        }
    }
    auto check=[&]()->bool{
        return hang[0]==lie[0]&&hang==vector<int>(n,hang[0])&&lie==vector<int>(n,lie[0]);
    };
    assert(check());
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<'\n';
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