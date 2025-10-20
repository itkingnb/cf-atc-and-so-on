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
    int n;
    cin>>n;
    vector<int>a(n);
    int c1=0,c0=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==0){
            c0++;
        }else if(a[i]==-1){
            c1++;
        }
    }
    cout<<(c1&1)*2+c0<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        AUTO_AC_MACHINE();
    }
}
