#include <stdio.h>
#include <conio.h>
#include <time.h>//��ͷ�ļ��Ǳ��������
int main()
{
time_t t;//����һ��ʱ�����
t=time(NULL);
char *time;//����һ���ַ������������ȡ�������ں�ʱ��
time=ctime(&t);//��ֵ
printf("%s",time);//����Ϳ�����
return 0;
}
