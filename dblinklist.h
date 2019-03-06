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

//���캯��
template<class T>
Doublelink<T>::Doublelink():count(0){
//������ͷ��ע���ͷû�����ݣ�
phead=new DNode<T>();
phead->prev=phead->next=phead;
//�����������Ϊ0��
count=0;
}

//��������
template<class T>
Doublink<T>::~Doublelink(){
//ɾ�����нڵ�;
DNode<T> *ptmp;
DNode<T> *pnode=phead->next;
while(phead!=pnode)
{
    ptmp=pnode;
    pnode=pnode->next;
    delete ptmp;
}
//ɾ����ͷ;
delete phead;
phead=NULL;
}

//���ؽڵ���Ŀ;
template<class T>
int Doublelink<T>::size(){
return count;
}

//���������Ƿ�Ϊ��;
template<class T>
int Doublelink<T>::is_empty(){
return count==0;
}

//��ȡ��indexλ�õĽڵ�;
template<class T>
DNode<T>* Doublelink<T>::get_node(int index){
//�жϻ�ȡ��������Ч��;
if(index<0||index>count)
{
    cout<<"get node falied!the index in out of bound"<<endl;
    return NULL;
}
//�������
if(index<=count/2)
{
    int i=0;
    DNode<T>* pindex=phead->next;
    while(i++<index){
        pindex=pindex->next;
    }
    return pindex;
}

//�������;
int  j=0;
int rindex=count-index-1;
DNode<T>* prindex=phead->prev;
while(j++<rindex)
{
    prindex=prindex->prev;
}
return prindex;
};

//��ȡ��indexλ�õĽڵ�λ��;
template<class T>
T Doublelink<T>::get(int index){
return get_node(index)->value;
}

//��ȡ��һ���ڵ��ֵ;
template<class T>
T Doublelink<T>::get_first(){
return get_node(0)->value;
}

//��ȡ���һ���ڵ��ֵ��
template<class T>
T Doublink<T>::get_last(){
return get_node(cout-1)->value;
}

//�������뵽��indexλ��֮ǰ
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

//���ڵ�����һ���ڵ㴦
template<class T>
int Doublelink<T>::insert_first(T t){
DNode<T> *pnode=new DNode<T>(t,phead,phead->next);
phead->next->prev=pnode;
phead->next=pnode;
count++;
return 0;
}

//���ڵ�׷�ӵ�ĩβ
template<class T>
int Doublelink<T>::append_last(T t){
DNode<T> *pnode(t,phead->prev,phead);
phead->prev->next=ponde;
phead->prev=pnode;
count++;
return 0;
}

//ɾ����index���ڵ�;
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

//ɾ����һ���ڵ�
template<class T>
int Doublelink<T>::delete_first(){
return del(0);
}

//ɾ�����һ���ڵ�
template<class T>
int Doublelink<T>::delete_first(){
return del(count-1);
}
#endif // DBLINKLIST_H_INCLUDED
