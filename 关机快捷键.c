#include<stdio.h>
#include<limits.h>
#include<time.h>
#include<conio.h>
#include<stdlib.h>
char*gettime()
{

    time_t t;
    t=time(NULL);
    char* time;
    time=ctime(&t);
    return time;
}
void fun()
{
    int T;
        printf("���԰�5��ȡ������Ŷ\n");
        scanf("%d",T);
        while(T!=5)
        {
            printf("���԰�5��ȡ������Ŷ\n");
        }
        if(T==5) system("shutdown -a");
}
int main()
{
    int T,t;
    char* ptr;
    char write[100];
    printf("��ã�����,�����ǣ�\n");
    ptr=gettime();
    printf("%s\n",ptr);
    printf("�װ�����������Ҫʲô�����أ�\n");
    printf("�ػ��밴1,�ػ������밴2,��ʱ�ػ��밴3,��ʱ�ػ��밴4,ȡ�������밴5\n");
    scanf("%d",t);
    if(t==1)
    {
        system("shutdown -s -t 20");
        //fun();
        return 0;
    }
    else
        if(t==2)
    {
        system("shutdown -r -t 20");
        //fun();
        return 0;
    }
    else
        if(t==3)
        {
            printf("��������ʱ�ػ�ʱ��(��)\n");
            scanf("%d",&T);
            system("shutdown -s -t T");
            //fun();
            return 0;
        }
        else
            if(t==4)
        {
            printf("������ʱ���,����:8:30");
            scanf("%s",write);
            system("at write shutdown -s");
            //fun();
            return 0;
        }
        /*else
            if(t==5)
        {
        printf("���԰�5��ȡ������Ŷ\n");
        scanf("%d",T);
        while(T!=5)
        {
        printf("���԰�5��ȡ������Ŷ\n");
        }
        if(T==5) return 0;
        }*/
    return 0;
}
