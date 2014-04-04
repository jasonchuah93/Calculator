#ifndef __STACK_H__
#define __STACK_H__

typedef struct{
	void *topOfStack;
}Stack;

//Function declaration
Stack *stackNew(void);
void push(void *data,Stack *stack);
void *pop(Stack *stack);

#endif //__STACK_H__