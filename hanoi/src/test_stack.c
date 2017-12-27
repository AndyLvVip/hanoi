/*
 * test_stack.c
 *
 *  Created on: 2017��12��26��
 *      Author: andy.lv
 */


#include <stdio.h>

#include "list.h"
#define NUM 10

static void printItem(void* item);

void testStack() {
	List stack;
	int items[NUM];
	listInit(&stack);
	listPrint(&stack, printItem);
	for(int i = 0; i < NUM; i++) {
		items[i] = i + 1;
		listAdd(&stack, &items[i]);
		listPrint(&stack, printItem);
	}
	listPrint(&stack, printItem);
	listDestroy(&stack);
}

static void printItem(void* item) {
	int* _item = item;
	printf("%d", *_item);
}
