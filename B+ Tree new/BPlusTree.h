// Created by Nicholas

#ifndef BPLUSTREE_H
#define BPLUSTREE_H

#include <String.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "Error.h"

using namespace std;
#define M 5

// BPlusTree
/*
	Implement a B+ tree 
*/
class BPlusTree
{
	private:	
		
		// leafNode
		// struct for a leaf node
		/*
		*/
		struct Node 
		{
			// the numbers actually stored there
		   int keys[M] = {-1};
		   
		   // array of child node pointers
		   struct Node *childPointers[M];
		   
		   bool leaf;
		   
		   // keys that have been filled
		   int filledValues;
		   
		   // pointer to parent
		   Node * parent;
		};
				
		
	public:
		
		BPlusTree();
		
		~BPlusTree();
	                   
		
		// nodes 
		struct Node *currentNode;
		struct Node *childNode;
		struct Node *root = NULL;
		
		
		
		// printNode
		// print the contents of a select node
		/*
		*/
		void printNode(Node *node)
		{
			// print the node kesy
			cout << "\n\t---keys:\t";
			for( int i = 0; i <=M; i++)
			{
				cout << node -> keys[i] << "_";
			}
			cout << "\t---\n";
			
			
		}
			
			
			
		// createNewNode
		// create a new subtree
		/*
			input:	keys (int[5]), the actual things stored in this node
					childPointers (Node **), pointers to the children of this node
					leaf: (bool) value to determine if this node is a leaf or not
					filledValues: (int), variable to store how many values have been filled in this node
					parent: (Node * ), pointer to the parent of this node
			output: newNode (struct Node)
		*/
		Node* createNewNode( int keys[M], struct Node **childPointers, bool leaf, int filledValues, struct Node * parent  )
		{
			cout << "create new node\n";
			struct Node *newNode = childNode;

			
	        cout << "clear keys\n";
	        //populate empty keys of new node
	        for(int i = 0; i < M; i++) 
			{
				cout << "clearing key " << i << "\n";
				newNode->keys[i] = -1;
			}			
	        cout << "keys cleared, now populate them with the inputted keys \n";
	        // populate keys of new node
			for(int i = 0; i < filledValues; i ++)
			{
				cout << "keys[i]=" << keys[i];
				newNode -> keys[i] = keys[i];	
			} 	
		    printNode(newNode);
			
			cout << "set the boolean for new node's leaf state\n";
			// build the node depending on if it is a leaf or not
			if( leaf == true ) 	newNode->leaf = true;
			else			  	newNode->leaf = false;
			
			
			newNode->filledValues = filledValues;

		
	        newNode->parent = parent;
		    // populate the child nodes with nulls
		    for (int i = 0; i < M+1; i++) 
			{
				cout << "initializing child pointers to null, child " << i << "\n";
		    	newNode -> childPointers[i] = NULL;
		    }
		    

		    
		    return newNode;
		}
		
		
		
		// split
		// split the current node in two
		/*
		*/
		void split(Node *currentNode)
		{
			// Error class instance for error loggign
			Error *error;
			
			/* to split the current node, split the record into 2 new minimum records.  Take the middle value of the overflowed leaf node and duplicate itin the parent non-leaf node.  
			The duplicate key and record of this key should be placed in a new left to right of the key in parent non-leaf node. */
			
			//if the current node is the root, set its value as the middle of its values and split
			if(currentNode == root)
			{

				int keysBuffer[M];

				
				// load keys from the current node into a buffer and wipe the current node's keys 
				for(int i = 0; i < M; i++)
				{
					keysBuffer[i] = currentNode->keys[i];
					currentNode->keys[i] = {-1}; 
				}
				
				// test printing the keysBuffer
				cout << "buffer: ";
				for(int i = 0; i < M; i++)
				cout << keysBuffer[i] << " ";
				cout << "\n";
				
				// the middle value of the keys of node, which will be the single key in the root
				int nodeMiddleValue = keysBuffer[M/2];
				currentNode->keys[0] = nodeMiddleValue;
					
				// test that there only exists a single non-"empty" element in the keys array
				for(int i = 1; i < M; i++)
				{
					if(currentNode->keys[i] != -1)
						error->newError((char*)"This is writing terms into the root node when it is split.  However, it seems that something has gone wrong and more than a single key is written into the root when it is split.");
				}
				
				
				cout << "node middle value: " << nodeMiddleValue << "\n";
				
				printNode(currentNode);
				
				// create new nodes for above and below the halfway value
				cout << "create lower half of split node\n";
				int minNodeKeys[M] = {-1}; 
				// populate lower half
				for(int i = 0; i < (M/2); i++)
				{
					//cout << "adding buffered key " << keysBuffer[i] << " to minNodeKeys";
					minNodeKeys[i] = keysBuffer[i];
				}	
				struct Node *minLeaf = createNewNode(minNodeKeys, NULL, true, (M/2), currentNode);

				cout << "create upper half of split node\n";
				int maxNodeKeys[M] = {-1}; 
				// populate upper half
				for(int i = (M/2) + 1; i < M; i++)	minNodeKeys[i] = keysBuffer[i];
				struct Node *maxLeaf = createNewNode(maxNodeKeys, NULL, true, M - (M/2), currentNode);
				
				printNode(minLeaf);
				printNode(maxLeaf);
			}

			// if the current node is not the root
			else 
			{
				//remove this error call when you start to work on this
				int i = 0;
				error->newError("the current node is supposed to be root, but currentNode equals root is false");			
			}			
			
				
			//if the current node is not the root, add its middle key to the parent and split
		}
		
		
		
