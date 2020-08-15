#include <stdlib.h>
#include <time.h>
#include<iostream>
using namespace std;

void generador(int arreglo[], int cantidad,int c )
{
    srand(time(NULL));
    
    for(c = 0; c < cantidad; c++)
    {
        arreglo[c] = 1 + rand() % (cantidad);
        cout << arreglo[c]<< " ";
    }
}
void insertionSort(int arr[], int n)  
{  
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
  
        /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
} 
 
int main()
{
    int c,cantidad,aux;
    cout<<"cantidad de elementos ? ";
    cin>>cantidad;
    int arreglo[cantidad];
    generador(arreglo,cantidad,c);

    insertionSort(arreglo,cantidad);

    cout<<endl;
    cout<<"MUESTRA EL GENERADOR DE ARREGLOS DE MANERA ORDENADA CRECIENTEMENTE "<<endl;
    for(c = 0; c < cantidad; c++)
    {
        cout << arreglo[c]<< " ";
    }
    return 0;
}