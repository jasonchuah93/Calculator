#ifndef __TRYEVALUATETHANPUSH_H__
#define __TRYEVALUATETHANPUSH_H__

#include "Token.h"
#include "Stack.h"

/**
	Evaluate all operators on the operator stack that have strictly lower
	precedence than the operator to be pushed. The evaluation of operators
	is from the top of stack to bottom
	
	Input :
		stack the operatorStack
		operator the operator to be pushed onto the operator stack 
		
**/

void tryEvaluateOperatorOnStackThenPush(OperatorToken *newToken,Stack *dataStack,Stack *operatorStack);


#endif //__TRYEVALUATETHANPUSH_H__