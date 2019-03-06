#include<iostream>
using namespace std;

struct Node{
char value;
Node *next;
Node *prev;

Node(Node* next,Node* prev,char value){
this->next=next;
this->prev=prev;
this->value=value;
}
Node(){}
};

class seqlink
{
public:
    seqlink(){
    curlen=0;
    Node *phead=new Node();
    phead->next=phead->prev=phead;
    }
    void _assign(seqlink* T);
    void contact(seqlink* T);
    int length();
    //void _substr(seqlink *S,int i,int j,seqlink *T);
    void push_char(char ch);
    void  _insert(int i,int j,seqlink *T);
    bool _empty();
    Node* getnode(int i);
    int strcmp(seqlink *T);
    void del();
    char get_value(int i);
    //void _replace(seqlink *S,int i,int j,seqlink *T);

private:
    int curlen;
    Node* phead;
};

    void seqlink::_assign(seqlink* T){//赋值
    phead=T->phead;
    curlen=T->curlen;
    }

    void seqlink::contact(seqlink* T){//链接
    phead->prev->next=T->phead->next;
    T->phead->next->prev=phead->prev;
    T->phead->next=phead;
    curlen+=T->curlen;
    }

    int seqlink::length(){//返回长度
    return curlen;
    }

    bool seqlink::_empty(){//判断是否为空
    return 0==curlen;
    }

    Node* seqlink::getnode(int i){//获得节点i；
        Node* pnode=phead;
        while(i--)
        {
            pnode=pnode->next;
            if(phead==pnode)
                cout<<"can't find this index"<<endl;
        }
   return pnode;
    }

    void seqlink:: _insert(int i,int j,seqlink *T){
        Node *pindex_i=getnode(i);
        Node *pindex_j=getnode(j);
        pindex_i->next=T->phead->next;
        T->phead->next->prev=pindex_i;
        T->phead->prev->next=pindex_j;
        pindex_j->prev=T->phead->prev;
        curlen+=T->curlen;
    }

    int seqlink::strcmp(seqlink *T){
        Node* pnode_S=phead;
        Node* pnode_T=T->phead;
        while(1)
        {
        pnode_S=pnode_S->next;
        pnode_T=pnode_T->next;
        if(pnode_S==phead&&pnode_T==T->phead)
            return 0;
        if(pnode_S!=phead&&pnode_T==T->phead)
            return 1;
        if(pnode_S==phead&&pnode_T!=T->phead)
            return -1;
        }
    }
    void seqlink::del(){
        Node *ptmp=phead->next;
        Node *p;
        while(ptmp!=phead)
        {
            p=ptmp;
            ptmp=ptmp->next;
            delete p;
        }
        delete ptmp;
    }

    void seqlink::push_char(char ch){
        Node* pnew=new Node(phead,phead->prev,ch);
        phead->prev->next=pnew;
        phead->prev=pnew;
        cout<<curlen<<endl;
        cout<<ch<<endl;
        curlen+=1;
        cout<<curlen<<endl;

    }

    char seqlink::get_value(int i){
    return getnode(i)->value;
    }
int main()
{
    seqlink *S=new seqlink();
    seqlink *T=new seqlink();
    S->push_char('a');
    cout<<S->length()<<endl;
    //S->push_char('b');
    /*T->push_char(T,'c');
    T->push_char(T,'d');
    //contact(S,T);
    for(int i=1;i<=length(S);i++)
    {
        cout<<get_value(S,i);
    }
    cout<<endl;*/
    return 0;
}
