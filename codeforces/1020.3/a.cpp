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
    string s;
    cin>>s;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            cnt++;
        }
        
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            ans+=cnt+1;
        }else{
            ans+=cnt-1;
        }
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
