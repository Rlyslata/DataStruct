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
    cout<<"����ʵ�������d��"<<endl;
    cin>>n>>dy;
   for(int i=1;i<=n;i++)
     {
        cin>>x[i];
        sum+=x[i];
     }
    X=sum/n;//ƽ����
    for(int i=1;i<=n;i++)
    {
        sum2+=(X-x[i])*(X-x[i]);//ƽ����;
    }
    S=sqrt(sum2/(n-1));//��׼���;
    SX=S/sqrt(n);//ƽ��ֵ�ı�׼���
    s1=tp[n-1]*SX*tp[n-1]*SX;//A�����ƽ��
    u1z=(dy/3)*(dy/3);//B����̬�ֲ�
    u1j=(0.683*dy)*(dy*0.683);//B����ȷֲ�;
    U1=sqrt(s1+u1j);
    U2=sqrt(s1+u1z);
    E1=U1/X;
    E2=U2/X;
    cout<<endl;
    cout<<"����������:"<<endl;
    cout<<endl;
    cout<<"����ƽ��ֵΪX="<<X<<endl;
    cout<<endl;
    cout<<"��׼���S="<<S<<endl;
    cout<<endl;
    cout<<"ƽ��ֵ�ı�׼���SX="<<SX<<endl;
    cout<<endl;
    cout<<"A�����ƽ��s1="<<s1<<endl;
    cout<<endl;
    cout<<"B�����ƽ��u1j="<<u1j<<"(B����ȷֲ�)"<<endl;
    cout<<endl;
    cout<<"B�����ƽ��u1z="<<u1j<<"(B����̬�ֲ�)"<<endl;
    cout<<endl;
    cout<<"��ȷ����U="<<U1<<"(B����ȷֲ�)"<<endl;
    cout<<endl;
    cout<<"��ȷ����U="<<U2<<"(B����̬�ֲ�)"<<endl;
    cout<<endl;
    cout<<"������E="<<E1<<"(B����ȷֲ�)"<<endl;
    cout<<endl;
    cout<<"������E="<<E2<<"(B����̬�ֲ�)"<<endl;
    cout<<endl;
    return 0;
}
