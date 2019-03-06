/*#include<iostream>
#include<algorithm>
using namespace std;
class link{
public:
int data;
link *next;
int L;
link *rcreat(int n)//头插法，逆序；
{
    link *p,*s;
    p=new link;
    for(int i=1;i<=n;i++)
    {
        s=new link;
        cin>>s->data;
        s->next=p;
        p=s;
    }
    L=n;
    return p;
}

int length()//求长度
{
    return L;
}
void Insert(link*,int,int);//在指定元素后插入
void Delet(link*,int);
//void setnull();
link *Locate(link*,int);//返回改元素的地址
link *prior(link*,int);//求该元素的前驱
link *succ(link*,int);//求该元素的后继
//int Get(int);
};
/*link *link::rcreat(int n)
{
    link *p,*s;
    p=new link;
    for(int i=1;i<=n;i++)
    {
        s=new link;
        cin>>s->data;
        s->next=p;
        p=s;
    }
    L=n;
    return p;
}


int link::length(){
    return L;
}
*/
/*
link *link::Locate(link *A,int x){
link *p;
while(A->data!=x)
{
    A=A->next;
    p=A;
}
return p;
}

void link::Delet(link *A,int x){
link *q,*p;
q=A;
p=A->next;
while(p->data!=x)
{
    q=p;
    p=p->next;
}
q->next=p->next;
delete p;
A->L-=1;
}

void link::Insert(link *A,int x,int y){
link*s;
link*p=new link;
s=Locate(A,x);
p->data=y;
p->next=s->next;
s->next=p;
A->L+=1;
return;
}

link *link::prior(link*A,int x){
   link *p;
   while(A->next->data!=x)
        {
            A=A->next;
        }
   return p=A;
}

link *link::succ(link*A,int x){
    return Locate(A,x)->next;
}

int main()
{
link *A;
A=A->rcreat(3);
A->Delet(A,4);
for(int i=1;i<=2;i++)
{
    cout<<A->data<<endl;
    A=A->next;
}
return 0;
}
*/
#include<iostream>

void  get1(int n)
{
    int a;
    std::cin>>a;

    if(n-1>=0)
    get1(n-1);
    std::cout<<a;
}
int main()
{
    get1(4);
    return 0;
}
