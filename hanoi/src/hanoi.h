/*
 * hanoi.h
 *
 *  Created on: 2017Äê12ÔÂ26ÈÕ
 *      Author: andy.lv
 */

#ifndef HANOI_H_
#define HANOI_H_
#include <stdbool.h>

#include "list.h"

typedef struct hanoi {
	Node* hNode;
	int size;
} Hanoi;

void hanoiInit(Hanoi*, void*, size_t, const int);

void hanoi(Hanoi*, void (*printItem)(void*));

void hanoiDestroy(Hanoi*);

void printHanoi(Hanoi*, void (*printItem)(void*));


#endif /* HANOI_H_ */
