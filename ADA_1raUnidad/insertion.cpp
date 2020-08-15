#include <iostream>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <chrono>

using namespace std;

void generador(int arreglo[], int cantidad)
{
    
    for(int c = 0; c < cantidad; c++)
    {
        arreglo[c] = 1 + rand() % (cantidad);
    }
}

void insertionSort(int arr[], int n)  
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
    
    
    for(int i=10;i<cantidad;i++)
    {
        int arr[i];
        generador(arr,i);
        auto start = std::chrono::high_resolution_clock::now();
        insertionSort(arr,i);
        auto finish = std::chrono::high_resolution_clock::now();
        std::cout<< std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() << " ns\n";
        cout<<endl;
    }
    return 0;  
}