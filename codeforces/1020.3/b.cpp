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
    int n,x;
    cin>>n>>x;
    int now=0;
    int n1=n-1;
    int n2=0;
    for(int i=0;i<n;i++){
        if(now==x){
            cout<<n1--<<" ";
        }else{
            cout<<n2++<<" ";
            now++;
        }
    }
    cout<<'\n';
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
