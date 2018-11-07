#include<iostream>
using namespace std;

class MyVector{
private:
  double *A;
  int length;
  int index;
public:
  friend ostream& operator <<(ostream& out,MyVector v);
   MyVector():index(0){}
   ~MyVector(){free(A);}
   MyVector(int l):index(0),length(l){
     A=(double*)malloc (length*sizeof(double));
   }
   MyVector(MyVector &temp_vector)
   {
     length=temp_vector.length;
     A=new double[temp_vector.length];
     for(int i=0;i<length;i++)
     A[i]=temp_vector.A[i];
   }
   bool redim(int l)
   {
     double* check=NULL;
     length=l;
     check=(double*) realloc(A,length*sizeof(double));
     A=check;
     if(check==NULL)
     return false;
     else
     return true;
   }
   void operator = (const MyVector &v)
   {
     length=v.length;
     //A=new double[length];
     for(int i=0;i<length;i++)
     A[i]=v.A[i];
   }
   double operator -(MyVector v)  // '-' Use for inner product operator
   {
     double product=0;
     if(length==v.length)
     {
       for(int i=0;i<length;i++)
       product+=A[i]*v.A[i];
       return product;
     }
     else
     cout<<"Error"<<endl;
   }
   MyVector operator *(int k)
   {
     MyVector temp;
     temp.A=new double[length];
    for(int i=0;i<length;i++)
    temp.A[i]=(this->A[i])*k;
    return temp;
   }
   MyVector operator +(MyVector v)
   {
     MyVector temp_v;
     temp_v.length=length;
     temp_v.A=new double[length];
     for(int i=0;i<length;i++)
     temp_v.A[i]=this->A[i]+v.A[i];
     return temp_v;
   }

   void setlength(int l)
   {
     length=l;
     A=(double*)malloc (length*sizeof(double));
   }

   int size_v()
   {
     return length;
   }
   void add(double item)
   {
     A[index++]=item;
   }
   void del()
  {
    if(index>=0)
     A[--index]=0;
     else
     cout<<"\nError";
   }
   void show_V()
   {
     cout<<"Vector Items:\n\n";
     for(int i=0;i<length;i++)
     cout<<A[i]<<endl;

   }

};
ostream& operator <<(ostream& out,MyVector v)
{
  for(int i=0;i<v.length;i++)
  out<<v.A[i]<<" ";
  out<<endl;
  return out;
}
int main(int argc, char const *argv[]) {

  MyVector v1(4),v2(5),v3,v4;
  v1.add(1);
  v1.add(2);
  v1.add(3);
  v1.add(4);

  v2.add(1);
  v2.add(2);
  v2.add(3);
  v2.add(4);
  v2.add(5);
  v3.setlength(5);
  v4.setlength(5);
  v3=v1+v2;
  v4=v2*3;
  cout<<"V1: "<<v1;
  cout<<"V2: "<<v2;
  cout<<"V3=v1+v2: "<<v3;
  cout<<"V4=v2*3: "<<v4;
  v2.del();
  v2.show_V();

  return 0;
}
