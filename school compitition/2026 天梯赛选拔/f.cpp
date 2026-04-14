#include<bits/stdc++.h>
using namespace std;
#define PI 3.141592
void solve(){
    int n;
    string op;
    cin>>n>>op;
    auto check=[&](string s)->char{
        if(count(s.begin(),s.end(),'_')){
            return 'S';
        }
        if(s[0]<='Z'){
            return 'P';
        }
        return 'C';
    };
    auto getc=[&](string s)->string{
        if(check(s)=='C'){
            return s;
        }
        if(check(s)=='P'){
            s[0]+=32;
            return s;
        }   
        string ans;
        bool ok=0;
        for(int i=0;i<s.size();i++){
            if(ok){
                ok=0;
                ans.push_back(s[i]-32);
            }else if(s[i]=='_'){
                ok=1;
            }else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    };
    auto getp=[&](string s)->string{
        if(check(s)=='P'){
            return s;
        }
        if(check(s)=='C'){
            s[0]-=32;
            return s;
        }   
        string ans;
        bool ok=1;
        for(int i=0;i<s.size();i++){
            if(ok){
                ok=0;
                ans.push_back(s[i]-32);
            }else if(s[i]=='_'){
                ok=1;
            }else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    };
    auto gets=[&](string s)->string{
        if(check(s)=='S'){
            return s;
        }
        if(check(s)=='C'){
            string ans;
            for(int i=0;i<s.size();i++){
                if(s[i]<='Z'){
                    ans.push_back('_');
                    s[i]+=32;
                }
                ans.push_back(s[i]);
            }
            return ans;
        }
        string ans;
        s[0]+=32;
        for(int i=0;i<s.size();i++){
            if(s[i]<='Z'){
                ans.push_back('_');
                s[i]+=32;
            }
            ans.push_back(s[i]);
        }
        return ans; 
    };
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        if(op=="Camel"){
            cout<<getc(s)<<'\n';
        }else if(op=="Pascal"){
            cout<<getp(s)<<'\n';
        }else{
            cout<<gets(s)<<'\n';
        }
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