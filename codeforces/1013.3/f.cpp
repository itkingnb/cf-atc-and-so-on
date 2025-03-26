#include<bits/stdc++.h>
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
    cout<<"Yes";
}
void no(){
    cout<<"No";
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
    ll n,m,d;
    cin>>n>>m>>d;
    vector<string>s(n);
    vector<vector<vector<ll>>>mem(n,vector<vector<ll>>(m,vector<ll>(2,-1)));
    vector<vector<bool>>vis(n,vector<bool>(m,0));
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    ll mod=998244353;
    ll res=0;
    ll ans=0;
    auto check=[&](int x,int y,int nx,int ny){
        return x>=0&&x<n&&y>=0&&y<m&&s[x][y]=='X'&&(nx-x)*(nx-x)+(ny-y)*(ny-y)<=d*d;
    };
    auto dfs=[&](auto&& dfs,int x,int y,int use,ll res)->ll{
        // ll tt=res;
        // cerr<<x<<y<<' '<<res<<endl;
        if(mem[x][y][use]!=-1){
            return (res+mem[x][y][use])%mod;
        }else if(x==0){
            res=1;
            if(use==1){
                return mem[x][y][use]=1;
            }else{
                // mem[x][y][0]=0;
                for(int i=1;i<=2000;i++){
                    if(check(x,y-i,x,y)){
                        res+=dfs(dfs,x,y-i,1,0);
                        res%=mod;
                    }
                    if(check(x,y+i,x,y)){
                        res+=dfs(dfs,x,y+i,1,0);
                        res%=mod;
                    }
                }
                res%=mod;
            }
            mem[x][y][use]=res;
            return res-1;
        }
        if(use==1){
            for(int i=1;i<=2000;i++){
                if(check(x-1,y-i,x,y)){
                    res+=dfs(dfs,x-1,y-i,0,0);
                    res%=mod;
                }
                if(check(x-1,y+i,x,y)){
                    res+=dfs(dfs,x-1,y+i,0,0);
                    res%=mod;
                }
            }
        }else{
            for(int i=1;i<=2000;i++){
                if(check(x-1,y-i,x,y)){
                    res+=dfs(dfs,x-1,y-i,0,0);
                    res%=mod;
                }
                if(check(x-1,y+i,x,y)){
                    res+=dfs(dfs,x-1,y+i,0,0);
                    res%=mod;
                }
                if(check(x,y-i,x,y)){
                    res+=dfs(dfs,x,y-i,1,1);
                    res%=mod;
                }
                if(check(x,y+i,x,y)){
                    res+=dfs(dfs,x,y+i,1,1);
                    res%=mod;
                }
            }
        }
        if(check(x-1,y,x,y)){
            res+=dfs(dfs,x-1,y,0,0);
            res%=mod;
        }
        return mem[x][y][use]=res;
    };
    for(int i=0;i<m;i++){
        if(s[n-1][i]=='X'){
            ans+=dfs(dfs,n-1,i,0,0);
            cerr<<ans<<" ";
            ans%=mod;
        }
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