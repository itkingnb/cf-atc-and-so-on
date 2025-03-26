#include<bits/stdc++.h>
using namespace std;
#define N 101
int din[N];

void solve(){
    int n;
    cin>>n;
    vector<int>houdai[N];
    for(int i=1;i<=n;i++){
        int a;
        while (cin>>a)
        {   
            if(a==0)
            break;
            din[a]++;
            houdai[i].push_back(a);
        }        
    }
    queue<int>family;
    for(int i=1;i<=n;i++){
        if(din[i]==0)
        family.push(i);
    }
    vector<int>ans;
    while (family.size())
    {
        int fa=family.front();
        family.pop();
        ans.push_back(fa);
        for(auto son:houdai[fa]){
            if(--din[son]==0)
            family.push(son);
        }
    }
    for(int i=0;i<n;i++)
    cout<<ans[i]<<" ";
}
int main(){
    solve();
    return 0;
}