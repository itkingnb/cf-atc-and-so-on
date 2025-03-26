#include<bits/stdc++.h>
using namespace std;
#define ll long long
int phi(int n){
  int res = n;
  for(int i=2; i*i<=n; i++){
    if(n%i == 0){
      res = res/i*(i-1);
      while(n%i == 0) n /= i;
    }
  }
  if(n>1) res = res/n*(n-1);
  return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    cout<<phi(n);
    return 0;
}