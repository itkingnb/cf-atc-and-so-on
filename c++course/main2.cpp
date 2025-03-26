#include<bits/stdc++.h>
using namespace std;
class A{
    public:
    int arr[100]={0};
    void show(){
        for(int i=0;i<100;i++){
            sort(this->arr,this->arr+100,greater<int>());
            if(this->arr[i]){
                cout<<this->arr[i]<<" ";
            }else
            break;
        }
    }
    A operator=(A a){
        A temp;
        int j=0;
        sort(a.arr,a.arr+10,greater<int>());
        for(int i=0;i<100;i++){
            if(a.arr[i]==0)
            break;
            else
            temp.arr[j++]=a.arr[i];
        }
        return temp;
    }
    friend A operator+(A a,A b){
        A temp;
        int i=0,j=0,t=0;
        sort(a.arr,a.arr+10,greater<int>());
        sort(b.arr,b.arr+10,greater<int>());
        while(a.arr[i]!=0||b.arr[j]!=0){
            if(a.arr[i]==b.arr[j]){
                temp.arr[t++]=a.arr[i++];
                j++;
            }else if(a.arr[i]>b.arr[j]){
                temp.arr[t++]=a.arr[i++];
            }else{
                temp.arr[t++]=b.arr[j++];
            }
        }
        return temp;
    }
};
class B{
    private:
    public:
};
class c{
    private:
    public:
};
int main(){
    A a,b;
    for(int i=0;i<6;i++){
        cin>>a.arr[i];
    }
    for(int i=0;i<4;i++){
        cin>>b.arr[i];
    }
    A c=a+b;
    c.show();
}
/*
3 4 5 6 7 9
2 4 6 9
*/