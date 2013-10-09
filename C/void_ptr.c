#include <stdio.h>


int main()
{
	int x = 0xaabbccdd;

	int z = 0x11223344; 

	void *void_xptr = (void*)&x;

	void_xptr += 1;

	int *xptr = (int*)void_xptr;

	int y = *xptr;

	printf("%x", y);
	return 0;
}
