#include<iostream>
#include<cmath>
#include<string>
#include <algorithm>
#include<vector>
#include<queue>
#include<map>
#include<numeric>
#include<cstring>
#define pii pair<int,int>
#define mii map<int,int>
#define msi map<string,int>
#define ll long long
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
    cout<<"Yes\n";
}
void no(){
    cout<<"No\n";
}
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
int lcm(int a,int b){
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
    vector<int>len(n);
    vector<vector<int>>a(n);
    vector<pii>adj;
    int mx=0,ta=0;
    for(int i=0;i<n;i++){
        cin>>len[i];
        a[i].resize(len[i]);
        for(int j=0;j<len[i];j++){
            cin>>a[i][j];
        }
        int target=0;
        int u=0,v=0,cnt=0;
        sort(a[i].begin(),a[i].end());
        for(int j=0;j<len[i];j++){
            if(a[i][j]==target)
            target++;
            else if(a[i][j]>target){
                cnt++;
                if(cnt==1)
                u=target;
                if(cnt==2){
                    adj.push_back({u,target});
                    ta=max(ta,target);
                    break;
                }
                target++;
                j--;
            }
        }
        if(!cnt){
            if(target-1!=a[i][len[i]-1])
            adj.push_back({target-1,target});
            else
            adj.push_back({target,target+1});
            ta=max(ta,target+1);            
        }
        else if(cnt==1){
            adj.push_back({u,target});
            ta=max(ta,target);
        }
    }
    //map<int,int>mp;
    vector<vector<int>>e(ta+1);
    vector<int>cnt(ta+1);
    for(auto [x,y]:adj)
        e[x].push_back(y)/*,cout<<x<<" "<<y<<'\n'*/;
    vector<int>dp(ta+1);
    int mxx=0;
    for(int i=ta;i>=0;i--){
        dp[i]=i;
        for(auto y:e[i]){
            dp[i]=max(dp[y],dp[i]);
            cnt[i]++;
            mxx=max(mxx,i);
        }
        if(cnt[i]>1) mxx=max(mxx,dp[i]);
        //cout<<dp[i]<<" ";
    }
    //cout<<mxx;
    ll ans=0;
    for(int i=0;i<=min(ta,m);i++){
        ans+=(ll)max({dp[i],mxx});
    }
    ans+=(ll)(m+min(ta,m)+1)*(m-min(ta,m))/2;
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