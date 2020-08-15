#include <iostream>
using namespace std;

class punto
{
private:
    int x, y;    
public:
    punto();
    punto(int, int);
    int getX() const;
    int getY() const;
    void setX(const int);
    void setY(const int);
    ~punto();
    friend class ArreglodePuntos;
};

punto::punto()
{
    x = 0;
    y = 0;
}

punto::punto(int _x, int _y){
    x = _x;
    y = _y;
}

int punto::getX() const{
    return x;
}

int punto::getY() const{
    return y;
}

void punto::setX(const int nuevo_x){
    x = nuevo_x;
}

void punto::setY(const int nuevo_y){
    y = nuevo_y;
}

punto::~punto()
{
    cout << "Destruyendo el punto" << endl;
}

class ArreglodePuntos :public punto
{
private:
    punto *ptr_punto;    
    int size;
    void Redimensionar(int);
public:
    ArreglodePuntos(const punto puntos[], const int tam);
    ArreglodePuntos(const ArreglodePuntos &o);    
    void push_back(const punto &);
    void insert(const int, const punto &);
    void remove(const int);
    const int getSize() const;
    void clear();
    ~ArreglodePuntos();
    friend class punto;
};

ArreglodePuntos::ArreglodePuntos(const punto puntos[], const int tam)
{
    puntos=new punto[tam];
}

ArreglodePuntos::ArreglodePuntos(const ArreglodePuntos &o){

    ptr_punto = new punto[o.size];
    for (size_t i = 0; i < size; i++)
    {
        ptr_punto[i] = o.ptr_punto[i];
    }  
    size = o.size;  
}

void ArreglodePuntos::Redimensionar(int n){
    size = size + n;
    ptr_punto = new punto[size];    
    
}

void ArreglodePuntos::push_back(const punto &p){

    ptr_punto[ size++ ] = p;
}

void ArreglodePuntos::insert(const int posicion, const punto &p){
    if(posicion==size)
    {
        size++;
        ptr_punto[posicion]=p;
    }
    else
    {
        for (size_t i=0;i<size;i++)
        {
            if(i==posicion)
            {
                int k=size-1;
                while(k<=0)
                {   
                    ptr_punto[k]=ptr_punto[k-1];
                }
                ptr_punto[posicion]=p;
            }
        }
    }
    
}

void ArreglodePuntos::remove(const int pos){
    if (pos < size)
    {   
        punto *aux_punto = &ptr_punto[pos];     
        for (size_t i = 0; i < size; i++)
        {
            if (i == pos)
            {
                int k=i;
                while (k < size)
                {
                    ptr_punto[k] = ptr_punto[k + 1];
                    k++;
                }
                break;                
            }            
        }
        size--;
        delete aux_punto;
                
    }else
    {
        return;
    }        
}

const int ArreglodePuntos::getSize() const{
    return size;
}

void ArreglodePuntos::clear(){
    while(size>0)
    {
        punto *aux = &ptr_punto[size-1];
        delete aux;
        size--;
    }
    ptr_punto=new punto[size];
}

ArreglodePuntos::~ArreglodePuntos()
{
    delete [] ptr_punto;
}

int main()
{
    punto tam=5;
    ArreglodePuntos *A;
    ArreglodePuntos a(A,tam);
    a.insert(0,5);   
    return 0;
}