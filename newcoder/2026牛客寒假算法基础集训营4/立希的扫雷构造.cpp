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
int dp[10][10][1<<9][100]; //n m this last
int cal[10][1<<9][1<<9];
int last[10][10][1<<9][100];
void init(){
    memset(dp,-0x3f,sizeof(dp));
    memset(last,-1,sizeof(last));
    auto get2=[&](int len,int x)->int{
        int ans=0;
        vector<int>a(len);
        for(int i=len-1;i>=0;i--){
            a[len-1-i]=(x>>i)&1;
        }
        for(int i=0;i<len;i++){
            if(a[i]){
                continue;
            }
            ans+=(i-1>=0&&a[i-1])+(i+1<len&&a[i+1]);
        }
        return ans;
    };
    auto get=[&](int len,int x,int y)->int{
        vector<vector<int>>a(2,vector<int>(len));
        for(int i=len-1;i>=0;i--){
            a[0][len-1-i]=(x>>i)&1;
            a[1][len-1-i]=(y>>i)&1;
        }
        int dx[]={-1,-1,-1,0,0,1,1,1};
        int dy[]={-1,0,1,-1,1,-1,0,1};
        int ans=0;
        for(int i=0;i<2;i++){
            for(int j=0;j<len;j++){
                if(a[i][j]){
                    continue;
                }
                for(int k=0;k<8;k++){
                    int nx=i+dx[k],ny=j+dy[k];
                    ans+=(nx>=0&&nx<2&&ny>=0&&ny<len&&a[nx][ny]==1);
                }
            }
        }
        ans-=get2(len,x);
        return ans;
    };
    // get(3,2,0);
    for(int i=1;i<=9;i++){
        for(int j=0;j<(1<<i);j++){
            for(int k=0;k<(1<<i);k++){
                cal[i][j][k]=get(i,j,k);
            }
        }
    }

    // cerr<<cal[3][0][2];
    for(int i=1;i<=9;i++){
        for(int j=0;j<(1<<i);j++){
            dp[1][i][j][__builtin_popcount(j)]=get2(i,j);
        }
        for(int j=2;j<10;j++){
            for(int k=0;k<(1<<i);k++){  
                for(int m=__builtin_popcount(k);m<=81;m++){
                    for(int n=0;n<(1<<i);n++){
                        if(dp[j-1][i][n][m-__builtin_popcount(k)]+cal[i][n][k]>dp[j][i][k][m]){
                            dp[j][i][k][m]=dp[j-1][i][n][m-__builtin_popcount(k)]+cal[i][n][k];
                            last[j][i][k][m]=n;
                        }
                    }
                }
            }
        }
    }
}
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    int mx=-1;
    int p=-1;
    vector<int>ans;
    for(int i=0;i<(1<<m);i++){
        if(dp[n][m][i][k]>mx){
            mx=dp[n][m][i][k];
            p=i;
        }
    }
    cout<<mx<<'\n';
    // cerr<<dp[2][3][2][1];
    while(n){
        ans.push_back(p);
        int kk=k-__builtin_popcount(p);
        p=last[n][m][p][k];
        k=kk;
        n--;
    }
    while(ans.size()){
        auto x=ans.back();
        ans.pop_back();
        for(int i=m-1;i>=0;i--){
            ((x>>i)&1)?cout<<'*':cout<<'.';
        }
        cout<<'\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    init();
    for(int i=0;i<t;i++){
        solve();
        // cout<<'\n';
    }
    return 0;
}