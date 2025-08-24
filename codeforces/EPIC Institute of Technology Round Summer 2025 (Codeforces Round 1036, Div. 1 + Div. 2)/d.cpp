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
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    vector<vector<int>>pos(n+10);
    vector<int>cnt(n+10,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
        cnt[a[i]]++;
        pos[a[i]].push_back(i);
    }
    if(cnt[1]>=k){
        yes();
        return ;
    }
    // set<int>s1,s2;
    // vector<pii>ans;
    // s1.lower_bound(1)-
    int now=0;
    int id=1;
    // while(now<k){
    //     int l=0,r=pos[id].size()-1;
    //     while(l<r){
    //         ans.push_back({pos[id][l],id});
    //         ans.push_back({pos[id][r],id});
    //         now+=2;
    //     }
    //     if(l==r){
    //         ans.push_back({pos[id][l],id});
    //         now++;
    //     }
    // }
    // vector<int>pre(n+1,0);
    // for(int i=1;i<=n;i++){
    //     pre[i]=pre[i-1]+cnt[i];
    // }
    vector<int>vec1,vec2;
    // sort(ans.begin(),ans.end());
    // // for(int i=0,j=ans.size()-1;)
    // int i=0,j=ans.size()-1;
    // while(i!=j){
    //     if(ans[i].second==ans[j].second){
    //         i++;
    //         j--;
    //     }else{

    //     }
    // }
    while(now<k){
        int l=0,r=pos[id].size()-1;
        if(((k-1)&1)&&now+1==k-1||(k&1)&&now+1==k){
            for(auto xx:pos[id]){
                auto x=lower_bound(vec1.begin(),vec1.end(),xx)-vec1.begin();
                auto y=lower_bound(vec2.begin(),vec2.end(),-xx)-vec2.begin();
                if(x==y){
                    yes();
                    return ;
                }
            }
            no();
            return ;
        }
        while(l<r&&now<k){
            auto x=lower_bound(vec1.begin(),vec1.end(),pos[id][l])-vec1.begin();
            auto y=lower_bound(vec2.begin(),vec2.end(),-pos[id][r])-vec2.begin();
            if(x==y){
                vec1.insert(vec1.begin()+x,pos[id][l]);
                vec2.insert(vec2.begin()+y,-pos[id][r]);
                l++;
                r--;
                now+=2;
            }else if(x<y){
                if(now+cnt[id]>=k){
                    l++;
                }else{
                    no();
                    return ;
                }
            }else{
                if(now+cnt[id]>=k){
                    r--;
                }else{
                    no();
                    return ;
                }
            }
        }
        if(l==r){
            if(((k-1)&1)&&now+1==k-1||(k&1)&&now+1==k){
                auto x=lower_bound(vec1.begin(),vec1.end(),pos[id][l])-vec1.begin();
                auto y=lower_bound(vec2.begin(),vec2.end(),-pos[id][r])-vec2.begin();
                if(x==y){
                    yes();
                    return ;
                }
            }else if(now!=0&&now+1<k){
                no();
                return ;
            }else{
                vec1.push_back(pos[id][l]);
                vec2.push_back(-pos[id][r]);
                now++;
            }
        }
        id++;
    }
    yes();
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