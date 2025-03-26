#include<iostream>
#include<cmath>
#include<string>
#include <algorithm>
using namespace std;
    
int main(){
    int n,m,a[9],b[50],c[100]={0},i,k,j,p,flag=0,ans=0;
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>a[i];
        c[i]=a[i];              //o-n-1 单个数字
        k=i;
    }
    for(i=0;i<m;i++){
        cin>>b[i];
    }
    i=n;
    for(j=0;j<n;j++)
        for(k=j+1;k<n;k++){
            c[i]=a[j]+a[k];
            i++;                   //0-i排序
        }
    sort(c,c+99);
    i++;//c[0]-c[i-1]
    for(j=m-1;j>=1;j--){
        b[j]=b[j]-b[j-1];
    }
    for(k=0;k<m;k++){
        flag=0;
        for(j=0;j<100;j++){
                    //cout<<c[j]<<c[p]<<b[k];
                if(c[j]==b[k]){
                        flag=1;
                        ans++;
                        break;
                    }
            }
        if(flag==0)
            break;
        }
        if(ans==m)
        cout<<"win!"<<'\n';
        else
        cout<<ans<<'\n';                              //b[0]
    return 0;
}