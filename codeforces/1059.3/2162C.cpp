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
    int a,b;
    cin>>a>>b;
    ll t=(a^b);
    vector<int>ans;
    for(int i=0;i<40;i++){
        if((t>>i)&1){
            ans.push_back(1LL<<i);
        }
    }
    if(ans.size()&&ans.back()>a){
        cout<<-1;
        return ;
    }else if(a==b){
        cout<<0;
    }else{
        cout<<ans.size()<<"\n";
        for(auto x:ans){
            cout<<x<<" ";
        }
    }
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
