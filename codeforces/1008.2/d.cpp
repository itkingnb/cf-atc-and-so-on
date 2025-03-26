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
    int n;
    cin>>n;
    vector<vector<string>>op(n,vector<string>(4));
    for(int i=0;i<n;i++){
        for(int j=0;j<4;j++){
            cin>>op[i][j];
        }
    }
    ll ans=0;
    ll res=1;
    // auto dfs=[&](auto&& self,int x)->void{
    //     if(x==n){
    //         ans=max(ans,res);
    //         return ;
    //     }
    //     if(op[x][0]==op[x][2]){
    //         if(op[x][0]=='+')
    //             res+=max(op[x][1]-'0',op[x][3]-'0');
    //         else
    //             res*=max(op[x][1]-'0',op[x][3]-'0');
    //         self(self,x+1);
    //     }else{
    //         if(op[x][0]=='+'){
    //             res+=op[x][1]-'0';
    //             self(self,x+1);
    //             res-=op[x][1]-'0';
    //             res*=op[x][3]-'0';
    //             self(self,x+1);
    //         }else{
    //             res+=op[x][3]-'0';
    //             self(self,x+1);
    //             res-=op[x][3]-'0';
    //             res*=op[x][1]-'0';
    //             self(self,x+1);
    //         }
    //     }
    // };
    function<void(int)>dfs;
    dfs=[&](int x)->void {
        if (x==n) {
            ans=max(ans, res);
            return;
        }

        if (op[x][0]==op[x][2]) { 
            if (op[x][0]=="+") {
                res+=max(stoi(op[x][1]),stoi(op[x][3]));
            } else {
                res*=max(stoi(op[x][1]), stoi(op[x][3]));
            }
            dfs(x + 1); // Recurse
        } else {
            if (op[x][0]=="+") {
                res += stoi(op[x][1]);
                dfs(x + 1);
                res -= stoi(op[x][1]); 
                res *= stoi(op[x][3]);
                dfs(x + 1);
                res /= stoi(op[x][3]); 
            } else {
                res+=stoi(op[x][3]);
                dfs(x + 1);
                res-=stoi(op[x][3]); 
                res*=stoi(op[x][1]);
                dfs(x + 1);
                res/=stoi(op[x][1]); 
            }
        }
    };
    dfs(0);
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