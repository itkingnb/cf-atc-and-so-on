#include<iostream>
#include<cmath>
#include<string>
#include <algorithm>
#include<vector>
#include<queue>
#include<map>
#include<numeric>
#include<cstring>
#define mii map<int,int>
#define msi map<string,int>
#define ll long long
#define all(x) (x).begin(), (x).end()
using namespace std;
#define pii pair<ll,ll>
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
void solve(){
    int n;
    cin>>n;
    vector<pii>a(n);
    int cl=0,cr=0,cu=0,cd=0;
    int pl=0,pr=0,pu=0,pd=0;
    ll mxl=1e10,mx2l=1e10,mxr=0,mx2r=0,mxu=0,mx2u=0,mxd=1e10,mx2d=1e10;
    map<pii,bool>mp;
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
        mp[a[i]]=1;
        if(mxl==(ll)1e10){
            mxl=a[i].first;
            pl=i;
            cl=1;
        }else{
            if(a[i].first<mxl){
                pl=i;
                mx2l=mxl;
                mxl=a[i].first;
                cl=1;
            }else if(a[i].first==mxl){
                cl++;
            }else{
                mx2l=min(a[i].first,mx2l);
            }
        }
        if(!mxr){
            mxr=a[i].first;
            cr=1;
            pr=i;
        }else{
            if(a[i].first>mxr){
                pr=i;
                mx2r=mxr;
                mxr=a[i].first;
                cr=1;
            }else if(a[i].first==mxr){
                cr++;
            }else{
                mx2r=max(a[i].first,mx2r);
            }
        }
        if(!mxu){
            mxu=a[i].second;
            cu=1;
            pu=i;
        }else{
            if(a[i].second>mxu){
                pu=i;
                mx2u=mxu;
                mxu=a[i].second;
                cu=1;
            }else if(a[i].second==mxu){
                cu++;
            }else{
                mx2u=max(a[i].second,mx2u);
            }
        }
        if(mxd==(ll)1e10){
            pd=i;
            mxd=a[i].second;
            cd=1;
        }else{
            if(a[i].second<mxd){
                pd=i;
                mx2d=mxd;
                mxd=a[i].second;
                cd=1;
            }else if(a[i].second==mxd){
                cd++;
            }else{
                mx2d=min(a[i].second,mx2d);
            }
        }
    }
    ll ans=maxll;
    ans=min(ans,(ll)(mxu-mxd+1)*(mxr-mxl+1));
    if(n==1){
        cout<<1;
        return ;
    }
    if(n==2){
        cout<<2;
        return ;
    }
    // ll l=0,r=0,u=0,d=0;
    // if(cl>=2){
    //     l=mxl;
    // }
    // if(cr>=2){
    //     r=mxr;
    // }
    // if(cu>=2){
    //     u=mxu;
    // }
    // if(cd>=2){
    //     d=mxd;
    // }
    if(cd==1){
        ll templ=mxl,tempr=mxr;
        if(pl==pd&&cl==1){
            mxl=mx2l;
        }
        if(cr==1&&pr==pd){
            mxr=mx2r;
        }
        ll a1=abs(mx2d-mxu)+1;
        if(a1*(abs(mxl-mxr)+1)>=n){
            ans=min(ans,a1*(abs(mxl-mxr)+1));
            mxl=templ;
            mxr=tempr;
        }else{
            for(int i=mxl;i<=mxr;i++){
                for(int j=mx2d;j<=mxu;j++){
                    if(!mp[{i,j}]){
                        ans=min(ans,a1*(abs(mxl-mxr)+1));
                        mxl=templ;
                        mxr=tempr;
                        goto out1;
                    }
                }
            }
            ans=min({ans,a1*(abs(mxl-mxr)+2),(a1+1)*(abs(mxl-mxr)+1)});
            mxl=templ;
            mxr=tempr;
        }
    }
    out1:
    if(cu==1){
        ll templ=mxl,tempr=mxr;
        if(pu==pl&&cl==1){
            mxl=mx2l;
        }
        if(cr==1&&pr==pu){
            mxr=mx2r;
        }
        ll a1=abs(mx2u-mxd)+1;
        if(a1*(abs(mxl-mxr)+1)>=n){
            ans=min(ans,a1*(abs(mxl-mxr)+1));
            mxl=templ;
            mxr=tempr;
        }else{
            for(int i=mxl;i<=mxr;i++){
                for(int j=mxd;j<=mx2u;j++){
                    if(!mp[{i,j}]){
                        ans=min(ans,a1*(abs(mxl-mxr)+1));
                        mxl=templ;
                        mxr=tempr;
                        goto out2;
                    }
                }
            }
            ans=min({ans,a1*(abs(mxl-mxr)+2),(a1+1)*(abs(mxl-mxr)+1)});
            mxl=templ;
            mxr=tempr;
        }
    }
    out2:
    if(cl==1){
        ll tempu=mxu,tempd=mxd;
        if(pl==pd&&cd==1){
            mxd=mx2d;
        }
        if(cu==1&&pl==pu){
            mxu=mx2u;
        }
        ll a1=abs(mx2l-mxr)+1;
        if(a1*(abs(mxu-mxd)+1)>=n){
            ans=min(ans,a1*(abs(mxu-mxd)+1));
            mxu=tempu;
            mxd=tempd;
        }else{
            for(int i=mx2l;i<=mxr;i++){
                for(int j=mxd;j<=mxu;j++){
                    if(!mp[{i,j}]){
                        ans=min(ans,a1*(abs(mxu-mxd)+1));
                        mxu=tempu;
                        mxd=tempd;
                        goto out3;
                    }
                }
            }
            ans=min({ans,a1*(abs(mxu-mxd)+2),(a1+1)*(abs(mxu-mxd)+1)});
            mxu=tempu;
            mxd=tempd;
        }
    }
    out3:
    if(cr==1){
        ll tempu=mxu,tempd=mxd;
        if(pr==pd&&cd==1){
            mxd=mx2d;
        }
        if(cu==1&&pr==pu){
            mxu=mx2u;
        }
        ll a1=abs(mxl-mx2r)+1;
        if(a1*(abs(mxu-mxd)+1)>=n){
            ans=min(ans,a1*(abs(mxu-mxd)+1));
            mxu=tempu;
            mxd=tempd;
        }else{
            for(int i=mxl;i<=mx2r;i++){
                for(int j=mxd;j<=mxu;j++){
                    if(!mp[{i,j}]){
                        ans=min(ans,a1*(abs(mxu-mxd)+1));
                        mxu=tempu;
                        mxd=tempd;
                        goto out4;
                    }
                }
            }
            ans=min({ans,a1*(abs(mxu-mxd)+2),(a1+1)*(abs(mxu-mxd)+1)});
            mxu=tempu;
            mxd=tempd;
        }
    }
    out4:
    cout<<ans;
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