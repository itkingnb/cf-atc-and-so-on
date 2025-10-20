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
    vector<int>a(n);
    cout<<0<<" ";
    int mx=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    int g=a[0];
    vector<int>mp(mx+1,0);
    for(int i=1;i*i<=a[0];i++){
        if(a[0]%i==0){
            mp[a[0]/i]++;
            mp[i]++;
        }
        if(i*i==a[0]){
            mp[i]--;
        }
    }
    // if()
    // int nxt=0;
    int ans=0;
    for(int i=1;i<n;i++){

        for(int j=1;j*j<=a[i];j++){
            if(a[i]%j==0){
                mp[j]++;
                mp[a[i]/j]++;
            }
            if(j*j==a[i]){
                mp[j]--;
            }
            if(mp[j]!=i+1){
                ans=max(ans,mp[j]);
            }
            if(mp[a[i]/j]!=i+1){
                ans=max(ans,mp[a[i]/j]);
            }
        }
        if(gcd(g,a[i])<g){
            ans=max(ans,mp[g]);
        }
        // ans=max(ans,nxt);
        g=gcd(g,a[i]);
        cout<<ans<<" ";
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