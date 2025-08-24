#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){
    ll x;
    cin>>x;
    for(ll i=2;;i++){
        if(x%i!=0){
            cout<<i;
            return ;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
        cout<<'\n';
    }
}