#include<iostream>
#include<cmath>
#include<string>
#include <algorithm>
#include<vector>
#include<queue>
#include<map>
#include<numeric>
#include<cstring>
#define pii pair<int,int>
#define mii map<int,int>
#define msi map<string,int>
#define ll long long
#define int ll
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
    cout<<"Yes\n";
}
void no(){
    cout<<"No\n";
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
bool flag;
int target,n,tt;
void check(vector<int> a,vector<int> b,vector<int> c){
    int al=1,ar,bl,br,cl,cr=n;
    for(int i=1;i<n+1;i++){
        if(a[i]-a[0]>=target){
            ar=i;
            break;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(c[n]-c[i]>=target){
            cl=i+1;
            break;
        }
    }
    bl=ar+1;
    br=cl-1;
    if(b[br]-b[bl-1]>=target){
        switch(tt){
            case 2:swap(bl,cl),swap(br,cr);break;
            case 3:swap(al,bl),swap(ar,br);break;
            case 4:swap(al,bl),swap(ar,br),swap(al,cl),swap(ar,cr);break;
            case 5:swap(al,cl),swap(ar,cr),swap(al,bl),swap(ar,br);break;
            case 6:swap(al,cl),swap(ar,cr);break;
        }
        cout<<al<<" "<<ar<<" "<<bl<<" "<<br<<" "<<cl<<" "<<cr;
        flag=true;
    }
}
void solve(){
    cin>>n;
    flag=false;
    tt=0;
    vector<int>a(n),b(n),c(n),prea(n+1,0),preb(n+1,0),prec(n+1,0);
    for(int i=0;i<n;i++){
    cin>>a[i];
    prea[i+1]=prea[i]+a[i];        
    }
    for(int i=0;i<n;i++){
    cin>>b[i];
    preb[i+1]=preb[i]+b[i];        
    }
    for(int i=0;i<n;i++){
    cin>>c[i];
    prec[i+1]=prec[i]+c[i];        
    }
    target=ceil(prea[n]/3.0);
    if(!flag){
        tt++;
        check(prea,preb,prec);
    }
    if(!flag){
        tt++;
        check(prea,prec,preb);
    }    
    if(!flag){
        tt++;
        check(preb,prea,prec);
    }    
    if(!flag){
        tt++;
        check(preb,prec,prea);
    }    
    if(!flag){
        tt++;
        check(prec,prea,preb);
    }    
    if(!flag){
        tt++;
        check(prec,preb,prea);
    }
    if(!flag)
    cout<<"-1";
}

signed main(){
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