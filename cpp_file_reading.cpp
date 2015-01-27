#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[])
{
	if (argc <=1) return 0;

	ifstream infile1;
	infile1.open(argv[1]);

	ifstream infile2;
	infile2.open(argv[1]);

	string inp;

	//move forward
	for (int i=0; i<atoi(argv[2]); i++)
	{
		getline(infile1, inp);
	}

	//read until the first pointer reaches end of file

	while (!infile1.eof())
	{
		getline(infile1, inp);
		getline(infile2, inp);
	}

	while (!infile2.eof())
	{
		getline(infile2, inp);
		printf("%s\n", inp.c_str());
	}

	return 0;
}