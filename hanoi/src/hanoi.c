/*
 * hanoi.c
 *
 *  Created on: 2017Äê12ÔÂ26ÈÕ
 *      Author: andy.lv
 */
#include <stdlib.h>
#include "hanoi.h"

#include "list.h"

extern long count;

void hanoiInit(Hanoi* hanoi, void* vals, size_t size, const int num) {
	Node* hNode = malloc(sizeof(Node));
	Node* lNode = malloc(sizeof(Node));
	Node* rNode = malloc(sizeof(Node));
	List* hList = malloc(sizeof(List));
	listInit(hList);
	for(int i = 0; i < num; i++) {
		listAdd(hList, vals + i * size);
	}
	hNode->val = hList;
	hNode->next = rNode;
	hNode->prev = lNode;

	List* lList = malloc(sizeof(List));
	listInit(lList);
	lNode->val = lList;
	lNode->next = hNode;
	lNode->prev = rNode;

	List* rList = malloc(sizeof(List));
	listInit(rList);
	rNode->val = rList;
	rNode->prev = hNode;
	rNode->next = lNode;
	hanoi->hNode = hNode;
	hanoi->size = num;
}

void hanoiDestroy(Hanoi* hanoi) {
	List* hList = hanoi->hNode->val;
	List* lList = hanoi->hNode->prev->val;
	List* rList = hanoi->hNode->next->val;
	listDestroy(hList);
	listDestroy(lList);
	listDestroy(rList);
	free(hList);
	free(lList);
	free(rList);
	Node* hNode = hanoi->hNode;
	Node* lNode = hNode->prev;
	Node* rNode = hNode->next;
	free(lNode);
	free(rNode);
	free(hNode);
}

static void shift(Hanoi* hanoi, Node* node, bool right, void (*printItem)(void*)) {
	count++;
	List* list = node->val;
	void* val = listRemoveFirst(list);
	if(right) {
		List* rList = node->next->val;
		listInsert(rList, val);
	}else {
		List* lList = node->prev->val;
		listInsert(lList, val);
	}
	printHanoi(hanoi, printItem);
}

static void _hanoi(Hanoi* h, Node* node, int num, bool right, void (*printItem)(void*)) {
	if(num == 0) return;
	_hanoi(h, node, num - 1, !right, printItem);
	shift(h, node, right, printItem);
	_hanoi(h, right? node->prev : node->next, num - 1, !right, printItem);
}

void hanoi(Hanoi* hanoi, void (*printItem)(void*)) {
	_hanoi(hanoi, hanoi->hNode, hanoi->size, true, printItem);
}


void printHanoi(Hanoi* hanoi, void (*printItem)(void*)) {
	List* hStack = hanoi->hNode->val;
	List* lStack = hanoi->hNode->prev->val;
	List* rStack = hanoi->hNode->next->val;
	printf("left:\t");
	listReversePrint(lStack, printItem);
	printf("hanoi:\t");
	listReversePrint(hStack, printItem);
	printf("right:\t");
	listReversePrint(rStack, printItem);
	printf("--------------------------------\n");
}
