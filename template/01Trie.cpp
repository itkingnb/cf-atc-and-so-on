#include<bits/stdc++.h>
using namespace std;
#define N 100001
int tree[N*31][2];
int idx;
void build(int n){
    int p=0;
    for(int i=31;i>=0;i--){
        int m=n>>i&1;
        if(!tree[p][m]) tree[p][m]=++idx;
        p=tree[p][m];
    }
}
int query(int n){
    int p=0,ans=0;
    for(int i=31;i>=0;i--){
        int m=n>>i&1;
        if(tree[p][!m]){
            ans += 1<<i;
            p=tree[p][!m];
        }
        else
        p=tree[p][m];
    }
    return ans;
}
void solve(){
    int n,ans=0;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        build(a[i]);
    }
    for(int i=0;i<n;i++){
        ans=max(query(a[i]),ans);
    }
    cout<<ans;
}
int main(){
    solve();
    return 0;
}