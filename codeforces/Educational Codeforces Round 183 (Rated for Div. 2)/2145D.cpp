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
    int n,k;
    cin>>n>>k;
    vector<int>ans(n,0);
    vector<bool>vis(n+1,0);
    vis[0]=1;
    int r=n,l=1;
    bool ok=(k==0);
    if(k==(n-1)*n/2){
        iota(ans.begin(),ans.end(),1);
        reverse(ans.begin(),ans.end());
        for(auto x:ans){
            cout<<x<<" ";
        }
        return ;
    }
    auto dfs=[&](auto &&self,int lo,int kk)->void{
        if(ok||kk==0){
            ok=1;
            return ;
        }
        for(int i=lo+1;i<n;i++){
            if(ok){
                return ;
            }
            if(!ok&&(i-lo+1)*(n-i)<=kk){
                vis[l]=1;
                vis[r]=1;
                ans[i-1]=r--;
                ans[i]=l++;
                self(self,i+1,kk-(n-i)*(i-lo+1));
                if(!ok){
                    vis[ans[i-1]]=0;
                    vis[ans[i]]=0;
                    ans[i-1]=ans[i]=0;
                    r++;
                    l--;
                }
            }
        }
    };
    for(int i=1;i<n;i++){
        if(ok){
            break;
        }
        if(i*(n-i)<=k){
            vis[l]=1;
            vis[r]=1;
            ans[i-1]=r--;
            ans[i]=l++;
            dfs(dfs,i+1,k-(n-i)*i);
            if(!ok){
                vis[--l]=0;
                vis[++r]=0;
                ans[i-1]=ans[i]=0;
            }
        }
    }
    if(!ok){
        cout<<0;
        return ;
    }
    int pi=1;
    for(int i=0;i<n;i++){
        while(pi<=n&&vis[pi]){
            pi++;
        }
        if(!ans[i]){
            ans[i]=pi;
            vis[pi]=1;
            // vis[]=1;
        }
        // vis[ans[i]]=1;
        cout<<ans[i]<<" ";
    }
    assert(vis==vector<bool>(n+1,1));


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
