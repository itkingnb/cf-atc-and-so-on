#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 23000000//大于两倍字符串的长度
string s;
char ss[N];
int d[N];//最长回文半径上取正
int ans;//d里面最大的-1就是这个字符串里最长回文子串的长度
void get_d(char *s,int len){
    d[1]=1;
    for(int i=2,l=0,r=1;i<=len;i++){
        if(i<=r) d[i]=min(d[r-i+l],r-i+1);
        while(s[i-d[i]]==s[i+d[i]]) d[i]++;
        if(i+d[i]-1>r) l=i-d[i]+1,r=i+d[i]-1;
        ans=max(ans,d[i]);
    }
}
void solve(){
    cin>>s;
    int k=1;
    ss[0]='$'; ss[1]='#';//防越界
    for(int i=0;i<s.size();i++){
        ss[++k]=s[i]; ss[++k]='#';
    }
    get_d(ss,k);
    cout<<ans-1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}