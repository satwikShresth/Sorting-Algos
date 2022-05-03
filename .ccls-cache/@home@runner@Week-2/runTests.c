//Mark Boady
//Sort Tester
//CS 260
#include <stdio.h> //For printf
#include <stdlib.h> //For rand and srand
#include <time.h> //For time

//Local Imports
#include "sorts.h"
#include "testLib.h"

//You may not change this file

//This program tests all for sorts
//Print a Usage Error Message
void printUsage();


//Takes a single letter as command line
//input
// b - test bubble sort
// i - test insertion sort
// m - test merge sort
// q - test quick sort
//Main Program
int main(int argc, char** argv){
	if(argc!=2){
		printUsage();
		return -1;
	}
	//Set the random number generator
	srand(time(0));
	//What is the max size to test with
	int maxSize = 13;
	//Get only the first letter
	char letter = argv[1][0];
	//Switch on letter
	switch(letter){
		case 'b':
			printf("Testing Bubble Sort\n");
			fullTestBed(maxSize, bubbleSort);
			break;
		case 'i':
			printf("Testing Insertion Sort\n");
			fullTestBed(maxSize, insertionSort);
			break;
		case 'm':
			printf("Testing Merge Sort\n");
			fullTestBed(maxSize, mergeSort);
			break;
		case 'q':
			printf("Testing Quick Sort\n");
			fullTestBed(maxSize, quickSort);
			break;
		default:
			printf("Did not understand %c\n",letter);
			printUsage();
			break;
	}
	return 0;
}



//Print a Usage Error Message
//Input: None
//Output: None
//Side Effect: Prints Command Line Arguments
void printUsage(){
	printf("One Command Line Argument is required.\n");
	printf("Select Sort to Test:\n");
	printf("b for Bubble Sort\n");
	printf("i for Insertion Sort\n");
	printf("m for Merge Sort\n");
	printf("q for Quick Sort\n");
}
