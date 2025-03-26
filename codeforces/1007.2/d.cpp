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
        ll l,r;
        cin>>l>>r;
        vector<int>a(n);
        vector<int>pre(n+1,0);
        for(int i=0;i<n;i++){
            cin>>a[i];
            pre[i+1]=pre[i]^a[i];
        }
        if((n&1)==0){
            pre.push_back(pre[n/2]^pre[n]);
            n++;
        }
        if(r<=n){
            cout<<(pre[r]^pre[r-1]);
            return ;
        }
        int ans=0;
        // cout<<pre.size();
        while(r>n){
            r/=2;
            if(r>=n)
                ans^=pre[n];
            if(r&1&&r>n){
                cout<<ans;
                return ;
            }else if(r&1){
                break;
            }
        }
        if(r!=n)
        ans^=pre[r];
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