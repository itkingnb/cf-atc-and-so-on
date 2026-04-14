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
vector<array<int,10>>dp(900010);
void init(){
    for(int i=0;i<=9;i++){
        dp[i][i]=1;
    }
    auto cal=[&](int x)->int{
        int res=0;
        while(x){
            res+=x%10;
            x/=10;
        }
        return res;
    };
    for(int i=10;i<=900000;i++){
        dp[i]=dp[cal(i)];
        int x=i;
        while(x){
            dp[i][x%10]++;
            x/=10;
        }
    }
}
void solve(){
    string s;
    cin>>s;
    if(s.size()==1){
        cout<<s;
        return ;
    }
    int sum=0;
    vector<int>cnt(10);
    while(s.size()){
        sum+=s.back()-'0';
        cnt[s.back()-'0']++;
        s.pop_back();
    }
    int idx=0;
    auto check=[&](int x)->bool{
        int tmp=sum;
        for(int i=0;i<10;i++){
            if(dp[x][i]>cnt[i]){
                return 0;
            }
            tmp-=dp[x][i]*i;
        }
        return tmp==x;
    };
    while(1){
        if(check(idx)){
            // cout<<idx;
            break;
        }
        idx++;
    }
    for(int i=9;i>=0;i--){
        cnt[i]-=dp[idx][i];
        // cerr<<i<<" "<<cnt[i]<<endl;
        for(int j=0;j<cnt[i];j++){
            cout<<i;
        }
    }
    auto cal=[&](int x)->int{
        int res=0;
        while(x){
            res+=x%10;
            x/=10;
        }
        return res;
    };
    while(idx>=10){
        cout<<idx;
        idx=cal(idx);
    }
    cout<<idx;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    init();
    for(int i=0;i<t;i++){
        solve();
        cout<<'\n';
    }
    return 0;
}