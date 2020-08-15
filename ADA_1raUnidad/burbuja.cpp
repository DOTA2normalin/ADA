#include<iostream>
#include <ctime>
#include <time.h>
#include <chrono>

using namespace std; 

void generador(int arreglo[], int cantidad)
{
    srand(time(NULL));
    
    for(int c = 0; c < cantidad; c++)
    {
        arreglo[c] = 1 + rand() % (cantidad);
    }
}

void burbuja(int arreglo[], int num,int comparacion,int asignacion)  
{  
    int aux;
    for(int z = 1; z < num; ++z) {
        comparacion+=2;
        asignacion+=2;
      for(int v = 0; v < (num - z); v++) {
          comparacion+=2;
          asignacion+=2;
         if(arreglo[v] > arreglo[v+1]){
            comparacion+=2;
            aux = arreglo[v];
            arreglo[v] = arreglo[v + 1];
            arreglo[v + 1] = aux;
            asignacion+=3;
         }
      }
    }
    cout<<" comparacion = "<< comparacion <<endl;
    cout<<" asignacion = "<< asignacion <<endl;
    unsigned suma =(comparacion*2)+(asignacion*8);
    cout <<"suma = "<<suma<<endl;
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