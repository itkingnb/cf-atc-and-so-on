    #include<iostream>
    #include<cmath>
    #include<string>
    #include <algorithm>
    #include<vector>
    #include<queue>
    #include<map>
    #include<numeric>
    #include<cstring>
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
        int n,mod;
        cin>>n>>mod;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        string s;
        cin>>s;
        int i=0,j=s.size()-1;
        int last=0;
        for(int k=0;k<n;k++){
            if(s[k]=='L'){
                if(k!=+n-1)
                last=i+1;
                i++;
            }else{
                if(k!=n-1)
                last=j-1;
                j--;
            }
        }
        vector<int>ans(n);
        ans[n-1]=a[last]%mod;
        int now=a[last];
        i=j=last;
        for(int k=s.size()-2;k>=0;k--){
            if(s[k]=='R'){
                j++;
                now*=a[j];
                now%=mod;
                ans[k]=now;
            }else{
                i--;
                now*=a[i];
                now%=mod;
                ans[k]=now;
            }
        }
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
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