#include <iostream>
using namespace std;
void crearmatrizA(int A[20][20],int k,int m)
{
	for(int i=0; i<k; ++i){
        	for(int j=0; j<m; ++j)
        	{
            		cout<<"Ingrese valor para A["<<i<<"]["<<j<<"]: ";
            		cin>>A[i][j];
        	}
        	cout<<"\n";
	}
}
 void crearmatrizB(int B[20][20],int o,int n)
 {
	for(int i=0; i<o; ++i)
    	{
        	for(int j=0; j<n; ++j)
        	{
            		cout<<"Ingrese valor para B["<<i<<"]["<<j<<"]: ";
            		cin>>B[i][j];
        	}
        	cout<<"\n";
	}
 }
 void mostrarmatricesAyB(int A[20][20],int k,int m,int B[20][20],int o,int n)
 {
 	cout<<"Matriz A: "<<endl;
    	for(int i=0; i<k; ++i)
    	{
        	for(int j=0; j<m; ++j)
        	{
            		cout<<A[i][j]<<" ";
        	}
        	cout<<endl;
    	}

    	cout<<"Matriz B: "<<endl;
    	for(int i=0; i<o; ++i)
    	{
        	for(int j=0; j<n; ++j)
        	{
            		cout<<B[i][j]<<" ";
        	}
        	cout<<endl;
    	}

}
void multiplicacion(int A[20][20],int k,int m,int B[20][20],int o,int n,int C[20][20])
{
	
	if (m==o){

	    // Generamos la matriz C.
    		for(int i=0; i<k; ++i){
        		for(int j=0; j<n; ++j){
        			C[i][j]=0;
            			for(int z=0; z<o; ++z){
                			C[i][j]+= A[i][z] * B[z][j];
            			}
        		}
        		cout<<"\n";
       	 	}
	}
	else{
		cout<<"no se puede multiplicar las dos matrices A y B ingrese los datos correctos";
	}
}
void mostrarC(int C[20][20],int k,int n)
{
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<C[i][j]<<" ";
		}
		cout<<"\n";
	}
}
int main()
{
    int A[20][20], B[20][20], C[20][20];
    int k, m,o, n;
    cout<<"Lectura de matriz A."<<endl;
    cout<<"Filas de A: "; cin>>k;
    cout<<"Columnas de A: "; cin>>m;
    cout<<endl;
    cout<<"Lectura de matriz B."<<endl;
    cout<<"Filas de B: "<<endl;
    cin>>o;
    cout<<"Columnas de B: "; cin>>n;
    cout<<endl;
    crearmatrizA(A,k,m);
    crearmatrizB(B,o,n);
	mostrarmatricesAyB(A,k,m,B,o,n);
	multiplicacion(A,k,m,B,o,n,C);
	cout<<"Nueva Matriz C:"<<endl;  
	mostrarC(C,k,n);
    return 0;
}