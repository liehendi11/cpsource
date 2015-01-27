#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main()
{
	int slices[8];
	for (int i=0; i<8; i++) scanf("%d", &slices[i]);

	int maxMush = 0;
	for (int i=0; i<8; i++)
	{
		maxMush = max(slices[i]+slices[(i+1)%8]+slices[(i+2)%8]+slices[(i+3)%8], maxMush);
	}

	printf("%d\n", maxMush);

	return 0;
}