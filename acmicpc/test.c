#include <stdio.h>

#define TEST *(volatile unsigned int *)0x40011008

int main()
{
	unsigned int * a = TEST;
	*a =10;
	printf("%d",a);
	TEST &= 0x00000000;
	printf("%x",&TEST);
	return 0;
}
