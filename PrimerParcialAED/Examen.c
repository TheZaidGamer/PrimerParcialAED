#include <stdio.h>
#include <stdlib.h>
#include <time.h> //se agrega estea libreria para clock_t que se podra ver en cuanto tiempo se tarda en compilar al completo el ordenamiento


void burbuja(int *A,int n); //se asignan primero en funciones todos los tipos de ordenamiento este tipo burbuja
void selecion (int *B,int n); //en esta es ordenamiento por seleccion 
void insercion(int *C, int n); //en este es ordenamiento por inserccion

int main(int argc)//en esta parte es para que se pueda compilar bien el programa desde la simbologia del sistema y tome el archivo setdatosedades.txt
{
	int n = 2000; //numero de elementos que se van a ordenar en todo el proceso
	int A[n];	// declaramos A que podra ser quien se imprima el arreglo de burbuja
	clock_t t_start, t_finish; 	//El clock_t que revisara el tiempo en que tarda en compilar cada ordenamiento
	double t_interval;
	int i; 
	int B[n]; //Declaramos B que sera la forma de ordenamiento tipo seleccion
	int C[n]; //Declaramos C que sera la forma de ordenamiento tipo Inserccion

	for (i=0;i<n;i++){
		scanf("%d", &A[i]);
		B[i]=A[i];
		C[i]=A[i];
	}


	t_start=clock();	//aqui se inicia el conteo de tiempo en el arreglo de tipo burbuja
	burbuja(A,n);
	t_finish=clock();
	t_interval = (double)(t_finish - t_start)/CLOCKS_PER_SEC;
	printf("\n\nTiempo de bubble sort: %.8f seconds.", t_interval);


	t_start=clock();	//aqui se inicia el conteo de tiempo en el arreglo de tipo seleccion
	selecion (B,n);
	t_finish=clock();
	t_interval = (double)(t_finish - t_start)/CLOCKS_PER_SEC;
	printf("\n\nTiempo de selection sort: %.8f seconds.", t_interval);


	t_start=clock();	//aqui se inicia el conteo de tiempo en el arreglo de tipo inserccion
	insercion (C, n);
	t_finish=clock();
	t_interval = (double)(t_finish - t_start)/CLOCKS_PER_SEC;
	printf("\n\nTiempo de insertion sort: %.8f seconds.", t_interval);
}



void burbuja(int *A,int n)	//aqui se inicia el ordenamiento tipo burbuja
{
	
	int eliminar=0, i=0, aux=0;

	while(n != eliminar){
      for(i=0; i <((n-1)-eliminar); i++){
          if(A[i]>A[i+1]){
             aux=A[i];
             A[i]=A[i+1];
             A[i+1]=aux;
          }
      	}
       eliminar++;
	}
	for(i=0;i<n;i++)
		printf("\nA[%d]=%d",i,A[i]);
}

void selecion (int *B,int n){  //aqui se inicia el ordenamiento tipo seleccion

	int aux=0, i=0, j=0, aux2=0;
	
	for(i=0; i<n; i++){
    	aux2=i;
    	for(j=i+1; j<n; j++){
        	if(B[j]<B[aux2]){	
            	aux2=j;
        	}	
        aux=B[i];
        B[i]=B[aux2];
        B[aux2]=aux;
    	}	
	}
	for(i=0;i<n;i++)
		printf("\nB[%d]=%d",i,B[i]);
}

void insercion(int *C, int n){ 	//aqui se inicia el ordenamiento tipo inserccion
	
	for (int i = 1; i < n;i++){
		int key = C[i];
		int j = i-1;
		
		while (j>=0 && C[j]>key){
			C[j+1]= C[j];
			j = j-1;
		}
		C[j+1]= key;
	}
	for(int i=0;i<n;i++)
		printf("\nC[%d]=%d",i,C[i]);
}


