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
    int n,m;
    cin>>n>>m;
    vector<int>a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    int now=0,p=0;
    int idx=0;
    int ans=0;
    while(idx<n){
        if((a[idx]-now)%2==0){
            if(p==b[idx]){
                ans+=a[idx]-now;
            }else{
                ans+=a[idx]-now-1;
            }
        }else{
            if(p==b[idx]){
                ans+=a[idx]-now-1;
            }else{
                ans+=a[idx]-now;
            }
        }
        now=a[idx];
        p=b[idx];
        idx++;
    }
    ans+=m-now;
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
