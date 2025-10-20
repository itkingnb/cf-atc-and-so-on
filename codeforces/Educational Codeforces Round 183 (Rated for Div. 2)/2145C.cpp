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
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ca=0,cb=0;
    vector<int>prea(n+1,0),preb(n+1,0);
    for(int i=0;i<n;i++){
        if(s[i]=='a'){
            ca++;
        }else{
            cb++;
        }
        prea[i+1]=prea[i]+(s[i]=='a');
        preb[i+1]=preb[i]+(s[i]=='b');
    }
    if(ca==cb){
        cout<<0;
        return ;
    }
    map<int,int>mp;
    int ans=n;
    int d=ca-cb;
    for(int i=1;i<=n;i++){
        // if(mp[])
        int dd=prea[i]-preb[i];
        if(dd-d==0||mp[dd-d]){
           ans=min(ans,i-mp[dd-d]); 
        }
        mp[dd]=i;
    }
    cout<<(ans==n?-1:ans);

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
