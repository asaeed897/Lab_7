#include<iostream>
using namespace std;

class MyVector{
private:
  double *A;
  int length;
public:
  static int index;
   MyVector(){}
   ~MyVector(){}
   MyVector(int l):length(l){
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
   void operator = (MyVector &v)
   {
     length=v.length;
     A=new double[length];
     for(int i=0;i<length;i++)
     A[i]=v.A[i];
   }
   double operator [] (int i)
   {
     return A[i];
   }

   void add(double item)
   {
     A[index++]=item;
   }
   void del()
  {
     A[--index]=0;
   }
   void show_V()
   {
     cout<<"Vector Items:\n\n";
     for(int i=0;i<length;i++)
     cout<<A[i]<<endl;

   }

};
int MyVector::index=0;
int main(int argc, char const *argv[]) {
  MyVector v1(3),v2;
  v1.add(1);
  v1.add(2);
  v1.add(3);
  /*v2=v1;
  v1.show_V();
  v2.show_V();
  v1.del();
  v1.show_V();
  v2.show_V();
*/
cout<<"Element:"<<v1[0];
  return 0;
}
