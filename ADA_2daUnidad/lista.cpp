#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cmath>
#include <chrono>
#include <vector>
using namespace std;


#define MX 2000000000
int n=1000;
template<typename T>
class Nodo{
    T data;
    Nodo<T> *next;
    template<typename U>
    friend class Lista;
   
   void delete_all()
    {
        if(next)
            next->delete_all();
        delete this;
    }
    template<typename N>
    friend class Iterator;
};

template<typename T>
class Lista{
public:
    Nodo<T> *head;
public:
    Lista(){
        head=NULL;
    }
    ~Lista(){
      Nodo<T> *recor=head;
      Nodo<T> *bor;
      while(recor!=NULL)
      {
         bor=recor;
         recor=recor->next;
         delete bor;
      }
   }
   void insertar(T x);
   void imprimir();
   void buscar(T x);
   void eliminar(T x);
   void del_all();
    
};

template<typename T>
void Lista<T>::insertar(T x)
{
    Nodo<T> *nuevo=new Nodo<T>();
    nuevo->data=x;

    Nodo<T> *aux1=head;
    Nodo<T> *aux2;

    while(aux1!=NULL &&  aux1->data< x)
    {
        aux2=aux1;
        aux1=aux1->next;
    }
    if(head==aux1)
    {
        head=nuevo;
    }
    else
    {
        aux2->next=nuevo;
    }
    nuevo->next=aux1;
}

template<typename T>
void Lista<T>::imprimir()
{
    Nodo<T> *rec=head;
    while(rec!=NULL)
    {
        cout<<rec->data<<"->";
        rec=rec->next;
    }
    cout<<"NULL";
}
template<typename T>
void Lista<T>::buscar(T x)
{
    Nodo<T>* actual=head;
    bool existe=false;
    while(actual!=NULL && actual->data<=x)
    {
        if(actual->data==x)
            existe=true;
        actual=actual->next;
    }
    if(existe==true)
    {
        cout<<"el numero si existe y es ="<<x;
    }
    else{
        cout<<"el numero no existe";
    }
}
template<typename T>
void Lista<T>::eliminar(T x)
{
    Nodo<T> *aux=head;
    Nodo<T> *anterior=NULL;
    while((aux!=NULL) && (aux->data!=x))
    {
        anterior=aux;
        aux=aux->next;
    }
    if(aux==NULL)
    {
        cout<<"EL ELEMENTO NO EXISTE";
    }
    else if(anterior==NULL)
    {
        head=head->next;
        delete aux;
    }
    else{
        anterior->next=aux->next;
        delete aux;
    }
}
template<typename T>
void Lista<T>::del_all()
{
   head->delete_all();
   head = 0;
}
int main(){
   auto start = std::chrono::high_resolution_clock::now();
   int n=8000;
   for(int i=0 ; i<n;i++){
      Lista<int> l;
      for( int j=0; j<n; j++) {
         int dato=rand()%MX;
         l.insertar(dato);
      }
      l.del_all();
   }
   auto finish = std::chrono::high_resolution_clock::now();
   std::cout<< std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() << " ns\n";
  
	return 0;
}