#include <stdio.h>
#include <conio.h>
#include <time.h>//该头文件是必须包含的
int main()
{
time_t t;//定义一个时间变量
t=time(NULL);
char *time;//定义一个字符串用来保存获取到的日期和时间
time=ctime(&t);//赋值
printf("%s",time);//输出就可以了
return 0;
}
