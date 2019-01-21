/*
 ============================================================================
 Name        : HelloWorld.c
 Author      : Marion Holvoet
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "../s3/watchData.h"

int main(void) {
	puts("!!!Hello World Marion!!!"); /* prints !!!Hello World!!! */

	{
		char line[80];
		sprintf(line, "WatchData size is %ld bytes", sizeof(WatchData));
		puts(line);
	}

	puts("Bye Cruel World");

	return EXIT_SUCCESS;
}
