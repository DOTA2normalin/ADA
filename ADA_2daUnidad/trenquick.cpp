#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  
  
int partition (int arr[], int l, int r)  
{  
    int pivot = arr[r];  
    int i = (l - 1); 
  
    for (int j = l; j <= r - 1; j++)  
    {  
        if (arr[j] < pivot)  
        {  
            i++;
            count++;
            swap(&arr[i], &arr[j]);  
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

int resuelve(int vagones[], int nVagones){
   return rand()%100;
}


int main() {
   int nCasos, nVagones;
   int vagones[52];
  
   // LA LECTURA DE LA ENTRADA DEL PROBLEMA
   cin >> nCasos;
   for(int caso=0 ; caso<nCasos; caso++){
      cin >> nVagones;
      for(int i{0}; i<nVagones; i++){
         cin >> vagones[i];
      }

      int resultado = resuelve(vagones, nVagones);

      cout <<resultado<< endl;

   }
   return 0;
}