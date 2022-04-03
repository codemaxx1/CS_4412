
#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;


class Priority_Queue
{
	private:
		//priorityQueue	
		int maxSize = 2147483646;	//maximum size of the array
		int* priorityQueue = new int[maxSize];	//priorityQueue of maximum size
		
		int position = 0; //the position currently being used

	public:
		Priority_Queue();
		~Priority_Queue();
	
	
	//printQueue
	//Print the priority queue 
	void printQueue()
	{
	
		int level = 1;	//iterated value that stores what level it is on
		
		cout << "\n \nPrinting Priority Queue\n";		
		cout << "position: " << position << "\n";
		for(int pivot = 0; pivot < position; pivot++)
		{
			cout << priorityQueue[pivot] << " ";
			
			//cout << "\t 2^level: " << pow(2,level) << " \t level: " << level << "\t pivot: " << pivot << "\t ";
			
			if( fmod(pow(2,level), pivot+2) == 0)
			{
				cout << "\n";
				level ++;		
			}	
			
		}
	
		cout << "\nPrinting Completed\n \n";		
	}
	
	
	//sortNew
	//sort the priority queue.  ie, ensure parents are >= children
	/*
		input: position to reposition from
	*/
	void sortNew(int value)
	{
		int level = log(position)/log(2);
		int tempPosition = position;
	
	    //iterate for each level
    	for(int iteration = 0; iteration <= level; iteration++)
		{
			int parent = getParent(position);
			
            //bubble the node up if it is smaller than its parent	
			if(value < priorityQueue[parent] )
			{
                //swap parent and the current child
				int parentValueTemp = priorityQueue[parent];
				priorityQueue[parent] = value;
				priorityQueue[position] = parentValueTemp; 
				
				//reset position to its parent
				position = getParent(position);
			}
			else
			{
				break;		
            }
		}
		position = tempPosition;
	}
	
	
	//sortRemove
	//sort the priority queue.  ie, ensure parents are >= children
	/*
		input: position to reposition from
	*/
	int sortRemove()
	{
		int value = priorityQueue[position];
		int level = log(position)/log(2);
		int tempPosition = position;
		int position = 0;
				
		//iterate for each level
		for(int iteration = 0; iteration < level; iteration++)
		{
			
			//find position of the smallest child
			int childPosition = 2*position + min(priorityQueue[2*position], priorityQueue[2*position+1]);
			
			//swap positions of "position" and childposition
			int tempValue = priorityQueue[position];
			priorityQueue[position] = priorityQueue[childPosition];
 			priorityQueue[childPosition] = tempValue;
					
			position =   childPosition ;
		}
		
		//reset the position to what it was before this operation
		position = tempPosition;
	}
	
	
	//getParent
	//return the parent of a node
	/*
		input: position of node to check
		output: position of parent to node
	*/
	int getParent(int position)
	{
		int parent;
		
		//if position is even, the parent is position/2.  If it is odd, the parent is floor(position/2)
		if(position % 2 == 0) parent = position/2;
		else parent = floor(position/2);
		
		return parent;
	}
	
	
	//add
	//add a new value to the priority queue
	/*
		input: value to add
		output: position to which the element is added
	*/
	int add(int value)
	{
		//add the new element/node to the queue		
		priorityQueue[position] = value;
        
        //bubble the node properly		
		sortNew(value);

		position++;

		return position;
	}
	
	
	//extractMin
	//extract the minimum value
	/*
		return: minimum value
	*/
	int extractMin()
	{
        //swap position 0 and the rightmost node
		int min;
		min = priorityQueue[0];
		priorityQueue[0] = priorityQueue[position -1];
		priorityQueue[position--] = 0;
			
		//bubble the 0 position node down
        sortRemove();
		
		return min;
	}
	
};


