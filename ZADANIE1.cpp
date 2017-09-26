// ZADANIE1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int main(int argc, char * argv[])
{




	for (int i = 0; i < argc; ++i)
	{
		std::cout << argv[i] << std::endl;
	}

	if (argc < 2 || argc > 3) return -1;
	else if (argc == 3)
	{



	}
	else if (argc == 2)
	{



	}
	


    return 0;
}

