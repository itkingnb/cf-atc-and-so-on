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
    vector<vector<long double>>p(n+1,vector<long double>(100010,0.0));
    vector<vector<int>>a(n+1);
    long double ans=0.0;
    for(int i=1;i<=n;i++){
        int m;
        cin>>m;
        a[i].resize(m);
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            p[i][a[i][j]]+=1.0/m;
        }
        sort(all(a[i]));
        a[i].erase(unique(a[i].begin(),a[i].end()),a[i].end());
        for(int j=1;j<i;j++){
            long double res=0.0;
            vector<int>t;
            for(auto x:a[i]){
                if(p[j][x]){
                    t.push_back(x);
                }
            }
            int k=t.size();
            for(auto x:t){
                res+=p[i][x]*p[j][x];
            }
            ans=max(ans,res);
        }
    }
    cout<<fixed<<setprecision(12)<<ans;
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