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
    int ans=0;
    while(n){
        if(n<=2){
            break;
        }
        ans+=n/3;
        n-=n/3*2;
    }
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
