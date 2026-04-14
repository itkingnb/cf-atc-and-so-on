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
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    vector<int>t;
    for(int i=0;i<n;i++){
        if(s[i]=='B'){
            t.push_back(i+1);
        }
    }
    int mod=t.size();
    while(q--){
        int x;
        cin>>x;
        if(t.size()==0){
            cout<<x<<'\n';
            continue;
        }
        int now=0;
        int idx=0;
        int d=(t[idx]-now-1+n)%n;
        int ans=0;
        while(x>0){
            if(d>=x){
                cout<<ans+x<<'\n';
                break;
            }

            x-=d;
            ans+=d;
            x/=2;
            ans++;
            if(x==0){
                cout<<ans<<"\n";
            }
            now=t[idx];
            idx=(idx+1)%mod;
            d=(t[idx]-now-1+n)%n;
        }
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
