#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<vector<int>>ans(n+1,vector<int>(n+1,0));
    vector<int>pos(n+1,0);
    for(int i=1;i<=n;i++){
        ans[1][i]=i;
        pos[i]=i;
    }
    int k=0;
    for(int i=2;i<=n;i++){
        k++;
        vector<int>pos2(n+1,0);
        for(int j=1;j<=n;j++){
            ans[i][pos[(j+k>n?(j+k)%n:(j+k))]]=j;
            pos2[j]=pos[(j+k>n?(j+k)%n:(j+k))];
        }
        pos=pos2;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<'\n';
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
        cout<<'\n';
    }
}