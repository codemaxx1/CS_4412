// created by Nicholas Garrett

#ifndef LOGGING_H
#define LOGGING_H

#include <iostream>
#include <fstream>
#include <string>
#include <String.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class logging
{
	public:
		logging();
		~logging();
	
		void logEntry(char * log)
		{
			cout << "*** Logging Entry ***\n" << log;
		}
		
};

#endif