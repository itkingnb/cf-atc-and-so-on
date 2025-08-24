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
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    vector<pii>a(26,{-1,-1});
    int idx=0;
    for(int i=0;i<n;i++){
        if(s[i]=='?'){
            continue;
        }
        idx=i;
        if(a[s[i]-'a'].first==-1){
            a[s[i]-'a'].first=i;
        }else{
            a[s[i]-'a'].second=i;
        }
    }
    int cnt=0;
    for(int i=0;i<m;i++){
        if(a[i].first!=-1&&a[i].second!=-1){
            for(int j=a[i].first+1;j<a[i].second;j++){
                if(s[j]=='?'){
                    s[j]='a'+i;
                }
            }
        }
    }
    for(int i=0;i<m;i++){
        if(a[i].first==-1&&a[i].second==-1){
            ;
        }else{
            continue;
        }
        for(int j=0;j<n;j++){
            if(s[j]=='?'){
                s[j]='a'+i;
                idx=j;
                break;
            }
        }
    }
    for(int i=0;i<m;i++){
        a[i].first=a[i].second=-1;
    }
    for(int i=idx-1;i>=0;i--){
        if(s[i]=='?'){
            s[i]=s[i+1];
        }
    }
    for(int i=idx+1;i<n;i++){
        if(s[i]=='?'){
            s[i]=s[i-1];
        }
    }
    // cout<<s;
    for(int i=0;i<n;i++){
        if(a[s[i]-'a'].first==-1){
            a[s[i]-'a'].first=i;
        }else{
            a[s[i]-'a'].second=i;
        }
    }
    ll ans=0;
    for(auto x:a){
        if(x.first>=0&&x.second>=0)
            ans+=x.second-x.first;
    }
    cout<<ans<<'\n';
    cout<<s;
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