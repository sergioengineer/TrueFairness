// BinaryWizer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char* argv[])
{
	if (argc < 2)
		return 1;

	ifstream _Filein(argv[1], ios::binary);
	if (!_Filein.is_open())
		return 2;
	ofstream _Fileout("Output.txt");
	char cInput = NULL, cOutput = NULL;

	while (!_Filein.eof())
	{
		_Filein.read(&cInput, 1);
		for (int iCont = 7; 0 <= iCont; iCont--)
		{
			cOutput = (char)((cInput & (1 << iCont)) >> iCont);
			cOutput += (char)0x30;
			_Fileout << (char)cOutput;
		}
		cInput = 0;
		_Fileout << " ";
	}

	return 0;
}

