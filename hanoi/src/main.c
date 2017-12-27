/*
 ============================================================================
 Name        : hanoi.c
 Author      : andy.lv
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void testHanoi(const int);

int main(int argc, char** argv) {
	int i;
	if(argc < 2 || !(i = atoi(argv[1]))) {
		printf("usage: hanoi [number]\n");
		exit(EXIT_SUCCESS);
	}
	testHanoi(i);
	return EXIT_SUCCESS;
}
