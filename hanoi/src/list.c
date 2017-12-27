/*
 * stack.c
 *
 *  Created on: 2017Äê12ÔÂ26ÈÕ
 *      Author: andy.lv
 */

#include <stdio.h>
#include <stdlib.h>

#include "list.h"


void listInit(List* list) {
	list->size = 0;
	list->top = NULL;
}

bool isListEmpty(List* list) {
	return list->size == 0;
}

void listInsert(List* list, void* item) {
	Node* node = malloc(sizeof(Node));
	node->val = item;
	if(isListEmpty(list)) {
		node->next = node;
		node->prev = node;
		list->top = node;
	}else {
		node->next = list->top;
		node->prev = list->top->prev;

		list->top->prev->next = node;
		list->top->prev = node;
		list->top = node;
	}
	list->size ++;
}


void listAdd(List* list, void* item) {
	Node* node = malloc(sizeof(Node));
	node->val = item;
	if(isListEmpty(list)) {
		node->next = node;
		node->prev = node;
		list->top = node;
	}else {
		node->next = list->top;
		node->prev = list->top->prev;

		list->top->prev->next = node;
		list->top->prev = node;
	}
	list->size ++;
}


static void* _listRemove(List* list, int index) {
	if(isListEmpty(list) || index < 0 || index > listSize(list) - 1)
		return NULL;
	Node* node = list->top;
	int i = 0;
	while(i++ != index) {
		node = node->next;
	}
	node->prev->next = node->next;
	node->next->prev = node->prev;
	if(list->top == node)
		list->top = node->next;
	list->size--;
	void* val = node->val;
	free(node);
	return val;
}

void* listRemoveFirst(List* list) {
	return _listRemove(list, 0);
}


void* listRemoveLast(List* list) {
	return _listRemove(list, listSize(list) - 1);
}

int listSize(List* list) {
	return list->size;
}

void listDestroy(List* list) {
	while(!isListEmpty(list))
		listRemoveFirst(list);
}

static void* listGet(List* list, int index) {
	if(index > listSize(list) - 1)
		return NULL;
	Node* current = list->top;
	int i = 0;
	while(i++ != index)
		current = current->next;
	return current->val;
}

void listReversePrint(List* list, void (*printItem)(void*)) {
	printf("[");
	int i = listSize(list);
	while(i > 0) {
		--i;
		void* val = listGet(list, i);
		(*printItem)(val);
		if(i > 0)
			printf(" ");
	}
	printf("]\n");
}

void listPrint(List* list, void (*printItem)(void*)) {
	printf("[");
	int i = 0;
	while(i < listSize(list)) {
		void* val = listGet(list, i);
		(*printItem)(val);
		if(i < listSize(list) - 1)
			printf(" ");
		i++;
	}
	printf("]\n");
}
