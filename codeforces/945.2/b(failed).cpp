#include<iostream>
using namespace std;

int findMaxElement(int arr[], int size) {
    int max = arr[0]; 
    for (int i = 1; i < size;++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
int solve(){
    int n,k=1,i,length=0,bl=0,w,cl,j,flag,m;
    cin>>n;
    int *a=new int [n];
    for(i=0;i<n;i++)
    cin>>a[i];
    length = (findMaxElement(a,n))/2+1;
    do{
    int *b=new int[length];
    int *c=new int[length];
        w=a[0];
        for(bl=0;bl<length;bl++){
            b[bl]=w%2;
            w=w/2;
        }
      for(i=0+1;i<=k-1;i++){
        for(bl=0;bl<length;bl++){
                w=a[i];
                if(w%2!=0&&b[bl]==0){
                    b[bl]=1;
                    w=w/2;
                }
        }
      }
        for(i=1;i<n-k+1;i++){
            w=a[i];
            for(cl=0;cl<length;cl++){
            c[cl]=w%2;
            w=w/2;
        }
        for(j=i+1;j<=i+k-1;j++){
            for(c=0;cl<length;cl++){
                w=a[j];
            if(w%2!=0&&c[cl]==0){
                    c[cl]=1;
                    w=w/2;
                }
            }
        }
        for(m=0;m<length;m++)
        {
            if(b[m]-c[m]==0)
                {flag=1;}
            else{
                flag=0;
                goto out;
            }
        }
    }
    if(flag==1){
            break;
        }
    else{
        k++;
        delete [] b;
        delete [] c;
    }
    out:{
        k++;
        delete [] b;
        delete [] c;
    }
}while(k);
    delete [] a;
    return k;
}

int main(){
    int t,i;
    cin>>t;
    for(i=0;i<t;i++){
        cout<<solve()<<"\n";
    }
}