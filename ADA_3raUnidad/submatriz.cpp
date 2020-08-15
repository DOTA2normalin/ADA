#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
using namespace std;
const int n=127;
int a[n][n];
void generar(int a[][n])
{
    srand(time(NULL));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int num=1+rand()%(1000-1);
            a[i][j]=num;
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }   
}
int Kadane(int a[n], int* start, 
           int* finish)  
{  
    int sum = a[0], maxSum = a[0], i;  
  
    *finish = -1;  
  
    int local_start = 0;  
  
    for (i = 0; i < n; ++i)  
    {  
        sum += a[i];  
        if (sum < 0)  
        {  
            sum = 0;  
            local_start = i + 1;  
        }  
        else if (sum > maxSum)  
        {  
            maxSum = sum;  
            *start = local_start;  
            *finish = i;  
        }  
    }  
  
    if (*finish != -1)  
        return maxSum;  
  
    maxSum = a[0];  
    *start = *finish = 0;  
  
    for (i = 1; i < n; i++)  
    {  
        if (a[i] > maxSum)  
        {  
            maxSum = a[i];  
            *start = *finish = i;  
        }  
    }  
    return maxSum;  
} 
void findMaxSum (int a[n][n])
{
    int maxSum=0,finalLeft,finalRight,finalTop,finalBottom;
    int temp[n],sum,start,finish;
    for (int left = 0; left < n; left++)
    {
        int temp[n] = {0};
 
        for (int right = left; right < n; right++)
        {
            for (int i = 0; i < n; i++)
                temp[i] += a[i][right];
 
            int sum = Kadane(temp,&start,&finish);
            if (sum > maxSum){
                maxSum = sum;
                finalLeft=left;
                finalRight=right;
                finalTop=start;
                finalBottom=finish;
            }
        }
    }
 
    cout<< maxSum;
}

int main(){

    fstream archivo("matrix.text");
    string linea;
    if(!archivo.is_open())
        archivo.open("matrix.txt",ios::in);
    while(getline(archivo,linea))
        cout<<linea<<"\n";
    archivo.close();
    for (int i = 0; i < n; i++)
    {
        
        for (int j = 0; j < n; j++)
        {
            cin>>a[i][j];
        }
        
    }
    if (0<n<128){
        generar(a);
        findMaxSum(a);
    }
    return 0;
}