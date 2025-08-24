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
    int n;
    cin>>n;
    vector<ll>p(n),s(n);
    vector<ll>a(n),b(n);
    vector<bool>fixa(n,0),fixb(n,0);
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    fixa[0]=fixb[0]=1;
    a[0]=p[0];b[0]=s.back();
    for(int i=1;i<n;i++){
        if(p[i]>p[i-1]){
            no();
            return ;
        }else if(p[i]==p[i-1]){
            a[i]=p[i];
        }else if(p[i-1]%p[i]==0){
            a[i]=p[i];
            fixa[i]=1;
        }else{
            no();
            return ;
        }
    }
    reverse(s.begin(),s.end());
    for(int i=1;i<n;i++){
        if(s[i]>s[i-1]){
            no();
            return ;
        }else if(s[i]==s[i-1]){
            b[i]=s[i];
        }else if(s[i-1]%s[i]==0){
            b[i]=s[i];
            fixb[i]=1;
        }else{
            no();
            return ;
        }
    }
    reverse(b.begin(),b.end());
    reverse(fixb.begin(),fixb.end());
    vector<ll>t(n);
    for(int i=0;i<n;i++){
        // if(fixa[i]||fixb[i]){
            
        // }
        t[i]=lcm(a[i],b[i]);
    }
    ll g=0;
    for(int i=0;i<n;i++){
        g=gcd(g,t[i]);
        if(g!=p[i]){
            no();
            return ;
        }
    }
    reverse(t.begin(),t.end());
    g=0;
    for(int i=0;i<n;i++){
        g=gcd(g,t[i]);
        if(g!=s[i]){
            no();
            return ;
        }
    }
    yes();
    // ll g=0;
    // for(int i=0;i<n;i++){
    //     cin>>p[i];
    //     if(!i){
    //         a[i]=p[i];
    //         g=a[i];
    //         fix[i]=1;
    //     }else{
    //         if(g==p[i]){
    //             a[i]=g;
    //         }else{
    //             a[i]=p[i];
    //             fix[i]=1;
    //             g=p[i];
    //         }
    //     }
    // }
    // for(int i=0;i<n;i++){
    //     cin>>s[i];
    // }
    // reverse(s.begin(),s.end());
    // reverse(a.begin(),a.end());
    // reverse(fix.begin(),fix.end());
    // for(int i=1;i<n;i++){
    //     if(s[i-1]%s[i]!=0||p[i-1]%p[i]!=0){
    //         no();
    //         return ;
    //     }
    // }
    // g=0;
    // if(fix[0]){
    //     if(s[0]!=a[0]){
    //         no();
    //         return ;
    //     }
    // }else{
    //     if(s[0]>=a[0]&&s[0]%a[0]==0){
    //         a[0]=s[0];
    //         g=s[0];
    //     }else{
    //         no();
    //         return ;
    //     }
    // }
    // for(int i=1;i<n;i++){
    //     if(gcd(g,a[i])>s[i]){
    //         no();
    //         return ;
    //     }
    //     if(gcd(g,a[i])==s[i]){
    //         g=s[i];
    //         continue;
    //     }else if(fix[i]){
    //         no();
    //         return ;
    //     }else{
    //         g=s[i];
    //         a[i]=lcm(g,a[i]);
    //     }
    // }
    // yes();

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