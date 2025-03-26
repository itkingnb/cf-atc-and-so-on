#include<iostream>
using namespace std;
class CRoot{
public:
	int small;
	CRoot(int n=2){small=n;}
	void showsmall(){
		cout<<"small="<<small<<endl;	
	};
};
class CDer1:public CRoot
{
public:	
	CDer1(int m):CRoot(m){}
};
class CDer2:public CRoot{
public:
	int small;	
	CDer2(int n=0){small=n;}
};
int main(){
	CRoot A;
	CDer1 B(3);
	CDer2 C;
	A.showsmall();
	B.showsmall();
	C.showsmall();
	return 0;
}
