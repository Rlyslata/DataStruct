/*//Josephus
#include<iostream>
using namespace std;

int main()
{
    int m;//报数上界；
    int n;//人数;
    int s;//报数开始位置;
    int arr[100];
    cout<<"    请输入数据"<<endl;
    cout<<"--------------------"<<endl;
    cin>>m>>n>>s;

    for(int i=1;i<=n;i++)
    {
        arr[i]=i;
    }

    for(int i=n;i>=2;i--)
    {
        int sq=s;
        int w;
        sq=(sq+m-1)%i;
        if(0==sq)
            sq=i;
        w=arr[sq];

        for(int j=sq;j<=i-1;j++)
        {
            arr[j]=arr[j+1];
        }
        arr[i]=w;
    }

    for(int i=n;i>=1;i--)
        cout<<arr[i]<<endl;

    return 0;
}
*/
//Josephus
/*#include<iostream>
using namespace std;

struct Link{
    int value;
    Link* next;
    Link* prev;
};

Link* hcreat(int n){
Link* phead=new Link();
phead->next=phead->prev=phead;
while(n--)
{
    Link* pnode=new Link();
    pnode->value=n+1;
    phead->next->prev=pnode;
    pnode->next=phead->next;
    pnode->prev=phead;
    phead->next=pnode;
}
return phead;
}
int main()
{
    int m,s,n;//报数上限，报数位置，人数；
    cout<<"    请输入数据:报数上限，报数位置，人数；"<<endl;
    cout<<"-------------------------------------------"<<endl;
    cin>>m>>s>>n;
    Link* phead=hcreat(n);
    while(n--)
    {
        int S=s;
        int M=m;
        Link* shead;
        Link* ptmp;
        while(S--)
        {
            shead=phead->next;
        }
        while(M--)
        {
            shead=shead->next;
            if(shead==phead)
                M++;
        }
        ptmp=shead;
        shead->prev->next=shead->next;
        shead->next->prev=shead->prev;
        cout<<ptmp->value<<endl;
        delete ptmp;
    }
    return 0;
}*//*
#include <stdio.h>
#include <string.h>
#include <malloc.h>
  void  GetMemory (char **p,  int  nbytes)
{
  *p = (char *)malloc (nbytes) ;

}

int  main (int  argc, char *argv [ ])
{
char *str = NULL ;

GetMemory (&str,100) ;
strcpy (str,"hello  ") ;
strcat (str,"world" ) ;
printf (str) ;
free(str);
if(str==NULL)
    printf("error!");
return 0 ;
}
*/


#include <stdio.h>
#include <string.h>
#include <malloc.h>
int  main (int  argc, char *argv [ ])
{
char *str =(char*)malloc(100);
strcpy (str,"hello  ") ;
strcat (str,"world" ) ;
printf (str) ;
free(str);
if(str==NULL)
    printf("error!");
return 0 ;
}

