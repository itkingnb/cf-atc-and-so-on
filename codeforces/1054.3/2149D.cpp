#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define int ll
void yes(){
    cout<<"yes"<<'\n';
}
void no(){
    cout<<"no"<<'\n';
}
void AUTO_AC_MACHINE(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int res=0;
    if(s==string(n,'a')||s==string(n,'b')){
        cout<<0<<'\n';
        return ;
    }
    auto work=[&](char ch)->int{
        vector<int>pre(n),suf(n);
        int cnt=0;
        int last=-1;
        for(int i=0;i<n;i++){
            if(s[i]==ch){
                if(last==-1){
                    last=i;
                    cnt++;
                    continue;
                }else{
                    pre[i]=cnt*(i-1-last)+pre[last];
                    cnt++;
                    last=i;
                }
            }
        }
        reverse(s.begin(),s.end());
        last=-1;
        cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]==ch){
                if(last==-1){
                    last=i;
                    cnt++;
                    continue;
                }else{
                    suf[i]=cnt*(i-1-last)+suf[last];
                    cnt++;
                    last=i;
                }
            }
        }
        reverse(s.begin(),s.end());
        reverse(suf.begin(),suf.end());
        int ans=1e18;
        for(int i=0;i<n;i++){
            if(s[i]==ch)
            ans=min(ans,suf[i]+pre[i]);
        }
        for(int i=0;i<n;i++){
            pre[i]=suf[i]=0;
        }
        // last=-1;
        vector<int>nxt(n,-1);
        last=-1;
        int now=0;
        for(int i=0;i<n;i++){
            if(s[i]==ch){
                if(last==-1){
                    pre[i]=i-now;
                    now++;
                    last=i;
                }else{
                    nxt[i]=last;
                    pre[i]=pre[last]+i-now;
                    now++;
                    last=i;
                }
            }
        }
        reverse(s.begin(),s.end());
        last=-1;
        now=0;
        for(int i=0;i<n;i++){
            if(s[i]==ch){
                if(last==-1){
                    suf[i]=i-now;
                    now++;
                    last=i;
                }else{
                    // nxt[i]=last;
                    suf[i]=suf[last]+i-now;
                    now++;
                    last=i;
                }
            }
        }
        reverse(s.begin(),s.end());
        reverse(suf.begin(),suf.end());
        for(int i=0;i<n;i++){
            if(nxt[i]!=-1&&s[i]==ch){
                ans=min(ans,pre[nxt[i]]+suf[i]);
            }
        }
        return ans;
    };
    res=min(work('a'),work('b'));
    cout<<res<<'\n';

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        AUTO_AC_MACHINE();
    }
}
