#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    const double tp[11]={0,0,1.84,1.32,1.20,1.14,1.11,1.09,1.08,1.07,1.06};
    int n=0;
    double X=0,U1=0,U2=0,E1=0,E2=0,S=0,SX=0,sum=0,sum2=0,s1,u1j,u1z,dy;
    double x[20];
    cout<<"输入实验次数，d仪"<<endl;
    cin>>n>>dy;
   for(int i=1;i<=n;i++)
     {
        cin>>x[i];
        sum+=x[i];
     }
    X=sum/n;//平均数
    for(int i=1;i<=n;i++)
    {
        sum2+=(X-x[i])*(X-x[i]);//平方和;
    }
    S=sqrt(sum2/(n-1));//标准误差;
    SX=S/sqrt(n);//平均值的标准误差
    s1=tp[n-1]*SX*tp[n-1]*SX;//A类分量平方
    u1z=(dy/3)*(dy/3);//B类正态分布
    u1j=(0.683*dy)*(dy*0.683);//B类均匀分布;
    U1=sqrt(s1+u1j);
    U2=sqrt(s1+u1z);
    E1=U1/X;
    E2=U2/X;
    cout<<endl;
    cout<<"计算结果如下:"<<endl;
    cout<<endl;
    cout<<"算数平均值为X="<<X<<endl;
    cout<<endl;
    cout<<"标准误差S="<<S<<endl;
    cout<<endl;
    cout<<"平均值的标准误差SX="<<SX<<endl;
    cout<<endl;
    cout<<"A类分量平方s1="<<s1<<endl;
    cout<<endl;
    cout<<"B类分量平方u1j="<<u1j<<"(B类均匀分布)"<<endl;
    cout<<endl;
    cout<<"B类分量平方u1z="<<u1j<<"(B类正态分布)"<<endl;
    cout<<endl;
    cout<<"不确定度U="<<U1<<"(B类均匀分布)"<<endl;
    cout<<endl;
    cout<<"不确定度U="<<U2<<"(B类正态分布)"<<endl;
    cout<<endl;
    cout<<"相对误差E="<<E1<<"(B类均匀分布)"<<endl;
    cout<<endl;
    cout<<"相对误差E="<<E2<<"(B类正态分布)"<<endl;
    cout<<endl;
    return 0;
}
