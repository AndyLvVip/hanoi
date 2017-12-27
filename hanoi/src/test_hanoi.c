/*
 * test_hanoi.c
 *
 *  Created on: 2017Äê12ÔÂ26ÈÕ
 *      Author: andy.lv
 */

#include <stdio.h>
#include "hanoi.h"
#define NUM 4
static void printItem(void* val);

long count = 0;

void testHanoi() {
	Hanoi h;
	int vals[NUM];
	for(int i = 0; i < NUM; i++)
		vals[i] = i + 1;
	hanoiInit(&h, vals, sizeof(int), NUM);
	printHanoi(&h, printItem);
	hanoi(&h, printItem);
	hanoiDestroy(&h);
	printf("\ntotal exe count: %ld\n", count);
}

static void printItem(void* val) {
	int* _val = val;
	printf("%d", *_val);
}
