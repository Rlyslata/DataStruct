#include<iostream>
#include<algorithm>
using namespace std;
template<class T>
struct DNode{
public:
    DNode* next;
    DNode* prev;
    T value;

public:
    DNode(){}
    DNode(T t,DNode* prev,DNode* next){
    this->next=next;
    this->prev=prev;
    value=t;
    }
};

template<class T>
class Single_link{
public:
    Single_link();
    ~Single_link(){}

    void swaplink(Single_link* phead);
    T get_first();
    int insert_first(T t);

private:
    DNode<T>* phead;

};
template<class T>
Single_link<T>::Single_link(){
    phead=new DNode<T>();
    phead->next=phead->prev=phead;
}

template<class T>
void Single_link<T>::swaplink(Single_link* pnode){
    DNode<T>* phead=pnode->phead;
    DNode<T>* pdlink=new DNode<T>();
    DNode<T>* ptmp=new DNode<T>();
    pdlink=phead->next;
    while(ptmp!=phead)
    {
        ptmp=pdlink->next;
        pdlink->next=phead->next;
        phead->next=pdlink;
        pdlink=ptmp;
    }
}

template<class T>
T Single_link<T>::get_first(){
    return phead->next->value;
}

template<class T>
int Single_link<T>::insert_first(T t){
DNode<T>* pnode=new DNode<T>(t,phead,phead->next);
phead->next->prev=pnode;
phead->next=pnode;
return 0;
}
int main()
{
    Single_link<int>* pdlink=new Single_link<int>();
    pdlink->insert_first(1);
    pdlink->insert_first(2);
    pdlink->insert_first(3);
    pdlink->insert_first(4);
    cout<<pdlink->get_first()<<endl;
    pdlink->swaplink(pdlink);
    cout<<pdlink->get_first()<<endl;
    return 0;
}
