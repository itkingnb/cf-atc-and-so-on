#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int l,r;
    cin>>l>>r;
    l--;r--;
    vector<bool>vis(n,1);
    for(int i=l;i<=r;i++){
        vis[i]=0;
    }
    int c10=0,c01=0;
    for(int i=1;i<n;i++){
        if(vis[i]&&vis[i-1]&&s[i]=='1'&&s[i-1]=='0'){
            c01++;
        }else if(vis[i]&&vis[i-1]&&s[i]=='0'&&s[i-1]=='1'){
            c10++;
        }
    }
    if(abs(c10-c01)>1){
        cout<<"No";
        return ;
    }
    if(l==0){
        if(s[r+1]=='1'){
            if(c01<=c10){
                cout<<"Yes";
            }else{
                cout<<"No";
            }
        }else{
            if(c10<=c01){
                cout<<"Yes";
            }else{
                cout<<"No";
            }
        }
        return ;
    }
    if(r==n-1){
        if(s[l-1]=='0'){
            if(c01<=c10){
                cout<<"Yes";
            }else{
                cout<<"No";
            }
        }else{
            if(c10<=c01){
                cout<<"Yes";
            }else{
                cout<<"No";
            }
        }
        return ;
    }
    if(s[l-1]==s[r+1]){
        c10==c01?cout<<"Yes":cout<<"No";
    }else if(s[l-1]=='1'){
        c10+1==c01?cout<<"Yes":cout<<"No";
    }else{
        c01+1==c10?cout<<"Yes":cout<<"No";
    }
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