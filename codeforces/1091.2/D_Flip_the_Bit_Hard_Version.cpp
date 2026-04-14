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
ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}
ll lcm(ll a,ll b){
    return (a*b)/gcd(a,b);
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
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int>p(k);
    set<int>s;
    for(int i=0;i<k;i++){
        cin>>p[i];
        p[i]--;
        s.insert(p[i]);
    }
    if(n==k){
        cout<<0;
        return ;
    }
    int end=n-1;
    while(p.size()&&p.back()==end){
        p.pop_back();
        end--;
    }
    auto get=[&](int t)->int{
        int ans=0;
        int l=0,r=n-1;
        while(l<=r){
            if(ans&1){
                while(l<n&&a[l]==1-t){
                    l++;
                }
                while(r>=0&&a[r]==1-t){
                    r--;
                }
            }else{
                while(l<n&&a[l]==t){
                    l++;
                }
                while(r>=0&&a[r]==t){
                    r--;
                }
            }
            l=min(l,p[0]);
            r=max(r,p[0]);
            if(l<r){
                ans++;
                continue;
            }
            if(l==r){
                assert(l==p[0]);
                if(ans&1){
                    if(a[p[0]]==1-t){
                        return ans;
                    }else{
                        ans++;
                    }
                }else{
                    if(a[p[0]]==t){
                        return ans;
                    }else{
                        ans++;
                    }
                }
            }
        }
        return ans;
    };
    if(p.size()==1){
        cout<<get(a[p[0]]);
        return ;
    }
    int t=a[p[0]];
    int l=0,r=n-1;
    int ans=0;
    while(l<p[0]||r>p.back()){
        if(ans&1){
            while(l<p[0]&&a[l]==1-t){
                l++;
            }
            while(r>p.back()&&a[r]==1-t){
                r--;
            }
        }else{
            while(l<p[0]&&a[l]==t){
                l++;
            }
            while(r>p.back()&&a[r]==t){
                r--;
            }
        }
        if(l<p[0]||r>p.back()){
            ans++;
        }
    }
    // vector<int>vec;
    vector<int>cnt(n);
    // vector<int>lst;
    int lst=-1;
    int can=0;
    for(int i=l;i<=r;i++){
        if(ans&1){
            if(a[i]==1-t){
                if(can&1){
                    can--;
                }
            }else if(can>=1){
                // can=max(0,can-2);/
                if(can%2==0){
                    can=max(0,can-1);
                }
            }else{
                if(s.count(i)){
                    cnt[i]=1;
                    can=cnt[i];
                }else{
                    cnt[lst]+=2;
                    can+=2;
                }
            }
        }else{
            if(a[i]==t){
                if(can&1){
                    can--;
                }
            }else if(can>=1){
                // can=max(0,can-2);
                if(can%2==0){
                    can=max(0,can-1);
                }
            }else{
                if(s.count(i)){
                    cnt[i]=1;
                    can=cnt[i];
                }else{
                    cnt[lst]+=2;
                    can+=2;
                }
            }
        }
        if(s.count(i)) lst=i;
    }
    cout<<ans+accumulate(cnt.begin(),cnt.end(),0);

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