#include <stdio.h>
#include "Libdebug.h"

void _init()
{
	printf("Inside _init()\n"); 
} 
void _fini()
{
	printf("Inside _fini()\n"); 
}

void tryPrint()
{
	printf("Tralala\n");
}