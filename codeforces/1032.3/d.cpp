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
    vector<int>a(n+1),b(n+1);
    vector<pii>mp(90);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mp[a[i]].first=0;
        mp[a[i]].second=i;
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
        mp[b[i]].first=1;
        mp[b[i]].second=i;
    }
    vector<pii>ans;
    int pa=1,pb=1;
    for(int i=1;i<=2*n;i++){
        if(pa==pb){
            while(mp[i].first!=0||mp[i].second!=pa){
                if(mp[i].first==0){
                    mp[a[mp[i].second-1]].second++;
                    swap(a[mp[i].second],a[mp[i].second-1]);
                    ans.push_back({1,mp[i].second-1});
                    mp[i].second--;
                }else if(mp[i].second!=pa){
                    if(b[mp[i].second-1]<a[mp[i].second]){
                        mp[a[mp[i].second]].first=1;
                        swap(b[mp[i].second],a[mp[i].second]);
                        ans.push_back({3,mp[i].second});
                        mp[i].first=0;
                    }else{
                        mp[b[mp[i].second-1]].second++;
                        swap(b[mp[i].second],b[mp[i].second-1]);
                        ans.push_back({2,mp[i].second-1});
                        mp[i].second--;
                    }
                }else{
                    mp[a[mp[i].second]].first=1;
                    swap(b[mp[i].second],a[mp[i].second]);
                    ans.push_back({3,mp[i].second});
                    mp[i].first=0;
                }
            }
            pa++;
        }else{
            while(!(mp[i].first==0&&mp[i].second==pa)&&!(mp[i].first==1&&mp[i].second==pb)){
                if(mp[i].first==1){
                    mp[b[mp[i].second-1]].second++;
                    swap(b[mp[i].second],b[mp[i].second-1]);
                    ans.push_back({2,mp[i].second-1});
                    mp[i].second--;
                }else{
                    mp[a[mp[i].second-1]].second++;
                    swap(a[mp[i].second],a[mp[i].second-1]);
                    ans.push_back({1,mp[i].second-1});
                    mp[i].second--;
                }
            }
            if(mp[i].first==0){
                pa++;
            }else{
                pb++;
            }
        }
    }
    cout<<ans.size()<<'\n';
    for(auto x:ans){
        cout<<x.first<<" "<<x.second<<'\n';
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