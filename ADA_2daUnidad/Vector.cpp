#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cmath>
#include <chrono>
#include <vector>

#define MX 2000000000
int n=1000;
using namespace std;


void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
} 

void print(vector<vector<int>> matrix)
{
   for(int i=0;i<n;i++)
   {
      for(int j=0;j<n;j++)
      {
         cout<<matrix[i][j]<<" ";
      }
      cout<<endl;
   }
}
int main()
{
   
   auto start = std::chrono::high_resolution_clock::now();

   vector<vector<int> > matrix;
   for(int i = 0; i<n; i++)
   {
      vector<int> myvector;
      for(int j = 0; j<n; j++)
      {
         int tempVal=rand()%MX;
         myvector.push_back(tempVal);
      }
      matrix.push_back(myvector);
   }
   //SORT
   for(int i=0;i<n;i++)
   {
      int j,key,k;
      for(j=0;j<n;j++)
      {
         key=matrix[i][j];
         k=j-1;
         while(k>=0 && matrix[i][k]>key)
         {
            swap(&matrix[i][k+1], &matrix[i][k]);  
            k--;
         }
         key=matrix[i][k+1];
      }
   }
   //Pop element
   vector<int> arr;
   for(int i=0;i<n;i++)
   {
      for(int j=0;j<n;j++)
      {
         if(j==499){
            arr.push_back(matrix[i][j]);
         }
      }
      cout<<arr[i]<<" ";

   }

   auto finish = std::chrono::high_resolution_clock::now();
   std::cout<< std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() << " ns\n";
   return 0;
}