//对称矩阵a[n][n]
//将其存储在s[n*(n+1)/2]中
//a[i][j]=a[j][i]=s[1+2+....+i+j]=s[(i+1)*i/2+j](i>=j)
//或a[i][j]=a[j][i]=s[n+n-1+n-(i-1)+j-i]=s[n*i-j*(j-1)/2+j-i](i<=j)

//上三角矩阵
//a[i][j]=a[j][i]=s[n+n-1+n-(i-1)+j-i]=s[n*i-j*(j-1)/2+j-i](i<=j)

//下三角矩阵
//a[i][j]=a[j][i]=s[1+2+....+i+j]=s[(i+1)*i/2+j](i>=j)

//对角阵
//a[i][j]=s[3*i](i==j),s[3*i-1](i=j-1),s[3*i+1](i=j+1)


/*#include<iostream>
using namespace std;
const int MAX=9;

class Node{
public:
    int i,j;//非零元的行列号;
    int v;//非零元的值;
};

class sparmatrix{
public:
    int rows,cols;//稀疏矩阵的行列数;
    int terms;//稀疏矩阵非零元的个数;
    Node data[MAX];//三元组表;

    void transpose(sparmatrix a,sparmatrix b);
    void fastrans(sparmatrix a,sparmatrix b);
};

void sparmatrix::transpose(sparmatrix a,sparmatrix b){
    b.rows=a.cols;
    b.cols=a.rows;
    b.terms=a.rows;
    if(a.terms>0&&a.terms<MAX)
    {
        int bno=0;
        for(int col=0;col<a.cols;col++)
            for(int ano=0;ano<a.terms;ano++)
            if(a.data[ano].j==col)
            {
                b.data[bno].j=a.data[ano].i;
                b.data[bno].i=a.data[ano].j;
                b.data[bno].v=a.data[ano].v;
                bno++;
            }

    }
    else
    {
        cout<<"overflow"<<endl;
        return;
    }
    for(int i=0;i<a.terms;i++)
        cout<<b.data[i].i<<"    "<<b.data[i].j<<"   "<<b.data[i].v<<endl;
}

void sparmatrix::fastrans(sparmatrix a,sparmatrix b){
    int pot[9],col,ano,bno;
    b.rows=a.cols;
    b.cols=a.rows;
    b.terms=a.terms;
    if(b.terms>0)
    {
        for(col=0;col<a.cols;col++)
        {
            pot[col]=0;
        }
        for(int t=0;t<a.terms;t++)
        {
            col=a.data[t].j;
            pot[col+1]=pot[col+1]+1;
        }
        for(col=1;col<a.terms;col++)
        {
            pot[col]=pot[col]+pot[col-1];
        }
        for(ano=0;ano<a.terms;ano++)
        {
            col=a.data[ano].j;
            bno=pot[col];
            b.data[bno].j=a.data[ano].i;
            b.data[bno].i=a.data[ano].j;
            b.data[bno].v=a.data[ano].v;
            pot[col]=pot[col]+1;

        }
    }
    for(int i=0;i<b.terms;i++)
    {
        cout<<b.data[i].i<<"    "<< b.data[i].j<<"      "<<b.data[i].v<<endl;
    }
}

int main()
{
    sparmatrix a,b;
    cin>>a.rows>>a.cols>>a.terms;
    for(int i=0;i<a.terms;i++)
        cin>>a.data[i].i>>a.data[i].j>>a.data[i].v;
    for(int i=0;i<a.terms;i++)
        cout<<a.data[i].i<<"    "<<a.data[i].j<<"   "<<a.data[i].v<<endl;
        cout<<endl;
        cout<<"转置"<<endl;
        a.transpose(a,b);
        cout<<endl;
        cout<<"快速转置"<<endl;
        a.fastrans(a,b);
        return 0;
}
*/
//十字链表
/*#include<iostream>
using namespace std;

class linknode{
public:
    int i,j;
    union vnext{
    int v;
    linknode *next;
    }k;

    linknode *rptr,*cptr;
    linknode* creatlinkmat();
};
linknode* linknode::creatlinkmat(){
int m,n,t,s,i,j,k;
linknode *p,*q,*cp[100],*hm;
cout<<"请输入稀疏矩阵的行列数及非零元的个数"<<endl;
cin>>m>>n>>t;
s=m>n?m:n;
hm=new linknode();
hm->i=m;
hm->j=n;
cp[0]=hm;
for(i=1;i<=s;i++)
{
    p=new linknode();
    p->i=0;
    p->j=0;
    p->rptr=p;
    p->cptr=p;
    cp[i]=p;
    cp[i-1]->k.next=p;
}
cp[s]->k.next=hm;
for(int x=1;x<=t;x++)
{
    cout<<"请输入一个三元组(i,j,v)"<<endl;
    cin>>i>>j>>k;//i>=1,j>=1;因为表头,行列链表头部储存数据,若输入i=0，则在执行p->rptr=q->rptr;q->rptr=p;时会出错,因为cp[0]没行列指向。
    p=new linknode();
    p->i=i;
    p->j=j;
    p->k.v=k;
    //将p插入i行链表中
    q=cp[i];
    while((q->rptr!=cp[i])&&(q->rptr->j<j))
    q=q->rptr;
    p->rptr=q->rptr;
    q->rptr=p;
    //将p插入j列链表中;
    q=cp[j];
    while((q->cptr!=cp[j])&&(q->cptr->i<i))
        q=q->cptr;
    p->cptr=q->cptr;
    q->cptr=p;
}
return hm;
}

int main()
{
    linknode *q,*p,T;
    linknode *hm=NULL;
    hm=T.creatlinkmat();
    p=hm->k.next;
    while(p->k.next!=hm)
    {
        q=p->rptr;
        while(q->rptr!=p)
        {
            cout<<q->i<<"   "<<q->j<<"  "<<q->k.v<<endl;
            q=q->rptr;
        }
        if(q!=p)
            cout<<q->i<<"   "<<q->j<<"  "<<q->k.v<<endl;
            cout<<endl;
            p=p->k.next;
    }
    return 0;
}
*/
//十字链表相加
#include<iostream>
using namespace std;

