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
    int n,k;
    cin>>n>>k;
    string s1;
    cin>>s1;
    s1='#'+s1+'#';
    vector<int>dp(n+1,1e9);
    // vector<int>next(k,n+10);
    vector<vector<int>>next(n+1,vector<int>(k,n+1));

    dp[n]=1;next[n-1][s1[n]-'a']=n;
    for(int i=n-1;i>=0;i--){
        next[i]=next[i+1];
        next[i][s1[i+1]-'a']=i+1;
        for(int j=0;j<k;j++){
            if(next[i][j]>n){
                dp[i]=1;
                break;
            }else{
                dp[i]=min(dp[i],dp[next[i][j]]+1);
            }
        }
    }
    // next[0]=next[1];
    // next[0][s1[1]-'a']=1;
    int q;
    cin>>q;
    while(q--){
        string s2;
        cin>>s2;
        int i=0,j=0;
        while(i<s2.size()&&j<=n){
            j=next[j][s2[i]-'a'];
            if(s1[j]==s2[i])
            i++;
        }
        if(i<s2.size()){
            cout<<0<<'\n';
            continue;
        }
        // j--;
        cout<<dp[j]<<'\n';
    }
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