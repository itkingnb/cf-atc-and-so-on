#include <iostream>
using namespace std;
class CData
{
public:
	static void Add(int a)
	{
		if(pCur>=data+20)
			cout<<"内存空间不足，无法添加！"<<endl;
		else
		{
			*pCur=a;
			pCur++;
		}
	}
	static void Print(void);
	static void Sort(void);
	static void Del(int d);
private:
	static int data[20];
	static int *pCur;
};
int CData::data[20];
int *CData::pCur=data;
void CData::Print(void)
{
	for(int i=0;i<(pCur-data);i++)
		cout<<data[i]<<",";
	cout<<endl;
}
void CData::Sort(void)
{
	int n=pCur-data;
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(data[i]>data[j])
			{
				int temp=data[i];
				data[i]=data[j];
				data[j]=temp;
			}
}
void CData::Del(int d)
{
	int* temp=data;
	for(int i=0;i<(pCur-data);i++){
		if(data[i]!=d){
			data[temp-data]=data[i];
			temp++;
		}else{
			continue;
		}
	}
	pCur=temp;
	
}
int main()
{
	CData::Add(40);
	CData::Add(20);
	CData::Add(-50);
	CData::Add(7);
	CData::Add(13);
	CData::Add(7);
	CData::Print();
	CData::Sort();
	CData::Print();
	cout<<"删除元素7以后:"<<endl;
	CData::Del(7);
	CData::Print();
	return 0;
}
