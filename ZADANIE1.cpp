// ZADANIE1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <sstream>
#include <iterator> 

using namespace std;

template <typename T>
size_t spocitaj(istream &str) 
{
	return distance(istream_iterator<T>(str), istream_iterator<T>());
}

struct Line
{
string lineData;
operator string() const
{
return lineData;
}
};

istream &operator>>(istream &str, Line &data)
{
getline(str, data.lineData);
return str;
}


int main(int argc, char * argv[]) 
{
	istream *p_vstup_stream = NULL;
	ifstream f;
	int vysledok = 0;

	/*
	for (int i = 0; i < argc; ++i) //vypisanie argumentov
	{
		cout << argv[i] << endl;
	}
	*/

	if (argc < 2 || argc > 3) return -1; //nespravny pocet argumentov v prikazovom riadku
	else if (argc == 3)
	{
		f.open(argv[2], fstream::in); 
		if (f.bad())
		{
			return -1; 
		}
		p_vstup_stream = new ifstream(argv[2], fstream::in);

	}
	else if (argc == 2)
	{
		cout << "Nacitanie textu z konzoly" << endl << "text:  " << endl;
		p_vstup_stream = &cin; //stream

	}


	if (argv[1] == string("-c"))
	{
		vysledok = spocitaj<char>(*p_vstup_stream);
	}
	else if (argv[1] == string("-w"))
	{
		vysledok = spocitaj<string>(*p_vstup_stream);
	}
	else if (argv[1] == string("-l"))
	{
		vysledok = spocitaj<Line>(*p_vstup_stream);
	}
	else return -1;


	cout << "vysledok je: " << vysledok << endl;


	if (p_vstup_stream != &cin) 
		f.close();


    return 0;
}