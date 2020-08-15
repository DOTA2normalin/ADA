#include <iostream>
using namespace std;

int raizcuadrada(int n)
{
	int i=0;
	for(;i<n;i++)
	{
		if(i*i==n)
		{
			
			break;
		}
	}
	return i;
}
int main()
{
	cout<<raizcuadrada(49);
	return 0;
}