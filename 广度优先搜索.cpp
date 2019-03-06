//邻接矩阵
/*#include<iostream>
using namespace std;

const int n=8;
const int e=10;
bool visited[n+1];

class graph{
public:
    int v[n+1];
    int arcs[n+1][n+1];//邻接矩阵

    void creatadj(graph &g);
    void bfs(graph g,int i);
};

void graph::creatadj(graph &g){
int i,j,k;
for(i=1;i<=n;i++)
    cin>>g.v[i];
for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    g.arcs[i][j]=0;
for(k=1;k<=e;k++)
{
    cin>>i>>j;
    g.arcs[i][j]=g.arcs[j][i]=1;
}
}

void graph::bfs(graph g,int i){
int q[n+1];
int f,r,j;
f=r=0;
cout<<g.v[i];
visited[i]=true;
r++;q[r]=i;
while(f<r)
{
    f++;//出队
    i=q[f];
    for(j=1;j<=n;j++)
        if((g.arcs[i][j]==1)&&(!visited[j]))
    {
        cout<<g.v[j];
        visited[j]=true;
        r++;//进队
        q[r]=j;
    }
}
}

int main()
{
    graph g;
    g.creatadj(g);
    g.bfs(g,1);
    return 0;
}
*/

#include<iostream>
using namespace std;

const int n=8;
const int e=10;
bool visited[n+1];

class link{
public:
    int data;
    link *next;
};

class node{
public:
    link a[n+1];

    void creatlink(node &g);
    void bfs(node g,int i);
    void print(node g);
};

void node::creatlink(node &g){
int i,j,k;
link *s;
for(i=1;i<=n;i++)
{
    g.a[i].data=i;
    g.a[i].next=NULL;
}

for(k=1;k<=e;k++)
{
    cin>>i>>j;
    s=new link();
    s->data=i;
    s->next=g.a[j].next;
    g.a[j].next=s;
    s=new link();
    s->data=j;
    s->next=g.a[i].next;
    g.a[i].next=s;
}
}
void node::bfs(node g,int i){
int f,r;
int q[n+1];
f=r=0;
link *p;
cout<<g.a[i].data;
visited[i]=true;
r++;
q[r]=i;
while(f<r)
{
    f++;
    i=q[f];
    p=g.a[i].next;
    while(p!=NULL)
    {
        if(!visited[p->data])
        {
            cout<<g.a[p->data].data;
            visited[p->data]=true;
            r++;
            q[r]=p->data;
        }
        p=p->next;
    }
}
}
void node::print(node g){
for(int i=1;i<=n;i++)
{
    link *p=g.a[i].next;
    cout<<i<<"->";
    while(p!=NULL)
    {
        cout<<p->data<<"->";
        p=p->next;
    }
    cout<<"NULL"<<endl;
}
}
int main()
{
   node g;
   g.creatlink(g);
   g.print(g);
   g.bfs(g,1);
   return 9;
}
