#include <iostream>
#include <chrono>
using namespace std;


void inter(int A[],int p,int q,int r)
{
    int B[r];
    for (int i=p;i<q;i++)
    {
        B[i]=A[i];
    }
    for (int j=q;j<r;j++)
    {
        B[r+q-j]=A[j];
    }
    int i=p;
    int j=r;
    for (int k=p;k<r;k++)
    {
        if(B[i]<=B[j])
        {
            A[k]=B[i];
            i++;
        }
        else{
            A[k]=B[j];
            j--;
        }
    }
}

void print(int A[],int n)
{
    int mitad=n/2;
    for (int i=0;i<n;i++)
    {
        if(i>=mitad)
        {
            A[i]=i-mitad;
        }
        else
        {
            A[i]=i+mitad;
        }
    }
}
int main()
{
    int cantidad;
    cout<<"cantidad? ";
    cin>>cantidad;
    int A[cantidad];
    for (int i=0;i<cantidad;i++)
    {
        cin>>A[i];
    }
    int mitad=cantidad/2;
    print(A,cantidad);
    auto start = std::chrono::high_resolution_clock::now();
    inter(A,0,mitad,cantidad);
    auto finish = std::chrono::high_resolution_clock::now();
    std::cout<< std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() << " ns\n";
    for (int i=0;i<cantidad;i++)
        cout<<A[i]<<" ";
    cout<<endl;
    return 0; 
}