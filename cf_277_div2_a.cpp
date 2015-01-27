#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

long long find(long long bil)
{
	if (bil %2!=0) return find(bil-1)-bil;
	return bil/2;
}

int main()
{
	long long bil;
	cin >> bil;
	cout << find(bil) << endl;
}