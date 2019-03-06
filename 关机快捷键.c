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
        printf("可以按5来取消服务哦\n");
        scanf("%d",T);
        while(T!=5)
        {
            printf("可以按5来取消服务哦\n");
        }
        if(T==5) system("shutdown -a");
}
int main()
{
    int T,t;
    char* ptr;
    char write[100];
    printf("你好，主人,现在是：\n");
    ptr=gettime();
    printf("%s\n",ptr);
    printf("亲爱的主人您想要什么服务呢？\n");
    printf("关机请按1,关机重启请按2,延时关机请按3,定时关机请按4,取消服务请按5\n");
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
            printf("请输入延时关机时间(秒)\n");
            scanf("%d",&T);
            system("shutdown -s -t T");
            //fun();
            return 0;
        }
        else
            if(t==4)
        {
            printf("请输入时间点,形如:8:30");
            scanf("%s",write);
            system("at write shutdown -s");
            //fun();
            return 0;
        }
        /*else
            if(t==5)
        {
        printf("可以按5来取消服务哦\n");
        scanf("%d",T);
        while(T!=5)
        {
        printf("可以按5来取消服务哦\n");
        }
        if(T==5) return 0;
        }*/
    return 0;
}
