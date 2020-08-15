#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;  

double count {0}; //variable global

void Gen(int A[],int n)
{
   int num;
   for(int i=0 ; i < n ; i++)
   {
      num=rand()%(n);
      A[i]= num;
   }
}


void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t; 
    count++;
}  
  
int partition(int arr[], int l, int r)  
{  
    int pivot = arr[r];  
    int i = (l - 1); 
  
    for (int j = l; j <= r - 1; j++)  
    {  
        if (arr[j] < pivot)  
        {  
            i++;
            //count++;
            int t = arr[i];  
            arr[i] = arr[j];  
            arr[j] = t;
        }  
    }  
    swap(&arr[i + 1], &arr[r]);  
    return (i + 1);  
}  
  

void quickSort(int arr[], int l, int r)  
{  
    if (l < r)  
    {  
        int pi = partition(arr, l, r);  
        quickSort(arr, l, pi - 1);  
        quickSort(arr, pi + 1, r);
    }  
}  
  
void printArray(int arr[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}  
  

int main()  
{  
    int tam;
    cout<<" tam ? ";
    cin>>tam;
    float pro=0;
    float promedio;
    for (int i = 0; i < 1; i++)
    {
        /* code */
        int A[tam];
        Gen(A,tam);
        printArray(A,tam);
        cout<<endl;
        quickSort(A,0,tam-1);
        printArray(A,tam);
    }
    cout<<count<<endl;

    return 0;
}  