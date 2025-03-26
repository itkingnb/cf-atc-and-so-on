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
int ask(int x,int y){
    cout<<"? "<<x<<" "<<y<<endl;
    int res;
    cin>>res;
    return res;
}
void solve(){   
    int n;
    cin>>n;
    vector<pii>a(n+1);
    vector<bool>vis(n+1,0);
    int cnt=0;
    for(int i=1;i<=n;i++){
        cin>>a[i].first;
        a[i].second=i;
        if(!vis[a[i].first]){
            cnt++;
        }
        vis[a[i].first]=1;
    }
    sort(all(a));
    if(cnt==n){
        int p=ask(a[1].second,a[n].second);
        int q=ask(a[n].second,a[1].second);
        if(p==q&&p>=n-1){
            cout<<"! B"<<endl;
        }else{
            cout<<"! A"<<endl;
        }
    }else{
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                int p=(i==n?ask(i,1):ask(i,n));
                int q=(i==n?ask(i,1):ask(i,n));
                if(p==0&&q==0){
                    cout<<"! A"<<endl;
                }else{
                    cout<<"! B"<<endl;
                }    
                return ;  
            }
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
        // cout<<'\n';
    }
    return 0;
}