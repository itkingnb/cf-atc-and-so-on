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
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>a(n),b(m);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    string s;
    cin>>s;
    sort(b.begin(),b.end());
    map<int,int>mp;
    vector<vector<int>>op(2*k+10);
    for(auto x:a){
        int idx=upper_bound(b.begin(),b.end(),x)-b.begin();
        int l=0,r=0;
        if(idx<m){
            r=b[idx]-x;
        }
        idx--;
        if(idx>=0){
            l=b[idx]-x;
        }
        if(l!=0&&-l<=k){
            mp[l]++;
            if(r!=0&&r<=k){
                op[l+k].push_back(r+k);
            }
        }
        if(r!=0&&r<=k){
            mp[r]++;
            if(l!=0&&-l<=k){
                op[r+k].push_back(l+k);
            }
        }
    }
    int ans=n;
    int now=0;
    int lstans=n;
    for(int i=0;i<k;i++){
        if(s[i]=='R'){
            now++;
        }else{
            now--;
        }
        mp[now]=max(0,mp[now]);
        ans-=mp[now];
        mp[now]=0;
        assert(ans>=0);
        assert(ans<=lstans);
        cout<<ans<<" ";
        lstans=ans;
        for(auto x:op[now+k]){
            mp[x-k]--;
        }
        op[now+k].clear();
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