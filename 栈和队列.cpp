//链栈
/*栈中元素        输出结果
                18
-               18 9
- *             18 9
- *(            18 9
- *(            18 9 4
- *(+           18 9 4 3
- *             18 9 4 3 +
-               18 9 4 3 + *
                18 9 4 3 + * -
中缀表达式：18-9*(4+3)=后缀表达式(逆波兰式)：18 9 4 3 + * -
                1
+               1 2
+ *             1 2 3
+               1 2 3 *
                1 2 3 * +
-               1 2 3 * +
-               1 2 3 * + 4
- /             1 2 3 * + 4
- /             1 2 3 * + 4 2
-               1 2 3 * + 4 2 /
                1 2 3 * + 4 2 / -
中缀表达式：1+2*3-4/2=后缀表达式(逆波兰式)： 1 2 3 * + 4 2 / -
                3
+               3
+               3 4
+ /             3 4
+ /(            3 4
+ /(            3 4 25
+ /( -          3 4 25
+ /( - (        3 4 25
+ /( - (        3 4 25 6
+ /( - ( +      3 4 25 6
+ /( - ( +      3 4 25 6 15
+ /( -          3 4 25 6 15 +
+ /             3 4 25 6 15 + -
+               3 4 25 6 15 + - /
+ *             3 4 25 6 15 + - /
+ *             3 4 25 6 15 + - / 8
+               3 4 25 6 15 + - / 8 *
                3 4 25 6 15 + - / 8 * +

将操作符与栈顶操作符比较 ,
若优先级大于栈顶元素则进栈，
否则退出栈顶元素并直接输出。

*/
/*阶乘及累和
#include<iostream>
using namespace std;
long long jc(long long n){
if(0==n)
    return 1;
else
    return n*jc(n-1);
}
long long  sum(long long n){
if(1==n)
    return 1;
else
    return n+sum(n-1);

}
long long sum1(long long n){
return (n+1)*n/2;
}
int main()
{
    long long a=6;
    cout<<jc(a)<<endl;
    cout<<sum1(555)<<endl;
    return 0;
}
*/
//顺序队列（循环队列）
/*#include<iostream>
using namespace std;
const int Maxsize=100;
template<class T>
class Sequeue{
public:
    T Queue[Maxsize];
    int Front;
    int Rear;

    void Iniqueue(Sequeue<T> &Q);
    void Enqueue(Sequeue<T> &Q,T t);
    void Dlqueue(Sequeue<T> &Q);
    T Gethead(Sequeue<T> &Q);
    bool Empty(Sequeue<T> &Q);
};

template<class T>
void Sequeue<T>::Iniqueue(Sequeue<T> &Q){
Q.Front=Q.Rear=Maxsize-1;
}

template<class T>
void Sequeue<T>::Enqueue(Sequeue<T> &Q,T t){
if(Q.Front==(Q.Rear+1)%Maxsize)
    cout<<"overflow"<<endl;
else
{
    Q.Rear=(Q.Rear+1)%Maxsize;
    Q.Queue[Q.Rear]=t;
}
}

template<class T>
void Sequeue<T>::Dlqueue(Sequeue<T> &Q){
if(Q.Front==Q.Rear)
    cout<<"underflow"<<endl;
else
{
    Q.Front=(Q.Front+1)%Maxsize;
}
}

template<class T>
T Sequeue<T>::Gethead(Sequeue<T> &Q){
    if(Q.Front==Q.Rear)
        cout<<"underflow"<<endl;
    else
        return Q.Queue[(Q.Front+1)%Maxsize];
}

template<class T>
bool Sequeue<T>::Empty(Sequeue<T> &Q)
{

    return Q.Front==Q.Rear;
}

int main()
{
    Sequeue<int> Q;
    Q.Iniqueue(Q);
    Q.Enqueue(Q,12);
    Q.Enqueue(Q,13);
    cout<<Q.Gethead(Q)<<endl;
    //cout<<Q.Queue[(Q.Front+2)%Maxsize]<<endl;
    Q.Dlqueue(Q);
    cout<<Q.Gethead(Q)<<endl;
    cout<<Q.Empty(Q)<<endl;
    Q.Dlqueue(Q);
    cout<<Q.Empty(Q)<<endl;
    Q.Dlqueue(Q);
    return 0;
}
*/

//链队列
#include<iostream>
#include<algorithm>
using namespace std;
template<class T>
class DNode{
public:
    T value;
    DNode<T>* next;
};

template<class T>
class Sequeue{
public:
    DNode<T>* Front;
    DNode<T>* Rear;

    Sequeue(){
    DNode<T>* p=new DNode<T>();
    if(NULL==p)
    {
        cout<<"内存非配失败"<<endl;
        exit(0);
    }
    p->next=NULL;
    Front=Rear=p;
    }

    void Enqueue(Sequeue<T> &Q,T t);
    void Dlqueue(Sequeue<T> &Q);
    bool Empty(Sequeue<T> &Q);
    T Gethead(Sequeue<T> &Q);
};

    template<class T>
    void Sequeue<T>::Enqueue(Sequeue<T> &Q,T t){
    DNode<T>* pnode=new DNode<T>();
    pnode->value=t;
    pnode->next=Q.Rear->next;
    Q.Rear->next=pnode;
    Q.Rear=pnode;
    }

    template<class T>
    void Sequeue<T>::Dlqueue(Sequeue<T> &Q){
    DNode<T>* ptmp;
    ptmp=Q.Front;
    Q.Front=Q.Front->next;
    delete ptmp;
    }

    template<class T>
    bool Sequeue<T>::Empty(Sequeue<T> &Q){
    return Q.Rear==Q.Front;
    }

    template<class T>
    T Sequeue<T>::Gethead(Sequeue<T> &Q){
    return Q.Front->next->value;
    }

    int main()
    {
        //int test
        Sequeue<int>* Q=new Sequeue<int>();
        Q->Enqueue(*Q,1);
        Q->Enqueue(*Q,2);
        cout<<Q->Gethead(*Q)<<endl;
        Q->Dlqueue(*Q);
        cout<<Q->Empty(*Q)<<endl;
        cout<<Q->Gethead(*Q)<<endl;
        Q->Dlqueue(*Q);
        cout<<Q->Empty(*Q)<<endl;

        //string test
        Sequeue<string>* Qs=new Sequeue<string>();
        Qs->Enqueue(*Qs,"helllo");
        Qs->Enqueue(*Qs,"world");
        cout<<Qs->Gethead(*Qs)<<endl;
        Qs->Dlqueue(*Qs);
        cout<<Qs->Empty(*Qs)<<endl;
        cout<<Qs->Gethead(*Qs)<<endl;
        Qs->Dlqueue(*Qs);
        cout<<Qs->Empty(*Qs)<<endl;
        //Q->Dlqueue(*Q);
        //cout<<Q->Empty(*Q)<<endl;
        return 0;
    }

