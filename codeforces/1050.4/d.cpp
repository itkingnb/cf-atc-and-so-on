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
    cin>>n;
    vector<ll>odd,even;
    ll ans=0;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        if(x&1){
            odd.push_back(x);
        }else{
            even.push_back(x);
        }
    }
    if(odd.size()==0){
        cout<<0<<'\n';
        return ;
    }else{
        sort(odd.begin(),odd.end(),greater<ll>());
        int idx=0;
        while(idx<odd.size()){
            ans+=odd[idx++];
            odd.pop_back();
        }
        // while(odd.size()){
        //     ans+=odd[0]
        // }
        // for(int i=0;i<odd.size();i+=2){
        //     ans+=odd[i];
        // }
        cout<<ans+accumulate(even.begin(),even.end(),0LL)<<'\n';
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
