#ifndef NKKK_H//_INCLUDED
#define NKKK_H//_INCLUDED
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
#define MAXN 10
class Matrix;
class Scalar;
class Vector;

class Math {
public:
  virtual Math& operator*(Math& rv) = 0;
  virtual Math& multiply(Matrix*) = 0;
  virtual Math& multiply(Scalar*) = 0;
  virtual Math& multiply(Vector*) = 0;
  virtual ~Math() {}
};

class Matrix : public Math {
public:
   int(*p)[MAXN]=new int [MAXN][MAXN];
   int m,n;
   Matrix(int (*ptr)[MAXN],int m1,int n1){
       m=m1;
       n=n1;
   for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    {
        *(*(p+i)+j)=*(*(ptr+i)+j);
    }
   }
   virtual ~Matrix(){delete [] p;}
   Math& operator*(Math& rv) {
    return rv.multiply(this); // 2nd dispatch
  }
  Math& multiply(Matrix* ptr);
  Math& multiply(Scalar* ptr);
  Math& multiply(Vector* ptr);
  void print()
  {
      for(int i=0;i<m;i++)
      {
          for(int j=0;j<n;j++)
      {
          cout<<*(*(p+i)+j)<<"     ";
      }
      cout<<endl;
      }

  }
};

class Scalar : public Math  {
public:
  int *p=new int;
  Scalar(int c1){*p=c1;}
  Math& operator*(Math& rv) {
    return rv.multiply(this); // 2nd dispatch
  }
  virtual~Scalar(){delete p;}
  Math& multiply(Matrix* ptr);
  Math& multiply(Scalar* ptr);
  Math& multiply(Vector* ptr);
  void print()
  {
      cout<<*p<<endl;
  }
};

class Vector : public Math  {
public:
   int (*p)[MAXN]=new int [MAXN][MAXN];
   int m,n;
   Vector(int (*ptr)[MAXN],int m1,int n1){
       m=m1;
       n=n1;
   for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    {
        *(*(p+i)+j)=*(*(ptr+i)+j);
    }
   }
   virtual~Vector(){delete [] p;}
  Math& operator*(Math& rv) {
    return rv.multiply(this); // 2nd dispatch
  }
  Math& multiply(Matrix* ptr);
  Math& multiply(Scalar* ptr);
  Math& multiply(Vector* ptr);
  void print()
  {
      for(int i=0;i<m;i++)
      {
          for(int j=0;j<n;j++)
      {
          cout<<*(*(p+i)+j)<<"     ";
      }
      cout<<endl;
      }

  }
};


    Matrix& matrixm(int (*pw)[MAXN],int m1,int n1,int (*pq)[MAXN],int m2,int n2)
    {
        Matrix *a=new Matrix(pw,m1,n2);
        int i, j, k;
    if (n1 != m2)
        {cout<<"data error"<<endl;exit(0);}
    for (i = 0; i < m1; i++)
        for (j = 0; j < n2; j++)
            for (*(*(a->p+i)+j) = k = 0; k < n1; k++)
               *(*(a->p+i)+j) += *(*(pw+i)+j) * (*(*(pq+i)+j));
    return *a;
    }


  Matrix &matrixs(int(*pw)[MAXN],int m1,int n1,int *c)
    {
        Matrix *a=new Matrix(pw,m1,n1);
        for(int i=0;i<m1;i++)
        {
            for(int j=0;j<n1;j++)
            *(*(a->p+i)+j)=*(*(pw+i)+j) * (*c);
        }
        return *a;
    }
   Scalar &scalars(int *c1,int *c2)
    {
        Scalar *a=new Scalar(0);
        *(a->p)=(*c1)*(*c2);
        return *a;
    }



Math& Matrix::multiply(Matrix* ptr) {
    matrixm(ptr->p,ptr->m,ptr->n,this->p,this->m,this->n).print();
    return *this;
  }
  Math& Matrix::multiply(Scalar* ptr) {
   matrixs(this->p,this->m,this->n,ptr->p).print();
    return *this;
  }
  Math& Matrix::multiply(Vector* ptr) {
  matrixm(ptr->p,ptr->m,ptr->n,this->p,this->m,this->n).print();
    return *this;
  }

  Math& Scalar::multiply(Matrix* ptr) {
  matrixs(ptr->p,ptr->m,ptr->n,this->p).print();
    return *this;
  }
  Math& Scalar::multiply(Scalar* ptr) {
    scalars(ptr->p,this->p).print();
    return *this;
  }
  Math& Scalar::multiply(Vector* ptr) {
    matrixs(ptr->p,ptr->m,ptr->n,this->p).print();
    return *this;
  }

  Math& Vector::multiply(Matrix*ptr) {
    matrixm(ptr->p,ptr->m,ptr->n,this->p,this->m,this->n).print();
    return *this;
  }
 Math& Vector::multiply(Scalar* ptr) {
      matrixs(this->p,this->m,this->n,ptr->p).print();
    return *this;
  }

  Math& Vector::multiply(Vector* ptr) {
     matrixm(ptr->p,ptr->m,ptr->n,this->p,this->m,this->n).print();
    return *this;
  }
#endif // NKKK_H_INCLUDED
