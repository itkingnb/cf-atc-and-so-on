#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<ll>a(n),b(m);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    ll suma=accumulate(a.begin(),a.end(),0LL);
    ll sumb=accumulate(b.begin(),b.end(),0LL);
    map<ll,bool>mp1,mp2;
    for(int i=0;i<n;i++){
        mp1[suma-a[i]]=1;
    }
    for(int i=0;i<m;i++){
        mp2[sumb-b[i]]=1;
    }
    while(q--){
        int x;
        cin>>x;
        bool f=(x<0);
        x=abs(x);
        bool ok=0;
        for(int i=1;i*i<=x;i++){
            if(x%i==0){
                int xx=i,yy=x/i;
                if(!f){
                    if(mp1[xx]&&mp2[yy]||mp1[yy]&&mp2[xx]||mp1[-xx]&&mp2[-yy]||mp1[-yy]&&mp2[-xx]){
                        // cout<<"YES\n";
                        ok=1;
                        break;
                    }else{
                        // cout<<"NO\n";
                    }
                }else{
                    if(mp1[-xx]&&mp2[yy]||mp1[-yy]&&mp2[xx]||mp1[xx]&&mp2[-yy]||mp1[yy]&&mp2[-xx]){
                        // cout<<"YES\n";
                        ok=1;
                        break;
                    }else{
                        // cout<<"NO\n";
                    }
                }
            }
        }
        if(ok){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
        cout<<'\n';
    }
}