#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>

using namespace std; 



void Gen(int A[],int n)
{
   srand(time(NULL));
   for(int i=0 ; i < n ; i++)
   {
      int num=rand()%n;
      A[i]=num;
   }
}



void inter(int A[],int p,int q,int r)
{
    int i,j;
    int B[r];
    int n1 = q-p+1;
    for ( i=0 ; i <= q ; i++)
    {
        B[i] = A[i];
        //cout<<B[i]<<" ";
    }
    //cout<<endl;
    for ( j=q+1 ; j <=r ; j++)
    {
        B[r+q+1-j] = A[j];
        //cout<<B[r+q+1-j]<<" ";
    }
    //cout<<endl;

    i=p; 
    j=r; 
    for ( int k=p; k <= r ; k++)
    {
        if( B[i] <= B[j] )
        {
            A[k]=B[i];
            i++;
        }
        else{
            A[k]=B[j];
            j--;
        }
    }
}


void merge_sort(int A[],int p,int r)
{
   if(p < r)
   {
      int q=p+(r-p)/2;
      merge_sort(A,p,q);
      merge_sort(A,q+1,r);
      inter(A,p,q,r);
   }
}
  

void printArray(int A[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 
 
int main() 
{ 
    int tam;
    cout<<"length ?" ;
    cin>>tam;
    int arr[tam] ;
    Gen (arr , tam);

    auto start = std::chrono::high_resolution_clock::now();
    merge_sort(arr, 0, tam - 1); 
    auto finish = std::chrono::high_resolution_clock::now();
    std::cout<< std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() << " ns\n";

  
    //cout<<"\nSorted array is \n"; 
    //printArray(arr, tam); 
    return 0; 
} 