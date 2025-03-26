#include<iostream>                                  //错啦，没做出来
#include<vector>
#include<algorithm>
using namespace std;


int lcm(int n1, int n2)
{
   int max;
   max = (n1 > n2) ? n1 : n2;
   while (true)
  {
       if (max % n1 == 0 && max % n2 == 0)
           return max;
       max++;
  }
}
int solve(){
    int n,i,ans=0,p,k;
    cin>>n;
    int*a=new int[n];
    int*b=new int[n];
    for(i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b,b+n);
    do{
        k=n-1;
        p=lcm(b[n],b[n-1]);
        for(i=0;i<n;i++){
            if(p==a[i])
            ans=n;
            break;
        }
        n--;
    }while(ans!=0);
    delete[] a;
    delete[] b;
    return ans;
}

int main(){
    int t,i;
    cin>>t;
    for(i-0;i<t;i++){
        solve();
        cout<<solve()<<'\n';
    }
    return 0;
}