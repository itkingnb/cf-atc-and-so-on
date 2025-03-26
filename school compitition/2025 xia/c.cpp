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
    int  n;
    cin>>n;
    auto ask=[&](int a,int b,int c)->int{
        int res;
        cout<<"? "<<a<<" "<<b<<" "<<c<<endl;
        cin>>res;
        return res;
    };
    int cnt=95;
    int si=1,sj=1,ei=n,ej=n;
    while(cnt--){
        int mi=(si+ei)>>1,mj=(sj+ej)>>1;
        if(mi==si&&mj==sj){
            break;
        }
        if(ask(si,sj,mi-si+1)){
            if(mi-si+1==1){
                break;
            }else{
                ei=mi;ej=mj;
            }
        }else if(ask(si,mj,ej-mj+1)){
            if(ej-mj+1==1){
                si=si,sj=mj;
                break;
            }else{
                sj=mj;
                ei=mi;
            }
        }else if(ask(mi,sj,mj-sj+1)){
            if(mj-sj+1==1){
                si=mi;
                break;
            }else{
                si=mi;ej=mj;
            }
        }else{
            si=mi,sj=mj;
        }
    }
    if(ask(si,sj,1)){
        cout<<"! "<<si<<" "<<sj<<endl;
    }else if(ask(si+1,sj,1)){
        cout<<"! "<<si+1<<" "<<sj<<endl;
    }else if(ask(si,sj+1,1)){
        cout<<"! "<<si<<" "<<sj+1<<endl;
    }else{
        cout<<"! "<<si+1<<" "<<sj+1<<endl;
    }
    
}

int main(){
    int t=1;
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
        cout<<'\n';
    }
    return 0;
}