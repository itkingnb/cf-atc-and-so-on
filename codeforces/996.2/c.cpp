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
    string s;
    cin>>s;
    vector<vector<bool>>vis(n,vector<bool>(m,0));
    vector<vector<ll>>mp(n,vector<ll>(m,0));
    vector<ll>sumh(n,0);
    vector<ll>suml(m,0);
    vector<int>ch(n,0);
    vector<int>cl(m,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mp[i][j];sumh[i]+=mp[i][j];suml[j]+=mp[i][j];
        }
    }
    int i=0,j=0;ch[i]++;cl[j]++;vis[i][j]=1;
    for(auto x:s){
        if(x=='D'){
            i++;
        }else{
            j++;
        }
        vis[i][j]=1;ch[i]++;cl[j]++;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]&&ch[i]==1){
                mp[i][j]=-sumh[i];
                sumh[i]=0;suml[j]+=mp[i][j];
                cl[j]--;ch[i]--;
                vis[i][j]=0;
            }else if(vis[i][j]&&cl[j]==1){
                mp[i][j]-=suml[j];
                suml[j]=0;sumh[i]+=mp[i][j];
                ch[i]--;cl[j]--;
                vis[i][j]=0;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]){
                mp[i][j]-=sumh[i]==0?suml[j]:sumh[i];
            }
            cout<<mp[i][j]<<" ";
        }
        cout<<'\n';
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