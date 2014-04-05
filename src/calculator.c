#include <stdio.h>
#include "calculator.h"
#include "Token.h"
#include "Stack.h"
#include "tokenizerNew.h"
#include "nextToken.h"
#include "tryEvaluatethenPush.h"
#include "operatorEvaluate.h"
#include <String.h>
#include "calculateToken.h"
#include "createNumberToken.h"
#include "Error.h"
#include "CException.h"

/**
	Evaluate an expression in text into a value
	Input :
		expression contains an expression to be evaluated in text 
	Return :
		the computed result 
	Throw :
		ERR_NO_EXPRESSION exception if expression is an empty text of NULL
		ERR_NOT_DATA exception if encounter other than number token
		ERR_NOT_OPERATOR exception if encounter other than Operator token
		ERR_INVALID_TOKEN exception if encounter unknown token
**/

int evaluate(char *expression,Stack *dataStack,Stack *operatorStack){
	
	Tokenizer *tokenizer;
	Token *token;
	Token *ansToken;
	ErrorCode e;
	int i;
	int counter =0;
	NumberToken *result;
	
	dataStack=stackNew();
	operatorStack=stackNew();
	tokenizer = tokenizerNew(expression);
	if(expression ==NULL){	
		Throw(ERR_NO_EXPRESSION);
	}
	
	while((token=nextToken(tokenizer))!=NULL){
		if(counter%2==0&&token->type==OPERATOR_TOKEN){
			Throw(ERR_NOT_DATA);
		}
		else if(counter%2==1&&token->type==NUMBER_TOKEN){
			Throw(ERR_NOT_OPERATOR);
		}
		
		if(isNumber(token)){
			
			push(token,dataStack);
		}
		else if(isOperator(token)) 
		{
			tryEvaluateOperatorOnStackThenPush((OperatorToken*)token,dataStack,operatorStack);
		}
		
		counter ++;
	}
	evaluateAllOperatorOnStack(dataStack,operatorStack);
	result=(NumberToken*)pop(dataStack);
	printf("counter needed for each expression : %d \n",counter);
	return result->value;
}

/**
	Evaluate all operators on the operator stack, with top of stack 
	operator being evaluated first.
	
	Input :
		stack the operatorStack
**/

void evaluateOperator(Stack *dataStack,OperatorToken *opeToken){
	NumberToken *num1;
	NumberToken *num2;
	Token *token1; 
	Token *token2; 
	int answer; 
	NumberToken *answerToken; 
	token1=(Token*)pop(dataStack); 
	num1=(NumberToken*)token1; 
	token2=(Token*)pop(dataStack); 
	num2=(NumberToken*)token2;
	answer = calculate(opeToken,num2,num1); 
	answerToken=createNumberToken(answer);
	push(answerToken,dataStack);
	
}

/**
	Evaluate all operators on the operator stack, with top of stack 
	operator being evaluated first.
	
	Input :
		stack the operatorStack
**/

void evaluateAllOperatorOnStack(Stack *dataStack,Stack *operatorStack){
	
	OperatorToken *opeToken;
	while((opeToken=pop(operatorStack))!=NULL)
	{
		evaluateOperator(dataStack,opeToken);
	}
}

/**
	Evaluate all operators on the operator stack that have strictly lower
	precedence than the operator to be pushed. The evaluation of operators
	is from the top of stack to bottom
	
	Input :
		stack the operatorStack
		operator the operator to be pushed onto the operator stack 
		
**/

void tryEvaluateOperatorOnStackThenPush(OperatorToken *newToken,Stack *dataStack,Stack *operatorStack)
{
	OperatorToken *previousToken;
	previousToken=(OperatorToken*)pop(operatorStack);
	if(previousToken==NULL)
	{
		push(newToken,operatorStack);
	}
	else{
		while(previousToken!=NULL)
		{
			if(newToken->precedence > previousToken->precedence)
			{
				break;
			}
			else
			{
				evaluateOperator(dataStack,previousToken);
			}
			previousToken=(OperatorToken*)pop(operatorStack);
		}
		if(previousToken!=NULL)
		{
			push(previousToken,operatorStack);
		}
		push(newToken,operatorStack);
	}
}

	

