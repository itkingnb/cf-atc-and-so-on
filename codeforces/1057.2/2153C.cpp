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
void fuck(int& cnt,int y){
    cnt+=y/2;
}
void solve(){
    int n;
    cin>>n;
    vector<ll>a(n);
    map<ll,int>mp;
    bool ok=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]++;
        if(mp[a[i]]>=2){
            ok=1;
        }
    }
    if(!ok){
        cout<<0;
        return ;
    }
    vector<ll>t;
    ll ans=0;
    int cnt=0;
    // ll minodd=1e18,mineven=1e18;
    for(auto [x,y]:mp){
        ans+=1LL*y/2*2*x;
        if(y>=2){
            // cnt++;
            fuck(cnt,y);
        }
        // y&=1;
        if(y&1){
            // minodd=min(minodd,x);
            t.push_back(x);
        }else{
            // mineven=min(mineven,x);
        }
    }
    sort(t.begin(),t.end());
    if(cnt>=2){
        if(t.size()==0){
            cout<<ans;
        }else if(t.size()==1){
            if(t[0]>=ans){
                cout<<ans;
            }else{
                cout<<ans+t[0];
            }
        }else{
            // ll res=ans;
            for(int i=t.size()-1;i>=1;i--){
                if(ans+t[i-1]>t[i]){
                    cout<<ans+t[i-1]+t[i];
                    return ;
                }
            }
            for(int i=t.size()-1;i>=0;i--){
                if(ans>t[i]){
                    cout<<ans+t[i];
                    return ;
                }
            }
            cout<<ans;
        }
    }else{
        if(t.size()==0){
            cout<<0;
        }else if(t.size()==1){
            if(t[0]>=ans){
                cout<<0;
            }else{
                cout<<ans+t[0];
            }
        }else{
            bool found=0;
            for(int i=t.size()-1;i>=1;i--){
                if(ans+t[i-1]>t[i]){
                    cout<<ans+t[i-1]+t[i];
                    return ;
                }
            }
            for(int i=t.size()-1;i>=0;i--){
                if(ans>t[i]){
                    cout<<ans+t[i];
                    return ;
                }
            }
            cout<<0;
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
        cout<<'\n';
    }
    return 0;
}