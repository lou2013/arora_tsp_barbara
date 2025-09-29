#include <stdio.h>
#include <string>
#include <iostream>
#include <Math.h>
#include <Windows.h>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <iomanip>
#include <sstream>
#include <limits>
#include "iostream"
#include <chrono>
#include <random>
#include <algorithm>
#define FLT_MAX 3.402823466e+38F    // max value
#define EERROR 5
#define ARRIBA  0
#define ABAJO  1
#define DERECHA 2
#define IZQUIERDA 3
#define posXC 0
#define posXF 80
#define posYCA 0
#define posYFA 37
#define posYCG 38
#define posYFG 74
#define posYCT 75
#define posYFT 111
#define posYCI 112
#define posYFI 148
#define posYCQ 149
#define posYFQ 185
#define posYCP 186
#define posYFP 222
#define posYCC 223
#define posYFC 260
#define HORIZONTAL 0
#define VERTICAL 1
#define MUSIC 0
// #define ERROR 1
#define CLICK 2
#define ZOOMIN 3
#define MAXANCHOIM 4000
#define ValueDef -1.0;
#define GRILLADODEF 5
#define MINGRILLADO 1
#define MAX_VAL 80
#define MIN_X_DEF 0.2
#define QuadTreeTSPH
#define LADOS 4
#define EERROR 5
#define NINGUNO -1
#define AMBOS -2
#define CTEDIM 10000
#define DISTANCIAINVALIDA -1
#define TamYdefault -1
#define TamYdefaultAll -3
#define TamYEqual -2
#define VALUE_DEF 0

