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
    int n,k;
    cin>>n>>k;
    vector<ll>a(n);
    map<int,int>mp;
    map<int,int>t;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]++;
    }
    for(auto [x,y]:mp){
        if(y%k){
            cout<<0<<'\n';
            return ;
        }else{
            t[x]=y/k;
        }
    }
    ll ans=0;
    map<int,int>now;
    for(int i=0,j=0;i<n;i++){
        now[a[i]]++;
        while(now[a[i]]>t[a[i]]){
            now[a[j++]]--;
        }
        ans+=i-j+1;
    }
    cout<<ans<<'\n';
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