class linknode{
public:
    int i,j;
    union vnext{
    int v;
    linknode *next;
    }k;

    linknode *rptr,*cptr;
    linknode* creatlinkmat();
    linknode* matadd(linknode *a,linknode *b);
};

linknode* linknode::creatlinkmat(){
int m,n,t,s,i,j,k;
linknode *p,*q,*cp[100],*hm;
cout<<"请输入稀疏矩阵的行列数及非零元的个数"<<endl;
cin>>m>>n>>t;
s=m>n?m:n;
hm=new linknode();
hm->i=m;
hm->j=n;
cp[0]=hm;
for(i=1;i<=s;i++)
{
    p=new linknode();
    p->i=0;
    p->j=0;
    p->rptr=p;
    p->cptr=p;
    cp[i]=p;
    cp[i-1]->k.next=p;
}
cp[s]->k.next=hm;
for(int x=1;x<=t;x++)
{
    cout<<"请输入一个三元组(i,j,v)"<<endl;
    cin>>i>>j>>k;//i>=1,j>=1;因为表头,行列链表头部储存数据,若输入i=0，则在执行p->rptr=q->rptr;q->rptr=p;时会出错,因为cp[0]没行列指向。
    p=new linknode();
    p->i=i;
    p->j=j;
    p->k.v=k;
    //将p插入i行链表中
    q=cp[i];
    while((q->rptr!=cp[i])&&(q->rptr->j<j))
    q=q->rptr;
    p->rptr=q->rptr;
    q->rptr=p;
    //将p插入j列链表中;
    q=cp[j];
    while((q->cptr!=cp[j])&&(q->cptr->i<i))
        q=q->cptr;
    p->cptr=q->cptr;
    q->cptr=p;
}
return hm;
}

