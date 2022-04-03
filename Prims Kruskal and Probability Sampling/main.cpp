//created by Nicholas

#include "PrimsAlgorithmV2.h"
//#include "PrimsAlgorithm.h"

#include <iostream>
#include <fstream>
#include <string>
#include <String.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


int main(int argc, char** argv) {
	
	// define the matrix0+
	const int M = 10;
	int matrix[M][M];
		
		
	/* *** read contents of the file and build a matrix from them *** */

	string str;
	ifstream file;
    
    
    // file name
   	char fname[100] = "P8-MTSTree-v1.txt";
  	file.open(fname);
   
   
   	// simple check to ensure file is present
   	if (!file)
   	{
   	   cout << "Error Occurred while opening file!";
   	   exit(0);
   	}
   	cout << "\n";
   
   	int iteration = 0;
   
   	cout << "matrix read from file:\n";
   	// iterate through the lines in the file
   	while( getline(file, str) )
    { 
	
		//read data from file object and put it into string.
        cout << str << "\n"; //print the data of the string
        
        if( str.empty()  )break;
        
		int iter = 0;
		
		// columns in each row
		for(int i = 0; str[i] != 59; i++)
		{
			
			int element; 
						
			// if current character is not at end and next character is spacer
			if( ( str[i] != 95 ) && ( str[i] != 59 ) && ( str[i+1] == 95 )  )
			{
				string charString(1, str[i]);
				element = stoi(charString);
				//cout << element << " current character is not at end and next character is spacer\n";
				matrix[iteration][iter]	= element;
				iter ++;
			}
			
			
			// if current character is not at end and next character also part of the same number (this is a two-digit value)
			else if( ( str[i] != 59 ) && ( str[i] != 95 ) && ( str[i+1] != 59 ) && ( str[i+1] != 95 ) )
			{
				string charString(1, str[i]);
				string nextString(1,str[i+1]);
				element = stoi(charString)*10 + stoi(nextString);
				//cout << element << " current and next characters are double-digit value\n";
				matrix[iteration][iter]	= element;
				iter ++;
				i ++;
			}
			
			
			// if current character is not at end and next char is terminator
			else if( ( str[i] != 95 ) && ( str[i] != 59 ) && ( str[i+1] == 59 )  )
			{
				string charString(1, str[i]);
				element = stoi(charString);
				//cout << element << " current character is not at end and next character is the end\n";
				matrix[iteration][iter]	= element;
				iter ++;
				i ++;
			}
			
			// if current character is a spacer character
			else 
			{
				//cout << "spacer\n";
			}
			
		}
		
    	iteration++;

	}
   	file.close();
   	cout << "\n\n";
  	
	
	/* *** Prim's algorithm *** */
	PrimsAlgorithmV2 *primsAlgorithmV2;
	primsAlgorithmV2->findMinSpanTree(matrix);
	
	/* *** probability algorithm *** */
	
	return 1;

}