		// insert
		// insert a new term into the B+ tree
		/*
		*/
		void insert(int key) 
		{
			// create instance of the Error class (for error logging and testing)
			Error *error;

			cout << "\ninserting key: " << key << "\n";
			
			
			// if there is a root
			if(root){
			
				error->newError("this code is not ready yet (unfinished)");
				printNode(currentNode);

				/* there is room in the leaf for a new key */
				// just insert the key
				if(currentNode->filledValues < M) 
				{
					
					cout << "\t\tfilledValue:" << currentNode->filledValues << "<M:" << M << "\tadding: "<< key <<"\n";
					

					// sort new inserts
					int i;
					for( i = 0; i <= currentNode->filledValues ; i++)
					{
						cout << "filledvalues: " << currentNode->filledValues << "\n";
							
						if( i == currentNode->filledValues)
						{
							currentNode->keys[i] = key;
						}
						
						
						int tempNodeKey = currentNode->keys[i];
						currentNode->keys[i] = min(tempNodeKey, key);
						key = max(tempNodeKey, key);
					
						
						cout << "\t\t\t key:" << key <<"\ttempNodeKey: " << tempNodeKey << "\ti:" << i << "\n";						
						
					}

  					// increment the number of values in this node
					currentNode->filledValues++;				

					printNode(currentNode);
				}			
	
	
				/* if both beighbors are full (or don't exist) */
				// split the record into 2 new minimum records.  Take the 
				else if(false)
				{
					//
					if( currentNode->filledValues == M && currentNode->leaf == true /*both neighbors are full*/  )
					{
						error->newError("both neighbors are full or don't exist'");
					}
				}
				
				else
				{
					error->newError("... this code is running... and it shouldn't'");
				}
				
	
			}
			
			
			// if the root node has not yet been defined
			else if(! root)
			{
				// simple testing check	
				if(key == 41) error->newError("key 41 is entered into root node, even though it shouldn't'");
				
				cout << "working with root node\n";
				/* there is room in the leaf for a new key */
				// just insert the key
				if(currentNode->filledValues < M) 
				{
					
					cout << "\t\tfilledValue:" << currentNode->filledValues << "<M:" << M << "\tadding: "<< key <<"\n";
					

					// sort new inserts
					int i;
					for( i = 0; i <= currentNode->filledValues ; i++)
					{
						cout << "filledvalues: " << currentNode->filledValues << "\n";
						if( i == currentNode->filledValues)
						{
							currentNode->keys[i] = key;
						}
						int tempNodeKey = currentNode->keys[i];
						currentNode->keys[i] = min(tempNodeKey, key);
						key = max(tempNodeKey, key);
						cout << "\t\t\t key:" << key <<"\ttempNodeKey: " << tempNodeKey << "\ti:" << i << "\n";						
						
					}

  					// increment the number of values in this node
					currentNode->filledValues++;				

					printNode(currentNode);
				}
				
				// error check if there are too many keys filled
				//else error->newError("on root node, we are running root-node code when there are >= m keys in node");
				
				
				// if the root node has all its available keys filled, set it as the root and continue
				if(currentNode->filledValues == M)
				{
					root = currentNode;
					cout << "\n\nSplit the node\n";
					split(currentNode);
				}
				
				
			}
			
			
			// if the root is not true or false (something bad happened)
			else error->newError("the root is both true and false");

		}
		
		void test()
		{

			int t[6] = {1,12,5,7,12,41};
		   	
			for(int i = 0; i < 6; i++) {
		    	cout<< "insert element " << t[i] << " into B+ tree\n"; 
		      	insert(t[i]);
		   	}
		   	
			cout<<"traversal of constructed B tree\n";
			
			//TODO traverse
		   	//traverse(r);
		}
		
};

#endif
