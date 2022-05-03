#ifndef _SORTS_H_
#define _SORTS_H_



//Takes 2 pointers to the adress of two ints and swap the places
//inputs are 2 int pointers
//output is none
//side effects is it swaps the elements in the adress
void swapPlaces(int *placeA,int *placeB);

//All sorts take
//Inputs:
//	A - An Array of Integers
//	size - The size of the Array
//Outputs:
//	None
//Side Effects:
//	Array A is sorted from index 0
//	to size-1

//Implementation of Bubble Sort
void bubbleSort(int* A, int size);

//Implementation of Insertion Sort
void insertionSort(int* A, int size);

//Implementation of Merge Sort
void mergeSort(int* A, int size);

//Implementation of Quick Sort
void quickSort(int* A, int size);

//Helper Functions
//These help with merge sort
//Sort a Section
void msortS(int* A, int start, int stop);
//Merge two Sections
void merge(int* A, int start, int middle, int stop);

//These help with quick sort
//Sort a section
void qsortS(int* A, int start, int stop);
//Partition
int partition(int* A, int start, int stop);

#endif
