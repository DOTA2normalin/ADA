#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cmath>
#include <chrono>
using namespace std;

#define MX 2000000000
int n=20;
int *array;

void seleccionsort(int  A[], int n) 
{
   int min,i,j,aux;
   for (i=0; i<n-1; i++) 
   {
      min=i;
      for(j=i+1; j<n; j++)
         if(A[min] > A[j])
            min=j;
         aux=A[min];
         A[min]=A[i];
         A[i]=aux ;
   }
 
} 
void print(int *array)
{
    for(int i=0;i<n;i++)
        cout<<array[i]<<" ";
    cout<<endl;
}
int main() {
   auto start = std::chrono::high_resolution_clock::now();
   int min,i,j,aux;
   for(int i=0; i<n; i++) {
      cout<<i <<" ";
      array=new int [n];
      for( int j=0; j<n; j++) {
         int dato=rand()%MX;
         array[j]=dato;
      }
      seleccionsort(array,n);
      //print(array);
      delete[] array;
   }
   auto finish = std::chrono::high_resolution_clock::now();
   std::cout<< std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() << " ns\n";
   return 0;
}