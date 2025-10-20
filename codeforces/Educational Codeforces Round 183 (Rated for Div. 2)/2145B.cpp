#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void yes(){
    cout<<"YES";
}
void no(){
    cout<<"NO";
}
void AUTO_AC_MACHINE(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    if(n==k){
        cout<<string(n,'-');
        return ;
    }
    // vector<string>ans;
    string ans(n,'+');
    int l=0,r=n-1;
    int cnt=0;
    for(int i=0;i<k;i++){
        if(s[i]=='0'){
            ans[l++]='-';
        }else if(s[i]=='1'){
            ans[r--]='-';
        }else{
            cnt++;
        }
    }
    for(int i=l;i<l+cnt;i++){
        ans[i]='?';
    }
    for(int i=r;i>r-cnt;i--){
        ans[i]='?';
    }
    // for(int i=l;i<=r;i++){
    //     if(i-l+1<=cnt&&r-i+1<=cnt){
    //         ans[i]='-';
    //     }
    // }
    cout<<ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        AUTO_AC_MACHINE();
        cout<<'\n';
    }
}
