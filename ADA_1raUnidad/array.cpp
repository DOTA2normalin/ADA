#include "iostream"

using namespace std;

void del(int a[],int n,int k)
{
   while(k>(n-1)||k<0);
      for(int i=k;i<n;i++)
      {
         a[i]=a[i+1];
      }
   n--;
   for(int i=0;i<n;i++)
      cout<<a[i]<<" ";
   
}
int main()
{
   int a[] = {3,3,-1,6,10,4,-5,4,-3,4,4,-4,4,-5,4,-3,-4,-5};
   int tam=sizeof(a)/sizeof(a[0]);
   int fila=a[0];
   del(a,tam,a[0]);
   int m[fila][20000];
   int cont=0;
   for (int i = 0; i < tam; i++)
   {
      int aux=a[0];
      for (int j = 2+cont,b=0; j <= aux; j++,b++)
      {
         /* code */
         
         m[i][b]=a[j];
         del(a,tam,a[j]);
         cout<<m[i][b]<<" ";
      }
      cont=cont+aux;
      cout<<endl;
      
   }
   

   /*int tam = a[0];
   int cont=1;
   for (int i = 0; i < tam; i++)
   {
      int aux=a[cont];
      //cont++;
      for(int j=1+cont; j<=aux;j++)
      {
         cout<< a [j]<<" ";
      }
      cont=cont+aux;
      cout<<" cont = " <<cont;
      cout<<endl;
   }*/


}