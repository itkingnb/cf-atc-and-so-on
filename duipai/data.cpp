#include <bits/stdc++.h>
using namespace std;
#define ll long long
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int main(){
    cout<<10<<" "<<5<<'\n';
    bool ok=0;
    while(!ok){
        ok=1;
        vector<bool>vis(6,0);
        vector<int>a(10);
        for(int i=0;i<10;i++){
            a[i]=rng()%5+1;
            vis[a[i]]=1;
        }
        for(int i=1;i<=5;i++){
            if(!vis[i]){
                ok=0;
            }
        }
        if(ok){
            for(auto x:a){
                cout<<x<<" ";
            }
        }
    }
    cout<<endl;
    int m=4;
    vector<bool>vis(6,0);
    while(m){
        int a=rng()%5+1,b=rng()%5+1;
        if(a!=b&&!vis[b]&&!vis[a]){
            cout<<a<<" "<<b<<"\n";
            vis[b]=1;
            m--;
        }
    }
    return 0;
}