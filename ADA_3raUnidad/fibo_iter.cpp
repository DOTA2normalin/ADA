#include <iostream>
#include <chrono>

using namespace std;



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

int main()
{

	cout<<" fibo _ iter "<< endl;

   	auto start_2 = std::chrono::high_resolution_clock::now();
   	for ( int i = 0 ;i <  1000 ;i++)
   		fibo_iter(50);
   	auto finish_2 = std::chrono::high_resolution_clock::now();
   	std::cout<< std::chrono::duration_cast<std::chrono::nanoseconds>(finish_2-start_2).count() << " ns\n";

	return 0;
}

