#include <iostream>
#include<stdexcept>//异常处理头文件
#include"classtest.cpp"
#include<set>
#include<QList>

using namespace std;
class A{};
class B{};
class C:public A
{
};
class D:public A,public B
{

};
class E:public virtual A
{

};

//递归函数
int counter(int m)
{

    if(m==1||m==0)
        return 1;
    else
    {
        return m*counter(m-1);
    }

}

void GetMemory(char **p,int num)
{
    *p=(char *)malloc(sizeof(char)*num);
}
int main()
{
    cout << "size of A"<<sizeof(A) << endl;
    cout<<"size of C"<<sizeof(C)<<endl;
    cout<<"size of D"<<sizeof(D)<<endl;
    cout<<"size of E"<<sizeof(E)<<endl;
    string a="hello";
   // string *b=&a;
    string *b;
    b=&a;
    string &c=a;//引用相当于C为a的译名

    cout<<*b<<",b is"<<b<<",&b is："<<&b<<"  C is:"<<c<<endl;
    //int c[5]={1,2,3,4,5};
   // cout<<*c<<",c:"<<c<<",&c："<<&c<<endl;

    char *str=NULL;
    GetMemory(&str,100);
    strcpy(str,"hahahaha");
    cout<<*str<<","<<str<<","<<&str<<endl;

//引用符号test
    int ival=1024;
    int &rival=ival;//rival相当于ival的别名
    //rival=5;
    rival++;
    const int &ri=42;
    cout<<"ival is:"<<ival<<endl;

    //typedef test
    typedef double wages;
    wages a1=1.1423;
    cout<<"a1:"<<a1<<endl;

    //enum枚举test
    enum day{Monday,Tuesday,Wedsday,Thurthday,Friday,Saturday,Sunday};
    int dayone=Monday;
   // day daytwo=Tuesday;
    double daytwo=Tuesday;
    cout<<"dayone is:"<<dayone<<endl<<"daytwo is:"<<daytwo<<endl<<sizeof(Tuesday)<<endl<<sizeof(int);


    //指针test
    int point=1024;
    //int *point1=point;error,can not be a variabe value;
    int *point2=&point;
   // point2=point;error,can not be a variabe value;
    int *point3;
    point3=point2;
    cout<<endl<<"point3 is:"<<point3<<"*point3 is:"<<*point3<<"&point3 is:"<<&point3<<endl;
    int *point4;
    point4=point2;
    char chart[3]={'1','2','3'};
    char *pchar=chart;
    cout<<endl<<"*pchar is:"<<*pchar<<"pchar is:"<<pchar<<endl;
    cout<<sizeof(*pchar)<<sizeof(pchar)<<sizeof(chart)<<endl;//输出为1  8（64位8字节）  3（说明指针和数组还是有区别）

   //const指针test
    int Acos=4;
    const int *toAcos=&Acos;// 与int const *toAcos=&Acos;等价，都是指针所指地址的内容为常量
   // *toAcos=12; error *toAcos is a const(readonly)
    toAcos=&point;
    int *const toBcos=&Acos;// 指针所指地址为常量，但指针所指地址的内容可以改变
    *toBcos=12;
   // toBcos=&point;error, toBcos is a const(readonly)
    const int *const toCcos=&Acos;
   // *toCcos=14;error *toCcos is const
   // toCcos=&point;error toCcos is const

  int douhao=1,douhao2=3;
  //if(douhao!=2)
    //  throw runtime_error("douhao is not equal 2!");抛出异常，立即结束程序

 // int douhao2=2;
 // douhao=3,douhao2=4;
  cout<<"douhao:"<<douhao<<"douhao2:"<<douhao2<<endl;

  cout<<"*********************************************************************"<<endl;

 // grandsonClass *grandson;//只声明指针不会创建对象，不会调用类对象构造函数和析构函数
  grandsonClass grandson1;//定义类对象，会同时调用对象构造函数并调用析构函数
  grandsonClass *grandson2=new grandsonClass;//new 构建新的对象会调用类构造函数
  //delete grandson2;//delete调用类的析构函数
  cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
  grandsonClass *grandson3=&grandson1;//不调用自身构造函数，没有新建对象
  grandsonClass grandson4;
  cout<<"kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk"<<endl;
  grandson4=*grandson2;
  delete grandson2;
  sonClass son;
  //try

 //显示转换static_cast,dynamic_cast,const_cast,reinterpret_cast
  //cast_name<type> expression

  //异常处理
//
  classInClass::innerClass k(4);
  cout<<"kkkkk:"<<k.s<<endl;
  //K.a=0;a为private，不能访问
 //  K.c=1;
 //  classInClass::innerClass::c=9;
  int counter1=counter(5);
  cout<<"counter:"<<counter1<<endl;

// noInitFuction *nofuction=new noInitFuction(cin);

  //cout<<"nofunction"<<nofuction->b<<"string h"<<nofuction->h<<endl;

  //浅拷贝和深拷贝
  classInClass A;
  A.num=new int(3);
  classInClass B=A;//默认合成复制构造函数,进行位复制，B和A中的num指针指向同一地址
  cout<<B.num<<"   "<<A.num<<endl;
  delete A.num;//A中的num指向的地址被释放，B中num所指地址还是那个地址，但是此地址已经被归还给系统，此地址将会动态分给后面申请空间的指针，B中num所指的内容会随后面的更改而更改
  A.num=NULL;
 // delete B.num；//errror the space has been free;
 cout<<A.num<<"    "<<(B.num)<<"    "<<*(B.num)<<endl;//打印出B中num所指地址的值；
 //深拷贝
 classInitTest Ctext;
 Ctext.xtest=new int(5);
 classInitTest Dtext(Ctext);
 cout<<Ctext.xtest<<"     "<<Dtext.xtest<<endl;
 delete Ctext.xtest;
 delete Dtext.xtest;
 cout<<"D中的xtest："<<*(Dtext.xtest)<<"   "<<*(B.num)<<endl;//由于B中num所指地址被分配给Ctext.xtext，值被改变，B中num所指内容发生改变
 cout<<"********************************************************************************************"<<endl;

 //数组和线性列表，集合等的初始化，或者复制
 std::set<int> setF,setC;
 setF.insert(5);
 setF.insert(3);
 setF.insert(4);
 setF.insert(0);
 setF.insert(2);
 for(std::set<int>::iterator i=setF.begin();i!=setF.end();i++)
 cout<<" "<<*i;
 cout<<endl;
 setC=setF;
 for(std::set<int>::iterator j=setC.begin();j!=setC.end();j++)
 cout<<" "<<*j;
 cout<<endl;
 cout<<"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"<<endl;

 std::set<int*> setH;
 std::set<int*>setI;
 int *sA=new int;
 int *sB=new int;
 int *sC=new int;
 *sA=23;
 *sB=24;
 *sC=25;
 setH.insert(sA);
 setH.insert(sB);
 setH.insert(sC);
 for(std::set<int*>::iterator i=setH.begin();i!=setH.end();i++)
 cout<<" "<<**i;
 cout<<endl;
 setI=setH;//浅拷贝
 delete *(setH.begin());
 int *sD=new int;
 *sD=66;
 for(std::set<int*>::iterator j=setI.begin();j!=setI.end();j++)
 cout<<" "<<**j;
 cout<<endl;

 QList<int*>listA;
 QList<int*>listB;
 int *la=new int;
 int *lb=new int;
 int *lc=new int;
 *la=1;
 *lb=2;
 *lc=3;

 listA.append(la);
 listA.append(lb);
 listA.append(lc);
for(int i=0;i<listA.size();i++)
    cout<<"  "<<*listA[i];
cout<<endl;
listB=listA;//浅拷贝
delete listA[listA.size()-1];
int *ld=new int;
 *ld=55;
for(int j=0;j<listB.size();j++)
    cout<<"  "<<*listB[j];
cout<<endl;

return 0;
}

