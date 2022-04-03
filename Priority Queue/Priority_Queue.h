
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
		//cout << "level: " << level;
		int tempPosition = position;
		for(int iteration = 0; iteration <= level; iteration++)
		{
			int parent = getParent(position);
			//cout << "parent" << parent << "\t\t value < priorityQueue[parent] =" << value << " < " << priorityQueue[parent] << " = " << (value < priorityQueue[parent]);
			
			if(value < priorityQueue[parent] )
			{
				//cout << "repositioning...";
				int parentValueTemp = priorityQueue[parent];
				
				priorityQueue[parent] = value;
				priorityQueue[position] = parentValueTemp; 
				
				position = getParent(position);
			}
			else
			{
				//cout << "for loop broken.\n";
				break;		}
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
		cout << "level: " << level << "\n";
				
		//iterate for each level
		for(int iteration = 0; iteration <= level; iteration++)
		{
			cout << "iteration: " << iteration << "\t\t level: " << level;
			//iterate for each child (2)
			for(int childOffset = 1; childOffset <=2; childOffset++){
			
				int childPosition = position+childOffset;
				
				//if the value is higher than that of its child, swap them
				if(value > priorityQueue[childPosition])
				{
					cout << "calue:" << value <<"\tpriorityQueue[childPosition]: " << priorityQueue[childPosition] << "\n";
					position+=pow(2,iteration);
					//level++;
					break;
				}	
				else 
				{
				
				}
			}
		}
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
		
		//if position is even
		if(position % 2 == 0) parent = position/2;
		else parent = floor(position/2);
		
		//cout << "parent of position " << position << " is " << parent << "\n"; 
		
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
		//cout << "position: " << position << " = " << value << "\n";

		//add the new element/node to the queue		
		priorityQueue[position] = value;
		
		//sort the 
		//if(value > priorityQueue[getParent(position)])
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
		int min;
		min = priorityQueue[0];
		cout << "position: " << position << "\n";
		for(int x = 0; x < position; x++)cout<<priorityQueue[x]<<" ";
		cout << "\n";
		
		cout << "priorityQueue[position-1]: " << priorityQueue[position-1] << "\n";
		
		priorityQueue[0] = priorityQueue[position -1];
		priorityQueue[position--] = 0;
		
		sortRemove();
		
		return min;
	}
	
};


