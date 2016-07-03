#include<iostream>
using namespace std;
class classInClass;
class fatherClass
{
public:
   fatherClass(){cout<<"I AM FATHERCLASS"<<endl;}
   ~fatherClass(){
       cout<<"Fatherclass is uncontrusting"<<endl;
   }
};

class sonClass:public fatherClass
{
public:
    sonClass(){cout<<"sonclass is contrusting!"<<endl;}
    ~sonClass(){cout<<"Sonclass unconstructing!"<<endl;}
};

class grandsonClass:public sonClass
{
public:
    grandsonClass(){
        cout<<"grandson is constructing!"<<endl;
    }
    ~grandsonClass(){
        cout<<"unConstructing grandsonclass"<<endl;
    }
};



class classInClass
{
public:
    classInClass():b(1){;}
    class innerClass{
    public:
        innerClass(){}
        innerClass(int is):a(0),e(1),s(is){c=0;}
      static int c;
     int s;
    protected:
        int e;
    private:
        int a;
        friend class classInitTest;

    }K;

    int b;
    innerClass ab;
    int *num;
    friend class classInitTest;
};
int classInClass::innerClass::c=0;//类静态成员只能在类外部初始化，且必须初始化

//类构造函数初始化测试
class classInitTest
{
public:
    classInitTest():t(1),r(t),constTest(t){
        cout<<"I am in the classInitTest默认构造函数"<<endl;
        t=0;
      //constTest=t;//不能赋值，只能列表初始化
        r=t;//内部引用必须显示初始化
       // xtest=&t;
    }
    classInitTest( const classInitTest &m):r(m.r),constTest(m.constTest){
        t=m.t;
        xtest=new int;
        if(xtest!=0)
        *xtest=*(m.xtest);

        cout<<"I am in copy function "<<endl;
       // return *this;
    }
    void setT(classInClass m){ t=m.b;}
private:
    int t;
    const int constTest;
    int &r;
public:
    int *xtest;

};


class noInitFuction{
public:
    noInitFuction(istream &is);
    int b;
    string h;
};
