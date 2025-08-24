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
    // int n,k;
    // cin>>n>>k;
    // vector<int>left(k,10);
    // vector<array<int,4>>a;
    // vector<int>mp(4,0);
    // vector<vector<int>>mpp;
    // bool ok=0;
    // for(int i=0;i<n;i++){
    //     int x,y,z;
    //     cin>>x>>y>>z;
    //     if(z==3&&x==10){
    //         mp[y]++;
    //         mpp[y].push_back(i+1);
    //         ok=1;
    //     }else{
    //         a.push_back({x,y,z,i+1});
    //     }
    // }
    // if(!ok){
    //     cout<<-1;
    //     return ;
    // }
    // vector<vector<int>>day(k+1);
    // vector<vector<int>>ans(k+1);
    // auto check=[&]()->bool{
    //     int id=1;
    //     for(int i=1;i<=k;i++){
    //         vector<bool>vis(day[i])
    //     }
    // };
    // auto dfs=[&](auto &&self,int x)->void{
    //     if(x==a.size()){
    //         if(check()){
    //             cout<<ans.size()<<'\n';
    //             for(int i=0;i<ans.size();i++){
    //                 for(auto x:ans[i]){
    //                     cout<<x<<' ';
    //                 }
    //             }
    //             exit(0);
    //         }
    //     }
    //     for(int i=1;i<=k;i++){
    //         day[i].push_back(x);
    //         self(self,1);
    //         day[i].pop_back();
    //     }
    // };
    // if(!a.size()){
    //     if(n>k){
    //         cout<<-1;
    //         return ;
    //     }else{
    //         cout<<n<<'\n';
    //         for(int i=1;i<=n;i++){
    //             cout<<i<<'\n';
    //         }
    //     }
    // }else{
    //     auto [x,y,z,id]=a[0];
    //     for(int i=1;i<=k;i++){
    //         day[i].push_back(0);
    //         dfs(dfs,1);
    //         day[i].pop_back();
    //     }
    // }
    int n,k;
    cin>>n>>k;
    vector<array<int,4>>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i][0]>>a[i][1]>>a[i][2];
        a[i][3]=i;
        if(a[i][2]==1){
            a[i][2]=2;
        }else if(a[i][2]==2){
            a[i][2]=1;
        }
    }
    sort(a.begin(),a.end(),[](array<int,4>x,array<int,4>y){
        return x[2]<y[2];
    });
    vector<int>left(k+1,10);
    vector<bool>vis(n+1,0);
    // queue<int>q;
    vector<vector<int>>ans(k+1);
    auto dfs=[&](auto &&self,int cnt,int day)->void{
        if(cnt==n){
            if(ans[day].size()&&day<=k){
                cout<<day<<"\n";
                for(int i=1;i<=day;i++){
                    for(auto x:ans[i]){
                        cout<<a[x][3]<<" ";
                    }
                    cout<<'\n';
                }
                exit(0);
            }else if(day-1<=k){
                cout<<day-1<<'\n';
                for(int i=1;i<=day-1;i++){
                    for(auto x:ans[i]){
                        cout<<a[x][3]<<" ";
                    }
                    cout<<'\n';
                }
                exit(0);
            }
            return ;
        }
        if(day>k){
            return ;
        }
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                if(a[i][2]==1){
                    bool f=0; 
                    for(auto x:ans[day-1]){
                        if(a[x][1]==a[i][1]&&left[day]>=a[i][0]){
                            f=1;
                        }
                    }
                    if(f){
                        ans[day].push_back(i);
                        vis[i]=1;
                        left[day]-=a[i][0];
                        self(self,cnt+1,day);
                        left[day]+=a[i][0];
                        self(self,cnt+1,day+1);
                        vis[i]=0;
                        ans[day].pop_back();
                    }
                }else if(a[i][2]==2){
                    if(left[day]>=a[i][0]&&ans[day].size()){
                        ans[day].push_back(i);
                        vis[i]=1;
                        left[day]-=a[i][0];
                        self(self,cnt+1,day);
                        left[day]+=a[i][0];
                        self(self,cnt+1,day+1);
                        vis[i]=0;
                        ans[day].pop_back();
                    }
                }else{
                    if(a[i][0]==left[day]){
                        ans[day].push_back(i);
                        vis[i]=1;
                        self(self,cnt+1,day+1);
                        vis[i]=0;
                        ans[day].pop_back();
                    }
                }
            }
        }
    };
    for(int i=1;i<=n;i++){
        if(a[i][0]==10&&a[i][2]==3){
            vis[i]=1;
            ans[1].push_back(i);
            dfs(dfs,1,2);
            vis[i]=0;
            ans[1].pop_back();
        }
    }
    cout<<-1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    // cin>>t;
    for(int i=0;i<t;i++){
        solve();
        cout<<'\n';
    }
    return 0;
}