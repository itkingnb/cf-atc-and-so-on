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
    cout<<"Yes\n";
}
void no(){
    cout<<"No\n";
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
    string s;
    cin>>s;
    int n=s.size();
    int ans=n-2;
    // int a[10]={0};
    vector<int>a(10,n);
    for(int i=0;i<n;i++){
        a[s[i]-'0']--;
    }
    for(int i=0;i<10;i++){
        ans=min(ans,a[i]);
    }
    for(int i=0;i<100;i++){
        string t=to_string(i);
        if(i<10){
            t='0'+t;
        }
        int idx=0;
        int res=0;
        for(int j=0;j<s.size();j++){
            if(s[j]==t[idx]){
                if(idx==1){
                    res+=2;
                    idx=0;
                }else{
                    idx++;
                }
            }
        }
        ans=min(ans,n-res);
    }
    cout<<ans;
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