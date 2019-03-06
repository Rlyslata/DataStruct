#include<iostream>
using namespace std;
const int n=8;//¶¥µãÊý
const int e=10;//±ßÊý
bool visited[n+1];

class graph{
public:
int v[n+1];
int arcs[n+1][n+1];

void creatadj(graph &g);
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
 /*for(int k=1;k<=n;k++)
{
    cout<<g.v[k]<<" ";
}
cout<<"        "<<endl;*/
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
