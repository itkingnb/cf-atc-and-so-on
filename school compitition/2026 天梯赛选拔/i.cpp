#include<bits/stdc++.h>
using namespace std;
#define PI 3.141592
void solve(){
    int n,m;
    cin>>n>>m;
    vector<deque<pair<char,int>>>a(n+1);
    for(int i=1;i<=n;i++){
        pair<char,int> t;
        cin>>t.first;
        t.second=i;
        a[i].push_back(t);
    }
    for(int i=0;i<m;i++){
        int op;
        cin>>op;
        if(op==1){
            int x,y;
            cin>>x>>y;
            while(a[x].size()){
                auto t=a[x].front();a[x].pop_front();
                a[y].push_front(t);
            }
        }else if(op==2){
            int x,y;
            cin>>x>>y;
            while(a[x].size()){
                auto t=a[x].back();a[x].pop_back();
                a[y].push_front(t);
            }
        }else{
            int x;
            cin>>x;
            vector<pair<char,int>>t;
            while(a[x].size()){
                auto tt=a[x].back();a[x].pop_back();
                t.push_back(tt);
            }
            while(t.size()){
                auto xx=t.back();t.pop_back();
                a[xx.second].push_front(xx);
            }
        }
    }
    // cerr<<1111<<endl;
    for(int i=1;i<=n;i++){
        stack<int>s1;
        int idx=0;
        stack<pair<char,int>>s2;
        vector<string>ans;
        string t;
        bool ok=1;
        while(a[i].size()){
            idx++;
            auto x=a[i].back().first;a[i].pop_back();
            if(x=='('){
                s1.push(idx);
            }else if(x==')'){
                if(!s1.size()){
                    ok=0;
                    break;
                }else{
                    auto y=s1.top();s1.pop();
                    while(s2.size()&&s2.top().second>y){
                        t.push_back(s2.top().first);
                        s2.pop();
                    }
                    if(t.size()){
                        reverse(t.begin(),t.end());
                        ans.push_back(t);
                        t.clear();
                    }
                    
                }
            }else{
                s2.push({x,idx});
            }
        }
        if(s1.size()){
            ok=0;
        }
        while(s2.size()){
            t.push_back(s2.top().first);
            s2.pop();
        }
        if(t.size()){
            reverse(t.begin(),t.end());
            ans.push_back(t);
        }
        if(ok){
            cout<<ans.size();
            for(int i=0;i<ans.size();i++){
                cout<<" "<<ans[i];
            }
        }else{
            cout<<-1;
        }
        if(i!=n){
            cout<<'\n'; 
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