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
    ll l,r;
    cin>>l>>r;
    vector<int>ans(15,0);
    auto check=[&](bool f)->bool{
        vector<int>t=ans;
        if(!f){
            t.back()=1;
        }
        ll now=0;
        ll tmp=1;
        bool ok=0;
        for(int i=0;i<15;i++){
            if(t[i]||ok){
                now+=tmp*t[i];
                tmp*=10;
                ok=1;
            }
        }
        return now<=r;
    };
    if(l==r){
        string s=to_string(l);
        reverse(s.begin(),s.end());
        bool ok=0;
        for(int i=0;i<s.size();i++){
            if(ok){
                cout<<s[i];
            }else if(s[i]!='0'){
                cout<<s[i];
                ok=1;
            }
        }
        return ;
    }
    for(int i=0;i<15;i++){
        for(int j=9;j>=0;j--){
            ans[i]=j;
            if(check(i==14)){
                break;
            }
        }
    }
    bool ok=0;
    for(int i=0;i<15;i++){
        if(ans[i]||ok){
            cout<<ans[i];
            ok=1;
        }
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