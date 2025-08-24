#include<bits/stdc++.h>
#define ll long long
using namespace std;
int b[26] = {1, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};
void solve(){
    string s;
    cin>>s;
    int a[26]={0};
    for(int i=0;i<s.size();i++){
        a[s[i]-'A']++;
    }
    int ans=0;
    for(int i=0;i<26;i++){
        int res=0;
        for(int j=0;j<26;j++){
            if(b[(j+i)%26]){
                res+=a[j]*b[(j+i)%26];
            }
        }
        // cout<<res<<" ";
        ans=max(ans,res);
    }
    cout<<ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}