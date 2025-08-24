#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define mii map<int,int>
#define msi map<string,int>
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
ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}
ll lcm(ll a,ll b){
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
    int a,b,x;
    cin>>a>>b>>x;
    int xx=x;
    vector<int>ans;
    bool f=0;
    if(b<a){
        f=1;
        swap(a,b);
    }
    int idx=1;
    while(x>1){
        ans.push_back(1);
        ans.push_back(0);
        a--;
        b--;
        x=xx-(2*idx-1);
        idx++;
    }
    if(x==1){
        for(int i=0;i<a;i++){
            ans.push_back(0);
        }
        for(int i=0;i<b;i++){
            ans.push_back(1);
        }
    }else{
        for(int i=0;i<a;i++){
            ans.push_back(0);
        }
        reverse(all(ans));
        for(int i=0;i<b;i++){
            ans.push_back(1);
        }
        reverse(all(ans));
    }
    for(int i=0;i<ans.size();i++){
        if(f){
            cout<<(1-ans[i]);
        }else{
            cout<<ans[i];
        }
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