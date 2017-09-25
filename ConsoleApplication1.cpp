// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <string>

using namespace std;

int main()
{
	int vysledok;
	char volba;
	string riadok, odpoved;

	cout << "Prajete si nacitat subor? Y/N" << endl;
	getline(cin, odpoved);

	vysledok = 0;

	if (odpoved == "Y" || odpoved == "y")
	{
		string subor;
		cout << "Zadajte nazov suboru (v tvare nazov.txt):" << endl;
		getline(cin,subor);
		
		fstream otvoreny_subor;
		otvoreny_subor.open(subor, fstream::in);

		if (!otvoreny_subor.is_open())
		{
			cout << "Subor sa nepodarilo otvorit" << endl;
		}

		cout << "Vyberte si ulohu:\n-c - spocitat znaky\n-w - spocitat slova\n-l - spocitat riadky\n";
		cin >> volba;

		if (volba == 'c')
		{
			cout << "neskor";
		}
		else if (volba == 'w')
		{
			cout << "neskor";
		}
		else if (volba == 'l')
		{
			while (!otvoreny_subor.eof())
			{
				getline(otvoreny_subor, riadok);
				vysledok++;
			}
			cout << "Pocet riadkov je: " << vysledok << endl;
		}
		else 
		{
			cout << "Neznama volba";
		}
		otvoreny_subor.close();
	} 
	else if (odpoved == "N" || odpoved == "n")
	{
		cout << "Nacitanie textu z konzoly. " << endl;
		cout << "Vyberte si ulohu:\n-c - spocitat znaky\n-w - spocitat slova\n-l - spocitat riadky\n";
		cin >> volba;
		cout << " Nacitavanie ukoncite riadkom, v ktorom bude iba '*' (hviezdicka)" << endl;

		if (volba == 'c')
		{
			cout << "neskor";
		}
		else if (volba == 'w')
		{
			cout << "neskor";
		}
		else if (volba == 'l')
		{
			do
			{
				getline(cin, riadok);
				vysledok++;
			} while (riadok != "*");

			cout << "Pocet riadkov je: " << vysledok-2 << endl;
			
		}
		else {
			cout << "Neznama volba";
		}

	}
	else 
	{
		cout << "Neznama volba";
	}

    return 0;
}

