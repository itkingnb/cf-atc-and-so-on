#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    auto check=[&](int x)->string{
        string ans;
        if((x>>2)&1){
            ans.push_back('r');
        }else{
            ans.push_back('-');
        }
        if((x>>1)&1){
            ans.push_back('w');
        }else{
            ans.push_back('-');
        }
        if((x>>0)&1){
            ans.push_back('x');
        }else{
            ans.push_back('-');
        }
        return ans;
    };
    cout<<check(n/100%10)<<check(n/10%10)<<check(n%10);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
        cout<<'\n';
    }
}