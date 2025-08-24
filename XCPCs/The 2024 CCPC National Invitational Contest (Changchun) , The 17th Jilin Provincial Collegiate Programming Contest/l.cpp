#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve(){
    ll k,x,y;
    cin>>k>>x>>y;
    if(k==1){
        cout<<x+y;
        return ;
    }
    if(k&1){
        ll need=(k-1)>>1;
        ll costy=y/need;
        if(x>=costy){
            ll ans=costy;
            x-=costy;
            y-=costy*need;
            y*=2;
            if(x+y>=k){
                ans++;
                x-=k-y;
                ans+=x/k;
                cout<<ans;
            }else{
                cout<<ans;
            }
        }else{
            ll ans=x;
            y-=x*need;
            ans+=y/(need+1);
            cout<<ans;
        }
    }else{
        ll costy=k>>1;
        ll ans=y/costy;
        y-=y/costy*costy;
        x+=y*2;
        ans+=x/k;
        cout<<ans;
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