//普里姆(prim)
/*#include<iostream>
using namespace std;
const int INF=0x3f3f3f3f;
const int n=6;
const int e=10;
class edge_set{
public:

int fromvex;//树边的起点
int endvex;//树边的终点
int weight;//树边的权
};

class min_tree{
public:
    edge_set ct[n+1];//最小生成树的边集
    int s[n+1][n+1];//网邻接矩阵

    void prim(min_tree &t);
};

void min_tree::prim(min_tree &t){
int i,j,k,Min,t1,m,w;
for(i=1;i<n;i++)
{
    t.ct[i].fromvex=1;
    t.ct[i].endvex=i+1;
    t.ct[i].weight=t.s[1][i+1];
}
for(k=2;k<=n;k++)
{
    m=k-1;
    Min=INF;
    for(j=k-1;j<=n-1;j++)
    {
        if(t.ct[j].weight<Min)
        {
            Min=t.ct[j].weight;
            m=j;
        }
    }
    edge_set temp=t.ct[k-1];
    t.ct[k-1]=t.ct[m];
    t.ct[m]=temp;
    j=t.ct[k-1].endvex;
    for(i=k;i<n;i++)
    {
        t1=t.ct[i].endvex;
        w=t.s[j][t1];
        if(w<t.ct[i].weight)
        {
            t.ct[i].weight=w;
            t.ct[i].fromvex=j;
        }
    }

}
}

int main()
{
    int i,w,j;
    min_tree t;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        if(i==j)
        t.s[i][j]=0;
    else
        t.s[j][i]=INF;
    for(int k=1;k<=e;k++)
    {
        cout<<"请输入一条边上的权值"<<endl;
        cin>>i>>j>>w;
        cout<<endl;
        t.s[i][j]=w;
        t.s[j][i]=w;
    }
    t.prim(t);
    for(i=1;i<n;i++)
    {
        cout<<t.ct[i].fromvex<<"    ";
        cout<<t.ct[i].endvex<<"     ";
        cout<<t.ct[i].weight<<endl;
    }
    return 0;
}
*/
//克鲁斯卡尔(kruska)
#include<iostream>
using namespace std;

const int n=6;
const int e=10;

class edge_set{                                     //定义一条边
public:
    int fromvex;
    int endvex;
    int weight;
};

class tree{                                         //定义生成树
public:
    edge_set c[n];                                   //存放生成树的边
    edge_set ge[e+1];
    int s[n+1][n+1];

    void kruska(tree &t);
};

void tree::kruska(tree &t){
int i,j;
for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    if(i==j) t.s[i][j]=1;
    else t.s[i][j]=0;
int k=1;
int d=1;
int m1,m2;
while(k<n)
{
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
    {
        if(t.ge[d].fromvex==j&&t.s[i][j]==1)
        m1=i;
        if(t.ge[d].endvex==j&&t.s[i][j]==1)
        m2=i;
    }

    if(m1!=m2)
    {
        t.c[k]=t.ge[d];
        k++;
        for(j=1;j<=n;j++)
        {
            t.s[m1][j]=t.s[m1][j]||t.s[m2][j];
            t.s[m2][j]=0;
        }
    }
    d++;
}
}
int main(void)
{
    int i=1;
    tree t;
    for(i=1;i<=e;i++)
    {
        cin>>t.ge[i].fromvex;
        cin>>t.ge[i].endvex;
        cin>>t.ge[i].weight;
    }
    t.kruska(t);
    for(i=1;i<n;i++)
    {
        cout<<t.c[i].fromvex<<"     ";
        cout<<t.c[i].endvex<<"      ";
        cout<<t.c[i].weight<<endl;
    }
    return 9;
}


