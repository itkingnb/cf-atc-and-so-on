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
    int n;
    cin>>n;
    int cnt=38;
    auto ask1=[&](int l,int r)->int{
        cnt--;
        cout<<1<<" "<<l<<" "<<r<<endl;
        int res;
        cin>>res;
        return res;
    };
    auto ask2=[&](int l,int r)->int{
        cnt--;
        cout<<2<<" "<<l<<" "<<r<<endl;
        int res;
        cin>>res;
        return res;
    };
    auto answer=[&](int l,int r){
        cout<<"! "<<l<<" "<<r<<endl;
    };
    int before=ask1(1,n),after=ask2(1,n);
    int t=after-before;
    int l=1,r=n;
    while(cnt){
        int mid=(l+r)>>1;
        if(r-l+1==t){
            answer(l,r);
            return;
        }
        int b=ask1(l,mid),a=ask2(l,mid);
        if(a-b==t){
            r=mid;
        }else if(b-a==0){
            l=mid+1;
        }else{
            int x=(a-b);
            answer(mid-x+1,mid-x+1+t-1);
            // break;
            return ;
        }
    }
    answer(l,l+t-1);

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
