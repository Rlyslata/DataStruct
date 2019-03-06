#ifndef DBLINKLIST_H_INCLUDED
#define DBLINKLIST_H_INCLUDED

#include<iostream>
using namespace std;

template<class T>
struct DNode{
public:
    T value;
    DNode *prev;
    DNode *next;
public:
    DNode(){}
    DNode(T t,DNode *prev,DNode *next){
    this->value=value;
    this->prev=prev;
    this->next=next;
    }
};
template<class T>
class Doublelink{
public:
    Doublelink();
    ~Doublelink();

    int size();
    int is_empty;

    T get(int index,T t);
    T get_first();
    T get_last();

    int insert(int index,T t);
    int insert_first(T t);
    int append_last(T t);

    int de(int index);
    int delete_first();
    int delete_last();

private:
    int count;
    DNode<T> *phead;
private:
    DNOde<T> *get_node(int index);
};

//构造函数
template<class T>
Doublelink<T>::Doublelink():count(0){
//创建表头，注意表头没有数据；
phead=new DNode<T>();
phead->prev=phead->next=phead;
//设置链表计数为0；
count=0;
}

//析构函数
template<class T>
Doublink<T>::~Doublelink(){
//删除所有节点;
DNode<T> *ptmp;
DNode<T> *pnode=phead->next;
while(phead!=pnode)
{
    ptmp=pnode;
    pnode=pnode->next;
    delete ptmp;
}
//删除表头;
delete phead;
phead=NULL;
}

//返回节点数目;
template<class T>
int Doublelink<T>::size(){
return count;
}

//返回链表是否为空;
template<class T>
int Doublelink<T>::is_empty(){
return count==0;
}

//获取第index位置的节点;
template<class T>
DNode<T>* Doublelink<T>::get_node(int index){
//判断获取参数的有效性;
if(index<0||index>count)
{
    cout<<"get node falied!the index in out of bound"<<endl;
    return NULL;
}
//正向查找
if(index<=count/2)
{
    int i=0;
    DNode<T>* pindex=phead->next;
    while(i++<index){
        pindex=pindex->next;
    }
    return pindex;
}

//反向查找;
int  j=0;
int rindex=count-index-1;
DNode<T>* prindex=phead->prev;
while(j++<rindex)
{
    prindex=prindex->prev;
}
return prindex;
};

//获取第index位置的节点位置;
template<class T>
T Doublelink<T>::get(int index){
return get_node(index)->value;
}

//获取第一个节点的值;
template<class T>
T Doublelink<T>::get_first(){
return get_node(0)->value;
}

//获取最后一个节点的值；
template<class T>
T Doublink<T>::get_last(){
return get_node(cout-1)->value;
}

//讲解点插入到第index位置之前
template<class T>
int Doublelink<T>::insert(int index,T t){
if(index==0)
    return insert_first(t);
    DNode<T> *pindex=get_node(index);
    DNode<T> *pnode=new DNode<T>(t,pindex->prev,pindex);
    pindex->prev->next=pnode;
    pindex->prev=pnode;
    count++;
    return 0;
}

//将节点插入第一个节点处
template<class T>
int Doublelink<T>::insert_first(T t){
DNode<T> *pnode=new DNode<T>(t,phead,phead->next);
phead->next->prev=pnode;
phead->next=pnode;
count++;
return 0;
}

//将节点追加到末尾
template<class T>
int Doublelink<T>::append_last(T t){
DNode<T> *pnode(t,phead->prev,phead);
phead->prev->next=ponde;
phead->prev=pnode;
count++;
return 0;
}

//删除第index处节点;
template<class T>
int Doublelik<T>::del(int index){
DNode<T> *pindex=get_node(index);
pindex->next->prev=pindex->prev;
pindex->prev->next=pindex->next;
//pindex->prev->next=prev->next;
//pindex->next->prev=pindex->prev;
delete pindex;
count--;
return 0;
}

//删除第一个节点
template<class T>
int Doublelink<T>::delete_first(){
return del(0);
}

//删除最后一个节点
template<class T>
int Doublelink<T>::delete_first(){
return del(count-1);
}
#endif // DBLINKLIST_H_INCLUDED
