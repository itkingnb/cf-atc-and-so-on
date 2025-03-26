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
int n,q;
int x,y;
string a[200010];
bool check(int x,int y){
    if(a[x][0]==a[y][0]||a[x][0]==a[y][1]||a[x][1]==a[y][0]||a[x][1]==a[y][1])
    return true;
    return false;
}
void solve(){
    
    map<string,vector<int>>mp;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mp[a[i]].push_back(i);
    }
    while (q--)
    {
        cin>>x>>y;
        if(x>y)
        swap(x,y);
        if(check(x,y)){
            cout<<abs(x-y)<<'\n';
            continue;
        }
        int ans=1e9;
        for(auto m:a[x]){
            for(auto n:a[y]){
                string s;
                s+=m;
                s+=n;
                if(m>n)
                swap(s[0],s[1]);
                auto it=lower_bound(mp[s].begin(),mp[s].end(),x);
                if(it!=mp[s].end()&&*it<y){
                    ans=y-x;
                    goto out;
                }
                if(it!=mp[s].begin()){
                    it--;
                    ans=min(ans,x+y-2*(*it));
                }
                auto ti=upper_bound(mp[s].begin(),mp[s].end(),y);
                if(ti!=mp[s].end())
                ans=min(ans,2*(*ti)-x-y);
            }
        }
        out:
        ans==1e9?cout<<"-1"<<'\n':cout<<ans<<'\n';
    }  
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
        //cout<<'\n';
    }
    return 0;
}