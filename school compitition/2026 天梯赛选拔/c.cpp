#include<bits/stdc++.h>
using namespace std;
#define PI 3.141592
void solve(){
    int r1,r2;
    cin>>r1>>r2;
    cout<<fixed<<setprecision(6)<<PI*(r2*r2-r1*r1);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while (t--){
        solve();
    }
    
}