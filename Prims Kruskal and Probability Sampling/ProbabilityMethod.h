#ifndef PROBABILITYMETHOD_H
#define PROBABILITYMETHOD_H

class ProbabilityMethod
{
	private:
		// 
		
	public:
		ProbabilityMethod();
		~ProbabilityMethod();
		
		// distanceOneNode
		// find all nodes that are a single step away
		/*
			input: matrix (int [N][N]) matrix of nodes 
		*/
		int distanceOneNodes( int matrix[N][N] )
		{
			
			// conNodeToWrite variable to store iterated value to write to in connectableNodes array
			int conNodeToWrite = 0;
			
			// zero out the connectableNodes array
			for(int i = 0; i < 10; i++)
			{
				connectableNodes[i][0] = -1;
				cout << "clearing: connectableNodes[" << i << "]:" << connectableNodes[i][0] << " \n";

			}

			
			// go through the rows corresponding to currentNode, and add any non-zero values to the connectable nodes matrix
			for( int i = 0; i < N; i++ )
			{
				if( matrix[i][currentNode] != 0 )
					connectableNodes[conNodeToWrite][0] = matrix[i][currentNode];
					connectableNodes[conNodeToWrite][1] = currentNode;
					connectableNodes[conNodeToWrite++][2] = i;
					cout << "matrix["<<i<<"]["<<currentNode<<"] : "<<matrix[i][currentNode] << "\n";
					//cout << "row. connectableNodes[" << conNodeToWrite << "]:" << connectableNodes[conNodeToWrite] << " \n";
			}
			
			
			
			conNodeToWrite = 0;
			// go through the columns corresponding to currentNode, and add any non-zero values to the connectable nodes matrix
			for( int i = 0; i < N; i++ )
			{
				if( matrix[currentNode][i] != 0 )
					connectableNodes[conNodeToWrite][0] = matrix[currentNode][i];
					connectableNodes[conNodeToWrite][1] = currentNode;
					connectableNodes[conNodeToWrite++][2] = i;
					cout <<"matrix["<<currentNode<<"]["<<i<<"]"<<matrix[currentNode][i] << "\n";
					//cout << "col. connectableNodes[" << conNodeToWrite << "]:" << connectableNodes[conNodeToWrite] << " \n";
			}
			
			cout << "returning connectable nodes array\n";
			//return connectableNodes;
		}
	
		
		
		//
		
		
	
};

#endif