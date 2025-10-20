#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void yes(){
    cout<<"YES";
}
void no(){
    cout<<"NO";
}
void AUTO_AC_MACHINE(){
    int n;
    cin>>n;
    vector<ll>b(n);
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    vector<ll>ans(n);
    ans[0]=1;
    vector<int>t;
    t.push_back(1);
    int now=2;
    // t.erase()
    for(int i=1;i<n;i++){
        // if(b[i]==b[i-1]+1){
        //     ans[i]=ans[i-1];
        // }else if(b[i]-b[i-1]==i+1){
        //     ans[i]=ans[i-1]+1;
        //     t.push_back(ans[i]);
        // }else{
        // }
        if(b[i]-b[i-1]==i+1){
            ans[i]=now;
            now++;
            t.push_back(ans[i]);
        }else{
            int d=b[i]-b[i-1];
            // d--;
            int k=t.size()-d;
            ans[i]=t[t.size()-d];
            t.erase(t.begin()+k,t.begin()+k+1);
            t.push_back(ans[i]);
        }
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        AUTO_AC_MACHINE();
        cout<<'\n';
    }
}