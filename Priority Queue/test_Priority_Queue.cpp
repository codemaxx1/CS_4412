//Create by Nicholas Garrett 	10/3/2021
/*
	test the priority queue created in 
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

//import priority queue
#include "Priority_Queue.h"

int sizeOfTestingArray = 15;
int range = 10;


//populate Array
//populate an inputted array with random values
/*
	input: array to randomize
*/
void populateArray(int* array)
{
	cout << "Creating random array:\n";
		
	for(int index = 0; index < sizeOfTestingArray; index++)
	{
		int value = rand()%range;
		array[index] = value;
		cout << value << " ";
	}
	
	cout << "\nrandom array completed\n \n";
}


int main()
{
	//text output 
	for(int x = 0; x < 50; x++) cout << "_";
	cout << "Testing started";
	for(int x = 0; x < 50; x++) cout << "_";
	cout << "\n \n";
	
	//generate instance of PriorityQueue class
	Priority_Queue *pQInstance = new Priority_Queue(); 
	
	//create array of values to test
	int* valuesToAdd = new int[sizeOfTestingArray];
	
	//populate this example array
	populateArray(valuesToAdd);
	
	//build the queue
	for(int pivot = 0; pivot < sizeOfTestingArray; pivot++)
	{
		cout << "add valuesToAdd[" << pivot << "] = " << valuesToAdd[pivot] << "\n";
		pQInstance->add(valuesToAdd[pivot]);
	}
	
	//print the queue
	pQInstance -> printQueue();
	
	
	//extract the min
	
	pQInstance -> extractMin();
	
	
	//print the queue
	pQInstance -> printQueue();
	
	return 1;
}
