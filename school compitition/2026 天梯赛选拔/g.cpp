#include<bits/stdc++.h>
using namespace std;
#define PI 3.141592
void solve(){
    vector<tuple<string,int,int>>a(5);
    for(auto &[aa,bb,cc]:a){
        cin>>aa>>bb>>cc;
        // cout<<aa<<" "<<bb<<" "<<cc;
    }
    auto check=[&](char x,char y,char z)->bool{
        for(int i=0;i<5;i++){
            auto [s,aa,bb]=a[i];
            int ta=0,tb=0;
            if(x==s[0]||y==s[0]||z==s[0]) ta++;
            if(x==s[1]||y==s[1]||z==s[1]) ta++;
            if(x==s[2]||y==s[2]||z==s[2]) ta++;
            if(s[0]==x) tb++;
            if(s[1]==y) tb++;
            if(s[2]==z) tb++;
            // cout<<ta<<" "<<tb<<'\n';
            if(ta==aa&&tb==bb){
                continue;
            }
            return 0;
        }
        return 1;
    };
    // check('A','B','A');
    vector<array<char,3>>ans;
    for(char x='A';x<='Z';x++){
        for(char y='A';y<='Z';y++){
            for(char z='A';z<='Z';z++){
                if(check(x,y,z)){
                    ans.push_back({x,y,z});
                }
            }
        }
    }
    cout<<ans.size()<<'\n';
    for(int i=0;i<ans.size();i++){
        cout<<ans[i][0]<<ans[i][1]<<ans[i][2]<<'\n';
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while (t--){
        solve();
    }
    
}