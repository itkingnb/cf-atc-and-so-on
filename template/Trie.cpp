#include<bits/stdc++.h>
using namespace std;
#define N 3000010
map<char,int>mp;
int idx,tree[N][62],cnt[N];
//cnt[x]代表以x为结点结束的个数，tree[x][y]指从节点x通过字符y指向的下一个节点，y是字符的数字映射
void build(string s){
    int p=0;
    for(int i=0;s[i];i++){
        int m=mp[s[i]];
        if(!tree[p][m]) tree[p][m]=++idx;
        p=tree[p][m];
        cnt[p]++;   
    }
}
int query(string s){
    int p=0,m=0;
    for(int i=0;s[i];i++){
        m=mp[s[i]];
        if(!tree[p][m])
        return 0;
        p=tree[p][m];
    }
    return cnt[p];
}
void solve(){
    idx=0;
    memset(tree,0,sizeof(tree));//tle就自己写
    memset(cnt,0,sizeof(cnt));
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        build(s);
    }
    for(int i=0;i<q;i++){
        string s;
        cin>>s;
        cout<<query(s)<<'\n';
    }
    /*
    tle写:
    for(int i=0;i<=idx;i++){
        cnt[i]=0;
        for(int j=0;j<62;j++){
            tree[i][j]=0;
        }
    }
    */
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int id=0;
    for(char i='a';i<='z';i++) mp[i]=id++;
	for(char i='A';i<='Z';i++) mp[i]=id++;
	for(char i='0';i<='9';i++) mp[i]=id++;
    int t;
    cin>>t;
    while(t--){
    solve();
    }
    return 0;
}