#include<bits/stdc++.h>
using namespace std;
#define PI 3.141592
void solve(){
    int n;
    cin>>n;
    cin.ignore();
    vector<string>s(11);
    for(int i=1;i<=n;i++){
        getline(cin,s[i]);
        // cout<<s[i];
        s[i].pop_back();
    }
    string ans;
    auto make=[&](auto &&self,int id)->string{
        for(int i=0;i<s[id].size();i++){
            if(s[id][i]!='*'){
                ans.push_back(s[id][i]);
                continue;
            }
            int x=s[id][i+1]-'0';
            string t1(s[id].begin(),s[id].begin()+i+1);
            string t2(s.begin()+i+2,s.end());
            s=t1+
            i++;
            if(x>n){
                continue;
            }
            self(self,x);
        }
        return s;
    };
    make(make,1);
    if(!ok||ans.size()>1e6){
        cout<<"#";
    }else{
        cout<<ans;
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