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
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    auto check1=[&](string ss)->int{
        int res=0;
        for(int i=1;i<n;i++){
            if(ss[i]==')'&&ss[i-1]=='('){
                res++;
            }
        }
        return res;
    };
    auto check2=[&](string ss)->int{
        int d=0;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            if(ss[i]=='('){
                mp[d++]++;
            }else{
                mp[--d]++;
            }
        }
        int res=0;
        for(auto [x,y]:mp){
            if(y==2){
                res++;
            }else{
                break;
            }
        }
        return res;
    };
    cerr<<check1(s)<<" "<<check1(t)<<" "<<check2(s)<<" "<<check2(t)<<endl;
    if(check1(s)==check1(t)&&check2(s)==check2(t)){
        yes();
    }else{
        no();
    }
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