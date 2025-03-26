#include<bits/stdc++.h>
using namespace std;
class CPoint{
    private:
    double x,y;
    public:
    CPoint(){x=0,y=0;};
    virtual void modify(double xx,double yy){x=xx,y=yy;};
    double getx(){return x;};
    double gety(){return y;};
};
class CLine:public CPoint{
    private:
    CPoint start,end;
    public:
    void modify(double a,double b,double c,double d){start.modify(a,b),end.modify(c,d);};
    double getlength(){return sqrt((start.getx()-end.getx())*(start.getx()-end.getx())+(start.gety()-end.gety())*(start.gety()-end.gety()));};
};
class CRect:public CLine{
    private:
    CLine a1,b1;//a长，b宽
    public:
    CRect(double a,double b,double c,double d,double e,double f,double g,double h){a1.modify(a,b,c,d);b1.modify(e,f,g,h);};
    double getarea(){return a1.getlength()*b1.getlength();};
    double getcircumference(){return 2*(a1.getlength()+b1.getlength());};
    double getlength(){return a1.getlength();};
    double getwidth(){return b1.getlength();};
};
int main(){
    CRect rec(0,0,4,0,0,0,0,3);
    cout<<"周长是："<<rec.getcircumference()<<endl;
    cout<<"面积是："<<rec.getarea()<<endl;
    cout<<"长是："<<rec.getlength()<<endl;
    cout<<"宽是："<<rec.getwidth()<<endl;
    return 0;
}