/*linknode* linknode::matadd(linknode *ha,linknode *hb){
linknode *pa,*pb,*qa,*ca,*cb,*p,*q;
linknode* hl[100];
int i,j,n;
if((ha->i!=hb->i)||(ha->j!=hb->j))
    cout<<"矩阵不匹配,不能相加"<<endl;
else
{
    p=ha->k.next;
    n=ha->j;
    for(i=1;i<=n;i++)
    {
        hl[i]=p;
        p=p->k.next;
    }
    ca=ha->k.next;
    cb=hb->k.next;
    while(ca->i==0)
    {
        pa=ca->rptr;
        pb=cb->rptr;
        qa=ca;
        while(pb->j!=0)
        {
            if((pa->j<pb->j)&&(pa->j!=0))
            {
                qa=pa;
                pa=pa->rptr;
            }
            else if((pa->j>pb->j)||(pa->j==0))
            {
                p=new linknode();
                p->i=pb->i;
                p->j=pb->j;
                p->k.v=pb->k.v;
                qa->rptr=p;
                p->rptr=pa;
                qa=p;
                pb=pb->rptr;
                j=p->j;
                q=hl[j]->cptr;
                while((q->i<p->i)&&(q->i!=0))
                {
                    hl[j]=q;
                    q=hl[j]->cptr;
                }
                hl[j]->cptr=p;
                p->cptr=q;
                hl[j]=p;
            }
            else
            {
                pa->k.v=pa->k.v+pb->k.v;
                if(0==pa->k.v)
                {
                    qa->rptr=pa->rptr;
                    j=pa->j;q=hl[j]->cptr;
                    while((q->i<pa->i)&&(q->i!=0))
                    {
                        hl[j]=q;
                        q=hl[j]->cptr;
                    }
                    hl[j]->cptr=q->cptr;
                    pa=pa->rptr;
                    pb=pb->rptr;
                    delete q;
                }
                else
                {
                    qa=pa;
                    pa=pa->rptr;
                    pb=pb->rptr;
                }
            }
            }
        }
       ca=ca->k.next;
       cb=cb->k.next;
    }
    return ha;
}
*/
linknode* linknode::matadd(linknode *ha,linknode *hb){
linknode *pa,*pb,*qa,*ca,*cb,*p,*q;
linknode *hl[100];
int i,j,n;
if((ha->i!=hb->i)||(ha->j!=hb->j))
    cout<<"矩阵不匹配，不能相加"<<endl;
else
{
    p=ha->k.next;
    n=ha->j;
    for(i=1;i<=n;i++)
    {
        hl[i]=p;
        p=p->k.next;
    }
    ca=ha->k.next;
    cb=ha->k.next;
    while(0==ca->i)
    {
        pa=ca->rptr;
        pb=cb->rptr;
        qa=ca;
        while(pb->j!=0)
        {
            if((pa->j<pb->j)&&(pa->j!=0))
            {
                qa=pa;pa=pa->rptr;
            }
            else if((pa->j>pb->j)||(pa->j==0))
            {
                p=new linknode();
                p->i=pb->i;
                p->j=pb->j;
                p->k.v=pb->k.v;
                qa->rptr=p;
                p->rptr=pa;
                qa=p;
                pb=pb->rptr;
                j=p->j;q=hl[j]->cptr;
                while((q->i<i)&&(q->i!=0))
                {
                    hl[j]=q;q=hl[j]->cptr;
                }
                hl[j]->cptr=p;
                p->cptr=q;
                hl[j]=p;
            }
            else
            {
                pa->k.v=pa->k.v+pb->k.v;
                if(pa->k.v==0)
                {
                    qa->rptr=pa->rptr;
                    j=pa->j;q=hl[j]->cptr;
                    while(q->i<pa->i)
                    {
                        hl[j]=q;q=hl[j]->cptr;
                    }
                    hl[j]->cptr=q->cptr;
                    pa=pa->rptr;pb=pb->rptr;
                    delete q;
                }
            else
            {
                qa=pa;pa=pa->rptr;
                pb=pb->rptr;
            }
            }
        }
    ca=ca->k.next;cb=cb->k.next;
}
}
return ha;
}
void print(linknode* hm){
linknode *p,*q,*r;
p=hm->k.next;
r=p;
while(p->k.next!=r)
{
    q=p->rptr;
    while(q->rptr!=p)
    {
        cout<<q->i<<"   "<<q->j<<"  "<<q->k.v<<endl;
        q=q->rptr;
    }
    if(p!=q)
        cout<<q->i<<"   "<<q->j<<"  "<<q->k.v<<endl;
    cout<<endl;
    p=p->k.next;
}
}
int main()
{
    linknode T1,T2;
    linknode *ha=NULL,*hb=NULL,*hc=NULL;
    ha=T1.creatlinkmat();
    hb=T2.creatlinkmat();
    print(ha);
    cout<<endl;
    print(hb);
    cout<<endl;
    hc=T1.matadd(ha,hb);
    print(hc);
    cout<<endl;
    return 0;
}
