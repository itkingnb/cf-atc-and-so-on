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
    cout<<"YES\n";
}
void no(){
    cout<<"NO\n";
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
    ll n,m,k;
    cin>>n>>m>>k;
    n--;
    vector<ll>mx(n+1);
    int d=1;
    mx[1]=1;
    for(int i=2;i<=n;i++){
        mx[i]=mx[i-1]+d;
        d++;
    }
    vector<int>vis(m+1);
    ll mm=m;
    for(int i=n;i>=1;i--){
        mx[i]=min(mx[i],m);
        m--;
    }
    if(k<(1+n)*(n)/2||k>accumulate(mx.begin(),mx.end(),0LL)){
        no();
        return ;
    }
    map<int,int>mp;
    ll left=k-(1+n)*(n)/2;
    for(int i=n;i>=1;i--){
        ll mn=min(mx[i]-i,left);
        left-=mn;
        mx[i]=mn+i;
        vis[mx[i]]=1;
        mp[mx[i]]=i;
    }
    assert(left==0);
    yes();
    // for(auto [x,y]:mp){
    //     cout<<y<<" "<<y+1<<" "<<x<<'\n';
    // }
    m=mm;
    // int v = 1;
    // while (v <= m && vis[v]) {
    //     v++;
    // }
    // for (int i = 2; v <= m; i++) {
    //     for (int j = 0; j < i - 1 && v <= m; j++) {
    //         cout << j + 1 << " " << i + 1 << " " << v << "\n";
    //         v++;
    //         while (v <= m && vis[v]) {
    //             v++;
    //         }
    //     }
    // }
    int p=1,q=3;
    for(int i=1;i<=m;i++){
        if(vis[i]){
            cout<<mp[i]<<" "<<mp[i]+1<<" "<<i<<'\n';
            continue;
        }
//         assert(p<=n+1&&q<=n+1);
        cout<<p<<" "<<q<<" "<<i<<'\n';
        p++;
        if(q-p==1){
            q++;
            p=1;
        }
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
        // cout<<'\n';
    }
    return 0;
}