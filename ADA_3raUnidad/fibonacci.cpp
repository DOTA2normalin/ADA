#include <iostream>
#include <chrono>

using namespace std;

void fibonacci(int n)
{
	int a[n];
	a[0]=0;
	a[1]=1;

	for (int i = 2 ;i < n ;i++)
	{
		a[i]=a[i-1]+a[i-2];
	} 
	cout<<endl;
}

int main()
{

	int n;
	cin>>n;
	int a[n];
	cout<<" fibo _ tabla "<< endl;
	auto start = std::chrono::high_resolution_clock::now();
	for ( int i = 0 ;i <  10000 ;i++)
   		fibonacci(500);
	auto finish = std::chrono::high_resolution_clock::now();
   	std::cout<< std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() << " ns\n";

   	
	return 0;
}

