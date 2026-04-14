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
    cout<<"no answer";
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
using ld=long double;
void solve(){
    ll xa,ya,xb,yb;
    cin>>xa>>ya>>xb>>yb;
    if(xa==xb&&ya==yb){
        no();
        return ;
    }
    // if(xa==xb){
    //     cout<<xa+4.0/(abs(ya-yb));
    //     return ;
    // }
    if(ya==yb){
        if(abs(ya)*abs(xa-xb)!=4){
            no();
        }else{
            cout<<1;
        }
        return ;
    }
    cout<<(ld)(4.0-xa*yb+xb*ya)/(ya-yb);
    // if(ya>yb){
    //     swap(xa,xb);
    //     swap(ya,yb);
    // }
    // ld x=4.0/(ya+abs(ya-yb));
    // if(xb>xa){
    //     x=xa+x;
    // }else{
    //     x=xa-x;
    // }
    // ld y=ya;
    
    // for(ld i=-4010;i<=4010;i+=0.0001){
    //     ld x1=xa-i,x2=xb-i,y11=ya,y22=yb;
    //     if(abs(abs(x1*y22-x2*y11)/2.0-2)<=0.001){
    //         cout<<i;
    //         return ;
    //     }
    // }
    // no();
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    // cin>>t;
    for(int i=0;i<t;i++){
        solve();
        // cout<<'\n';
    }
    return 0;
}