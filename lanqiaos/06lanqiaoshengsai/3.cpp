#include<bits/stdc++.h>
using namespace std;

int main(){
    int k,m,n;
    int mx,my,nx,ny;
    cin>>k>>m>>n;
    if(m%k==0)
    my=m/k-1;
    else
    my=m/k;
    if(n%k==0)
    ny=n/k-1;
    else
    ny=n/k;
    if(my%2==1)
    mx=k-m%k+1;
    else
    mx=m%k;
    if(ny%2==1)
    nx=k-n%k+1;
    else
    nx=n%k;
    //cout<<mx<<my<<nx<<ny;
    cout<<fabs(my-ny)+fabs(mx-nx);
    return 0;
}