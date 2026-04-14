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
    vector<string>s(n);
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    vector<vector<char>>ans(n,vector<char>(m,'N'));
    // int c0=0,c1=0;
    map<char,int>mp;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            mp[s[i][j]]++;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mp[s[i][j]]==1){
                cout<<'N';
            }else{
                cout<<'Y';
            }
        }
        cout<<'\n';
    }
    // int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
    // auto check=[&](int x,int y)->bool{
    //     return x>=0&&y>=0&&x<n&&y<m;
    // };
    // int cnt=0;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         for(int k=0;k<4;k++){
    //             int nx=i+dx[k],ny=j+dy[k];
    //             if(check(nx,ny)&&s[nx][ny]==s[i][j]){
    //                 ans[i][j]='Y';
    //                 break;
    //             }
    //         }
    //         if(ans[i][j]=='N'){
    //             cnt++;
    //         }
    //     }
    // }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(ans[i][j]=='Y'||!(cnt&1)){
    //             cout<<'Y';
    //         }else{
    //             cout<<ans[i][j];
    //         }
    //     }
    //     cout<<'\n';
    // }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
        // cout<<'\n';  
    }
    return 0;
}