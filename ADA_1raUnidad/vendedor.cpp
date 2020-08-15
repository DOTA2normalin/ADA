
#include "iostream"
#include "algorithm" 
using namespace std;


void cod_lineal(int arr[],  int tam)
{
	int max_sum = 0;
	int e = 0, d = -1;
	int sum = 0;
	int i = 1, g = 0;
	while(g < tam)
	{
		sum = sum +arr[g];
		if (sum < 0)
		{
			sum = 0; i = g+1;
		}
		else
		{
			if (sum >= max_sum)
			{
				max_sum = sum;
				d = g; e = i;
			}
		}
		cout<<"la ruta entre la calle "<<g<<"y la calle "<<g+1<<" es "<<sum<<endl;
		g++;
		
	}

	cout<<e<<"el maximo es: "<<max_sum<<endl;	
}

int max1(int a, int b, int c)
{
	int aux = max(a,b);
	return max(aux, c);
}


int divide_venceras(int arr[], int p, int r)
{
	if ( p == r) return max(0, arr[p]);
	
	int q;
	q = (p+r)/2;
	int maxizq, maxder, max2izq, sum = 0;
	maxizq = divide_venceras(arr, p, q);
	maxder =  divide_venceras(arr, q+1, r);
	max2izq =sum = arr[q];
	for (int i = q-1; i >= p ; i--)
	{
		sum = sum + arr[i];
		max2izq = max(max2izq, sum);
	}
	int max2der;
	max2der = sum = arr[q+1];

	for (int f = q+2; f <= r; ++f)
	{
		sum = sum + arr[f];
		max2der = max(max2der, sum);

	}
	int maxcruz;
	maxcruz = max2izq + max2der;
	return max1(maxizq,maxcruz,maxder);
}
int main()
{
	int tam;
	cout<<"cantidad de elementos"<<endl;
	cin>>tam;
	int arr[tam];
	for (int i = 0; i < tam; ++i)
	{
		cin>>arr[i];
	}
	cod_lineal(arr, tam);

	cout<<endl<<"el maximo es con la divide: "<<endl;
	cout<<divide_venceras(arr, 0, tam-1)<<endl;
	return 0;
}