#include<iostream>
using namespace std;

class node{
public:
    int atom;
    node *link;

    union{
    node *slink;
    char data;
    }ds;

    void creat(node *LS);
    void print(node *LS);
    int depth(node *LS);
};

int node::depth(node *LS){
int Max=0;
while(LS!=NULL)
{
    if(LS->atom==0)
    {
        int dep=depth(LS->ds.slink);
        if(dep>Max) Max=dep;
    }
    LS=LS->link;
}
return Max+1;
}

void node::creat(node *LS){
char ch;
cin>>ch;
if(ch=='#')
LS=NULL;
else if('(')
{
    LS=new node();
    LS->atom=0;
    creat(LS->ds.slink);
}
else{
    LS=new node();
    LS->atom=1;
    LS->ds.data=ch;
}
cin>>ch;
if(LS==NULL);
else if(ch==',')
    creat(LS->link);
else if((ch==')')||(ch==';'))
    LS->link=NULL;
}

void node::print(node *LS)
{
    if(LS->atom==0)
    {
        cout<<'(';
        if(LS->link==NULL)
            cout<<'#';
        else
            print(LS->ds.slink);
    }
    else
        cout<<LS->ds.data;
    if(LS->atom==0)
        cout<<')';
    if(LS->link!=NULL)
    {
        cout<<',';
        print(LS->link);
    }
}

int main()
{
    node T;
    node *LS=new node();
    T.creat(LS);
    cout<<T.depth(LS)<<endl;
    T.print(LS);
    return 0;
}








