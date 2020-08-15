#include <iostream>
using namespace std;

//paso 1
int fibonacci(int n)
{
    if (n==0)
    {
        return 0;
    }
    if (n==1)
    {
        return 1
    }
    return fibonacci(n-1)+fibonacci(n-2);
}
//paso 2
int  fibonnacci_iterativo(int n){
    if n == 0:
        return 0
    int previo2 = 0;
    int previo = 1;
    int suma = 0;
    for(int i=2;i<n;i++){
        suma = previo+previo2;
        previo2 = previo;
        previo = suma;
    }
    return previo;
}
//paso 3 y paso 4 
void fibo_iter(int n)
{
    if (n==0)
    {
        cout<< 0 <<endl;
    }
    int a[n];
    int anterior = 0;
    int actual = 1;
    a[anterior]=0;
    a[actual]=1;

    for (int i =2 ;i<n;i++)
    {
        a[i]=a[i-1]+a[i-2];
        a[anterior] =a [actual];
        a[actual] = a[i]; 
    }
}
//paso 5 
void fibo_iter(int n,int modulo)
{
   int  fibonnacci_iterativo(int n){
    if n == 0:
        return 0
    int previo2 = 0;
    int previo = 1;
    int suma = 0;
    for(int i=2;i<n;i++){
        suma = (previo%modulo+previo2%modulo)%modulo;
        previo2 = previo;
        previo = suma;
    }
    return previo;

}
int fibonacci(int n,int modulo)
{
    if (n==0)
    {
        return 0;
    }
    if (n==1)
    {
        return 1
    }
    return (fibonacci(n-1)%modulo+fibonacci(n-2)%modulo)%modulo;
}
//paso 6
int multiplicacion(int A[20][20],int B[20][20],int C[20][20])
{
    C[0][0] = A[0][0]*B[0][0] + A[0][1]*B[1][0];
    C[0][1] = A[0][0]*B[0][1]+ A[0][1]*B[1][1];
    C[1][0] = A[1][0]*B[0][0] + A[1][1]*B[1][0];
    C[1][1] = A[1][0]*B[0][1]+ A[1][1]*B[1][1];
    return C;
}

//paso 7
int pot(int A[20][20],int n)
{
    if(potencia == 2) {
        return multiplicacion(A,A,A);
    }
    else {
        return multiplicacion(pot(A,n/2),pot(A,n/2),pot(A,n));
    }
}
//paso 8
void crearmatrizA(int A[20][20],int k,int m)
{
    for(int i=0; i<k; ++i){
            for(int j=0; j<m; ++j)
            {
                    cout<<"Ingrese valor para A["<<i<<"]["<<j<<"]: ";
                    cin>>A[i][j];
            }
            cout<<"\n";
    }
}
 void crearmatrizB(int B[20][20],int o,int n)
 {
    for(int i=0; i<o; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                    cout<<"Ingrese valor para B["<<i<<"]["<<j<<"]: ";
                    cin>>B[i][j];
            }
            cout<<"\n";
    }
 }
 void mostrarmatricesAyB(int A[20][20],int k,int m,int B[20][20],int o,int n)
 {
    cout<<"Matriz A: "<<endl;
        for(int i=0; i<k; ++i)
        {
            for(int j=0; j<m; ++j)
            {
                    cout<<A[i][j]<<" ";
            }
            cout<<endl;
        }

        cout<<"Matriz B: "<<endl;
        for(int i=0; i<o; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                    cout<<B[i][j]<<" ";
            }
            cout<<endl;
        }

}
int multiplicacion(int A[20][20],int B[20][20],int C[20][20],int n)
{
    
    C[0][0] = ((A[0][0]*B[0][0])%n + (A[0][1]*B[1][0])%n)%n;
    C[0][1] = ((A[0][0]*B[0][1])%n + (A[0][1]*B[1][1])%n)%n;
    C[1][0] = ((A[1][0]*B[0][0])%n + (A[1][1]*B[1][0])%n)%n;
    C[1][1] = ((A[1][0]*B[0][1])%n + (A[1][1]*B[1][1])%n)%n;
    return C;
}

int pot(int A[20][20],int n)
{
    if(potencia == 2) {
        return multiplicacion(A,A,A,n);
    }
    else {
        return multiplicacion(pot(A,n),pot(A,n),pot(A,n),n);
    }
}
