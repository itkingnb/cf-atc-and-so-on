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
    int n;
    cin>>n;
    vector<int>ans(n,3);
    ans.back()=6;
    if(n==1||n==3){
        cout<<-1;
        return ;
    }
    ll sum=6;
    for(int i=n-3;i>=0;i-=2){
        ans[i]=3;
        sum+=3;
    }
    int cnt=0;
    for(int i=n-2;i>=0;i-=2){
        sum-=3;
        cnt++;
    }
    int last=0;
    for(int i=n-2;i>=0;i-=2){
        if(sum){
            ans[i]=6;
            sum-=3;
        }
        // last=i;
    }
    for(auto x:ans){
        cout<<x;
    }
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