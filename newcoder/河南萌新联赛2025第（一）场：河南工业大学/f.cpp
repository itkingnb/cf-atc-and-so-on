#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod=1e9+7;
void solve(){
    ll n,s,x;
    cin>>n>>s>>x;
    ll ss=s;
    vector<ll>ans(n);
    ans[0]=x;
    s-=x;
    if(s<0){
        cout<<"zetsubou";
        return ;
    }
    for(int i=63;i>=0;i--){
        ll cnt=0;
        for(int j=0;j<n;j++){
            if(((ans[j]>>i)&1)==0){
                cnt++;
            }
        }
        int mx=min((cnt%2==0?cnt:cnt-1),((s/(1LL<<i))%2==0?(s/(1LL<<i)):(s/(1LL<<i)-1)));
        for(int j=0;j<n&&mx;j++){
            if(((ans[j]>>i)&1)==0){
                mx--;
                s-=(1LL<<i);
                ans[j]+=(1LL<<i);
            }
        }
    }
    ll xo=0;
    ll sum=0;
    for(int i=0;i<n;i++){
        sum+=ans[i];
        xo^=ans[i];
    }
    if(x==xo&&ss==sum){
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
    }else{
        cout<<"zetsubou";
    }
}   
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
        cout<<'\n';
    }
    
}