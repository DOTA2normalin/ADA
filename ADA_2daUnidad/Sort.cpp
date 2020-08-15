/*#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>
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

int main() 
{ 
   int tam;
   cout<<"length ? ";
   cin>>tam;
   int arr[tam];
   Gen(arr, tam);

   auto start = std::chrono::high_resolution_clock::now();
   sort(arr, arr+tam); 
   auto finish = std::chrono::high_resolution_clock::now();
   std::cout<< std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() << " ns\n";

   /*cout << "\nArray after sorting using "
         "default sort is : \n"; 
   for (int i = 0; i < tam; ++i) 
      cout << arr[i] << " "; 
   
   return 0; 
}*/



#include <iostream>
#include <cstdlib>
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
int compare(const void* a, const void* b)
{
	return ( *(int*)a - *(int*)b);
}

int main()
{
	int num;
   cout<<" length ?" ;
   cin>>num;
	int arr[num];
   Gen( arr , num );

   auto start = std::chrono::high_resolution_clock::now();
	qsort(arr,num,sizeof(int),compare);
   auto finish = std::chrono::high_resolution_clock::now();
   std::cout<< std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() << " ns\n";

	return 0;
}