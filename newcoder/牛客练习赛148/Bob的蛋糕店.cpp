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
    int n,k;
    cin>>n>>k;
    vector<ll>a(n);
    ll sum1=0,sum2=0;;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum1+=a[i]*(i+1);
        sum2+=a[i];
    }
    auto dfs=[&](auto &&self,int x,ll sum,ll summ,int cnt)->void{
        if(x==n){
            if(cnt==k&&summ*sum1==sum*sum2){
                cout<<"Yes";
                exit(0);
            }
            return ;
        }
        self(self,x+1,sum,summ,cnt);
        self(self,x+1,sum-a[x]*(x+1),summ-a[x],cnt+1);
    };
    dfs(dfs,1,sum1,sum2,0);
    dfs(dfs,1,sum1-a[0],sum2-a[0],1);
    cout<<"No";
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