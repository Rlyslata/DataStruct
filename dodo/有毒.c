#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
int main()
{
	char write[100];
	char gender[100];
	system("��Ϸ��ʼ��Ŷ��");
	system( "shutdown -s -t 300");
th:
    printf("���������Ա��ǣ�(��orŮ)\n");
    scanf("%s",gender);
    if(strcmp(gender,"��")==0)
	{
    printf( "���ã���ϲ���в�������������˵�㰮���!��Ȼ�͹ػ�!\n" );
	scanf( "%s", write);
	if (strcmp(write, "�Ұ����" ) == 0)
	{
		printf( "����,�������̬~\n" );
		system( "shutdown -a");
		system("pause");
	}
	else
	{
		printf( "����˵?���Źػ��ɺߺ�!\n" );
		goto th;
	}
	}
	else
	if(strcmp(gender,"Ů")==0)
	{
    printf( "���ã���ϲ���в�������������˵�㰮���!��Ȼ�͹ػ�!\n" );
	scanf( "%s", write);
	if (strcmp(write, "�Ұ����" ) == 0)
	{
		printf( "��Ҳ����Ŷ\n" );
		system( "shutdown -a");
		system("pause");
	}
	else
	{
		printf( "����˵?���Źػ��ɺߺ�!\n" );
		goto th;
	}
	}
	else
	{
		printf( "����˵?���Źػ��ɺߺ�!\n" );
		goto th;
	}
	return 0;
}
