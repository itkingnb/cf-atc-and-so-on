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
    int x,n;
    cin>>x>>n;
    if(n&1){
        cout<<x;
    }else{
        cout<<0;
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
