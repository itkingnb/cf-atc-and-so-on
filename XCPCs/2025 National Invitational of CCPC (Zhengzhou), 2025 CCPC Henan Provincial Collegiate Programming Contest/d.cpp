#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve(){
    string s;
    cin>>s;
    ll a=stoll(s);
    auto check=[&](ll x)->bool{
        for(int i=1;i<=1000;i++){
            if(x==i*i){
                return 1;
            }
        }
        return 0;
    };
    if(check(a)){
        a=0;
        for(int i=0;i<s.size();i++){
            a+=(s[i]-'0');
        }
        if(check(a)){
            cout<<"Yes";
        }else{
            cout<<"No";
        }
    }else{
        cout<<"No";
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