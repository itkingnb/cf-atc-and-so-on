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
    int n;
    cin>>n;
    vector<int>a(2*n);
    vector<vector<int>>aa(1e6+10);
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        aa[x].push_back(i);
        aa[y].push_back(i);
    }
    // sort(all(x));
    vector<int>stk;
    vector<bool>vis(n+10,false);
    bool f1=0,f2=0;
    vector<bool>close(n+10,0);
    bool f3=0;
    int open=0;
    vector<int>cnt(n+10,0);
    for(int i=1;i<1e6+10;i++){
        for(auto x:aa[i]){
            if(!vis[x]){
                if(f2){
                    no();
                    return ;
                }
                cnt[x]=open;
                open++;
                f1=1;
                stk.push_back(x);
                vis[x]=1;
            }else{
                if(!f3&&stk.back()==x){
                    no();
                    return ;
                }else{
                    stk.push_back(x);
                    close[x]=1;
                    open--;
                    if(cnt[x]-open>=2){
                        no();
                        return ;
                    }
                }
            }
        }
        // f3=0;
        while(stk.size()&&close[stk.back()]){
            stk.pop_back();
            f3=1;
        }
        if(stk.size()==0&&f1){
            f2=1;
        }
    }
    yes();
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