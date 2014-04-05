#ifndef __OPERATOREVALUATE_H__
#define __OPERATOREVALUATE_H__

#include "Stack.h"

//Function declaration
void evaluateAllOperatorOnStack(Stack *dataStack,Stack *operatorStack);
void evaluateOperator(Stack *dataStack,OperatorToken *opeToken);

#endif //__OPERATOREVALUATE_H__