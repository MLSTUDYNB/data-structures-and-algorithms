#pragma once

#include <stdlib.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int StackTypeDate;

typedef struct stack
{
	StackTypeDate* arr;
	int top;
	int capacity;
}Stack;

void InitStack(Stack* ps);

void StackPush(Stack* ps,StackTypeDate x);

bool StackEmpty(Stack* ps);

void StackPop(Stack* ps);

StackTypeDate StackTop(Stack* ps);

int StackSize(Stack* ps);

void StackDestroy(Stack* ps);