float c=100;
class Punto {
protected:
    float x;
    float y;
public:
    Punto(float, float);
    Punto();
    ~Punto();
    void setX(float);
    void setY(float);
    float getX();
    float getY();
    float distancia_Total_a(Punto*);
    float distancia_X_a(Punto*);
    float distancia_Y_a(Punto*);
    std::string toString();
    bool operator ==(Punto p) { return ((this->y == p.y) && (this->x == p.x)); }
    bool operator <(Punto* p) { return (this->y < p->y); }
};
Punto::Punto(float xx, float yy) {
    x = xx;
    y = yy;
}
//---------------------------------------------------------------------------
Punto::Punto() {
    x = ValueDef;
    y = ValueDef;
}
//---------------------------------------------------------------------------
Punto::~Punto() {}
//---------------------------------------------------------------------------
void Punto::setX(float xx) { x = xx; }
//---------------------------------------------------------------------------
void Punto::setY(float yy) { y = yy; }
//---------------------------------------------------------------------------
float Punto::getX() { return x; }
//---------------------------------------------------------------------------
float Punto::getY() { return y; }
//---------------------------------------------------------------------------
float Punto::distancia_Total_a(Punto* p) {
    return pow(((this->x - p->x) * (this->x - p->x)) + ((this->y - p->y) * (this->y - p->y)), .5);
}
//---------------------------------------------------------------------------
float Punto::distancia_X_a(Punto* p) {
    if (this->x > p->x)
        return this->x - p->x;
    else
        return p->x - this->x;
}
//---------------------------------------------------------------------------
float Punto::distancia_Y_a(Punto* p) {
    if (this->y > p->y)
        return this->y - p->y;
    else
        return p->y - this->y;
}
//---------------------------------------------------------------------------
std::string Punto::toString() {
    std::ostringstream oss;
    oss << "( " << std::fixed << std::setprecision(2)
        << x << " , " << y << " )";
    return oss.str();
}
std::string formatCoordinates(double x, double y) {
    std::stringstream oss;
    oss.imbue(std::locale("")); // For thousands separator
    oss << std::fixed << std::setprecision(2); // Set floating-point precision to 2 decimal places
    oss << "( " << x << " , " << y << " )";
    return oss.str();
}
class PuntoExtendido : public Punto {
private:
    int ubicacion;
public:
    PuntoExtendido();
    PuntoExtendido(float, float, int);
    ~PuntoExtendido();
    void setUbicacion(int u) { ubicacion = u; };
    int getUbicacion() { return ubicacion; };
};
PuntoExtendido::PuntoExtendido() {
    this->x = 0.0;
    this->y = 0.0;
    this->ubicacion = -1;
}
//---------------------------------------------------------------------------
PuntoExtendido::PuntoExtendido(float x, float y, int ubic) :Punto(x, y) {
    ubicacion = ubic;
}
//---------------------------------------------------------------------------
PuntoExtendido::~PuntoExtendido() {}
//--------------------------------------------------------------------------
template <class T> class Matriz {
private:
    T*** matriz;
    unsigned int tamX, tamY;
public:
    Matriz(unsigned int, unsigned int);
    ~Matriz();
    unsigned int getSizeX();
    unsigned int getSizeY(unsigned int);
    T* get(unsigned int, unsigned int);
    void set(T*, unsigned int, unsigned int);
    bool posValida(unsigned int, unsigned int);
};
template <class T>
class Lista2 {
    class Nodo {
    public:
        Nodo* sig;
        T* elem;
    };
    Nodo* raiz, * actual, * final;
    int longitud;
public:
    Lista2();
    ~Lista2();
    void vaciar();
    void agregar(T* elem);
    void agregarOrdenado(T* elem);
    void agregarFinal(T* elem);
    void eliminar(T* elem);
    void eliminarSinBorrar(T* elem);
    T* primero();
    T* siguiente();
    T* pertenece(T* elem);
    int tamanio();
    T* get(int);
    void clonar(Lista2<T>* origen);
    void agregarLista(Lista2<T>* list);
};
template <class T>
class Lista {
    class Nodo {
    public:
        Nodo* sig;
        T* elem;
    };
    Nodo* raiz, * actual, * final;
    int longitud;
public:
    Lista();
    ~Lista();
    void vaciar();
    void agregar(T* elem);
    void agregarOrdenado(T* elem);
    void agregarFinal(T* elem);
    void eliminar(T* elem);
    void eliminarSinBorrar(T* elem);
    T* primero();
    T* siguiente();
    T* pertenece(T* elem);
    int tamanio();
    T* get(int);
    void clonar(Lista<T>* origen);
    void agregarLista(Lista<T>* list);
};
template <class T>
Lista<T>::Lista() { raiz = actual = final = NULL; longitud = 0; };
//--------------------------------
template <class T>
Lista<T>::~Lista() { vaciar(); };
//--------------------------------
template <class T>
void Lista<T>::vaciar() {
    Nodo* aux = raiz;
    while (raiz != NULL)
    {
        aux = raiz;
        raiz = raiz->sig;
        delete aux;
    };
    raiz = final = actual = NULL;
    longitud = 0;
};
//--------------------------------
template <class T>
void Lista<T>::agregar(T* elem)
{
    Nodo* aux = new Nodo;
    aux->elem = elem;
    aux->sig = raiz;
    if (raiz == NULL) { //primera inserci�n
        final = aux;
    }
    raiz = aux;
    longitud++;
}
//--------------------------------
template <class T>
void Lista<T>::agregarOrdenado(T* elem) {
    Nodo* aux = new Nodo;
    Nodo* actual, * anterior;
    aux->elem = elem;
    aux->sig = NULL;
    actual = raiz;
    anterior = NULL;
    while ((actual != NULL) && (actual->elem < elem)) {
        anterior = actual;
        actual = actual->sig;
    };
    //actualizo datos del puntero al final
    if (actual != NULL && actual->sig == NULL) {
        final = actual;
    };
    if (actual == NULL) {
        final = aux;
    }
    //caso insercion en la raiz
    if (anterior == NULL) {
        aux->sig = raiz;
        raiz = aux;
    }
    else {
        aux->sig = actual;
        anterior->sig = aux;
    };
    longitud++;
}
//--------------------------------
template <class T>
void Lista<T>::agregarFinal(T* elem) {
    Nodo* aux = new Nodo;
    Nodo* actual;
    aux->elem = elem;
    aux->sig = NULL;
    actual = raiz;
    //caso insercion en la raiz
    if (actual == NULL) {
        aux->sig = raiz;
        raiz = aux;
        final = raiz;
    }
    else {
        final->sig = aux;
        final = aux;
    }
    longitud++;
};
//--------------------------------
template <class T>
void Lista<T>::eliminar(T* elem)
{// si el elemento no esta no pasa nada
    Nodo* aux2, * aux1 = raiz;
    if (raiz == NULL) return;
    //primer caso
    if (*(raiz->elem) == *elem)
    {
        raiz = raiz->sig;
        longitud--;
        if (raiz == NULL) {
            final = NULL;
        }
        delete aux1;
        return;
    }
    aux2 = aux1->sig;
    while (aux2 != NULL) {
        if (*(aux2->elem) == *elem)
        {
            aux1->sig = aux2->sig;
            if (aux1->sig == NULL) { //elimine el �ltimo nodo
                final = aux1;
            }
            longitud--;
            delete aux2;
            return;
        }
        else
        {
            aux1 = aux2;
            aux2 = aux2->sig;
        };
    };
};
//--------------------------------
template <class T>
void Lista<T>::eliminarSinBorrar(T* elem)
{// si el elemento no esta no pasa nada
    Nodo* aux2, * aux1 = raiz;
    if (raiz == NULL) return;
    //primer caso
    if (*(raiz->elem) == *elem)
    {
        raiz = raiz->sig;
        longitud--;
        if (raiz == NULL) {
            final = NULL;
        }
        return;
    }
    aux2 = aux1->sig;
    while (aux2 != NULL) {
        if (*(aux2->elem) == *elem)
        {
            aux1->sig = aux2->sig;
            if (aux1->sig == NULL) { //elimine el �ltimo nodo
                final = aux1;
            }
            longitud--;
            return;
        }
        else
        {
            aux1 = aux2;
            aux2 = aux2->sig;
        };
    };
};
//--------------------------------
template <class T>
T* Lista<T>::get(int pos) {
    if (pos < longitud) {
        Nodo* aux1 = raiz;
        T* aux = new T;
        int i;
        for (i = 0; i < pos; i++)
            aux1 = aux1->sig;
        aux = aux1->elem;
        return aux;
    }
    else
        return NULL;
};
//--------------------------------
template <class T>
T* Lista<T>::pertenece(T* elem)
{// NULL si no existe y sino la posici�n
    Nodo* aux = raiz;
    while (aux != NULL)
    {
        if (*(aux->elem) == (*elem))
            return (aux->elem);
        else
            aux = aux->sig;
    };
    return NULL;
};
//--------------------------------        
template <class T>
T* Lista<T>::primero()
{
    if (raiz == NULL)
        return(NULL);
    else {
        actual = raiz;
        return(raiz->elem);
    }
}
//--------------------------------
template <class T>
T* Lista<T>::siguiente()
{
    if (actual == NULL)
        return(NULL);
    else
        if (actual->sig == NULL)
            return(NULL);
        else
        {
            actual = actual->sig;
            return(actual->elem);
        };
};
//--------------------------------
template <class T>
int Lista<T>::tamanio()
{
    return(longitud);
};
//--------------------------------
template <class T>
void Lista<T>::clonar(Lista<T>* origen) {
    T* tmp;
    for (T* aux = origen->primero(); aux; aux = origen->siguiente()) {
        tmp = new T;
        *tmp = *aux;
        agregarFinal(tmp);
    };
};
//--------------------------------
//anibal
template <class T>
void Lista<T>::agregarLista(Lista<T>* list) {
    T* tmp;
    for (T* aux = list->primero(); aux; aux = list->siguiente()) {
        tmp = new T;
        *tmp = *aux;
        agregar(tmp);
    };
};
template class Lista2<Punto>;
template <class T>
Lista2<T>::Lista2() { raiz = actual = NULL; longitud = 0; };
//--------------------------------
template <class T>
Lista2<T>::~Lista2() { vaciar(); };
//--------------------------------
template <class T>
void Lista2<T>::vaciar() {
    Nodo* aux = raiz;
    while (raiz != NULL)
    {
        aux = raiz;
        raiz = raiz->sig;
        delete aux;
    };
    raiz = final = actual = NULL;
    longitud = 0;
};
//--------------------------------
template <class T>
void Lista2<T>::agregar(T* elem)
{
    Nodo* aux = new Nodo;
    aux->elem = elem;
    aux->sig = raiz;
    if (raiz->sig == NULL) { //primera inserci�n
        final = raiz;
    }
    raiz = aux;
    longitud++;
}
//--------------------------------
template <class T>
void Lista2<T>::agregarOrdenado(T* elem) {
    Nodo* aux = new Nodo;
    Nodo* actual, * anterior;
    aux->elem = elem;
    aux->sig = NULL;
    actual = raiz;
    anterior = NULL;
    while ((actual->elem < elem) && (actual != NULL)) {
        anterior = actual;
        actual = actual->sig;
    };
    //actualizo datos del puntero al final
    if (actual != NULL && actual->sig == NULL) {
        final = actual;
    };
    if (actual == NULL) {
        final = aux;
    }
    //caso insercion en la raiz
    if (anterior == NULL) {
        aux->sig = raiz;
        raiz = aux;
    }
    else {
        aux->sig = actual;
        anterior->sig = aux;
    };
    longitud++;
}
//--------------------------------
template <class T>
void Lista2<T>::agregarFinal(T* elem) {
    Nodo* aux = new Nodo;
    Nodo* actual;
    aux->elem = elem;
    aux->sig = NULL;
    actual = raiz;
    //caso insercion en la raiz
    if (actual == NULL) {
        aux->sig = raiz;
        raiz = aux;
        final = raiz;
    }
    else {
        final->sig = aux;
        final = aux;
    }
    longitud++;
};
//--------------------------------
template <class T>
void Lista2<T>::eliminar(T* elem)
{// si el elemento no esta no pasa nada
    Nodo* aux2, * aux1 = raiz;
    if (raiz == NULL) return;
    //primer caso
    if (*(raiz->elem) == *elem)
    {
        raiz = raiz->sig;
        longitud--;
        if (raiz == NULL) {
            final = NULL;
        }
        delete aux1;
        return;
    }
    aux2 = aux1->sig;
    while (aux2 != NULL) {
        if (*(aux2->elem) == *elem)
        {
            aux1->sig = aux2->sig;
            if (aux1->sig == NULL) { //elimine el �ltimo nodo
                final = aux1;
            }
            longitud--;
            delete aux2;
            return;
        }
        else
        {
            aux1 = aux2;
            aux2 = aux2->sig;
        };
    };
};
//--------------------------------
template <class T>
void Lista2<T>::eliminarSinBorrar(T* elem)
{// si el elemento no esta no pasa nada
    Nodo* aux2, * aux1 = raiz;
    if (raiz == NULL) return;
    //primer caso
    if (*(raiz->elem) == *elem)
    {
        raiz = raiz->sig;
        longitud--;
        if (raiz == NULL) {
            final = NULL;
        }
        return;
    }
    aux2 = aux1->sig;
    while (aux2 != NULL) {
        if (*(aux2->elem) == *elem)
        {
            aux1->sig = aux2->sig;
            if (aux1->sig == NULL) { //elimine el �ltimo nodo
                final = aux1;
            }
            longitud--;
            return;
        }
        else
        {
            aux1 = aux2;
            aux2 = aux2->sig;
        };
    };
};
//--------------------------------
template <class T>
T* Lista2<T>::get(int pos) {
    if (pos < longitud) {
        Nodo* aux1 = raiz;
        T* aux = new T;
        int i;
        for (i = 0; i < pos; i++)
            aux1 = aux1->sig;
        aux = aux1->elem;
        return aux;
    }
    else
        return NULL;
};
//--------------------------------
template <class T>
T* Lista2<T>::pertenece(T* elem)
{// NULL si no existe y sino la posici�n
    Nodo* aux = raiz;
    while (aux != NULL)
    {
        if (*(aux->elem) == (*elem))
            return (aux->elem);
        else
            aux = aux->sig;
    };
    return NULL;
};
//--------------------------------        
template <class T>
T* Lista2<T>::primero()
{
    if (raiz == NULL)
        return(NULL);
    else {
        actual = raiz;
        return(raiz->elem);
    }
}
//--------------------------------
template <class T>
T* Lista2<T>::siguiente()
{
    if (actual == NULL)
        return(NULL);
    else
        if (actual->sig == NULL)
            return(NULL);
        else
        {
            actual = actual->sig;
            return(actual->elem);
        };
};
//--------------------------------
template <class T>
int Lista2<T>::tamanio()
{
    return(longitud);
};
//--------------------------------
template <class T>
void Lista2<T>::clonar(Lista2<T>* origen) {
    T* tmp;
    for (T* aux = origen->primero(); aux; aux = origen->siguiente()) {
        tmp = new T;
        *tmp = *aux;
        agregarFinal(tmp);
    };
};
//--------------------------------
//anibal
template <class T>
void Lista2<T>::agregarLista(Lista2<T>* list) {
    T* tmp;
    for (T* aux = list->primero(); aux; aux = list->siguiente()) {
        tmp = new T;
        *tmp = *aux;
        agregar(tmp);
    };
};
class Cuadrante {
private:
    bool tieneHijos;
    unsigned int level;
    unsigned int indice;
    unsigned int indiceReal;
    unsigned int X;
    unsigned int Y;
    unsigned int largo;
    union D {
        unsigned int posPrimerHijo;
        PuntoExtendido* nodoIn;
    }Dato;
    Punto** portales;
    unsigned int cantPortales;
public:
    Cuadrante() {
        tieneHijos = false;
        level = 0;
        indice = 0;
        indiceReal = 0;
        portales = NULL;
        cantPortales = 0;
        Dato.nodoIn = NULL;
    };
    ~Cuadrante() {
        //se borran cada uno de los portales que posee el cuadrante
        /*for (unsigned int i = 0; i < cantPortales; i++)
            if (portales[i] != NULL) {
                delete(portales[i]);
                portales[i] = NULL;
            };*/
        if (portales != NULL) {
            delete(portales);
            portales = NULL;
        }
        
    };
    void setTieneHijos() { tieneHijos = true; };
    void setLevel(unsigned int x) { level = x; };
    void setIndice(unsigned int d) { indice = d; };
    void setIndiceReal(unsigned int ir) { indiceReal = ir; };
    void setposHijos(unsigned int p) { Dato.posPrimerHijo = p; };
    void setNodoIn(PuntoExtendido* p) { Dato.nodoIn = p; };
    void inicPortales(unsigned int tam) {
        cantPortales = tam;
        portales = new Punto * [tam];
        for (unsigned int i = 0; i < tam; i++)
            portales[i] = NULL;
    }
    unsigned int getLevel() { return level; };
    unsigned int getIndice() { return indice; };
    unsigned int getIndiceReal() { return indiceReal; };
    unsigned int getposHijos() { return Dato.posPrimerHijo; };
    PuntoExtendido* getNodoIn() {
        if (this->tieneHijos)
            return NULL;
        //if (this->Dato.nodoIn == NULL)
          //std::cout << "Error: nodoIn is NULL for leaf node." << std::endl;
        return this->Dato.nodoIn;
    }
    bool hijos() { return tieneHijos; };
    Punto** getPortales() { return portales; };
    unsigned int getCantPortales() { return cantPortales; };
    bool operator ==(Cuadrante c) { return this->indice == c.indice; };
    bool contienePortal(Punto* portal) {
        unsigned int pos = 0;
        while ((pos < cantPortales) && (portales[pos] != portal))
            pos++;
        return pos < cantPortales;
    }
    void getApareo(unsigned int apareo, Punto*& portal1, Punto*& portal2) {
        if ((cantPortales != 0) && (apareo < ((cantPortales * (cantPortales - 1)) / 2))) {
            int aux = apareo;
            int num = 1;
            int resta = 0;
            while ((aux - ((int)this->cantPortales - num)) >= 0) {
                aux -= this->cantPortales - num;
                if (aux >= 0)
                    resta = aux;
                num++;
            }
            portal1 = this->portales[num - 1];
            if ((num - 1) == 0)
                portal2 = this->portales[apareo + 1];
            else
                portal2 = this->portales[resta + num];
        }
        else {
            apareo = apareo - ((cantPortales * (cantPortales - 1)) / 2);
            return getApareo(apareo, portal2, portal1);
        };
    }
    unsigned int getNumApareo(Punto* portal1, Punto* portal2) {
        int ubicacion1, ubicacion2, pos;
        ubicacion1 = ubicacion2 = -1;
        pos = 0;
        while ((pos < cantPortales) && ((ubicacion1 == -1) || (ubicacion2 == -1))) {
            if (portales[pos] == portal1)
                ubicacion1 = pos;
            if (portales[pos] == portal2)
                ubicacion2 = pos;
            pos++;
        };
        if (ubicacion1 >= ubicacion2) { //el primer portal es mayor que el primero
            return getNumApareo(portal2, portal1) + ((cantPortales * (cantPortales - 1)) / 2);
        };
        if (ubicacion1 == 0)     //si el primer indice de portal es el cero
            return ubicacion2 - 1;
        unsigned int indice = 0;
        for (unsigned int s = 0; s < ubicacion1; s++)
            indice += this->cantPortales - (1 + s);
        for (unsigned int s = ubicacion1 + 1; s < ubicacion2; s++)
            indice++;
        return indice;
    }
    unsigned int getX() { return X; };
    unsigned int getY() { return Y; };
    unsigned int getLargo() { return largo; };
    void setX(unsigned int x) { X = x; };
    void setY(unsigned int y) { Y = y; };
    void setLargo(unsigned int larg) { largo = larg; };
    void setPortales(Lista2<Punto>* port) {
        inicPortales(port->tamanio());
        this->cantPortales = 0;
        for (Punto* p = port->primero(); p; p = port->siguiente()) {
            portales[cantPortales++] = p;
        }
    }
};
class SubSolucion {
private:
    float distancia;
    Lista<unsigned int>* hijos;
    Lista<unsigned int>* apareos;
    Lista<bool>* inversiones;
public:
    SubSolucion();
    ~SubSolucion();
    void addHijo(unsigned int x);
    void addApareo(unsigned int a);
    void setDistancia(float d) { distancia = d; };
    Lista<unsigned int>* getHijos() { return hijos; };
    Lista<unsigned int>* getApareos() { return apareos; };
    Lista<bool>* getInversiones() { return inversiones; };
    float getDistancia() { return distancia; };
    void addInversion(bool);
};
//---------------------------------------------------------------------------
SubSolucion::SubSolucion() {
    distancia = DISTANCIAINVALIDA;
    apareos = new Lista<unsigned int>;
    hijos = new Lista<unsigned int>;
    inversiones = new Lista<bool>;
}
//---------------------------------------------------------------------------
SubSolucion::~SubSolucion() {
    delete(hijos);
    hijos = NULL;
    delete(apareos);
    apareos = NULL;
}
//---------------------------------------------------------------------------
void SubSolucion::addHijo(unsigned int x) {
    unsigned int* x1 = new unsigned int;
    *x1 = x;
    hijos->agregarFinal(x1);
}
//---------------------------------------------------------------------------
void SubSolucion::addApareo(unsigned int a) {
    unsigned int* a1 = new unsigned int;
    *a1 = a;
    apareos->agregarFinal(a1);
}
//---------------------------------------------------------------------------
void SubSolucion::addInversion(bool i) {
    bool* b1 = new bool;
    *b1 = i;
    inversiones->agregarFinal(b1);
}
//---------------------------------------------------------------------------
template <class T> class MatrizVariable {
private:
    T*** matriz;
    unsigned int tamX;
    int* tamY;
    bool inicializado;
    //metodos usados para manejo de dimensiones variables
    void inic_TamY();   //inicializa en default value las dimensiones de las columnas
    void reset_TamY(unsigned int); //setea el valor pasado como parametro como dimension de las columnas
    void set_TamY(unsigned int, unsigned int);//setea el valor dado en la columna indicada
public:
    MatrizVariable(unsigned int);
    ~MatrizVariable();
    void inicColumna(unsigned int);
    void inicColumna(unsigned int, unsigned int);
    unsigned int getSizeY(unsigned int);
    unsigned int getSizeX();
    T* get(unsigned int, unsigned int);
    void set(T*, unsigned int, unsigned int);
    bool posValida(unsigned int, unsigned int);
};
template <class T> MatrizVariable<T>::MatrizVariable(unsigned int x) {
    matriz = new T * *[x];
    for (unsigned int i = 0; i < x; i++)
        matriz[i] = NULL;
    tamX = x;
    inic_TamY();
}
//---------------------------------------------------------------------------
template <class T> unsigned int MatrizVariable<T>::getSizeX() {
    return tamX;
}
//---------------------------------------------------------------------------
template <class T> void MatrizVariable<T>::inicColumna(unsigned int y) {
    for (unsigned int i = 0; i < this->getSizeX(); i++) {
        matriz[i] = new T * [y];
        for (unsigned int j = 0; j < y; j++)
            matriz[i][j] = NULL;
    };
    reset_TamY(y);
}
//---------------------------------------------------------------------------
template <class T> void MatrizVariable<T>::inicColumna(unsigned int col, unsigned int y) {
    matriz[col] = new T * [y];
    for (unsigned int j = 0; j < y; j++)
        matriz[col][j] = NULL;
    set_TamY(col, y);
};
//---------------------------------------------------------------------------
template <class T> void MatrizVariable<T>::inic_TamY() {
    inicializado = false;
    tamY = new int[1];
    tamY[0] = TamYdefaultAll;
}
//---------------------------------------------------------------------------
template <class T> void MatrizVariable<T>::reset_TamY(unsigned int value) {
    delete(tamY);
    tamY = new int[2];
    tamY[0] = TamYEqual;
    tamY[1] = value;
};
//---------------------------------------------------------------------------
template <class T> T* MatrizVariable<T>::get(unsigned int x, unsigned int y) {
    if (!this->posValida(x, y))
        return NULL;
    return matriz[x][y];
}
//---------------------------------------------------------------------------
template <class T> void MatrizVariable<T>::set(T* elem, unsigned int x, unsigned int y) {
    if (this->posValida(x, y))
        matriz[x][y] = elem;
}
//---------------------------------------------------------------------------
template <class T> void MatrizVariable<T>::set_TamY(unsigned int col, unsigned int value) {
    if (!inicializado) {
        delete(tamY);
        tamY = new int[tamX];
        for (int i = 0; i<int(tamX); i++)
            tamY[i] = TamYdefault;
    };
    inicializado = true;
    tamY[col] = value;
}
//---------------------------------------------------------------------------
template <class T> MatrizVariable<T>::~MatrizVariable() {
    if (tamY != NULL) {
        delete(tamY);
    }
}
//---------------------------------------------------------------------------
template <class T> unsigned int MatrizVariable<T>::getSizeY(unsigned int col) {
    switch (tamY[0])
    {
    case TamYdefaultAll: return tamY[1];
    case TamYEqual:   return tamY[1];
    };
    return tamY[col];
}
//---------------------------------------------------------------------------
template <class T> bool MatrizVariable<T>::posValida(unsigned int x, unsigned int y) {
    if (x >= this->getSizeX() || y >= this->getSizeY(x)) return false;
    return true;
}
template class MatrizVariable<Punto>;
template class MatrizVariable<SubSolucion>;
class Perturbacion {
    std::string* archivo;       //archivo de Imput
    int cteAproximacion;       //constante de aproximacion de la Optima Solucion
    unsigned int numNodos, numNodosOrig;
    float largoBoundingBox;
    unsigned int largoEnclosingBox;
    PuntoExtendido* nodosImput, ** nodosOriginales, **clonedInput;
    float minCoordX;
    float minCoordY;
public:
    Perturbacion(std::string* arch, int cte) {
        //ruta de datos y constante de aproximacion
        archivo = arch;
        cteAproximacion = cte;
        numNodosOrig = 0;
        //instancia de entrada
        getImput();
        if (nodosImput == NULL)
            return;
        cloneInput();
        //guarda aparte los datos de entrada sin modificar
        copyImput();
        //calculo largo del primer bounding box sin perturbar
        largoBoundingBox = getLargoBB();
        perturbar();
       
    };
    Perturbacion() {
        for (unsigned int i = 0; i < numNodosOrig; i++)
            delete(nodosOriginales[i]);
        delete(nodosOriginales);
        nodosOriginales = NULL;
        delete(nodosImput);
        nodosImput = NULL;
    };
    void cloneInput(){
        clonedInput = new PuntoExtendido * [numNodosOrig]; 
        for (unsigned int i = 0; i < numNodosOrig; i++) {
            clonedInput[i] = new PuntoExtendido(nodosImput[i].getX(), nodosImput[i].getY(), nodosImput[i].getUbicacion());
            }
            
    }
    void perturbar() {
    // Pure translation + enclosing box; no quantization/scaling.
    this->largoBoundingBox = getLargoBB();
    shiftNodos();
    this->largoEnclosingBox = getLargoEB();
    cutNodos();
};

