#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void yes(){
    cout<<"yes"<<'\n';
}
void no(){
    cout<<"no"<<'\n';
}
void AUTO_AC_MACHINE(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<0<<" ";
    if(n>=2){
        int last=(max(a[0],a[1])>gcd(a[0],a[1]));
        cout<<(max(a[0],a[1])>gcd(a[0],a[1]))<<" ";
        int gg=gcd(a[0],a[1]),g=max(a[0],a[1]),ggg=gg;
        for(int i=2;i<n;i++){
            if(gg==1){
                if(a[i]%g==0&&g>gg){
                    last++;
                    // cout<<last<<" ";
                }
                cout<<last<<" ";
                continue;
            }
            if(ggg!=1&&gcd(ggg,a[i])==1){
                cout<<i<<" ";
                gg=1;
                g=ggg;
                last=i;
                continue;
            }
            ggg=gcd(ggg,a[i]);
            
            if(a[i]%g==0&&g>gg){
                last++;
                // cout<<last<<" ";
            }else if(gg>gcd(gg,a[i])){
                gg=gcd(gg,a[i]);
                last++;
            }
            cout<<last<<" ";
        }
    }
    cout<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        AUTO_AC_MACHINE();
    }
}
