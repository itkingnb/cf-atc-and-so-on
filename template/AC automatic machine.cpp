#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000010
vector<string>strs;
int ne[N],ch[N][26],cnt[N];
int p,idx;
void trie(string s){
    int p=0;
    for(int i=0;s[i];i++){
        int m=s[i]-'a';
        if(!ch[p][m]) ch[p][m]=++idx;
        p=ch[p][m];   
    }
    cnt[p]++;
}
void build(){
    queue<int>q;
    for(int i=0;i<26;i++){
        if(ch[0][i])
        q.push(ch[0][i]);
    }
    while(!q.empty()){
        auto  u=q.front();q.pop();
        for(int i=0;i<26;i++){
            if(ch[u][i]){
                ne[ch[u][i]]=ch[ne[u]][i];
                q.push(ch[u][i]);
            }
            else ch[u][i]=ch[ne[u]][i];
        }
    }
}
int AC(string s){
    int ans=0;
    p=0;
    for(int i=0;s[i];i++){
        p=ch[p][s[i]-'a'];
        for(int j=p;j&&~cnt[j];j=ne[j]){
            ans+=cnt[j],cnt[j]=-1;
        }
    }
    return ans;
}
void solve(){
    int n;
    cin>>n;
    strs.resize(n);
    for(int i=0;i<n;i++){
        cin>>strs[i];
        trie(strs[i]);
    }
    build();
    string s;
    cin>>s;
    cout<<AC(s);   
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}