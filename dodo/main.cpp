//: C15:OperatorPolymorphism.cpp
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
// Polymorphism with overloaded operators
#include <iostream>
#include"../nkkk.h"
using namespace std;
int main() {
    int data1[MAXN][MAXN];
  int (*pa)[MAXN]=data1;
  int m1,n1;
  int data2[MAXN][MAXN];
  int (*pb)[MAXN]=data2;
  int m2,n2;
  cin>>m1>>n1;
  for(int i=0;i<m1;i++)
    for(int j=0;j<n1;j++)
  {
      cin>>*(*(pa+i)+j);
  }


  cin>>m2>>n2;
  for(int i=0;i<m2;i++)
    for(int j=0;j<n2;j++)
  {
      cin>>*(*(pb+i)+j);
  }

  Matrix a(pa,m1,n1),b(pb,m2,n2);
  Math *M1=&a;Math *M2=&b;
  (*M1)*(*M2);
  cout<<"xiao gao pan"<<"  161 10161828"<<endl;

  /*int data1[MAXN][MAXN];
  int (*pa)[MAXN]=data1;
  int m1,n1,c;
  cin>>m1>>n1;
  for(int i=0;i<m1;i++)
    for(int j=0;j<n1;j++)
  {
      cin>>*(*(pa+i)+j);
  }

   Matrix a(pa,m1,n1);
   cin>>c;
   Scalar C(c);
   Math *M1=&a;Math *M2=&C;
  (*M1)*(*M2);*/
  return 0;
} ///:~
