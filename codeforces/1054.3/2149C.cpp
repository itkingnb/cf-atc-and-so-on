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
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    
    vector<int>cnt(n+10);
    int fk=0,fk1=0;
    int mex=0;
    int ans=0;
    for(int i=0;i<n;i++){
        cnt[a[i]]++;
        if(mex==a[i]){
            mex++;
        }

        if(a[i]==k){
            fk++;
        }
        if(mex>a[i]){
            continue;
        }
    }
    for(int i=mex;i<k;i++){
        if(!cnt[i]){
            if(fk){
                fk--;
                ans++;
                continue;
            }else{
                ans++;
            }
        }
    }
    cout<<ans+fk<<'\n';

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
