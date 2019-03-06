#include<iostream>
using namespace std;
char pre[10];
char ind[10];
class bitree
{
public:
    char data;
    bitree *lchild,*rchild;
    int ltag,rtag;

    bitree *creat();//����������
    void lorder(bitree* bt);//����
    void vorder(bitree* bt);//����
    void preorder(bitree *root);//����
    bitree* creat(int l1,int h1,int l2,int h2);//��������ͺ�����ԭ������
    void leaf(bitree* t);//Ҷ����
    int Leaf(bitree *T);//Ҷ����
    void inth(bitree *p);//����
    bitree* indordersucc(bitree *index);//����ֱ��ǰ��
    bitree* indordernext(bitree *index);//����ֱ�Ӻ��
    bitree* preordernext(bitree *index);//����ֱ�Ӻ��
    bitree* postordernext(bitree *index);//����ֱ��ǰ��
    void preorder_xs(bitree *root);//������������������
    void indorder_xs(bitree *root);//������������������
};

bitree *bitree::creat()
{
    bitree *q[100];
    bitree *s;
    bitree *root;
    int front=1,rear=0;
    char ch;
    root=NULL;
    cin>>ch;
    while(ch!='#')
    {
        s=NULL;
        if(ch!=',')
        {
            s=new bitree();
            s->data=ch;
            s->lchild=NULL;
            s->rchild=NULL;
        }
        rear++;
        q[rear]=s;
        if(rear==1) root=s;
        else
        {
            if(s!=NULL&&q[front]!=NULL)
            {
                if(rear%2==0)
                    {
                        cout<<q[front]->data<<"lchild is: "<<s->data<<endl;
                        q[front]->lchild=s;
                    }
                else
                    {
                        cout<<q[front]->data<<"rchild is: "<<s->data<<endl;
                        q[front]->rchild=s;
                    }
            }
            if(rear%2==1) front++;
        }
        cin>>ch;

    }
    return root;

}


/*
bitree* bitree::creat(){
bitree *root=NULL;
char ch;
cin>>ch;
if(ch!=',')
{
    root=new bitree();
    root->data=ch;
    root->lchild=creat();
    root->rchild=creat();
}
return  root;
}
*/

//�и�������
void bitree::vorder(bitree *root){
bitree *p=root;
if(p!=NULL)
{
    vorder(p->lchild);
    cout<<p->data<<"    ";
    vorder(p->rchild);
}
}
//ǰ������
void bitree::preorder(bitree *root){
bitree *p=root;
if(p!=NULL)
{
    cout<<p->data<<"    ";
    preorder(p->lchild);
    preorder(p->rchild);
}
}
void bitree::lorder(bitree *bt){
    bitree *q[100],*p;
    int f,r;
    q[1]=bt;
    f=r=1;
    while(f<=r)
    {
        p=q[f];
        f++;
        cout<<p->data<<"    ";
        if(p->lchild!=NULL)
        {
            r++;
            q[r]=p->lchild;
        }
        if(p->rchild!=NULL)
        {
            r++;
            q[r]=p->rchild;
        }
    }
}

bitree* bitree::creat(int l1,int h1,int l2,int h2){
    bitree *t;
    int s;
    if(h1-l1!=h2-l2)
        cout<<"input error"<<endl;
    else
    {
        if(l1>h1) t=NULL;
        else
        {
            t=new bitree();
            t->data=pre[l1];
            s=l2;
            while((s<h2)&&(pre[l1]!=ind[s]))
                s++;
            if(ind[s]!=pre[l1]) cout<<"input error"<<endl;
            else
            {
                t->lchild=creat(l1+1,l1+s-l2,l2,s-1);
                t->rchild=creat(l1+s-l2+1,h1,s+1,h2);
            }
        }

    }
return t;
}
int sum=0;
void bitree::leaf(bitree* t){
   if(t!=NULL)
   {
       if(t->lchild==NULL&&t->rchild==NULL)
            sum++;
       else
       {
           leaf(t->lchild);
           leaf(t->rchild);
       }

   }

}
bitree* bitree::indordersucc(bitree *index){//���������������ֱ��ǰ��
bitree *bt=index;
if(bt->ltag==1)
bt=index->lchild;
else
{
    bt=bt->lchild;
    while(bt->rtag==0) bt=bt->rchild;
}
return bt;
}

bitree* bitree::indordernext(bitree *index){//���������������ֱ�Ӻ��
bitree *bt=index;
if(bt->rtag==1)
bt=index->rchild;
else
{
    bt=bt->rchild;
    while(bt->rtag==0) bt=bt->lchild;
}
return bt;
}

bitree* bitree::preordernext(bitree *index){
if(index->ltag==1)
    return index->rchild;
    else if(index->rtag==1)
        return index->lchild;
        else
            return NULL;
}

bitree* bitree::postordernext(bitree *index){
if(index->ltag==1)
    return index->rchild;
    else if(index->rtag==1)
    return index->lchild;
    else
    return NULL;
}

int bitree::Leaf(bitree* T)//���������Ҷ�ӽ�����Ŀ
{
if(!T) return 0; //����û��Ҷ��
else if(!T->lchild&&!T->rchild) return 1; //Ҷ�ӽ��
else return Leaf(T->lchild)+Leaf(T->rchild);//��������Ҷ������
}

bitree *Pre=NULL;
void bitree::inth(bitree *p){
    if(p!=NULL)
    {
        inth(p->lchild);
        if(p->lchild==NULL)
            p->ltag=1;
        if(p->rchild==NULL)
            p->rtag=1;
        if(Pre!=NULL)
        {
            if(Pre->rtag==1) Pre->rchild=p;
            if(p->ltag==1) p->lchild=Pre;
        }
        Pre=p;
        inth(p->rchild);
    }
}

void bitree::preorder_xs(bitree *root){//������������������
if(root==NULL)
    ;
    else
{
    bitree *bt=root;
    while(bt!=NULL)
    {
        cout<<bt->data<<"   "<<endl;
        bt=preordernext(bt);
    }
}
}

void bitree::indorder_xs(bitree *root){//������������������
if(root==NULL)
    ;
    else
{
    bitree *bt=root;
    while(bt->ltag==1)
        bt=bt->lchild;
    while(bt!=NULL)
    {
        cout<<bt->data<<"   "<<endl;
        bt=indordernext(bt);
    }
}
}


int main()
{
    int l1,h1,l2,h2,n;
    int i=1;
    bitree T;
    bitree *root,*bt;
    root=T.creat();
    if(NULL==root->rchild)
      cout<<"�ҿ�"<<endl;
    T.leaf(root);
    cout<<"leaf="<<T.Leaf(root)<<endl;
    cout<<"leaf="<<sum<<endl;
    cout<<"�������"<<endl;
    T.lorder(root);
    cout<<endl;
    cout<<"ǰ������"<<endl;
    T.preorder(root);
    cout<<endl;
    cout<<"�и�����"<<endl;
    T.vorder(root);
    cout<<endl;
    cin>>n;
    for(i=1;i<=n&&i<10;i++)
        cin>>pre[i];
    l1=1;h1=i-1;
    for(i=1;i<=n&&i<10;i++)
        cin>>ind[i];
    l2=1;h2=i-1;
    bt=bt->creat(l1,h1,l2,h2);
    cout<<"�������"<<endl;
    bt->lorder(bt);
    cout<<endl;
    cout<<"ǰ������"<<endl;
    bt->preorder(bt);
    cout<<endl;
    cout<<"�и�����"<<endl;
    bt->vorder(bt);
    cout<<endl;
    return 0;
}