    void shiftNodos() {
    for (unsigned int i = 0; i < numNodos; i++) {
        nodosImput[i].setX(nodosImput[i].getX() - minCoordX + 1.0f);
        nodosImput[i].setY(nodosImput[i].getY() - minCoordY + 1.0f);
    }
};;
    void cutNodos() {
        PuntoExtendido* nuevo = new PuntoExtendido[numNodos];
        int indice = 0;
        bool hayIgual = false;
        for (unsigned int i = 0; i < numNodos - 1; i++) {
            hayIgual = false;
            for (unsigned int j = i + 1; hayIgual == false && j < numNodos; j++)
                if (((int)nodosImput[i].getX() == (int)nodosImput[j].getX()) && ((int)nodosImput[i].getY() == (int)nodosImput[j].getY()))
                    hayIgual = true;
            if (!hayIgual)
                nuevo[indice++] = nodosImput[i];
        };
        nuevo[indice] = nodosImput[numNodos - 1];
        nodosImput = nuevo;
        numNodos = indice + 1;
    };
    float getLargoBB() {
    float minX = FLT_MAX, minY = FLT_MAX;
    float maxX = 0.0f,     maxY = 0.0f;
    for (unsigned int i = 0; i < numNodos; i++) {
        if (nodosImput[i].getX() > maxX) maxX = nodosImput[i].getX();
        if (nodosImput[i].getY() > maxY) maxY = nodosImput[i].getY();
        if (nodosImput[i].getX() < minX) minX = nodosImput[i].getX();
        if (nodosImput[i].getY() < minY) minY = nodosImput[i].getY();
    }
    this->minCoordX = minX;
    this->minCoordY = minY;
    float spanX = maxX - minX;
    float spanY = maxY - minY;
    float span  = (spanX > spanY) ? spanX : spanY;
    this->largoBoundingBox = span;
    return span;
};;
    unsigned int getLargoEB() {
    unsigned int need = (unsigned int)(std::ceil(this->largoBoundingBox) + 1.0f);
    if (need < 1U) need = 1U;
    unsigned int L = 1U;
    while (L < need) L <<= 1U;
    return (this->largoEnclosingBox = L);
};;
    void getImput() {
        std::ifstream file;
        file.open(*this->archivo);
        if (!file.is_open()) {
            std::cerr << "Error opening file: " << this->archivo << std::endl;
            return;
        }
        std::vector<std::string> nodosList;
        std::string line;
        while (std::getline(file, line)) {
            nodosList.push_back(line);
        }
        file.close();
        std::string info;
        // Check if there are at least 4 lines in the file
        if (nodosList.size() < 4) {
            std::cerr << "File format is incorrect: less than 4 lines" << std::endl;
            return;
        }
        // Fetch the 4th line to extract the number of nodes
        info = nodosList[3];
        std::string::size_type spacePos = info.find(" ");
        if (spacePos != std::string::npos) {
            info = info.substr(spacePos + 1, MAX_VAL);
        }
        this->numNodos = std::atoi(info.c_str());
        nodosImput = new PuntoExtendido[numNodos];
        if (this->numNodos == 0) {
            // If numNodos is still 0, re-parse
            spacePos = info.find(" ");
            if (spacePos != std::string::npos) {
                info = info.substr(spacePos + 1, MAX_VAL);
                spacePos = info.find(" ");
                if (spacePos != std::string::npos) {
                    info = info.substr(spacePos + 1, MAX_VAL);
                    this->numNodos = std::atoi(info.c_str());
                    nodosImput = new PuntoExtendido[numNodos];
                }
            }
        }
        // Load node coordinates
        this->numNodosOrig = 0;
        for (int i = 6; i < nodosList.size() - 1; i++) {
            // Parse X coordinate
            std::stringstream ss(nodosList[i]);
            std::string token;
            int j = 0;
            while (std::getline(ss, token, ' ') && !token.empty()) {
                if (j == 1) {
                    nodosImput[numNodosOrig].setX(std::atof(token.c_str()));
                }
                else if (j == 2) {
                    nodosImput[numNodosOrig].setY(std::atof(token.c_str()));
                    break; // Break after setting Y to avoid unnecessary processing
                }
                j++;
            }
            // Set node location
            nodosImput[numNodosOrig].setUbicacion(numNodosOrig);
            this->numNodosOrig++;
        }
    }
    unsigned int getNumNodos() { return numNodos; }
    float getLargoBoundingBox() { return largoBoundingBox; }
    unsigned int getLargoEnclosingBox() { return largoEnclosingBox; }
    Punto* getPerturbacion() { return nodosImput; }
    PuntoExtendido** getCloneInput() { return clonedInput;}
    bool nodos(int x1, int x2, int y1, int y2) {
        int aux = 0;
        int finx;
        int finy;
        if ((x1 > this->largoBoundingBox) || (y1 > this->largoBoundingBox))
            return false;
        for (unsigned int i = 0; i < numNodos; i++)
            if ((((int)nodosImput[i].getX() >= x1) && ((int)nodosImput[i].getX() < x2)) && (((int)nodosImput[i].getY() >= y1) && ((int)nodosImput[i].getY() < y2)))
            {
                aux++;
                if (aux > 1)
                    return true;
            };
        return false;
    }
    PuntoExtendido* getNodo(int x1, int x2, int y1, int y2) {
        if ((x1 > this->largoBoundingBox) || (y1 > this->largoBoundingBox))
            return NULL;
        for (unsigned int i = 0; i < numNodos; i++)
            if ((((int)nodosImput[i].getX() >= x1) && ((int)nodosImput[i].getX() < x2)) && (((int)nodosImput[i].getY() >= y1) && ((int)nodosImput[i].getY() < y2)))
                return &nodosImput[i];
        return NULL;
    }
    void copyImput() {
        nodosOriginales = new PuntoExtendido * [numNodosOrig];
        float x = FLT_MAX;
        float y = FLT_MAX;
        //std::cout << numNodosOrig << std::endl;
        for (unsigned int i = 0; i < numNodosOrig; i++) {
            nodosOriginales[i] = new PuntoExtendido(nodosImput[i].getX(), nodosImput[i].getY(), nodosImput[i].getUbicacion());
            /*std::cout << nodosImput[i].getX()<< std::endl;*/
            if (nodosImput[i].getX() < x)
                x = nodosImput[i].getX();
            if (nodosImput[i].getY() < y)
                y = nodosImput[i].getY();
        }
        for (unsigned int i = 0; i < numNodosOrig; i++) {
            nodosOriginales[i]->setX(nodosOriginales[i]->getX() - x);
            nodosOriginales[i]->setY(nodosOriginales[i]->getY() - y);
        }
    }
    float getMinY() {
        float minY_1 = nodosOriginales[0]->getY();
        float minY_2 = nodosOriginales[0]->getY();
        //busco el menor Y
        for (unsigned int i = 1; i < numNodosOrig; i++)
            if (nodosOriginales[i]->getY() < minY_1)
                minY_1 = nodosOriginales[i]->getY();
        //busco el menor Y mayor que el anterior
        for (unsigned int i = 1; i < numNodosOrig; i++)
            if ((nodosOriginales[i]->getY() < minY_2) && (nodosOriginales[i]->getY() > minY_1))
                minY_2 = nodosOriginales[i]->getY();
        if (minY_2 - minY_1 == 0)
            return MIN_X_DEF;
        return minY_2 - minY_1;
    }
    float getMinX() {
        float minX_1 = nodosOriginales[0]->getX();
        float minX_2 = nodosOriginales[0]->getX();
        //busco el menor Y
        for (unsigned int i = 1; i < numNodosOrig; i++)
            if (nodosOriginales[i]->getX() < minX_1)
                minX_1 = nodosOriginales[i]->getX();
        //busco el menor Y mayor que el anterior
        for (unsigned int i = 1; i < numNodosOrig; i++)
            if ((nodosOriginales[i]->getX() < minX_2) && (nodosOriginales[i]->getX() > minX_1))
                minX_2 = nodosOriginales[i]->getX();
        if (minX_2 - minX_1 == 0)
            return MIN_X_DEF;
        return minX_2 - minX_1;
    }
    PuntoExtendido** getNodosImput() { return nodosOriginales; };
    int getNumNodosO() { return numNodosOrig; };
    Punto* getNodosPerturbados() { return nodosImput; };
};
class Portalizacion {
private:
    unsigned int cantPortalesPorLado;
    Matriz<Punto>* portales;
public:
    Portalizacion(unsigned int, unsigned int,unsigned int r);
    ~Portalizacion();
    Punto* get(unsigned int x, unsigned int y) { return portales->get(x, y); };
    void set(unsigned int x, unsigned int y);
    Lista2<Punto>* getPortales(unsigned int x, unsigned int y, unsigned int dim);
    void portalizar(Lista<Cuadrante>*, Lista<Cuadrante>*);
    bool hayPortales(int, int, int, int);
};
//---------------------------------------------------------------------------
Portalizacion::Portalizacion(unsigned int width, unsigned int height,unsigned int r) {
    portales = new Matriz<Punto>(width, height);
    cantPortalesPorLado = r;
}
//---------------------------------------------------------------------------
Portalizacion::~Portalizacion() {
    delete(portales);
}
//---------------------------------------------------------------------------
Lista2<Punto>* Portalizacion::getPortales(unsigned int x, unsigned int y, unsigned int dim) {
    Lista2<Punto>* aux = new Lista2<Punto>();
    for (int x2 = x + dim; x2 >= (int)x; x2--) {
        Punto* p = portales->get(x2, y);
        if (p != NULL)
            aux->agregarFinal(p);
    }
    for (int y2 = y; y2 < y + dim; y2++) {
        Punto* p = portales->get(x, y2);
        if (p != NULL)
            aux->agregarFinal(p);
    }
    for (int x2 = x; x2 < x + dim; x2++) {
        Punto* p = portales->get(x2, y + dim);
        if (p != NULL)
            aux->agregarFinal(p);
    }
    for (int y2 = y + dim; y2 > (int)y; y2--) {
        Punto* p = portales->get(x + dim, y2);
        if (p != NULL)
            aux->agregarFinal(p);
    }
    return aux;
};
//---------------------------------------------------------------------------
void Portalizacion::portalizar(Lista<Cuadrante>* c, Lista<Cuadrante>* h) {
    unsigned int x, y, dim;
    Lista2<Punto>* portales;

    auto add_side_portals = [this](unsigned int x, unsigned int y, unsigned int dim, int dir) {
        // Place up to `cantPortalesPorLado` evenly-spaced portals per side (excluding corners).
        // For small `dim`, rounding may collapse some positions; `set` will dedup.
        if (dim == 0) return;
        const unsigned int k = cantPortalesPorLado > 0 ? cantPortalesPorLado : 1;
        // Precompute interior coordinate offsets in [1, dim-1]
        // Use round to spread as evenly as possible.
        for (unsigned int i = 1; i <= k; ++i) {
            double t = (static_cast<double>(i) / (k + 1)); // (0,1)
            unsigned int off = static_cast<unsigned int>( (t * dim) + 0.5 ); // round
            if (off == 0) off = 1;
            if (off >= dim) off = dim - 1;
            switch (dir) {
                case ARRIBA:   // top edge: (x+off, y)
                    this->set(x + off, y);
                    break;
                case IZQUIERDA: // left edge: (x, y+off)
                    this->set(x, y + off);
                    break;
                case ABAJO:    // bottom edge: (x+off, y+dim)
                    this->set(x + off, y + dim);
                    break;
                case DERECHA:  // right edge: (x+dim, y+off)
                    this->set(x + dim, y + off);
                    break;
            }
        }
    };

    // First pass: ensure leaves have portals; for each side, add K evenly-spaced points
    for (Cuadrante* auxH = h->primero(); auxH; auxH = h->siguiente()) {
        x = auxH->getX();
        y = auxH->getY();
        dim = auxH->getLargo();

        // Only add if that side has no portals yet (shared edges will be deduped by `set` anyway).
        if (!this->hayPortales(x, y, dim, ARRIBA))   add_side_portals(x, y, dim, ARRIBA);
        if (!this->hayPortales(x, y, dim, IZQUIERDA)) add_side_portals(x, y, dim, IZQUIERDA);
        if (!this->hayPortales(x, y, dim, ABAJO))    add_side_portals(x, y, dim, ABAJO);
        if (!this->hayPortales(x, y, dim, DERECHA))  add_side_portals(x, y, dim, DERECHA);

        portales = this->getPortales(x, y, dim);
        auxH->setPortales(portales);
    }

    // Second pass: populate portal arrays for non-leaf quadrants from the global matrix
    for (Cuadrante* auxC = c->primero(); auxC; auxC = c->siguiente()) {
        x = auxC->getX();
        y = auxC->getY();
        dim = auxC->getLargo();
        portales = this->getPortales(x, y, dim);
        auxC->setPortales(portales);
    }

for (Cuadrante* auxC = c->primero(); auxC; auxC = c->siguiente()) {
        x = auxC->getX();
        y = auxC->getY();
        dim = auxC->getLargo();
        portales = this->getPortales(x, y, dim);
        auxC->setPortales(portales);
    }
}
//---------------------------------------------------------------------------
void Portalizacion::set(unsigned int x, unsigned int y) {
    Punto* p = portales->get(x, y);
    if (p == NULL) {
        p = new Punto(x, y);
        portales->set(p, x, y);
    };
}
//---------------------------------------------------------------------------
bool Portalizacion::hayPortales(int x, int y, int dim, int dir) {
    bool hay = false;
    switch (dir)
    {
    case ARRIBA:
        for (int x2 = x + dim; x2 >= (int)x; x2--) {
            Punto* p = portales->get(x2, y);
            if (p != NULL)
                hay = true;
        }
        break;
    case IZQUIERDA:
        for (int y2 = y; y2 < y + dim; y2++) {
            Punto* p = portales->get(x, y2);
            if (p != NULL)
                hay = true;
        }
        break;
    case ABAJO:
        for (int x2 = x; x2 < x + dim; x2++) {
            Punto* p = portales->get(x2, y + dim);
            if (p != NULL)
                hay = true;
        }
        break;
    case DERECHA:
        for (int y2 = y + dim; y2 >= (int)y; y2--) {
            Punto* p = portales->get(x + dim, y2);
            if (p != NULL)
                hay = true;
        }
        break;
    }
    return hay;
}
//---------------------------------------------------------------------------
class QuadTree {
protected:
    Cuadrante** quadtr;
    unsigned __int64 dimension;
    unsigned __int64 dimensionAsignada;
    void expandir(unsigned int); //le da mas espacio de memoria al quadtree
public:
    QuadTree(unsigned int);
    ~QuadTree();
    void agregar(Cuadrante*, unsigned int);
    Cuadrante** root();
};
//---------------------------------------------------------------------------
QuadTree::QuadTree(unsigned int dim) {
    dimension = dim;
    dimensionAsignada = CTEDIM;
    if (dimensionAsignada == 0)
        quadtr = NULL;
    else {
        quadtr = new Cuadrante * [dimensionAsignada];
        for (unsigned int i = 0; i < dimensionAsignada; i++)
            quadtr[i] = NULL;
    };
}
//---------------------------------------------------------------------------
QuadTree::~QuadTree() {}
//---------------------------------------------------------------------------
void QuadTree::agregar(Cuadrante* info, unsigned int pos) {
    if (pos > dimensionAsignada)
        expandir(pos);
    *(quadtr + pos) = info;
}
//---------------------------------------------------------------------------
void QuadTree::expandir(unsigned int posRequerida) {
    int indiceExpansion = posRequerida / CTEDIM;
    Cuadrante** nuevoQuadtr = new Cuadrante * [dimensionAsignada + ((indiceExpansion + 1) * CTEDIM)];
    for (unsigned int i = 0; i < dimensionAsignada; i++)
        nuevoQuadtr[i] = this->quadtr[i];
    for (unsigned int j = dimensionAsignada; j < dimensionAsignada + ((indiceExpansion + 1) * CTEDIM); j++)
        nuevoQuadtr[j] = NULL;
    delete(this->quadtr);
    this->quadtr = nuevoQuadtr;
    dimensionAsignada = dimensionAsignada + ((indiceExpansion + 1) * CTEDIM);
}
//---------------------------------------------------------------------------
Cuadrante** QuadTree::root() { return quadtr; }
//---------------------------------------------------------------------------
class QuadTreeTSP : public QuadTree {
private:
    unsigned int ancho;
    unsigned int alto;
    unsigned int cantCuadrantes;
    unsigned int cantHojas;
    unsigned int maxCuadrante;
    unsigned int dimComprimida;
    unsigned int* indicesLevel;
    void make(Perturbacion* pert, unsigned int dim, unsigned int* indiceReal, unsigned int numCuadrante, unsigned int x, unsigned int y, Portalizacion* portalizacion) {
        this->cantCuadrantes++;
        Cuadrante* aux = new Cuadrante;
        aux->setLevel(log2(this->ancho / dim));  //calculo del Numero de Nivel
        aux->setIndice(numCuadrante);
        aux->setIndiceReal(*indiceReal);
        aux->setX(x);
        aux->setY(y);
        aux->setLargo(dim);
        //actualizando el indice real para el proximo cuadrante
        (*indiceReal) = (*indiceReal) + 1;
        if (maxCuadrante < numCuadrante)
            maxCuadrante = numCuadrante;
        //Corte Recursion: Dimension minima o Cuadrante con menos de dos nodos
        if ((dim > 1) && (pert->nodos(x, x + dim, y, y + dim))) {
            aux->setTieneHijos();
            aux->setposHijos(4 * numCuadrante + 1);
            this->agregar(aux, numCuadrante);
            //llamado a la recursion
            make(pert, dim / 2, indiceReal, 4 * numCuadrante + 1, x, y, portalizacion);
            make(pert, dim / 2, indiceReal, 4 * numCuadrante + 2, x + (dim / 2), y, portalizacion);
            make(pert, dim / 2, indiceReal, 4 * numCuadrante + 3, x, y + (dim / 2), portalizacion);
            make(pert, dim / 2, indiceReal, 4 * numCuadrante + 4, x + (dim / 2), y + (dim / 2), portalizacion);
        }
        else { //llegue a una hoja
            cantHojas++;
            aux->setNodoIn(pert->getNodo(x, x + dim, y, y + dim));
            this->agregar(aux, numCuadrante);
        }
    };
    bool pertenece(Punto* p, Punto** points, unsigned int size);
    void comprimirRepresentacion();
public:
    // Constructor and Destructor
    QuadTreeTSP(unsigned int ancho, unsigned int alto, unsigned int cantCuadrantes, int someParameter);
    virtual ~QuadTreeTSP();
    // Public member functions
    bool esPadre(unsigned int node);
    unsigned int getPadre(unsigned int x);
    unsigned int getNumeroDeHijo(unsigned int h);
    Cuadrante* getHijo(unsigned int x, unsigned int y);
    void make(Perturbacion* pert, Portalizacion* portalizacion) {
        unsigned int* indice = new unsigned int;
        *indice = 0;
        make(pert, ancho, indice, 0, 0, 0, portalizacion);
        comprimirRepresentacion();
        delete(indice);
    };
    unsigned int getCantCuadrantes();
    unsigned int getProfundidad();
    unsigned int getDimComprimida();
    unsigned int getAncho();
    Lista<Cuadrante>* getCuadrantes() {
        //si ya fue construido el quadtree
        if (cantCuadrantes != 0) {
            Lista<Cuadrante>* auxL = new Lista<Cuadrante>;
            for (unsigned int i = 0; i < this->dimComprimida; i++)
                //si el lugar esta ocupado
                if (this->quadtr[i] != NULL)
                    auxL->agregar(this->quadtr[i]);
            return auxL;
        }
        else
            return NULL;
    };
    Lista<Cuadrante>* getCuadrantesPadres() {
        //si ya fue construido el quadtree
        if (cantCuadrantes != 0) {
            Lista<Cuadrante>* auxL = new Lista<Cuadrante>;
            for (unsigned int i = 0; i < this->dimComprimida; i++)
                //si el lugar esta ocupado
                if ((this->quadtr[i] != NULL) && (this->quadtr[i]->hijos()))
                    auxL->agregar(this->quadtr[i]);
            return auxL;
        }
        else
            return NULL;
    };
    unsigned int getIndexCLevel(unsigned int level);
    Cuadrante* getCuadrante(unsigned int index);
    Cuadrante** getArreglo();
    unsigned int getAnchoLevel(unsigned int level);
    unsigned int getMaxLevelOcupado();
    Punto* getComienzo(unsigned int index);
    bool adyacentes(unsigned int node1, unsigned int node2);
    unsigned int getAdyacenteDe(unsigned int node);
    unsigned int getAdyacenteDistintoDe(unsigned int node1, unsigned int node2);
    bool hermanos(unsigned int node1, unsigned int node2);
    Lista<Cuadrante>* getHojas() {
        //si ya fue construido el quadtree
        if (cantCuadrantes != 0) {
            Lista<Cuadrante>* auxL = new Lista<Cuadrante>;
            for (int i = this->dimComprimida - 1; i >= 0; i--)
                //si no posee hijos es una hoja
                if ((this->quadtr[i] != NULL) && (!this->quadtr[i]->hijos()))
                    auxL->agregarFinal(this->quadtr[i]);
            return auxL;
        }
        else
            return NULL;
    };
    Lista<Cuadrante>* getHijosde(unsigned int padre) {
        if (this->esPadre(padre)) {
            Lista<Cuadrante>* auxL = new Lista<Cuadrante>;
            auxL->agregar(this->getHijo(padre, 4));
            auxL->agregar(this->getHijo(padre, 3));
            auxL->agregar(this->getHijo(padre, 2));
            auxL->agregar(this->getHijo(padre, 1));
            return auxL;
        }
        else
            return NULL;
    };
    Lista<Punto>* getPortalesCompartidos(unsigned int hijo1, unsigned int hijo2) {
        //si son hijos adyacentes
        if (this->adyacentes(hijo1, hijo2)) {
            Punto** auxH1;
            Punto** auxH2;
            Lista<Punto>* auxRtdo = new Lista<Punto>;
            auxH1 = this->quadtr[hijo1]->getPortales();
            auxH2 = this->quadtr[hijo2]->getPortales();
            unsigned int longitud = this->quadtr[hijo2]->getCantPortales();
            for (unsigned int i = 0; i < this->quadtr[hijo1]->getCantPortales(); i++)
                if (pertenece(auxH1[i], auxH2, longitud))
                    auxRtdo->agregar(auxH1[i]);
            if (auxRtdo->tamanio() != 0)
                return auxRtdo;
            else
                return NULL;
        }
        else
            return NULL;
    }
    int elRestoSinNodos(unsigned int padre, unsigned int hijo1, unsigned int hijo2);
    unsigned int hijoQueCompartePortal(Punto* portal, unsigned int padre);
};
//---------------------------------------------------------------------------
QuadTreeTSP::QuadTreeTSP(unsigned int dim, unsigned int ancho, unsigned int alto, int cte) :QuadTree(dim) {
    cantCuadrantes = 0;
    cantHojas = 0;
    this->alto = alto;
    this->ancho = ancho;
    maxCuadrante = 0;
    dimComprimida = 0;
    unsigned int profundidad = this->getProfundidad();
    indicesLevel = new unsigned int[profundidad + 1];
    indicesLevel[0] = 0;
    for (unsigned int l = 1; l <= profundidad; l++) {
        indicesLevel[l] = pow(4, l - 1) + indicesLevel[l - 1];
    }
}
//---------------------------------------------------------------------------
QuadTreeTSP :: ~QuadTreeTSP() {
    for (unsigned int i = 0; i < dimComprimida; i++)
        if (quadtr[i] != NULL) {
            delete(quadtr[i]);
            quadtr[i] = NULL;
        };
    if (quadtr != NULL) {
        delete(quadtr);
        quadtr = NULL;
    };
}
//---------------------------------------------------------------------------
Cuadrante* QuadTreeTSP::getHijo(unsigned int padre, unsigned int nHijo) { return quadtr[4 * padre + nHijo]; }
//---------------------------------------------------------------------------
unsigned int QuadTreeTSP::getPadre(unsigned int x) { return floor((x - 1) / 4); }
//---------------------------------------------------------------------------
unsigned int QuadTreeTSP::getNumeroDeHijo(unsigned int h) { return ((h - 1) % 4) + 1; }
//---------------------------------------------------------------------------
unsigned int QuadTreeTSP::getCantCuadrantes() { return cantCuadrantes; }
//---------------------------------------------------------------------------
unsigned int QuadTreeTSP::getAnchoLevel(unsigned int level) { return this->ancho / pow(2, level); }
//---------------------------------------------------------------------------
Cuadrante** QuadTreeTSP::getArreglo() { return this->quadtr; }
//---------------------------------------------------------------------------
unsigned int QuadTreeTSP::getAncho() { return this->ancho; }
//---------------------------------------------------------------------------
unsigned int QuadTreeTSP::getProfundidad() { return log2(ancho); }
//---------------------------------------------------------------------------
unsigned int QuadTreeTSP::getDimComprimida() { return dimComprimida; };
//---------------------------------------------------------------------------
//Devuelve si una posicion del Quadtree es "nodo" u "hoja"
bool QuadTreeTSP::esPadre(unsigned int pos) {
    if (this->quadtr[pos] != NULL)
        return quadtr[pos]->hijos();
    return false;
}
//---------------------------------------------------------------------------
void QuadTreeTSP::comprimirRepresentacion() {
    Cuadrante** newQuad;
    newQuad = new Cuadrante * [maxCuadrante + 1];
    for (unsigned int i = maxCuadrante + 1; i < this->dimensionAsignada; i++)
        delete(this->quadtr[i]);
    for (unsigned int i = 0; i < maxCuadrante + 1; i++)
        newQuad[i] = this->quadtr[i];
    this->quadtr = newQuad;
    this->dimComprimida = maxCuadrante + 1;
}
//---------------------------------------------------------------------------
unsigned int QuadTreeTSP::getIndexCLevel(unsigned int level) {
    return indicesLevel[level];
}
//---------------------------------------------------------------------------
bool QuadTreeTSP::adyacentes(unsigned int hijo1, unsigned int hijo2) {
    unsigned int padre1 = this->getPadre(hijo1);
    unsigned int padre2 = this->getPadre(hijo2);
    //si poseen el mismo padre
    if (padre1 == padre2) {
        //hijos 1 y 2
        if (padre1 * 4 + 1 == hijo1)
            if ((padre1 * 4 + 3 == hijo2) || (padre1 * 4 + 2 == hijo2))
                return true;
        if (padre1 * 4 + 1 == hijo2)
            if ((padre1 * 4 + 3 == hijo1) || (padre1 * 4 + 2 == hijo1))
                return true;
        //hijos 2 y 4
        if (padre1 * 4 + 2 == hijo1)
            if (padre1 * 4 + 4 == hijo2)
                return true;
        if (padre1 * 4 + 2 == hijo2)
            if (padre1 * 4 + 4 == hijo1)
                return true;
        //hijos 3 y 4
        if (padre1 * 4 + 3 == hijo1)
            if (padre1 * 4 + 4 == hijo2)
                return true;
        if (padre1 * 4 + 3 == hijo2)
            if (padre1 * 4 + 4 == hijo1)
                return true;
        return false;
    }
    else
        return false;
};
//---------------------------------------------------------------------------
bool QuadTreeTSP::hermanos(unsigned int hijo1, unsigned int hijo2) {
    return (this->getPadre(hijo1) == this->getPadre(hijo2));
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
Cuadrante* QuadTreeTSP::getCuadrante(unsigned int cuadr) {
    if (cuadr < this->dimComprimida)
        return this->quadtr[cuadr];
    else
        return NULL;
}
//---------------------------------------------------------------------------
unsigned int QuadTreeTSP::getMaxLevelOcupado() {
    return this->quadtr[maxCuadrante]->getLevel();
}
//---------------------------------------------------------------------------
bool QuadTreeTSP::pertenece(Punto* punto, Punto** lista, unsigned int longitud) {
    for (unsigned int i = 0; i < longitud; i++)
        if (lista[i] == punto)
            return true;
    return false;
}
//---------------------------------------------------------------------------
int QuadTreeTSP::elRestoSinNodos(unsigned int padre, unsigned int hijoI, unsigned int hijoII) {
    unsigned int h1, h2;
    h1 = 4 * padre + 1;  //ubica la posicion del primer hijo del padre
    while ((h1 == hijoI) || (h1 == hijoII))
        h1++;
    h2 = 4 * padre + 1;
    while ((h2 == h1) || (h2 == hijoI) || (h2 == hijoII))
        h2++;
    //si los dos hijos son padres se supone que siempre tiene algun hijo con nodos
    if ((quadtr[h1]->hijos()) && (quadtr[h2]->hijos()))
        return AMBOS;
    //si el h1 es padre y h2 no lo es
    if (quadtr[h1]->hijos()) {
        if (quadtr[h2]->getNodoIn() == NULL)
            return h1;
        else
            return AMBOS;
    };
    //si el h2 es padre y h1 no lo es
    if (quadtr[h2]->hijos()) {
        if (quadtr[h1]->getNodoIn() == NULL)
            return h2;
        else
            return AMBOS;
    };
    //si ambos hijos son hojas se analiza si poseen o no nodos
    if ((quadtr[h1]->getNodoIn() == NULL) && (quadtr[h2]->getNodoIn() == NULL))
        return NINGUNO; //ninguno de los hijos posee nodos
    if ((quadtr[h1]->getNodoIn() != NULL) && (quadtr[h2]->getNodoIn() != NULL))
        return AMBOS;  //los dos poseen
    if ((quadtr[h1]->getNodoIn() != NULL) && (quadtr[h2]->getNodoIn() == NULL))
        return h1;   //el hijo h1 posee nodos
    if ((quadtr[h1]->getNodoIn() == NULL) && (quadtr[h2]->getNodoIn() != NULL))
        return h2;   //el hijo h2 posee nodos
    return NINGUNO;
}
//---------------------------------------------------------------------------
unsigned int QuadTreeTSP::getAdyacenteDe(unsigned int indice) {
    unsigned int numHijo = this->getNumeroDeHijo(indice);
    if ((numHijo == 1))
        return indice + 2;
    if ((numHijo == 3))
        return indice + 1;
    if (numHijo == 2)
        return indice + 2;
    if (numHijo == 4)
        return indice - 2;
    return 0;
}
//---------------------------------------------------------------------------
unsigned int QuadTreeTSP::hijoQueCompartePortal(Punto* portal, unsigned int padre) {
    unsigned int hijo = 4 * padre + 1; // tomamos el primer hijo
    unsigned int fin = 4 * padre + 4;
    while ((hijo <= fin) && (!quadtr[hijo]->contienePortal(portal)))
        hijo++;
    if (hijo <= fin) //si pare en alguno de los hijos validos
        return hijo;
    else
        return fin + 1;   //sino retorno hijo imposible
}
//---------------------------------------------------------------------------
unsigned int QuadTreeTSP::getAdyacenteDistintoDe(unsigned int padre, unsigned int adyConocido) {
    unsigned int suma = ((padre * 4) + 1);
    suma = suma + (suma + 3);
    return suma - adyConocido;
}
//---------------------------------------------------------------------------
class ProgramacionDinamica {
private:
    QuadTreeTSP* quad;
    Cuadrante** quadtr;
    MatrizVariable<SubSolucion>* matriz;
    Perturbacion* perturbacion;
    void makeHojas(); //resuelve la Programacion para las hojas
    void makeSolucionLevel(unsigned int); //construye la solucion del nivel dado
    void makeSolucion();
public:
    ProgramacionDinamica(QuadTreeTSP* quadt,Perturbacion* perturbacion_=NULL) {
        quad = quadt;
        perturbacion = perturbacion_;
        quadtr = quad->getArreglo();
        matriz = new MatrizVariable<SubSolucion>(quad->getCantCuadrantes());
    }
    ~ProgramacionDinamica();
    void execute();
    void reconstructFromQuadrant(unsigned int qIdx, unsigned int aparIdx, std::vector<Punto*>& path, std::set<unsigned int>& visitedNodes);
    void reconstructPath(std::vector<Punto*>& path);
    SubSolucion* getSubSolucion(unsigned int, unsigned int);
};
//---------------------------------------------------------------------------
ProgramacionDinamica::~ProgramacionDinamica() { delete(matriz); };
//---------------------------------------------------------------------------
void ProgramacionDinamica::execute() {
    //construye las soluciones de las hojas
    makeHojas();
    unsigned int maxLevel = quad->getMaxLevelOcupado();
    //construye las soluciones en todos los demas niveles
    for (unsigned int level = maxLevel - 1; level > 0; level--)  //no se consideran ni el cero ni el maxLevel
        makeSolucionLevel(level);
    //construye la Solucion (NIVEL 0)
    makeSolucion();
}
//---------------------------------------------------------------------------
void ProgramacionDinamica::makeHojas() {
    Lista<Cuadrante>* hojas = quad->getHojas();
    unsigned int cantPortales, apareos, iReal;
    float dist1, dist2;
    Punto* apar1, * apar2, * nodo;
    SubSolucion* sb;
    apar1 = NULL;
    apar2 = NULL;
    nodo = NULL;
    //resuelvo el problema para cada una de las hojas
    for (Cuadrante* c = hojas->primero(); c != NULL; c = hojas->siguiente()) {
        //inicializando el tamaño de la columna correspondiente a la hoja
        iReal = c->getIndiceReal();
        cantPortales = c->getCantPortales();
        apareos = (cantPortales * (cantPortales - 1));
        matriz->inicColumna(iReal, apareos);
        for (unsigned int i = 0; i < apareos; i++) {
            sb = new SubSolucion();
            c->getApareo(i, apar1, apar2);
            nodo = c->getNodoIn();
            if (apar1 && apar2 && nodo) {
                dist1 = nodo->distancia_Total_a(apar1);
                dist2 = nodo->distancia_Total_a(apar2);
                sb->setDistancia(dist1 + dist2);
            }
            else {
                dist1 = apar1->distancia_Total_a(apar2);
                sb->setDistancia(dist1);
            };
            matriz->set(sb, iReal, i);
        };
    };
}
void ProgramacionDinamica::makeSolucionLevel(unsigned int level) {
    unsigned int primerIndice = quad->getIndexCLevel(level); //primer cuadrante de ese nivel
    unsigned int ultimoIndice = quad->getIndexCLevel(level + 1); //primer cuadrante del nivel proximo
    unsigned int cantPortales, apareos, iReal, hijo1, hijo2;
    float dist1, dist2, distMin, distActual;
    Punto* apar1, * apar2;
    SubSolucion* sb;
    apar1 = NULL;
    apar2 = NULL;
    //para cada Cuadrante del nivel dado      
    for (unsigned int ind = primerIndice; ind < ultimoIndice; ind++) {
        if ((quadtr[ind] != NULL) && (quadtr[ind]->hijos())) {
            cantPortales = quadtr[ind]->getCantPortales();
            apareos = (cantPortales * (cantPortales - 1));
            iReal = quadtr[ind]->getIndiceReal();
            matriz->inicColumna(iReal, apareos);
            //para cada uno de sus apareos
            for (unsigned int apareo = 0; apareo < apareos; apareo++) {
                sb = new SubSolucion();
                distMin = FLT_MAX;
                distActual = 0;
                quadtr[ind]->getApareo(apareo, apar1, apar2);
                //obtengo los hijos que comparten los portales
                hijo1 = quad->hijoQueCompartePortal(apar1, ind); //hijo que comparte el portal de comienzo
                hijo2 = quad->hijoQueCompartePortal(apar2, ind); //hijo que comparte el portal de fin
                Lista<Punto>* portCompartidosI = NULL;
                Lista<Punto>* portCompartidosII = NULL;
                Lista<Punto>* portCompartidosIII = NULL;
                Lista<Punto>* portCompartidosIV = NULL;
                unsigned int aparI, aparII, aparIII, aparIV, aparV, aparMinI, aparMinII, aparMinIII, aparMinIV, aparMinV;
                if (hijo1 != hijo2) {    //si los portales no pertenecen al mismo hijo
                    //averiguo si los demas hijos poseen nodos o no, o cual de ellos posee
                    int cualConNodos = quad->elRestoSinNodos(ind, hijo1, hijo2);
                    //tengo en cuenta los casos posibles a presentarse
                    if (quad->adyacentes(hijo1, hijo2)) {
                        if (cualConNodos == NINGUNO) {  //ninguno de los otros hijos poseen nodos
                            portCompartidosI = quad->getPortalesCompartidos(hijo1, hijo2);
                            unsigned int numHijo = quad->getNumeroDeHijo(hijo1);
                            //recorro cada uno de los portales que comparten los hijos
                            for (Punto* paux = portCompartidosI->primero(); paux != NULL; paux = portCompartidosI->siguiente()) {
                                //obtengo los numeros de apareamientos
                                aparI = quadtr[hijo1]->getNumApareo(apar1, paux);
                                aparII = quadtr[hijo2]->getNumApareo(paux, apar2);
                                distActual = matriz->get(quadtr[hijo1]->getIndiceReal(), aparI)->getDistancia() + matriz->get(quadtr[hijo2
                                ]->getIndiceReal(), aparII)->getDistancia();
                                //comparo con los datos minimos anteriores
                                if (distActual < distMin) {
                                    distMin = distActual;
                                    aparMinI = aparI;
                                    aparMinII = aparII;
                                };
                            };
                            //seteo de la matriz con la min distancia obtenida
                            sb->addHijo(hijo1);
                            sb->addHijo(hijo2);
                            sb->addApareo(aparMinI);
                            sb->addApareo(aparMinII);
                            sb->setDistancia(distMin);
                            matriz->set(sb, iReal, apareo);
                        } //fin del if cualConNodos==NINGUNO
                        else { //si los otros poseen nodos o uno de ellos posee
                            unsigned int hijo3, hijo4;
                            hijo3 = quad->getAdyacenteDistintoDe(ind, hijo2);
                            hijo4 = quad->getAdyacenteDistintoDe(ind, hijo1);
                            portCompartidosI = quad->getPortalesCompartidos(hijo1, hijo3);
                            portCompartidosII = quad->getPortalesCompartidos(hijo3, hijo4);
                            portCompartidosIII = quad->getPortalesCompartidos(hijo4, hijo2);
                            unsigned int numHijo = quad->getNumeroDeHijo(hijo1);
                            unsigned int numHijo2 = quad->getNumeroDeHijo(hijo2);
                            for (Punto* p1 = portCompartidosI->primero(); p1 != NULL; p1 = portCompartidosI->siguiente()) {
                                aparI = quadtr[hijo1]->getNumApareo(apar1, p1);
                                for (Punto* p2 = portCompartidosII->primero(); p2 != NULL; p2 = portCompartidosII->siguiente()) {
                                    aparII = quadtr[hijo3]->getNumApareo(p1, p2);
                                    for (Punto* p3 = portCompartidosIII->primero(); p3 != NULL; p3 = portCompartidosIII->siguiente()) {
                                        aparIII = quadtr[hijo4]->getNumApareo(p2, p3);
                                        aparIV = quadtr[hijo2]->getNumApareo(p3, apar2);
                                        //comparo con los datos minimos anteriores
                                        distActual = matriz->get(quadtr[hijo1]->getIndiceReal(), aparI)->getDistancia() + matriz->get(quadtr[hijo2]->getIndiceReal(), aparIV)->getDistancia() + matriz->get(quadtr[hijo4]->getIndiceReal(), aparIII)->getDistancia() + matriz->get(quadtr[hijo3]->getIndiceReal(), aparII)->getDistancia();
                                        if (distActual < distMin) {
                                            distMin = distActual;
                                            aparMinI = aparI;
                                            aparMinII = aparII;
                                            aparMinIII = aparIII;
                                            aparMinIV = aparIV;
                                        };
                                    };
                                };
                            };
                            //seteo los datos minimos encontrados en la matriz
                            sb->addHijo(hijo1);
                            sb->addHijo(hijo3);
                            sb->addHijo(hijo4);
                            sb->addHijo(hijo2);
                            sb->addApareo(aparMinI);
                            sb->addApareo(aparMinII);
                            sb->addApareo(aparMinIII);
                            sb->addApareo(aparMinIV);
                            sb->setDistancia(distMin);
                            matriz->set(sb, iReal, apareo);
                        };//fin del else cual sin nodos
                    }//fin del if adyacentes(hijo1,hijo2)
                    else { //Los Hijos Estan Cruzados
                        //si los demas hijos excepto h1 y h2, no poseen nodos ninguno de ellos
                        //habra que elegir un camino que pase por cualquiera de los otros hijos
                        if (cualConNodos == NINGUNO) {
                            unsigned int hijo3;
                            hijo3 = quad->getAdyacenteDe(hijo1);
                            portCompartidosI = quad->getPortalesCompartidos(hijo1, hijo3);
                            portCompartidosII = quad->getPortalesCompartidos(hijo3, hijo2);
                            unsigned int numHijo = quad->getNumeroDeHijo(hijo1);
                            for (Punto* p1 = portCompartidosI->primero(); p1 != NULL; p1 = portCompartidosI->siguiente()) {
                                aparI = quadtr[hijo1]->getNumApareo(apar1, p1);
                                for (Punto* p2 = portCompartidosII->primero(); p2 != NULL; p2 = portCompartidosII->siguiente()) {
                                    aparII = quadtr[hijo3]->getNumApareo(p1, p2);
                                    aparIII = quadtr[hijo2]->getNumApareo(p2, apar2);
                                    distActual = matriz->get(quadtr[hijo1]->getIndiceReal(), aparI)->getDistancia() + matriz->get(quadtr[hijo3]->getIndiceReal(), aparII)->getDistancia() + matriz->get(quadtr[hijo2]->getIndiceReal(), aparIII)->getDistancia();
                                    //comparo con los datos minimos anteriores
                                    if (distActual < distMin) {
                                        distMin = distActual;
                                        aparMinI = aparI;
                                        aparMinII = aparII;
                                        aparMinIII = aparIII;
                                    };
                                };
                            };
                            //seteo datos minimos en la matriz
                            sb->addHijo(hijo1);
                            sb->addHijo(hijo3);
                            sb->addHijo(hijo2);
                            sb->addApareo(aparMinI);
                            sb->addApareo(aparMinII);
                            sb->addApareo(aparMinIII);
                            sb->setDistancia(distMin);
                            matriz->set(sb, iReal, apareo);
                        } //fin del if cualConNodos==NINGUNO //Los Hijos Estan Cruzados
                        else {
                            if (cualConNodos == AMBOS) { //si los otros dos hijos poseen nodos
                                unsigned int hijo3, hijo4, numHijo;
                                numHijo = quad->getNumeroDeHijo(hijo1);
                                if (numHijo == 3) {
                                    hijo3 = hijo1 - 2;  //corresponde al hijo 1
                                    hijo4 = hijo1 + 1;  //corresponde al hijo 4
                                };
                                //agregado
                                if (numHijo == 1) {
                                    hijo3 = hijo1 + 2;  //corresponde al hijo 3
                                    hijo4 = hijo1 + 1;  //corresponde al hijo 2
                                };
                                if (numHijo == 2) {
                                    hijo3 = hijo1 - 1;  //corresponde al hijo 1
                                    hijo4 = hijo1 + 2;  //corresponde al hijo 4
                                };
                                if (numHijo == 4) {
                                    hijo3 = hijo1 - 1;  //corresponde al hijo 2
                                    hijo4 = hijo1 - 2;  //corresponde al hijo 3
                                };
                                //agregado
                                portCompartidosI = quad->getPortalesCompartidos(hijo1, hijo3);
                                portCompartidosII = quad->getPortalesCompartidos(hijo3, hijo2);
                                portCompartidosIII = quad->getPortalesCompartidos(hijo1, hijo4);
                                portCompartidosIV = quad->getPortalesCompartidos(hijo4, hijo2);
                                for (Punto* p1 = portCompartidosI->primero(); p1 != NULL; p1 = portCompartidosI->siguiente()) {
                                    aparI = quadtr[hijo1]->getNumApareo(apar1, p1);
                                    for (Punto* p2 = portCompartidosII->primero(); p2 != NULL; p2 = portCompartidosII->siguiente()) {
                                        aparII = quadtr[hijo3]->getNumApareo(p1, p2);
                                        aparIII = quadtr[hijo2]->getNumApareo(p2, apar2);
                                        distActual = matriz->get(quadtr[hijo1]->getIndiceReal(), aparI)->getDistancia() + matriz->get(quadtr[hijo3]->getIndiceReal(), aparII)->getDistancia() + matriz->get(quadtr[hijo2]->getIndiceReal(), aparIII)->getDistancia();
                                        //comparo con los datos minimos anteriores
                                        if (distActual < distMin) {
                                            distMin = distActual;
                                            aparMinI = aparI;
                                            aparMinII = aparII;
                                            aparMinIII = aparIII;
                                        };
                                    };
                                };
                                float distMin2, distActual2;
                                unsigned int aparMinV, aparMinVI, aparV, aparVI;
                                distMin2 = FLT_MAX;
                                distActual2 = 0;
                                for (Punto* p1 = portCompartidosIII->primero(); p1 != NULL; p1 = portCompartidosIII->siguiente()) {
                                    distActual2 = apar1->distancia_Total_a(p1);
                                    aparIV = quadtr[hijo1]->getNumApareo(apar1, p1);
                                    for (Punto* p2 = portCompartidosIV->primero(); p2 != NULL; p2 = portCompartidosIV->siguiente()) {
                                        aparV = quadtr[hijo4]->getNumApareo(p1, p2);
                                        aparVI = quadtr[hijo2]->getNumApareo(p2, apar2);
                                        distActual2 += p2->distancia_Total_a(apar2) + matriz->get(quadtr[hijo4]->getIndiceReal(), aparV)->getDistancia();
                                        if (distActual2 < distMin2) {
                                            distMin2 = distActual;
                                            aparMinIV = aparIV;
                                            aparMinV = aparV;
                                            aparMinVI = aparVI;
                                        };
                                    };
                                };
                                distMin += distMin2;
                                //seteo los datos minimos encontrados en la matriz
                                sb->addHijo(hijo1);
                                sb->addHijo(hijo3);
                                sb->addHijo(hijo2);
                                sb->addHijo(hijo1);
                                sb->addHijo(hijo4);
                                sb->addHijo(hijo2);
                                sb->addApareo(aparMinI);
                                sb->addApareo(aparMinII);
                                sb->addApareo(aparMinIII);
                                sb->addApareo(aparMinIV);
                                sb->addApareo(aparMinV);
                                sb->addApareo(aparMinVI);
                                sb->setDistancia(distMin);
                                matriz->set(sb, iReal, apareo);
                            } //fin del if (cualConNodos==AMBOS) //Los Hijos Estan Cruzados
                            else { //si solo uno de los otros hijos posee nodos
                                portCompartidosI = quad->getPortalesCompartidos(hijo1, cualConNodos);
                                portCompartidosII = quad->getPortalesCompartidos(cualConNodos, hijo2);
                                unsigned int numHijo1 = quad->getNumeroDeHijo(hijo1);
                                unsigned int numHijo2 = quad->getNumeroDeHijo(cualConNodos);
                                for (Punto* p1 = portCompartidosI->primero(); p1 != NULL; p1 = portCompartidosI->siguiente()) {
                                    aparI = quadtr[hijo1]->getNumApareo(apar1, p1);
                                    for (Punto* p2 = portCompartidosII->primero(); p2 != NULL; p2 = portCompartidosII->siguiente()) {
                                        aparII = quadtr[cualConNodos]->getNumApareo(p1, p2);
                                        aparIII = quadtr[hijo2]->getNumApareo(p2, apar2);
                                        distActual = matriz->get(quadtr[hijo1]->getIndiceReal(), aparI)->getDistancia() + matriz->get(quadtr[cualConNodos]->getIndiceReal(), aparII)->getDistancia() + matriz->get(quadtr[hijo2]->getIndiceReal(), aparIII)->getDistancia();
                                        //comparo con los datos minimos anteriores
                                        if (distActual < distMin) {
                                            distMin = distActual;
                                            aparMinI = aparI;
                                            aparMinII = aparII;
                                            aparMinIII = aparIII;
                                        };
                                    };
                                };
                                //seteo datos minimos en la matriz
                                sb->addHijo(hijo1);
                                sb->addHijo(cualConNodos);
                                sb->addHijo(hijo2);
                                sb->addApareo(aparMinI);
                                sb->addApareo(aparMinII);
                                sb->addApareo(aparMinIII);
                                sb->setDistancia(distMin);
                                matriz->set(sb, iReal, apareo);
                            };//fin del else (cualConNodos==AMBOS)
                        };//fin del else cualConNodos==NINGUNO
                    };//fin del else adyacentes(hijo1,hijo2)
                } //fin del if hijo1!=hijo2
                else {  //la subsolucion se construye para portales de comienzo y fin en el mismo hijo
                    unsigned int hijo3, hijo4, numHijo;
                    numHijo = quad->getNumeroDeHijo(hijo1);
                    if (numHijo == 1) {   //camino a recorrer 1-3-4-2-1
                        hijo2 = hijo1 + 2;  //corresponde al hijo 3
                        hijo3 = hijo1 + 3;  //corresponde al hijo 4
                        hijo4 = hijo1 + 1;  //corresponde al hijo 2
                    };
                    if (numHijo == 2) {   //camino a recorrer 2-1-3-4-2
                        hijo2 = hijo1 - 1;  //corresponde al hijo 1
                        hijo3 = hijo1 + 1;  //corresponde al hijo 3
                        hijo4 = hijo1 + 2;  //corresponde al hijo 4
                    };
                    if (numHijo == 3) {  //camino a recorrer 3-4-2-1-3
                        hijo2 = hijo1 + 1;  //corresponde al hijo 4
                        hijo3 = hijo1 - 1;  //corresponde al hijo 2
                        hijo4 = hijo1 - 2;  //corresponde al hijo 1
                    };
                    if (numHijo == 4) {  //camino a recorrer 4-2-1-3-4
                        hijo2 = hijo1 - 2;  //corresponde al hijo 2
                        hijo3 = hijo1 - 3;  //corresponde al hijo 1
                        hijo4 = hijo1 - 1;  //corresponde al hijo 3
                    };
                    portCompartidosI = quad->getPortalesCompartidos(hijo1, hijo2);
                    portCompartidosII = quad->getPortalesCompartidos(hijo2, hijo3);
                    portCompartidosIII = quad->getPortalesCompartidos(hijo3, hijo4);
                    portCompartidosIV = quad->getPortalesCompartidos(hijo4, hijo1);
                    for (Punto* p1 = portCompartidosI->primero(); p1 != NULL; p1 = portCompartidosI->siguiente()) {
                        aparI = quadtr[hijo1]->getNumApareo(apar1, p1);
                        for (Punto* p2 = portCompartidosII->primero(); p2 != NULL; p2 = portCompartidosII->siguiente()) {
                            aparII = quadtr[hijo2]->getNumApareo(p1, p2);
                            for (Punto* p3 = portCompartidosIII->primero(); p3 != NULL; p3 = portCompartidosIII->siguiente()) {
                                aparIII = quadtr[hijo3]->getNumApareo(p2, p3);
                                for (Punto* p4 = portCompartidosIV->primero(); p4 != NULL; p4 = portCompartidosIV->siguiente()) {
                                    aparIV = quadtr[hijo4]->getNumApareo(p3, p4);
                                    aparV = quadtr[hijo1]->getNumApareo(p4, apar2);
                                    distActual = apar2->distancia_Total_a(p4) + matriz->get(quadtr[hijo1]->getIndiceReal(), aparI)->getDistancia() + matriz->get(quadtr[hijo2]->getIndiceReal(), aparII)->getDistancia() + matriz->get(quadtr[hijo3]->getIndiceReal(), aparIII)->getDistancia() + matriz->get(quadtr[hijo4]->getIndiceReal(), aparIV)->getDistancia();
                                    //comparo con los datos minimos anteriores
                                    if (distActual < distMin) {
                                        distMin = distActual;
                                        aparMinI = aparI;
                                        aparMinII = aparII;
                                        aparMinIII = aparIII;
                                        aparMinIV = aparIV;
                                        aparMinV = aparV;
                                    };
                                };
                            };
                        };
                    };
                    //seteo los datos minimos encontrados en la matriz
                    sb->addHijo(hijo1);
                    sb->addHijo(hijo2);
                    sb->addHijo(hijo3);
                    sb->addHijo(hijo4);
                    sb->addHijo(hijo1);
                    sb->addApareo(aparMinI);
                    sb->addApareo(aparMinII);
                    sb->addApareo(aparMinIII);
                    sb->addApareo(aparMinIV);
                    sb->addApareo(aparMinV);
                    sb->setDistancia(distMin);
                    matriz->set(sb, iReal, apareo);
                };//fin del else hijo1!=hijo2
            };//fin del for de apareo
        }; //fin del if (ind es padre)
    }; //fin del for de ind
}
void ProgramacionDinamica::makeSolucion() {
    SubSolucion* sb = new SubSolucion();
    float distMin1, distMin2, distActual1, distActual2;
    distMin1 = FLT_MAX;
    distMin2 = FLT_MAX;
    distActual1 = 0;
    distActual2 = 0;
    unsigned int aparMinI, aparMinII, aparMinIII, aparMinIV;
    Lista<Punto>* portCompartidosI, * portCompartidosII, * portCompartidosIII, * portCompartidosIV;
    portCompartidosI = NULL;
    portCompartidosII = NULL;
    portCompartidosIII = NULL;
    portCompartidosIV = NULL;
    portCompartidosI = quad->getPortalesCompartidos(1, 2);
    portCompartidosII = quad->getPortalesCompartidos(4, 2);
    portCompartidosIII = quad->getPortalesCompartidos(1, 3);
    portCompartidosIV = quad->getPortalesCompartidos(3, 4);
    for (Punto* p1 = portCompartidosIII->primero(); p1 != NULL; p1 = portCompartidosIII->siguiente()) {
        for (Punto* p3 = portCompartidosII->primero(); p3 != NULL; p3 = portCompartidosII->siguiente()) {
            for (Punto* p2 = portCompartidosI->primero(); p2 != NULL; p2 = portCompartidosI->siguiente()) {
                unsigned int apareo1, apareo2;
                apareo1 = quadtr[1]->getNumApareo(p1, p2);
                apareo2 = quadtr[2]->getNumApareo(p2, p3);
                distActual1 = matriz->get(quadtr[1]->getIndiceReal(), apareo1)->getDistancia() + matriz->get(quadtr[2]->getIndiceReal(), apareo2)->getDistancia();
                if (distActual1 < distMin1) {
                    distMin1 = distActual1;
                    aparMinI = apareo1;
                    aparMinII = apareo2;
                };
            };
            for (Punto* p4 = portCompartidosIV->primero(); p4 != NULL; p4 = portCompartidosIV->siguiente()) {
                unsigned int apareo3, apareo4;
                apareo3 = quadtr[3]->getNumApareo(p1, p4);
                apareo4 = quadtr[4]->getNumApareo(p3, p4);
                distActual2 = matriz->get(quadtr[3]->getIndiceReal(), apareo3)->getDistancia() + matriz->get(quadtr[4]->getIndiceReal(), apareo4)->getDistancia();
                if (distActual2 < distMin2) {
                    distMin2 = distActual2;
                    aparMinIII = apareo3;
                    aparMinIV = apareo4;
                };
            };
        };
    };
    matriz->inicColumna(0, 1);
    //seteo los datos minimos encontrados en la matriz
    sb->addHijo(1);
    sb->addHijo(2);
    sb->addHijo(3);
    sb->addHijo(4);
    sb->addApareo(aparMinI);
    sb->addApareo(aparMinII);
    sb->addApareo(aparMinIII);
    sb->addApareo(aparMinIV);
    sb->setDistancia(distMin1 + distMin2);
    matriz->set(sb, 0, 0);
}

SubSolucion* ProgramacionDinamica::getSubSolucion(unsigned int fila, unsigned int col) {
    return matriz->get(fila, col);
}


void ProgramacionDinamica::reconstructFromQuadrant(unsigned int qIdx, unsigned int aparIdx, std::vector<Punto*>& path, std::set<unsigned int>& visitedNodes) {    Cuadrante* quad = quadtr[qIdx];
    if (!quad) return;

    // Leaf: emit its single node (if any), in original coordinates
    if (!quad->hijos()) {
        PuntoExtendido* perturbedNode = quad->getNodoIn();
        if (perturbedNode) {
            unsigned int originalNodeIdx = perturbedNode->getUbicacion();
            if (visitedNodes.find(originalNodeIdx) == visitedNodes.end()) {
                PuntoExtendido* extPoint = perturbacion->getCloneInput()[originalNodeIdx];
                Punto* point = new Punto(extPoint->getX(), extPoint->getY());
                path.push_back(point);
                visitedNodes.insert(originalNodeIdx);
            }
        }
        return;
    }

    // Internal: fetch the chosen subsolution at this (quad, aparIdx)
    unsigned int realIdx = quad->getIndiceReal();
    SubSolucion* subsol = matriz->get(realIdx, aparIdx);
    if (!subsol) return;

    // Gather children + their selected apareos and decode their portal pairs, along with inversion flags
    Lista<unsigned int>* hijos = subsol->getHijos();
    Lista<unsigned int>* apareos = subsol->getApareos();
    Lista<bool>* inversiones = subsol->getInversiones();

    struct ChildInfo {
        unsigned int idx;
        unsigned int apar;
        bool inv;
        Punto* p1;
        Punto* p2;
        bool used;
    };
    std::vector<ChildInfo> kids;
    unsigned int* apar = apareos->primero();
    bool* invp = inversiones ? inversiones->primero() : nullptr;
    for (unsigned int* h = hijos->primero(); h != NULL; h = hijos->siguiente()) {
        ChildInfo ci{};
        ci.idx = *h;
        ci.apar = apar ? *apar : 0;
        ci.inv = invp ? *invp : false;
        ci.p1 = ci.p2 = nullptr;
        ci.used = false;
        Cuadrante* cq = quadtr[ci.idx];
        if (cq && cq->getCantPortales() >= 2) {
            cq->getApareo(ci.apar, ci.p1, ci.p2);
        }
        kids.push_back(ci);
        apar = apareos->siguiente();
        if (invp) invp = inversiones->siguiente();
    }

    // Decode this quad's entry/exit portals for this aparIdx (when available)
    Punto* parentIn = nullptr;
    Punto* parentOut = nullptr;
    if (quad->getCantPortales() >= 2) {
        quad->getApareo(aparIdx, parentIn, parentOut);
    }

    auto shares_portal = [](const ChildInfo& a, const ChildInfo& b) -> bool {
        return (a.p1 && (a.p1 == b.p1 || a.p1 == b.p2)) ||
               (a.p2 && (a.p2 == b.p1 || a.p2 == b.p2));
    };

    // Pick start child: try the one containing parentIn; fallback to first
    int start = -1;
    if (parentIn) {
        for (int i = 0; i < (int)kids.size(); ++i) {
            if ((kids[i].p1 == parentIn) || (kids[i].p2 == parentIn)) { start = i; break; }
        }
    }
    if (start == -1) start = 0;
    kids[start].used = true;

    // Build an order where consecutive children share a boundary portal
    std::vector<int> order;
    order.reserve(kids.size());
    order.push_back(start);

    while ((int)order.size() < (int)kids.size()) {
        int cur = order.back();
        bool found = false;
        for (int i = 0; i < (int)kids.size(); ++i) {
            if (kids[i].used) continue;
            if (shares_portal(kids[cur], kids[i])) {
                kids[i].used = true;
                order.push_back(i);
                found = true;
                break;
            }
        }
        if (!found) {
            // Fallback (should be rare if DP is consistent)
            for (int i = 0; i < (int)kids.size(); ++i) {
                if (!kids[i].used) { kids[i].used = true; order.push_back(i); break; }
            }
        }
    }

    // Recurse in that order, applying inversion (reverse) of child path if required
    for (int pos : order) {
        std::vector<Punto*> childPath;
        reconstructFromQuadrant(kids[pos].idx, kids[pos].apar, childPath, visitedNodes);
        if (kids[pos].inv) {
            std::reverse(childPath.begin(), childPath.end());
        }
        path.insert(path.end(), childPath.begin(), childPath.end());
    }
}

void ProgramacionDinamica::reconstructPath(std::vector<Punto*>& path) {
    std::set<unsigned int> visited;
    const unsigned int rootIdx = 0;

    // Choose the root column (apareo) with minimum DP cost
    unsigned int bestCol = 0;
    float bestDist = std::numeric_limits<float>::infinity();
    const unsigned int cols = matriz->getSizeY(rootIdx);
    for (unsigned int y = 0; y < cols; ++y) {
        SubSolucion* ss = matriz->get(rootIdx, y);
        if (ss && ss->getDistancia() >= 0.0f && ss->getDistancia() < bestDist) {
            bestDist = ss->getDistancia();
            bestCol = y;
        }
    }
    reconstructFromQuadrant(rootIdx, bestCol, path, visited);
}




//---------------------------------------------------------------------------
// Function to load lines from a file into a vector of strings
std::vector<std::string> loadFileToVector(const std::string& filename) {
    std::vector<std::string> lines;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            lines.push_back(line);
        }
        file.close();
    }
    else {
        std::cerr << "Error opening file: " << filename << std::endl;
    }
    return lines;
}
template class Matriz<Punto>;
//---------------------------------------------------------------------------
template <class T> Matriz<T>::Matriz(unsigned int x, unsigned int y) {
    matriz = new T * *[x];
    for (unsigned int i = 0; i < x; i++) {
        matriz[i] = new T * [y];
        for (unsigned int j = 0; j < y; j++)
            matriz[i][j] = NULL;
    };
    tamX = x;
    tamY = y;
}
//---------------------------------------------------------------------------
template <class T> Matriz<T>::~Matriz() {
    for (unsigned int j = 0; j < this->getSizeY(VALUE_DEF); delete matriz[j++]);
    delete matriz;
}
//---------------------------------------------------------------------------
template <class T> unsigned int Matriz<T>::getSizeX() {
    return tamX;
}
//---------------------------------------------------------------------------
template <class T> unsigned int Matriz<T>::getSizeY(unsigned int col) {
    return tamY;
}
//---------------------------------------------------------------------------
template <class T> T* Matriz<T>::get(unsigned int x, unsigned int y) {
    if (!this->posValida(x, y)) return NULL;
    return matriz[x][y];
}
//---------------------------------------------------------------------------
template <class T> void Matriz<T>::set(T* elem, unsigned int x, unsigned int y) {
    if (this->posValida(x, y))
        matriz[x][y] = elem;
}
//---------------------------------------------------------------------------
template <class T> bool Matriz<T>::posValida(unsigned int x, unsigned int y) {
    if (x >= this->getSizeX() || y >= this->getSizeY(VALUE_DEF)) return false;
    return true;
}
//123123123
class Trimer {
private:
    QuadTreeTSP* quad;
    Cuadrante** quadtr;
    ProgramacionDinamica* pd;
    Perturbacion* pert;
    unsigned int tamanio, numNodos, divide;
    PuntoExtendido** caminoTrimed;
    void setMaxTamanio(); //setea la variable tamaño que se refiere al arreglo de Par
    void Trim(); //prepara las condiciones para optimizar el camino
    void Trim2(unsigned int, unsigned int, unsigned int*); //optimiza el camino obtenido poligonizandolo
    void inicCaminoTrimed();
public:
    void addOriginalNode(Punto* perturbedNode, Perturbacion* perturbacion);
    Trimer(QuadTreeTSP*, ProgramacionDinamica*, Perturbacion*);
    ~Trimer();
    void execute();
    PuntoExtendido** getCaminoTrimed();
    std::string toString();
    float getLargoCamino(bool close =false);
    int getDivide() { return divide; };
};
Trimer::Trimer(QuadTreeTSP* q, ProgramacionDinamica* pdin, Perturbacion* per) {
    quad = q;
    quadtr = quad->getArreglo();
    pd = pdin;
    pert = per;
    tamanio = 0;
    caminoTrimed = NULL;
    //setea los datos del Maximo tamaño del arreglo
    setMaxTamanio();
    //inicializo camino
    inicCaminoTrimed();
};
//---------------------------------------------------------------------------
Trimer::~Trimer() {
};

