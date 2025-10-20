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
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    vector<int>a(m);
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    vector<int>ans=a;
    int idx=0;
    int now=1;
    if(a[0]==1){
        idx++;
    }
    for(int i=0;i<n;i++){
        if(s[i]=='A'){
            now++;
            ans.push_back(now);
        }else{
            while(idx<m&&((a[idx]<now+1)||(now+1==a[idx]))){
                if(a[idx]<now+1){
                    idx++;
                    continue;
                }
                now++;
            }
            now++;
            ans.push_back(now);
            while(idx<m&&((a[idx]<now+1)||(now+1==a[idx]))){
                if(a[idx]<now+1){
                    idx++;
                    continue;
                }
                now++;
            }
            now++;
        }
    }
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    cout<<ans.size()<<'\n';
    for(auto x:ans){
        cout<<x<<" ";
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