#include <iostream>

using namespace std;

static int c;
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
            c++;
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


int main()
{
   int t,n;
   int i,j;
   int *train;
   int sum,tmp;
   cin>>t;
   while(t--)
   {
      cin>>n;
      for(i=c=0;i<n;++i)
         cin>>*(train+i);
      quickSort(train,0,n);
      cout<<c<<endl;
   }
   return 0;
}