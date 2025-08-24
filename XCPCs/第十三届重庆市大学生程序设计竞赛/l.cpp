#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve(){
    int n;
    cin>>n;
    ll mod=998244353;
    ll sum=0;
    int idx=-1;
    vector<ll>s;
    for(int i=0;i<n;i++){
        string op;
        cin>>op;
        if(op=="Push"){
            ll x;
            cin>>x;
            s.push_back(x);
            sum+=x;
            sum%=mod;
        }else if(op=="Repeat"){
            if(s.size()<n){
                int num=s.size();
                for(int i=0;i<num;i++){
                    s.push_back(s[i]);
                }
            }
            sum*=2;
            sum%=mod;
        }else{
            sum=(sum+mod-s.back())%mod;
            s.pop_back();
        }
        cout<<sum<<'\n';
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();

    }
}