#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    int n;
    cin>>n;
    if(n==2){
        cout<<1<<" "<<2<<'\n';
        return ;
    }
    if(n==4){
        cout<<-1<<'\n';
        return ;
    }
    if(n&1){
        for(int i=1;i<n;i+=2){
            cout<<i<<" "<<i+1<<'\n';
            cout<<i<<" "<<i+2<<'\n';
        }
    }else{
        cout<<1<<" "<<2<<'\n';
        cout<<3<<" "<<2<<'\n';
        cout<<3<<" "<<4<<'\n';
        cout<<4<<" "<<5<<'\n';
        cout<<4<<" "<<6<<'\n';
        for(int i=5;i+3<=n;i+=2){
            cout<<i<<" "<<i+2<<'\n';
            cout<<i<<" "<<i+3<<'\n';
        }
    }

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}