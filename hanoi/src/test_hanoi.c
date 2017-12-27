/*
 * test_hanoi.c
 *
 *  Created on: 2017Äê12ÔÂ26ÈÕ
 *      Author: andy.lv
 */

#include <stdio.h>
#include <stdlib.h>
#include "hanoi.h"
static void printItem(void* val);

long count = 0;

void testHanoi(const int num) {
	Hanoi h;
	int* vals = malloc(sizeof(int) * num);
	int* _vals = vals;
	for(int i = 0; i < num; i++)
		*_vals++ = i + 1;
	hanoiInit(&h, vals, sizeof(int), num);
	printHanoi(&h, printItem);
	hanoi(&h, printItem);
	printf("\ntotal exe count: %ld\n", count);
	hanoiDestroy(&h);
	free(vals);
}

static void printItem(void* val) {
	int* _val = val;
	printf("%d", *_val);
}
