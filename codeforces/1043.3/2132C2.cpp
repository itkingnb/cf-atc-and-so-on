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
    vector<ll>t;
    ll tp=3;
    int idx=1;
    vector<ll>cost;
    t.push_back(1);
    cost.push_back(3);
    while(tp<=n){
        t.push_back(tp);
        cost.push_back(qpow(3,idx+1)+idx*qpow(3,idx-1));
        idx++;
        tp*=3;
    }
    int cnt=0;
    vector<ll>ans(40,0);
    while(n){
        auto x=upper_bound(t.begin(),t.end(),n)-t.begin();
        x--;
        cnt++;
        ans[x]++;
        n-=t[x];
    }
    if(cnt>k){
        cout<<-1;
        return ;
    }
    k-=cnt;
    ll res=0;
    // cout<<cost[0]<<" ";
    for(int i=39;i>0;i--){
        ll mx=min(k/2,ans[i]);
        ans[i]-=mx;
        k-=2*mx;
        ans[i-1]+=3*mx;
        if(ans[i]){
            res+=ans[i]*cost[i];
        }
    }
    res+=ans[0]*cost[0];
    cout<<res;
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