//---------------------------------------------------------------------------
void Trimer::inicCaminoTrimed() {
    numNodos = pert->getNumNodos();
    caminoTrimed = new PuntoExtendido * [numNodos];
    for (unsigned int i = 0; i < numNodos; i++)
        caminoTrimed[i] = NULL;
};
//---------------------------------------------------------------------------
void Trimer::execute() {
    //Realiza el trim del camino
    this->Trim();
};
//---------------------------------------------------------------------------
PuntoExtendido** Trimer::getCaminoTrimed() {
    return caminoTrimed;
};
//---------------------------------------------------------------------------
void Trimer::setMaxTamanio() {
    unsigned int maxL;
    maxL = quad->getMaxLevelOcupado();
    for (unsigned int i = 0; i < maxL; i++)
        tamanio += 6 * pow(6, i);
    tamanio++; //nunca se usa la posicion cero por ello se necesita un espacio mas
};
//---------------------------------------------------------------------------
void Trimer::Trim() {
    SubSolucion* sb = pd->getSubSolucion(0, 0);
    Lista<unsigned int>* hijos = sb->getHijos();
    Lista<unsigned int>* apareos = sb->getApareos();
    unsigned int* pos = new unsigned int;
    *pos = 0;
    unsigned int* apar = apareos->primero();
    for (unsigned int* h = hijos->primero(); h != NULL; h = hijos->siguiente()) {
        if (*h == 3)
            this->divide = (*pos);
        Trim2(*h, *apar, pos);
        //actualizo apareo
        apar = apareos->siguiente();
    };
};
//---------------------------------------------------------------------------
void Trimer::Trim2(unsigned int indice, unsigned int apareo, unsigned int* posArr) {
    if (!(quadtr[indice]->hijos())) { //si es una hoja
        PuntoExtendido* nodo = quadtr[indice]->getNodoIn();
        if (nodo != NULL) {
            caminoTrimed[*posArr] = nodo;
            (*posArr)++;
        };
    }  //tiene hijos que se deben analizar
    else {
        //sucesivos llamados a la recursion
        SubSolucion* sb = pd->getSubSolucion(quadtr[indice]->getIndiceReal(), apareo);
        Lista<unsigned int>* apareos = sb->getApareos();
        Lista<unsigned int>* hijos = sb->getHijos();
        //incorporo otros casos donde se debe invertir
        SubSolucion* sb_hijoActual;  //será la subsolucion del hijo actual
        sb_hijoActual = NULL;
        unsigned int* h = new unsigned int;
        unsigned int* apar = new unsigned int;
        (*h) = 0;
        (*apar) = 0;
        int tam = hijos->tamanio();
        //un tamaño mayor a 5 indicara que pasara por el mismo cuadrantre mas de una vez
        //pero solo se tiene en cuenta una por eso se lo acota
        if (tam >= 5)
            tam = 4;
        for (int i = 0; i < tam; i++) {
            apar = apareos->get(i);
            h = hijos->get(i);
            Trim2(*h, *apar, posArr);
        }
    }
};
//---------------------------------------------------------------------------
std::string Trimer::toString() {
    std::string resultado = "Trimed Path \n";
    for (unsigned int pos = 0; pos < numNodos; pos++)
        resultado += caminoTrimed[pos]->toString() + "\n";
    resultado += "Join point 1 to point " + std::to_string(divide) + "\n";
    resultado += "Length of the Road = " + std::to_string(this->getLargoCamino());
    return resultado;
};
//---------------------------------------------------------------------------
float Trimer::getLargoCamino(bool close) {
    PuntoExtendido** clonedPoints = pert->getCloneInput();
    float res = 0;

    for (unsigned int i = 0; i < numNodos - 1; i++)
        res += clonedPoints[caminoTrimed[i]->getUbicacion()]->distancia_Total_a(
                   clonedPoints[caminoTrimed[i + 1]->getUbicacion()]
               );

    // Close the cycle explicitly
    if(close){
        res += clonedPoints[caminoTrimed[numNodos - 1]->getUbicacion()]->distancia_Total_a(
               clonedPoints[caminoTrimed[0]->getUbicacion()]
           );
    }
    

    return res;
}

