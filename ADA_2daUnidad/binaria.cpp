#include <iostream>
using namespace std;
int main()
{
    int n, i, A[100], num, primero, ultimo, medio;
    cout<<"Ingrese un arreglo ordenado: ";
    cout<<"Cuantos elementos te gustaria ingresar?: ";
    cin>>n;
    
    for (i=0; i<100;i++) 
    {
        cout<<"Ingrese el numero que desea buscar: ";
        cin>>num;
    }
    primero=0;
    ultimo=n-1;
    medio=(primero+ultimo)/2;
    while (primero<=ultimo); 
    {
        if (A[medio]< num);
        {
            primero=medio+1;
        } else if (A[medio]== num) 
        {
            cout<<" Se encontro la posición ";
            cout<<medio+1;
            break;
        }
        else {
            ultimo = medio - 1;
        }

        medio = (primero+ultimo)/2;
    }
    if (primero>ultimo)
    {
        cout<<num<<" no se encontro";
    }

    return 0;
}