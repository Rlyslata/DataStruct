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

    bitree *creat();//建立二叉树
    void lorder(bitree* bt);//层序
    void vorder(bitree* bt);//中序
    void preorder(bitree *root);//先序
    bitree* creat(int l1,int h1,int l2,int h2);//根据先序和后续还原二叉树
    void leaf(bitree* t);//叶子数
    int Leaf(bitree *T);//叶子数
    void inth(bitree *p);//线索
    bitree* indordersucc(bitree *index);//中序直接前驱
    bitree* indordernext(bitree *index);//中序直接后继
    bitree* preordernext(bitree *index);//先序直接后继
    bitree* postordernext(bitree *index);//后序直接前驱
    void preorder_xs(bitree *root);//先序线索二叉树遍历
    void indorder_xs(bitree *root);//中序线索二叉树遍历
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

//中根遍历；
void bitree::vorder(bitree *root){
bitree *p=root;
if(p!=NULL)
{
    vorder(p->lchild);
    cout<<p->data<<"    ";
    vorder(p->rchild);
}
}
//前根遍历
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
bitree* bitree::indordersucc(bitree *index){//查找中序二叉树的直接前驱
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

bitree* bitree::indordernext(bitree *index){//查找中序二叉树的直接后继
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

int bitree::Leaf(bitree* T)//求二叉树中叶子结点的数目
{
if(!T) return 0; //空树没有叶子
else if(!T->lchild&&!T->rchild) return 1; //叶子结点
else return Leaf(T->lchild)+Leaf(T->rchild);//左子树的叶子数加
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

void bitree::preorder_xs(bitree *root){//先序线索二叉树遍历
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

void bitree::indorder_xs(bitree *root){//中序线索二叉树遍历
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
      cout<<"右空"<<endl;
    T.leaf(root);
    cout<<"leaf="<<T.Leaf(root)<<endl;
    cout<<"leaf="<<sum<<endl;
    cout<<"层序遍历"<<endl;
    T.lorder(root);
    cout<<endl;
    cout<<"前根遍历"<<endl;
    T.preorder(root);
    cout<<endl;
    cout<<"中根遍历"<<endl;
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
    cout<<"层序遍历"<<endl;
    bt->lorder(bt);
    cout<<endl;
    cout<<"前根遍历"<<endl;
    bt->preorder(bt);
    cout<<endl;
    cout<<"中根遍历"<<endl;
    bt->vorder(bt);
    cout<<endl;
    return 0;
}



