#include <iostream>
//HUAMAN COAQUIRA LUCIANA JULISSA
//CIENCIA DE LA COMPUTACION 2 - GRUPO A
//CUI: 20210671
using namespace std;

template <class T> void mostrarArray(T* array, int n){
  for (int i=0; i<n; i++){
    cout<<*(array+i)<<" ";
  }
  cout<<endl;
}

template <typename T> bool compare1(T x, T y) { //direccion ascendente
    return x <= y; 
}

template <typename T> bool compare2(T x, T y) {//direccion descendete
    return x > y;
}

template<typename T> void eliminarArray(T* array,int n)
{
	delete []array;
}

// FUNCIONES DE INSERTION SORT

template <class T> void insertionsort(T* arreglo,int size, bool (*p)(int , int))
{
    //ENTENDEMOS QUE EL 1 ELEMENT SIN ORDENAR ES EL MASA PEQUENIO
    //ASI QUE COMEZAMOS CON EL SEGUNDO
    for(int k=1; k<size; k++) //
    { 
        T temp = arreglo[k]; //GUARDAMOS EL INDICE DEL ELEMENTO ANTERIOR
        int j = k-1;
        while(j>=0 && p(temp,arreglo[j]) ) 
        //MOVER TODOS LOS ELEMENTOS DE LA LISTA HACIA LA DIRECCION DE FUNCION
        //SI SON MAYORES/MENORES QUE EL ELEMENTO A INSERTAR
        { 
            arreglo[j+1] = arreglo[j]; // 
            j--;
        } 
        //INSERTARMOS EL ELEMENTO
        arreglo[j+1] = temp; 
    } 
}

//FUNCIONES DE QUICK SORT

template<typename T>
void intercambio(T* a, T* b) 
{ 
    T t = *a; 
    *a = *b; 
    *b = t; 
} 
template<typename T>
int partition (T *array, int inicio, int fin,bool (*p)(T,T)) 
{ 
    T pivot = array[fin]; 
    int i = (inicio - 1); 
    //Mientras no se cruzana los indiices
    for (int j = inicio; j <= fin- 1; j++) 
    { 
        if (p(array[j],pivot)) 
        { 
            //si todavia no se cruzan los indices seguimos intercambiando
            i++; 
            intercambio(&array[i], &array[j]); 
        } 
    } 
    //se intercambia los indices en el lugar que corresponde
    intercambio(&array[i + 1], &array[fin]); 
    //nueva posicion del pivote
    return (i + 1); 
} 
template<typename T>
//funcion recursiva para hacer el ordenamiento
void quickSort(T *array, int inicio, int fin,bool (*p)(T,T)) 
{ 
    //caso base
    if (inicio < fin) 
    { 
        int pivot = partition(array, inicio, fin, p); 
        quickSort(array, inicio, pivot - 1,p); //ordenar lista de los menores
        quickSort(array, pivot + 1, fin,p); //ordenar lista de los mayores
    } 
} 

//FUNCIONES DE MERGE SORT

template<typename T>
	void merge(T* array, int incio, int fin, int mid, bool (*p)(T,T))
{
	int i = incio,k = i;
	int j = mid+1;
    //tamnio de los sublistas izq y derech
    T c[100];
	
    //unir lista temporal con la lista real
	while (i <= mid && j <= fin) 
	{
		if (p(array[i],array[j])) 
		{
			c[k] = array[i];
			i++;
		}
		else
		{
			c[k] = array[j];
			j++;
		}
		k++;
	}
	while (i <= mid) //dato extra en la lista -izquierda
	{
		c[k] = array[i];
		k++;
		i++;
	}
	while (j <= fin) //dato extra en la lista - derecha
	{
		c[k] = array[j];
		k++;
		j++;
	}
	for (i = incio; i < k; i++) //colocar datos en orden
		array[i] = c[i];
}
template<typename T>
	void mergesort(T *arr, int incio, int fin, bool (*p)(T,T))
{
	T mid;
    //caso base
	if (incio < fin) //manera recursiva
	{
		mid=(incio+fin)/2;
		mergesort(arr,incio,mid,p);
		mergesort(arr,mid+1,fin,p);    
		merge(arr,incio,fin,mid,p);
	}
}

template<typename T>
	void eliminaLista(T*&array,int&n)
{
	delete []array;
}


