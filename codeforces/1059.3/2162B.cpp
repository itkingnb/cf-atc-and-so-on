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
    vector<int>ans;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            ans.push_back(i+1);
        }
    }
    cout<<ans.size()<<'\n';
    for(auto x:ans){
        cout<<x<<" ";
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
