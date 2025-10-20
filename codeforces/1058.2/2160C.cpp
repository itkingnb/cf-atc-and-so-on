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
    ll n;
    cin>>n;
    string s;
    for(int i=0;i<64;i++){
        if((n>>i)&1){
            s.push_back('1');
        }else{
            s.push_back('0');
        }
    }
    if(n==0){
        yes();
        return ;
    }
    auto check=[&](string s)->bool{
        int l=0,r=s.size()-1;
        while(l<r){
            if(s[l]!=s[r]){
                return 0;
            }
            l++;
            r--;
        }
        if((int)s.size()&1){
            if(s[l]!='0'){
                return 0;
            }
        }
        return 1;
    };
    while(s.back()=='0'){
        // cerr<<s<<endl;
        s.pop_back();
        if(check(s)){
            yes();
            return ;
        }
    }
    no();
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
