#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll s;
    cin>>s;
    vector<int>t(7);
    for(int i=0;i<7;i++){
        cin>>t[i];
    }
    int l=0,r=s;
    int ans=0;
    auto check=[&](int x)->bool{
        vector<int>tt=t;
        vector<int>a(3,x);
        a[0]-=t[0];
        a[1]-=t[1];
        a[2]-=t[3];
        if(a[0]>0){
            int mx=min(a[0],t[2]);
            a[0]-=mx;
            t[2]-=mx;
            if(a[0]>0){
                int mx1=min(a[0],t[4]);
                a[0]-=mx1;
                t[4]-=mx1;
                if(a[0]>0){
                    int mx2=min(a[0],t[6]);
                    a[0]-=mx2;
                    t[6]-=mx2;
                }
            }
        }
        if(a[1]>0){
            int mx=min(a[1],t[2]);
            a[1]-=mx;
            t[2]-=mx;
            if(a[1]>0){
                int mx1=min(a[1],t[5]);
                a[1]-=mx1;
                t[5]-=mx1;
                if(a[1]>0){
                    int mx2=min(a[1],t[6]);
                    a[1]-=mx2;
                    t[6]-=mx2;
                }
            }
        }
        if(a[2]>0){
            int mx=min(a[2],t[4]);
            a[2]-=mx;
            t[4]-=mx;
            if(a[2]>0){
                int mx1=min(a[2],t[5]);
                a[2]-=mx1;
                t[5]-=mx1;
                if(a[2]>0){
                    int mx2=min(a[2],t[6]);
                    a[2]-=mx2;
                    t[6]-=mx2;
                }
            }
        }
        t=tt;
        return a[0]<=0&&a[1]<=0&&a[2]<=0;

    };
    // check(11);
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
        cout<<'\n';
    }
}