int main(){

    int n=10;
    int arreglo1[10] = {5,2,2,7,1,3,5,2,10,1};
    char arreglo2[10] = {'A','Z','F','S','B','C','Q','O'};
    float arreglo3[10] = {3.5,4.2,1.3,2.9,4.6,10.4,3.5,6.2,7.1,4.1};
    void (*opcionesArray[])(char*,int) = {mostrarArray,eliminarArray};
   
    string op;
    while(true){
        cout<<"----------MENU----------"<<endl;
        cout<<"1. Quick sort "<<endl;
        cout<<"2. Insertion sort "<<endl;
        cout<<"3. Merge sort "<<endl;
        cout<<"4. Salir "<<endl;
        cin>>op;
        if(op=="1"){
            cout<<"\nQUICK SORT ASCENDENTE"<<endl;
            cout<<"\nINT:"<<endl;
            mostrarArray(arreglo1,n);
            quickSort(arreglo1,0,n-1, compare1);
            mostrarArray(arreglo1,n);
            cout<<"\nCHAR:"<<endl;
            mostrarArray(arreglo2,n);
            quickSort(arreglo2,0,n-1, compare1);
            mostrarArray(arreglo2,n);
            cout<<"\nFLOAT:"<<endl;
            mostrarArray(arreglo3,n);
            quickSort(arreglo3,0,n-1, compare1);
            mostrarArray(arreglo3,n);
            cout<<"\nQUICK SORT DESCENDENTE"<<endl;
            cout<<"\nINT:"<<endl;
            mostrarArray(arreglo1,n);
            quickSort(arreglo1,0,n-1, compare2);
            mostrarArray(arreglo1,n);
            cout<<"\nCHAR:"<<endl;
            mostrarArray(arreglo2,n);
            quickSort(arreglo2,0,n-1, compare2);
            mostrarArray(arreglo2,n);
            cout<<"\nFLOAT:"<<endl;
            mostrarArray(arreglo3,n);
            quickSort(arreglo3,0,n-1, compare2);
            mostrarArray(arreglo3,n);
        }
        else if(op=="2"){
            cout<<"\nINSERTION SORT ASCENDENTE"<<endl;
            cout<<"\nINT:"<<endl;
            mostrarArray[0]=(arreglo1,n);
            insertionsort(arreglo1,n, compare1);
            mostrarArray[0]=(arreglo1,n);
            cout<<"\nCHAR:"<<endl;
            mostrarArray(arreglo2,n);
            insertionsort(arreglo2,n, compare1);
            mostrarArray(arreglo2,n);
            cout<<"\nFLOAT:"<<endl;
            mostrarArray(arreglo3,n);
            insertionsort(arreglo3,n, compare1);
            mostrarArray(arreglo3,n);
            cout<<"\nINSERTION SORT DESCENDENTE"<<endl;
            cout<<"\nINT:"<<endl;
            mostrarArray(arreglo1,n);
            insertionsort(arreglo1,n, compare2);
            mostrarArray(arreglo1,n);
            cout<<"\nCHAR:"<<endl;
            mostrarArray(arreglo2,n);
            insertionsort(arreglo2,n, compare2);
            mostrarArray(arreglo2,n);
            cout<<"\nFLOAT:"<<endl;
            mostrarArray(arreglo3,n);
            insertionsort(arreglo3,n, compare2);
            mostrarArray(arreglo3,n);
            
        }
        else if(op=="3"){
            cout<<"\nMERGUE SORT ASCENDENTE"<<endl;
            cout<<"\nINT:"<<endl;
            mostrarArray(arreglo1,n);
            mergesort(arreglo1,0,n-1, compare1);
            mostrarArray(arreglo1,n);
            cout<<"\nCHAR:"<<endl;
            mostrarArray(arreglo2,n);
            mergesort(arreglo2,0,n-1, compare1);
            mostrarArray(arreglo2,n);
            cout<<"\nFLOAT:"<<endl;
            mostrarArray(arreglo3,n);
            mergesort(arreglo3,0,n-1, compare1);
            mostrarArray(arreglo3,n);
            cout<<"\nMERGUE SORT DESCENDENTE"<<endl;
            cout<<"\nINT:"<<endl;
            mostrarArray(arreglo1,n);
            mergesort(arreglo1,0,n-1, compare2);
            mostrarArray(arreglo1,n);
            cout<<"\nCHAR:"<<endl;
            mostrarArray(arreglo2,n);
            mergesort(arreglo2,0,n-1, compare2);
            mostrarArray(arreglo2,n);
            cout<<"\nFLOAT:"<<endl;
            mostrarArray(arreglo3,n);
            mergesort(arreglo3,0,n-1, compare2);
            mostrarArray(arreglo3,n);
        }
        else if(op=="4"){
            break;
        }
        else{
            cout<<"VALOR INCORRECTO"<<endl;
        }
    }
    return 0;
}