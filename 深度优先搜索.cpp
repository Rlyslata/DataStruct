//邻接矩阵
/*#include<iostream>
using namespace std;
const int n=8;//顶点数
const int e=10;//边数
bool visited[n+1];

class graph{
public:
int v[n+1];
int arcs[n+1][n+1];

void creatadj(graph &g);//不使用引用就不能改变数组的值,哎，竟然在这个地方栽了跟头
void dfs(graph g,int i);
};

void graph::creatadj(graph &g){
int i,j,k;
for(k=1;k<=n;k++)
{
    g.v[k]=k;
    cout<<g.v[k];
}
cout<<endl;
for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
{
    g.arcs[i][j]=0;
}
for(k=1;k<=e;k++)
{
    cin>>i>>j;
    g.arcs[i][j]=1;
    g.arcs[j][i]=1;
}
}

void graph::dfs(graph g,int i){
 int j;
 cout<<g.v[i]<<endl;;
 visited[i]=true;
 for(j=1;j<=n;j++)
 {
     if((g.arcs[i][j]==1)&&(!visited[j]))
        dfs(g,j);
 }
}

int main()
{
    graph g;
    g.creatadj(g);
    for(int i=1;i<=n;i++)
        visited[i]=false;
    g.dfs(g,1);
    return 0;
}
*/



//邻接表
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
    void dfs(node g,int i);
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

void node::dfs(node g,int i){
link *p;
cout<<g.a[i].data;
visited[i]=true;
p=g.a[i].next;
while(p!=NULL)
{
    if(!visited[p->data])
        dfs(g,p->data);
    p=p->next;
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
    for(int i=1;i<=n;i++)
        visited[i]=false;
    g.creatlink(g);
    g.print(g);
    g.dfs(g,1);
    return 0;
}



