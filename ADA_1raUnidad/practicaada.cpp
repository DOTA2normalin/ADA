#include <iostream>
#include <string>
using namespace std;

int factorial(int n)
{
    if(n==0)
        return 1;
    else if(n==1)
        return 1;
    else
    {
        return n*factorial(n-1);
    }
    
}

void print(int n)
{
    if(n==0)
        return ;
    else{
        cout<< n <<" ";
        return print(n-1);
    }
}
void insersort(int A[],int n)
{
    for (int i = 1; i < n; i++)
    {
        int aux=A[i];
        int j=i-1;
        while (j>=0 && aux<A[j] )
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=aux;   
    }
}
void bublesort(int A[],int n)
{
    for (int i = 0 ; i<n; i++)
    {
        for (int j = 0; j <n; j++)
        {
            if( A[j] > A[j+1])
            {
                int a=A[j];
                A[j]=A[j+1];
                A[j+1]=a;
            }
        }
    }
    
}
int main()
{
    int A[6]={8,7,9,4,3,2};
    int B[10]={9,8,7,5,10,1,45,100,0,-8,};
    bublesort(A,6);
    int i=0;
    for(i=0;i < 6;i++)
        cout<<A[i]<<" ";
    cout<<endl;
    insersort(B,10);
    int j=0;
    for(j=0;j < 10;j++)
        cout<<B[j]<<" ";
    cout<<endl;
    cout<< factorial(1) ;
    cout<<endl;
    print(5);
    cout<<endl;

    int s=0;
    for(int i=1;i<20-2;i++)
    {
        for(int j=i;j<20 ;j++){
            s=s+1;
        }
        cout<<s <<endl;
    }
    cout<< s ;
    return 0;
}