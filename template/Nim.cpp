#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    int ans=0;
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        ans^=m;
    }
    ans==0?cout<<"No"<<'\n':cout<<"Yes"<<'\n';
}
//a^b^c^c^...!=0先手必胜，反之必败
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--){
    solve();
    }
    return 0;
}