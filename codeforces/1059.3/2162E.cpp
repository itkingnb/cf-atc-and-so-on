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
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    vector<bool>vis(n+1,0);
    vector<int>t;
    for(int i=0;i<n;i++){
        cin>>a[i];
        vis[a[i]]=1;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            t.push_back(i);
        }
    }
    if(!t.size()){
        int p=0;
        while(k--){
            cout<<a[p++]<<" ";
        }
        return ;
    }else if(t.size()==1){
        int cnt=0;
        int last=-1;
        for(int i=n-1;i>=0&&t.size()<3;i--){
            if((vis[a[i]]&&cnt)||cnt==2){
                vis[a[i]]=0;
                t.push_back(a[i]);
                
                if(a[i]!=last){
                    t.push_back(last);
                }
                i=n;
                // cnt++;
            }else if(vis[a[i]]){
                vis[a[i]]=0;
                last=a[i];
                cnt++;
            }
        }
    }else if(t.size()==2){
        t.push_back(a.back());
    }
    
    int p=0;
    int mod=t.size();
    while(k--){
        cout<<t[p]<<" ";
        p=(p+1)%mod;
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
