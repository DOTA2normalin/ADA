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

void burbuja(int arreglo[], int num,int comparacion,int asignacion)  
{  
    int aux;
    for(int z = 1; z < num; ++z) {
      for(int v = 0; v < (num - z); v++) {
         if(arreglo[v] > arreglo[v+1]){
            aux = arreglo[v];
            arreglo[v] = arreglo[v + 1];
            arreglo[v + 1] = aux;
         }
      }
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
    burbuja(arr, cantidad,1,1);
    auto finish = std::chrono::high_resolution_clock::now();
    std::cout<< std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() << " ns\n";
    return 0;  
}