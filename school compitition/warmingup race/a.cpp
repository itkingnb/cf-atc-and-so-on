#include<iostream>
using namespace std;

int main(){
    int s,k=0;
    for(int i=2;i<61;i++){
        for(s=1;s<=i/2;s++){
            if(i%s==0)
            k += s;
        }
        if(k>i)
        cout<<i<<endl;
        k=0;
    }
    return 0;
}