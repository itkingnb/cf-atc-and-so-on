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
    int a,b;
    cin>>a>>b;
    if(b==0){
        cout<<string(a,'0');
        return ;
    }
    if(b<=(a+1)){
        if(b>a){
            cout<<1;
            b--;
        }
        int t=a/(b+1);
        int left=a%(b+1);
        for(int i=0;i<left;i++){
            cout<<string(t+1,'0')<<1;
            a-=t+1;
        }
        for(int i=0;i<b-(left);i++){
            cout<<string(t,'0')<<1;
            a-=t;
        }
        cout<<string(a,'0');
    }else{
        swap(a,b);
        if(b>a){
            cout<<0;
            b--;
        }
        int t=a/(b+1);
        int left=a%(b+1);
        for(int i=0;i<left;i++){
            cout<<string(t+1,'1')<<0;
            a-=t+1;
        }
        for(int i=0;i<b-(left);i++){
            cout<<string(t,'1')<<0;
            a-=t;
        }
        cout<<string(a,'1');
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