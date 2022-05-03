#include <stdlib.h>//malloc and free
#include "sorts.h"

void swapPlaces(int *placeA,int *placeB)
{
  int swapElement = *placeA;
  *placeA = *placeB;
  *placeB = swapElement;
}


void bubbleSort(int* A, int size){
  for(int swap = 1;swap == 1;){
    swap =0;
    for(int i = 1;i<size;i++){
        if(A[i-1]>A[i]){
          swapPlaces(&A[i-1],&A[i]);
          swap = 1;
        }
    }
  }
}

//Implementation of Insertion Sort
void insertionSort(int* A, int size){
  for(int i =1;i< size;i+=1)
      for(int j = i; j>0 && A[j-1]>A[j];j -= 1)
          swapPlaces(&A[j-1],&A[j]);
}

//Implementation of Merge Sort
void mergeSort(int* A, int size){
	msortS(A,0,size-1);
}
//Implementation of Quick Sort
void quickSort(int* A, int size){
  qsortS(A,0,size-1);
}

//Helper Functions
//These help with merge
//Sort a Section
void msortS(int* A, int start, int stop){
  if(start>=stop)
    return;
  int middle = start + floor((stop-start)/2);
  msortS(A,start,middle);
  msortS(A,middle+1,stop);
  merge(A,start,middle,stop);
}

//Merge two Sections
void merge(int* A, int start, int middle, int stop){
  int* Aux = malloc((stop-start+1)*sizeof(*Aux));
  for(int i=0;i<(stop+1-start);i++)
    {
      *(Aux+i) = *(A+start+i);
    }
  int Aux_middle = middle-start, Aux_stop = stop-start;
  int i = 0, j=Aux_middle+1;
  for(int k=start;k<stop+1;k++)
  {
    if (i>Aux_middle)
    {
      *(A+k)=*(Aux+j);
      j++;
    }
    else if (j>Aux_stop)
    {
      *(A+k)=*(Aux+i);
      i++;
    }
    else if (*(Aux+j)>*(Aux+i))
    {
      *(A+k)=*(Aux+i);
      i++;
    }
    else
    {
      *(A+k) = *(Aux+j);
      j++;
    }
  }
  free(Aux);
}

//These help with quicksort
void qsortS(int* A, int start, int stop){
  if(start<stop)
  {
    int p = partition(A,start,stop);
    qsortS(A,start,p-1);
    qsortS(A,p+1,stop);
  }
}
//Partition
int partition(int* A, int start, int stop){
	int randIndex = (rand() % (stop+1-start)) + start;
  swapPlaces(&A[randIndex],&A[stop]);
  int pivot = A[stop];
  int i = start;
  for(int j=start;j<stop;j++)
  {
    if (A[j] <=pivot)
    {
      swapPlaces(&A[i],&A[j]);
      i++;
    }
  }
  swapPlaces(&A[i],&A[stop]);
	return i;
}
