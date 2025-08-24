#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void yes(){
    cout<<"yes"<<'\n';
}
void no(){
    cout<<"no"<<'\n';
}
void AUTO_AC_MACHINE(){
    int n;
    ll k;
    cin>>n>>k;
    vector<ll>a(n),b(n);
    ll target=-1;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        cin>>b[i];
        if(b[i]==-1){
            cnt++;
        }else{
            target=b[i]+a[i];
        }
    }
    if(cnt==n){
        ll mx=*max_element(a.begin(),a.end());
        ll mn=*min_element(a.begin(),a.end());
        cout<<max(0LL,k-(mx-mn)+1)<<'\n';
    }else{ 
        bool ok=true;
        for(int i=0;i<n;i++){
            if(b[i]!=-1){
                if(a[i]+b[i]!=target){
                    cout<<0<<'\n';
                    return ;
                }
            }else{
                ll t1=target-a[i];
                if(t1<0||t1>k){
                    cout<<0<<'\n';
                    return ;
                }
            }
        }
        cout<<1<<'\n';
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        AUTO_AC_MACHINE();
    }
}
