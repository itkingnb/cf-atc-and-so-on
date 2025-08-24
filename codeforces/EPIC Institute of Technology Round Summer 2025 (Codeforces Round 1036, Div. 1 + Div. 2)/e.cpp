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
int tt=0;
void solve(){
    tt++;
    int n;
    cin>>n;
    vector<ll>a(n);
    vector<ll>ans1,ans2;
    ll sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    // if(tt==4002){
    //     cout<<1<<'\n';
    //     for(int i=0;i<n;i++){
    //         cout<<a[i]<<' ';
    //     }
    //     return ;
    // }
    // ll pre=0
    vector<ll>pre(n,0);
    for(int i=0;i<n;i++){
        pre[i]=(i?pre[i-1]+a[i]:a[i]);
        if(pre[i]*2==sum){
            cout<<1<<'\n';
            for(int j=0;j<n;j++){
                cout<<a[j]<<' ';
            }
            return ;
        }
    }
    vector<ll>suf(n,0);
    for(int i=n-1;i>=0;i--){
        suf[i]=(i==n-1?a[i]:suf[i+1]+a[i]);
    }
    bool ok=0;
    bool re=0;
    for(int i=1;i<n;i++){
        if(pre[i-1]>suf[i]&&(pre[i-1]-suf[i])%2==0&&!ok){
            auto x=lower_bound(pre.begin(),pre.end(),(pre[i-1]-suf[i])/2)-pre.begin();
            if(pre[i-1]-pre[x]>=(pre[i-1]-suf[i])/2){
                ok=1;
                ll ta=(pre[i-1]-suf[i])/2;
                ll ta2=(pre[i-1]-suf[i])/2;
                for(int j=0;j<n;j++){
                    if(j<=x){
                        ll mx=min(ta,a[j]);
                        ans1.push_back(mx);
                        a[j]-=mx;
                        ans2.push_back(a[j]);
                        ta-=mx;
                    }else if(j<i){
                        ll mx=min(ta2,a[j]);
                        ans1.push_back(mx);
                        a[j]-=mx;
                        ans2.push_back(a[j]);
                        ta2-=mx;
                    }else{
                        ans1.push_back(0);
                        ans2.push_back(a[j]);
                    }
                }
            }
        }
    }
    if(!ok){
        reverse(a.begin(),a.end());
        reverse(suf.begin(),suf.end());
        reverse(pre.begin(),pre.end());
        swap(suf,pre);
        re=1;
        for(int i=1;i<n;i++){
            if(pre[i-1]>suf[i]&&(pre[i-1]-suf[i])%2==0&&!ok){
                auto x=lower_bound(pre.begin(),pre.end(),(pre[i-1]-suf[i])/2)-pre.begin();
                assert(x>=0&&i-1>=0&&i>=0);
                if(pre[i-1]-pre[x]>=(pre[i-1]-suf[i])/2){
                    ok=1;
                    ll ta=(pre[i-1]-suf[i])/2;
                    ll ta2=(pre[i-1]-suf[i])/2;
                    for(int j=0;j<n;j++){
                        if(j<=x){
                            ll mx=min(ta,a[j]);
                            ans1.push_back(mx);
                            a[j]-=mx;
                            ans2.push_back(a[j]);
                            ta-=mx;
                        }else if(j<i){
                            ll mx=min(ta2,a[j]);
                            ans1.push_back(mx);
                            a[j]-=mx;
                            ans2.push_back(a[j]);
                            ta2-=mx;
                        }else{
                            ans1.push_back(0);
                            ans2.push_back(a[j]);
                        }
                    }
                }
            }
        }
    }
    if(ok){
        cout<<2<<'\n';
        if(re){
            reverse(ans1.begin(),ans1.end());
            reverse(ans2.begin(),ans2.end());
        }
        for(int i=0;i<n;i++){
            cout<<ans1[i]<<" \n"[i==n-1];
        }
        for(int i=0;i<n;i++){
            cout<<ans2[i]<<" \n"[i==n-1];
        }
    }else{
        cout<<-1;
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