#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
using namespace std;
int maxint = INT_MAX;// 2147483647
int minint = INT_MIN;// -2147483648
long long maxll = LLONG_MAX;// 9223372036854775807
long long minll = LLONG_MIN;// -9223372036854775808
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
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
ll qpow(ll a, ll k, ll p=maxll)
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
    ll n,k;
    cin>>n>>k;
    vector<bool>vis(n+1,0);
    // if(k<2*n+n-1)
    if(n==1){
        if(k==2){
            cout<<1;
            return ;
        }
        cout<<-1;
        return ;
    }
    if(n==2){
        if(k==5){
            cout<<"1 2";
            return ;
        }
        cout<<-1;
        return ;
    }
    if(k<2*n+n-1||k>n+(1+n)*n/2){
        cout<<-1;
        return ;
    }
    ll left=k-2*n-n+1;
    // cerr<<left<<'\n';
    vector<int>t;
    for(int i=n-2;i>=1;i--){
        if(left>=i){
            t.push_back(i);
            // cout<<i<<" ";
            left-=i;
            vis[i]=1;
        }
    }
    reverse(t.begin(),t.end());
    for(int i=0;i<t.size();i++){
        cout<<t[i]<<" ";
    }
    assert(left==0);
    cout<<n-1<<" ";
    for(int i=1;i<=n-2;i++){
        if(!vis[i]){
            cout<<i<<" ";
        }
    }
    cout<<n;

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