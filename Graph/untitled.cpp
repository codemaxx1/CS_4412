//created by Nicholas
/*

*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

// initial variables
int matrixSize = 8;
int matrix [8][8];
int priorityQueue[64];
int dataTable[4][64];

//create matrix
/*
  input: size of array
  return: none
*/
void  populateMatrix()
{
	cout << "populating matrix:\n";
    
    for(int i = 0; i < matrixSize; i++)
    {
        for(int j = 0; j < matrixSize; j++)
        {
                // initialize 30% of the rows to 1 using a mod 3 function
                if((i + j) % 3 == 0) matrix[i][j] = 1;
                else matrix[i][j] = -1;
				cout << matrix[i][j];       
        }
        cout << "\n";
    }
    
    cout << "matrix populated\n\n";
    
}


// printData
// print the matrix, priority queue, etc.
/*
*/
void printData(  )
{
	// print the matrix
	cout << "printing matrix: The rows are the \"from\" vertices and the columns are the \"to\" vertices\n";
	for(int i = 0; i < matrixSize; i++)
	{
	
		for(int j = 0; j < matrixSize; j++)
		{
	
			int value = matrix[i][j];
			
			cout << "[" << value ;
			if(value > 0)cout<< " ] ";
			else cout << "] " ;
		}
		cout << "\n";
	}
	cout << "matrix printed\n";
	
	
	// print the priority queue
	cout << "printing priorityQueue: \n";
	for( int i = 0; i < matrixSize*matrixSize; i++)
	{
		int value = priorityQueue[i];
		cout << value;
	}
	cout << "\npriorityQueue printed\n";
	
	
	// print the data table
	cout << "\nprinting the data table: \n";
	
	cout << "color: \t\t\t[";
	for(int i = 0; i < matrixSize*matrixSize; i++)
	{
		int value = dataTable[0][i];
		cout << value;
	}
	cout << "]\n";

	cout << "distance to V1: \t[";
	for(int i = 0; i < matrixSize*matrixSize; i++)
	{
		int value = dataTable[1][i];
		cout << value;
	}
	cout << "]\n";

	cout << "vertex #: \t\t[";
	for(int i = 0; i < matrixSize*matrixSize; i++)
	{
		int value = dataTable[2][i];
		cout << value;
	}
	cout << "]\n";
	
	cout << "priority #:\t\t[";
	for(int i = 0; i < matrixSize*matrixSize; i++)
	{
		int value = dataTable[3][i];
		cout << value;
	}
	cout << "]\n";
	cout << "ndata table printed\n";
}



// depthFirstSearch
//
/**/
int depthFirstSearch(int targetVertex)
{
	int sourceVertex = 0;
	
	while (true)
	{
		cout << "edges out from " << sourceVertex << ": ";		
		
		for(int i = 1; i <= matrixSize; i++)
		{
			if(matrix[sourceVertex][i-1] > 0)
			{
				cout << i;
			}
		}
		break;	
	}
	
	
}


// main method
int main()
{
	populateMatrix();

	printData();
	
	depthFirstSearch(9);

	return 1;
}
