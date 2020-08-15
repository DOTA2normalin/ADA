#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>

using namespace std; 
double count {0};
void Gen(int A[],int n)
{
   //srand(time(0));
   int num;
   for(int i=0 ; i < n ; i++)
   {
      num=rand()%n;
      A[i]= num;
   }
}


float maximo(int A[],int n,int numVeces)
{
   int max=A[0];
   for(int i=1;i<n;i++)
   {
      if(A[i] > max)
      {
         max=A[i];
         numVeces++;
         count++;
      }
   }
   return numVeces;
}
void print(int A[],int n)
{
   for(int i=0;i<n;i++)
      cout<<A[i]<<" ";
}
int main()
{
   int numVector=200;
   double promedio=0;
   int tam;
   cout<<"tam ? ";
   cin>>tam;
   double logaritmo;
   for(int i=0;i<200;i++)
   {
      int array[tam];
      Gen(array,tam);
      //print(array,tam);
      //cout<<endl;
      promedio=promedio+maximo(array,tam,0);
      //cout<<"promedio = " <<promedio<<endl;
   }
   cout<<count/200<<endl;
   cout<<promedio<<endl;
   double pro=promedio/200;
   logaritmo=log(tam)+1;
   cout<<"promedio= "<< pro<<endl;
   cout<<"logaritmo n + 1= "<<logaritmo<<endl;
   return 0;
}