#include <iostream>
using namespace std;

int main()
{
    int suma=0;
    for(int i=1;i<1000;i++)
    {
        if(i%3==0 || i%5==0)
            suma+=i;     
    }
    cout<<"Problema 1 Euler =  "<< suma <<endl;

    long a=1;
    long b=1;
    long result=0;
    long summed=0;
    while(result<4000000)
    {
        if(result%2==0)
            summed+=result;
        result=a+b;
        b=a;
        a=result;
    }
    cout<<"Problema 2 Euler = "<<summed <<endl;
    
    int mayor=1;
    int ie;
    for(ie=1;ie<600851475143;ie++)
    {
        int contador=0;
        for(int j=1;j<=ie;j++)
        {
            if(j%ie==0)
                contador++;
        }
        if(contador==2)
            mayor=ie;
        cout<< mayor << "  ";
    }
}