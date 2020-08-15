#include <iostream>
#include <ctime>
#include <time.h>
#include <chrono>
using namespace std; 

void generador(int arr[], int num)
{
    int x=0;
    for(int i=num; i>0; i--)
    {
        arr[x] = i;
        x++;
    }
}

void insertionSort(int arr[], int n,int comparaciones,int asignaciones)  
{  
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;
        }  
        arr[j + 1] = key;
 
    }
}  
  
// A utility function to print an array of size n  
void printArray(int arr[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        cout << arr[i] << " ";  
    cout << endl; 
}  
  
int main()  
{  


    int cantidad;
    cout<<"cantidad de elementos ? ";
    cin>>cantidad;
    int arr[cantidad];
    generador(arr,cantidad);
    auto start = std::chrono::high_resolution_clock::now();
    insertionSort(arr, cantidad,1,1);
    auto finish = std::chrono::high_resolution_clock::now();
    std::cout<< std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() << " ns\n";
    return 0;  
}