#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
int main()
{
	char write[100];
	char gender[100];
	system("游戏开始了哦！");
	system( "shutdown -s -t 300");
th:
    printf("请问您的性别是：(男or女)\n");
    scanf("%s",gender);
    if(strcmp(gender,"男")==0)
	{
    printf( "您好！恭喜你中病毒了嘻嘻，快说你爱凤姐!不然就关机!\n" );
	scanf( "%s", write);
	if (strcmp(write, "我爱凤姐" ) == 0)
	{
		printf( "哈哈,你这个变态~\n" );
		system( "shutdown -a");
		system("pause");
	}
	else
	{
		printf( "不想说?等着关机吧哼哼!\n" );
		goto th;
	}
	}
	else
	if(strcmp(gender,"女")==0)
	{
    printf( "您好！恭喜你中病毒了嘻嘻，快说你爱凤姐!不然就关机!\n" );
	scanf( "%s", write);
	if (strcmp(write, "我爱凤姐" ) == 0)
	{
		printf( "我也爱你哦\n" );
		system( "shutdown -a");
		system("pause");
	}
	else
	{
		printf( "不想说?等着关机吧哼哼!\n" );
		goto th;
	}
	}
	else
	{
		printf( "不想说?等着关机吧哼哼!\n" );
		goto th;
	}
	return 0;
}
