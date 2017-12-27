/*
 * stack.h
 *
 *  Created on: 2017Äê12ÔÂ26ÈÕ
 *      Author: andy.lv
 */

#ifndef LIST_H_
#define LIST_H_
#include <stdbool.h>
#include <stdio.h>
typedef struct node {
	void* val;
	struct node* next;
	struct node* prev;
} Node;

typedef struct list {
	Node* top;
	int size;
} List;

void listInit(List*);

void listDestroy(List*);

bool isListEmpty(List*);

int listSize(List*);

void listInsert(List*, void* item);

void listAdd(List*, void* item);

void* listRemoveFirst(List*);

void* listRemoveLast(List*);

void listPrint(List*, void (*printNode)(void*));

void listReversePrint(List*, void (*printItem)(void*));

#endif /* LIST_H_ */
