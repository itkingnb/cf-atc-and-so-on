#include<iostream>
using namespace std;

int main(){
    int n,i,k,p,time=0,m,q;
    double avg;
    cin>>n;
    int* a=new int[n];
    int* b=new int[n]{0};
    for(i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
    }//...
    for(p=0;p<n;p++){
    for(i=0;i<n-1;i++){
        if(b[i]>b[i+1]){
            k=b[i]; b[i]=b[i+1]; b[i+1]=k;
        }
    }
}
    /*for(i=0;i<n;i++){
        cout<<a[i]<<'\n';
    }  
    for(i=0;i<n;i++){
        cout<<b[i]<<'\n';
    }*/
    k=0;
    for(i=0;i<n;i++){
        if(b[i-1]==b[i])
            m=q+1;
        for(p=0+m;p<n;p++)
            if(a[p]==b[i]){
            cout<<(p+1)<<' ';
            q=p;
            break;
        }
    k+=b[i];
    time+=k;
    }
    time-=k;
    cout<<'\n';
    avg=time*1.0/n;
    printf("%.2f",avg);
    delete []a;
    delete []b;
    return 0;
}