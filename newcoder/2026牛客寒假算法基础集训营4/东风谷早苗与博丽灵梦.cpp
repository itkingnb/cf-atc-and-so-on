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
#define int ll
int ex_gcd(int a,int b,int &x,int &y){
    if(b==0){
        x=1,y=0;
        return a;
    }
    int x1,y1,d;
    d=ex_gcd(b,a%b,x1,y1);
    x=y1; y=x1-a/b*y1;
    return d;
}
#define lll __int128_t
lll gcd(lll a,lll b){
    return b?gcd(b,a%b):a;
}
lll lcm(lll a,lll b){
    return (a*b)/gcd(a,b);
}
void solve(){
    int  x,a,s;
    cin>>x>>a>>s;
    int xx,yy;
    int d=ex_gcd(a,s,xx,yy);
    if(x%d){
        no();
        return ;
    } 
    lll ansx=(lll)x/d*xx,ansy=(lll)x/d*yy;
    // cout<<ansx<<" "<<ansy;
    lll tt=lcm((lll)a,(lll)s);
    lll t=(ansy-ansx)/(tt/a+tt/s);
    auto change=[&](lll t)->pair<lll,lll>{
        return {ansx+t*tt/a,ansy-t*tt/s};
    };
    vector<pair<lll,lll>>ans;
    // if(min(change(t).first,change(t).second)>=0){
    //     ans.push_back(change(t));
    // }
    // t--;
    // if(min(change(t).first,change(t).second)>=0){
    //     ans.push_back(change(t));
    // }
    // t+=2;
    // if(min(change(t).first,change(t).second)>=0){
    //     ans.push_back(change(t));
    // }
    for(int i=t-100;i<=t+100;i++){
        if(min(change(i).first,change(i).second)>=0){
            ans.push_back(change(i));
        }
    }
    if(!ans.size()){
        no();
        return ;
    }
    yes();
    cout<<'\n';
    sort(ans.begin(),ans.end(),[](pair<lll,lll>aa,pair<lll,lll>bb){
        return max(aa.first,aa.second)<max(bb.first,bb.second);
    });
    cout<<(ll)ans[0].first<<" "<<(ll)ans[0].second;

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