#ifndef __OPERATOREVALUATE_H__
#define __OPERATOREVALUATE_H__

#include "Stack.h"

//Function declaration

/**
	Evaluate all operators on the operator stack, with top of stack 
	operator being evaluated first.
	
	Input :
		stack the operatorStack
**/

void evaluateAllOperatorOnStack(Stack *dataStack,Stack *operatorStack);
void evaluateOperator(Stack *dataStack,OperatorToken *opeToken);

#endif //__OPERATOREVALUATE_H__