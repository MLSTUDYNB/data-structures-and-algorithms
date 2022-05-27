#define _CRT_SECURE_NO_WARNINGS 1

#include "stack.h"

void InitStack(Stack* ps)
{
	assert(ps);
	ps->arr = NULL;
	ps->top = ps->capacity = 0;
}

bool StackEmpty(Stack* ps)
{
	assert(ps);

	return ps->capacity == 0;
}

void StackPush(Stack* ps, StackTypeDate x)
{
	assert(ps);

	if (ps->capacity == ps->top)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		ps->arr = (StackTypeDate*)realloc(ps->arr,sizeof(StackTypeDate) * newcapacity);
		ps->capacity = newcapacity;
	}

	ps->arr[ps->top] = x;
	ps->top++;
}

void StackPop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	ps->top--;
}

StackTypeDate StackTop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->arr[ps->top-1];
}

int StackSize(Stack* ps)
{
	assert(ps);

	return ps->top;
}

void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->arr);
	ps->arr = NULL;
	ps->capacity = ps->top = 0;
}