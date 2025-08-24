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
    int n;
    cin>>n;
    vector<int>a(n);
    vector<int>ans(n);
    int mx=0,ii=-1;
    map<int,vector<int>>mp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]].push_back(i);
        mx=max(a[i],mx);
        if(a[i]==-1){
            ii=i;
        }
    }
    mx=1;
    int k=n;
    bool ok=false;
    int cnt=0;
    int lo=1,hi=n;
    if(mp[1].size()==n-1){
        ok=true;
        ans[ii]=1;
        if(ii!=0&&ii!=n-1){
            for(int i=0;i<n;i++){
                if(a[i]!=-1&&!ans[i]){
                    ans[i]=hi--;
                }
                if(a[n-i-1]!=-1&&!ans[n-i-1]){
                    ans[n-i-1]=hi--;
                }
            }
        }else{
            if(ii==0){
                lo++;
            }
            for(int i=0;i<n;i++){
                if(a[i]!=-1&&!ans[i]){
                    ans[i]=(ii==0?lo++:hi--);
                }
            }
        }
        cnt=n-1;
    }
    while(cnt!=n-1){
        int l=0,r=mp[mx].size()-1;
        while(l<r){
            if(mx&1){
                ans[mp[mx][r--]]=hi--;
                ans[mp[mx][l++]]=hi--;
                cnt+=2;
            }else{
                ans[mp[mx][r--]]=lo++;
                ans[mp[mx][l++]]=lo++;
                cnt+=2;
            }
        }
        if(l==r){
            cnt++;
            if(mx&1){
                ans[mp[mx][l]]=hi--;
            }else{
                ans[mp[mx][l]]=lo++;
            }
        }
        // if((mx&1)==0){
        //     reverse(mp[mx].begin(),mp[mx].end());
        // }
        // for(auto x:mp[mx]){
        //     if(mx&1)
        //         ans[x]=hi--;
        //     else
        //         ans[x]=lo++;
        //     cnt++;
        // }
        mx++;
    }
    if(!ok)
    ans[ii]=hi;
    for(auto x:ans){
        cout<<x<<" ";
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