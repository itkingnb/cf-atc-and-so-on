#include<bits/stdc++.h>
using namespace std;
void solve(){
    int a[100010]={0};
    vector<int>c;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        c.push_back(k);
    }
    vector<int>b;
    for(int i=0;i<m;i++){
        int k;
        cin>>k;
        b.push_back(k);
    }
    for(int i=b.size()-1;i>=0;i--){
        if(a[b[i]]==0){
            cout<<b[i]<<" ";
            a[b[i]]++;
        }
    }
    for(int i=0;i<n;i++){
        if(a[c[i]]==0)
        cout<<c[i]<<" ";
    }
}
int main(){
    solve();
    return 0;
}