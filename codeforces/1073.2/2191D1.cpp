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
    string s;
    cin>>s;
    vector<int>suf(n);
    for(int i=n-2;i>=0;i--){
        suf[i]=suf[i+1]+(s[i+1]==')');
    }
    bool ok=0;
    string ans;
    int now=0;
    for(int i=0;i<n;i++){
        if(s[i]=='('&&now+1<=suf[i]){
            now++;
            ans.push_back('(');
        }else if(s[i]==')'){
            if(ok&&now>0){
                now--;
                ans.push_back(')');
            }else if(suf[i]>=now){
                continue;
            }else{
                ans.push_back(')');
                now--;
            }
        }
        if(ans.back()=='('&&s[(int)ans.size()-1]==')'){
            ok=1;
        }
    }
    cout<<ans<<endl;
    auto check=[&](string x)->bool{
        for(int i=0;i<x.size();i++){
            if(s[i]==x[i]){
                continue;
            }else if(s[i]==')'&&x[i]=='('){
                return 1;
            }else{
                return 0;
            }
        }
        return 0;
    };
    !check(ans)?cout<<-1:cout<<(int)ans.size();
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