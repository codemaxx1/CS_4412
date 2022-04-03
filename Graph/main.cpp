//created by Nicholas
/*

*/

// libraries
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

// headers
#include "PriorityQueue.h"
#include "Part2_4.h"

using namespace std;

// initial variables
int matrixSize = 8;
int matrix [8][8];
int priorityQueue[8];

// data table containing [color] [dist to (0,0)] [vertex #] [priority] [visited]
int dataTable[6][8];


//populate matrix
//populate relational matrix to hold vertices between nodes
/*
*/
void  populateMatrix()
{
	cout << "populating matrix:\n";
    
    //build relational matrix to hold vertices between nodes
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
// print the matrix, priority queue, etc. *It's not pretty, but it does its job
/*
*/
void printData(  )
{
	// print the matrix
	cout << "printing relational matrix: The rows are the \"from\" vertices and the columns are the \"to\" vertices\n";
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
	
		
	// print the data table
	cout << "\nprinting the data table: \n";
	
	cout << "color: \t\t\t[";
	for(int i = 0; i < matrixSize; i++)
	{
		int value = dataTable[0][i];
		cout << value << " ";
	}
	cout << "]\n";

	cout << "distance to V1: \t[";
	for(int i = 0; i < matrixSize; i++)
	{
		int value = dataTable[1][i];
		cout << value << " ";
	}
	cout << "]\n";

	cout << "vertex #: \t\t[";
	for(int i = 0; i < matrixSize; i++)
	{
		int value = dataTable[2][i];
		cout << value << " ";
	}
	cout << "]\n";
	
	cout << "priority #:\t\t[";
	for(int i = 0; i < matrixSize; i++)
	{
		int value = dataTable[3][i];
		cout << value << " ";
	}
	cout << "]\n";
	
	cout << "visited:\t\t[";
	for(int i = 0; i < matrixSize; i++)
	{
		int value = dataTable[4][i];
		cout << value << " ";
	}
	cout << "]\n";
	
	cout << "path:\t\t\t[";
	for(int i = 0; i < matrixSize; i++)
	{
		int value = dataTable[5][i];
		cout << value << " ";
	}
	cout << "]\n";
	cout << "ndata table printed\n";
}



// notVisited
// determine if the inputted node has been visited 
/*
	inputs: node to analyze (int)
	output: true if not visited, false if visited
*/
bool notVisited(int node)
{
	
	cout << "( node : " << node;
	
	// if the node at (row, column) is unvisited, return true
	if(dataTable[4][node] != 1)
	{ 	
		cout << " unvisited ) ";
		return true;
	}
	
	cout << " visited ) ";
	return false;
}


// depthFirstSearch
/*This search algorithm is not quite finished--as you can quite easily see.  */
/**/
int depthFirstSearch(int targetVertex)
{
	// check that the target Vertex is in the range of possible vertexes (matrixSize is offset due to plus-one on array)
	if(targetVertex > matrixSize)
	{
		cout << "Error: your target vertex extends past the map size\n";
		return -1;
	}
	
	
	cout << "\nstarting depth first search\n";

	int sourceVertex = 0;
	PriorityQueue *pq = new PriorityQueue();
	

	while(true)
	{
		if(sourceVertex == targetVertex)
		{
			cout << "target located.";
			return 1;
		}	
		
		//mark sourceVertex as visited
		dataTable[5][sourceVertex] = 1;
		
		//find children and add to queue
		for(int i = 0; i < matrixSize; i++)
		{
			if( matrix[sourceVertex][i] == 1 && notVisited(i))
			{
				pq->Insert(i);
			}
		}
		
		pq->PrintQueue();
		
		break;
	}
	
	cout << "\ndepth first search ended\n";
	return 1;
}


//breadthFirstSearch
//
/*
*/
int breadthFirstSearch(int targetVertex)
{
	// check that the target Vertex is in the range of possible vertexes (matrixSize is offset due to plus-one on array)
	if(targetVertex > matrixSize)
	{
		cout << "Error: your target vertex extends past the map size\n";
		return -1;
	}
	
	
	cout << "\nstarting breadth first search\n";

	int sourceVertex = 0;
	
	PriorityQueue *pq = new PriorityQueue();
	
	int iter = 0;
	//dataTable[5][0] = sourceVertex;
	
	while (true)
	{
		//record the path
		dataTable[5][iter] = sourceVertex+1;
		
		iter++;
		if(sourceVertex+1 == targetVertex)
		{
			
			cout<<"\n Vertex found.  Distance traversed: " << iter << "\n";
			cout << "path:\t\t\t[";
			for(int i = 0; i < matrixSize; i++)
			{
				int value = dataTable[5][i];
				cout << value << " ";
			}
			cout << "]\n";
			//printData();		
			
			break;
		}
		
		cout << "\n\n\n\nedges out from " << sourceVertex << ": ";
		// add that pivot to the array of visited nodes
		dataTable[4][sourceVertex] = 1;		
		
		// find all outcoing edges and push them onto the priority queue
		for(int i = 1; i <= matrixSize; i++)
		{
			
			// if the pivot value is 1 and it is not pointing to itself, add that pivot to the queue of values to search
			if(matrix[sourceVertex][i-1] > 0 )
			{
				
				// node does not add itself
				if( i != sourceVertex+1 && notVisited(i))
				{
					cout << i << " ";
					// add the node to the priority queue
					pq->Insert(i);
				}
				else
				{
					cout << " !" << i << " ";
				}
				
			
			}
		}
		
		pq->PrintQueue();
		
		// iterate through the nodes until the target vertex is found
		printData();
		
		sourceVertex = pq->ExtractMin();

		cout << "new source vertex: " << sourceVertex ;
		
		// check that the we have not iterated past the number of nodes, as this signifies an error
		if(iter > matrixSize-1)
		{
			cout << "Error: something went wrong and search iterated past the map size\n";
			return -1;
		}
		
	}
	
	cout << "\nbreadth first search ended\n";
	return 1;
}


// main method
int main()
{
	populateMatrix();

	printData();
	
	// the assignment says to find the 9th node, though there are only 8 nodes, so I am just searching for hte last (8th) node
	//depthFirstSearch(8);
	
	breadthFirstSearch(8);

	/*Part24 *p24 = new Part24();
	p24->PrintMatrix();
	p24->shortestPath(9);
	*/
	return 1;
}
