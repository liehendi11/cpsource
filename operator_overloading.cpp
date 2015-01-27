#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Cents
{
private:
	int m_cents;
public:
	Cents(int cents)
	{
		m_cents = cents;
	}

	operator int()
	{
		return m_cents;
	}
};

int main()
{
	Cents cent(5);
	//printf("%d\n", cent);
	int k = cent;
	printf("%d\n", cent);
	printf("%d\n", k);
	cout << k << endl;
	return 0;
}