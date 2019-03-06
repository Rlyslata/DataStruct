//双亲孩子法
#include<iostream>
using  namespace std;

const int n=8;//叶子数目;
const int m=2*n-1;//树的棵数;
class tree{
public:
    float weight;
    int parent;
    int lch,rch;
    void creathuffmantree();
};

tree hftree[m+1];
void tree::creathuffmantree(){
int i,j,p1,p2;
float s1,s2;
for(i=1;i<=m;i++)
{
    hftree[i].weight=0;
    hftree[i].parent=0;
    hftree[i].lch=0;
    hftree[i].rch=0;
}
for(i=1;i<=n;i++)
    cin>>hftree[i].weight;
for(i=n+1;i<=m;i++)
{
    p1=p2=0;
    s1=s2=32767;
    for(j=1;j<=i-1;j++)
        {
        if(hftree[j].parent==0)
            if(hftree[j].weight<s1)
            {
            s2=s1;
            s1=hftree[j].weight;
            p2=p1;
            p1=j;
            }
            else
            if(hftree[j].weight<s2)
            {
            s2=hftree[j].weight;
            p2=j;
            }
        }
    hftree[i].weight=hftree[p1].weight+hftree[p2].weight;
    hftree[i].lch=p1;
    hftree[i].rch=p2;
    hftree[p1].parent=i;
    hftree[p2].parent=i;
}
for(i=1;i<=m;i++)
    cout<<i<<"  "<<hftree[i].weight<<"  "<<hftree[i].parent<<"  "<<hftree[i].lch<<" "<<hftree[i].rch<<endl;
}

int main()
{
    tree t;
    t.creathuffmantree();
    return 0;
}