LARGE_INTEGER frecuencia;
template class Lista<Punto>;
template class Lista<Cuadrante>;
template class Lista<unsigned int>;
template class Lista<bool>;

float calculatePathLength(const std::vector<Punto*>& path, bool close) {
    if (path.size() < 2) return 0.0;
    
    float res = 0;
    for (size_t i = 0; i < path.size() - 1; ++i) {
        if (path[i] && path[i + 1]) {
            res += path[i]->distancia_Total_a(path[i + 1]);
        }
    }
    
    if (close) {
        if (path.size() > 1) {
            res += path.back()->distancia_Total_a(path.front());
        }
    }
    
    return res;
}

void execute(std::string Pathinput,bool calculateClose=false,float portal_per_edge=1) {
    using Clock = std::chrono::high_resolution_clock;
    using Duration = std::chrono::duration<long double>;
    // Perturbacion
    auto start = Clock::now();
    Perturbacion p = Perturbacion(&Pathinput, c);
    auto end = Clock::now();
    Duration tiempoPert = end - start;
    // std::cout << "Time for Perturbacion: " << tiempoPert.count() << " seconds\n";
    int width = p.getLargoEnclosingBox();
    // std::cout << " width: " << width << " seconds\n";
    // Portalizacion
    start = Clock::now();
    Portalizacion port = Portalizacion(width, width,portal_per_edge);
    end = Clock::now();
    tiempoPert = end - start;
    // std::cout << "Time for Portalizacion constructor: " << tiempoPert.count() << " seconds\n";
    Duration tiempoPort = end - start;
    // QuadTree
    start = Clock::now();
    QuadTreeTSP q = QuadTreeTSP(width, width, width, c);
    q.make(&p, &port);
    end = Clock::now();
    Duration tiempoQ = end - start;
    // Portalizacion (again)
    start = Clock::now();
    Lista<Cuadrante>* cuadrn = q.getCuadrantesPadres();
    end = Clock::now();
    tiempoPort = (end - start);
    // std::cout << "Time for getCuadrantesPadres: " << tiempoPort.count() << " seconds\n";
    start = Clock::now();
    Lista<Cuadrante>* hojas = q.getHojas();
    end = Clock::now();
    tiempoPort = (end - start);
    // std::cout << "Time for getHojas: " << tiempoPort.count() << " seconds\n";
    start = Clock::now();
    port.portalizar(cuadrn, hojas);
    end = Clock::now();
    tiempoPort = (end - start);
    // Programacion Dinamica
    ProgramacionDinamica progD = ProgramacionDinamica(&q,&p);
    start = Clock::now();
    progD.execute();
    end = Clock::now();
    std::vector<Punto*> tspPath;
    
    auto build_path_for_root = [&](unsigned int rootCol, std::vector<Punto*>& out) {
        std::set<unsigned int> visitedTmp;
        progD.reconstructFromQuadrant(0, rootCol, out, visitedTmp);
    };

    // Sweep all root columns (apareos) and pick the one minimizing the measured length
    tspPath.clear();
    std::vector<Punto*> bestPathLocal;
    float bestLen = std::numeric_limits<float>::infinity();
    for (unsigned int y = 0;; ++y) {
        SubSolucion* ss = progD.getSubSolucion(0, y);
        if (!ss) break;
        std::vector<Punto*> cand;
        build_path_for_root(y, cand);
        float L = calculatePathLength(cand, calculateClose); // open if false, closed if true
        if (L < bestLen) { bestLen = L; bestPathLocal.swap(cand); }
    }
    if (!bestPathLocal.empty()) {
        tspPath.swap(bestPathLocal);
    } else {
        progD.reconstructPath(tspPath);
    }

    std::cout<<std::endl<<"start\n";
    for (Punto* p : tspPath) {
        std::cout << p->toString() <<",\n";
    }
    std::cout<<"finish"<<std::endl;
    Duration tiempoProg = end - start;
    // Trimer
    Trimer t = Trimer(&q, &progD, &p);
    start = Clock::now();
    t.execute();
    end = Clock::now();
    Duration tiempoTrim = end - start;
    // std::cout << t.toString();
    float largo = calculatePathLength(tspPath,calculateClose);
    std::cout << "path length was:" << largo << std::endl;
    // Output the measured times
    // std::cout << "Time for Perturbacion: " << tiempoPert.count() << " seconds\n";
    // std::cout << "Time for Portalizacion: " << tiempoPort.count() << " seconds\n";
    // std::cout << "Time for QuadTree: " << tiempoQ.count() << " seconds\n";
    // std::cout << "Time for ProgramacionDinamica: " << tiempoProg.count() << " seconds\n";
    // std::cout << "Time for Trimer: " << tiempoTrim.count() << " seconds\n";
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " <filepath> <calculateClose> <portals_per_edge>" << std::endl;
        std::cerr << "Example: " << argv[0] << " C:/path/to/file.txt true 4" << std::endl;
        return 1; // Return an error code
    }

    // 1. Get the file path from the first argument
    std::string filePath = argv[1];

    // 2. Get the 'calculateClose' boolean from the second argument
    std::string closeStr = argv[2];
    bool calculateClose = (closeStr == "true" || closeStr == "1");

    // 3. Get the 'portals_per_edge' float from the third argument
    float portalsPerEdge = std::stof(argv[3]);

    // Now call your execute function with these variables
    execute(filePath, calculateClose, portalsPerEdge);

    return 0;
    // std::string archivOpen="C:\\Users\\lou2013\\Desktop\\arora_tsp_barbara\\archiv.txt";
    // execute(archivOpen,false,2);
    // return 0;
}